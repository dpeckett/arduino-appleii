// Share speaker pin for output
#define CASSETTE_READ_PIN A5
#define SPEAKER_PIN 5

#ifndef cbi
#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
#endif
#ifndef sbi
#define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))
#endif

void cassette_header(unsigned short periods) {
  // Header Tone
  for(int i = 0; i < periods*128; ++i) {
    digitalWrite(SPEAKER_PIN, HIGH);
    delayMicroseconds(650);
    digitalWrite(SPEAKER_PIN, LOW);
    delayMicroseconds(650);
  }
  // Sync pulse, one half cycle at 2500hz and then 2000hz
  // 2500 hz
  digitalWrite(SPEAKER_PIN, HIGH);
  delayMicroseconds(200);
  // 2000 hz
  digitalWrite(SPEAKER_PIN, LOW);
  delayMicroseconds(250);
}

void cassette_write_byte(unsigned char val) {
  // Shift it out, MSB first
  digitalWrite(SPEAKER_PIN, HIGH);
  delayMicroseconds((val&0x80) ? 500 : 250);  
  digitalWrite(SPEAKER_PIN, LOW);
  delayMicroseconds((val&0x80) ? 500 : 250);
  //bit 6
  digitalWrite(SPEAKER_PIN, HIGH);
  delayMicroseconds((val&0x40) ? 500 : 250);  
  digitalWrite(SPEAKER_PIN, LOW);
  delayMicroseconds((val&0x40) ? 500 : 250);
  //bit 5
  digitalWrite(SPEAKER_PIN, HIGH);
  delayMicroseconds((val&0x20) ? 500 : 250);  
  digitalWrite(SPEAKER_PIN, LOW);
  delayMicroseconds((val&0x20) ? 500 : 250);
  //bit 4
  digitalWrite(SPEAKER_PIN, HIGH);
  delayMicroseconds((val&0x10) ? 500 : 250);  
  digitalWrite(SPEAKER_PIN, LOW);
  delayMicroseconds((val&0x10) ? 500 : 250);
  //bit 3
  digitalWrite(SPEAKER_PIN, HIGH);
  delayMicroseconds((val&0x08) ? 500 : 250);  
  digitalWrite(SPEAKER_PIN, LOW);
  delayMicroseconds((val&0x08) ? 500 : 250);
  //bit 2
  digitalWrite(SPEAKER_PIN, HIGH);
  delayMicroseconds((val&0x04) ? 500 : 250);  
  digitalWrite(SPEAKER_PIN, LOW);
  delayMicroseconds((val&0x04) ? 500 : 250);  
  //bit 1
  digitalWrite(SPEAKER_PIN, HIGH);
  delayMicroseconds((val&0x02) ? 500 : 250);  
  digitalWrite(SPEAKER_PIN, LOW);
  delayMicroseconds((val&0x02) ? 500 : 250);  
  //bit 0
  digitalWrite(SPEAKER_PIN, HIGH);
  delayMicroseconds((val&0x01) ? 500 : 250);  
  digitalWrite(SPEAKER_PIN, LOW);
  delayMicroseconds((val&0x01) ? 500 : 250);
}

void cassette_write_block(unsigned short A1, unsigned short A2) {
  unsigned char checksum = 0xFF, val = 0;
  for(unsigned short addr = A1; addr <= A2; ++addr) {
    val = read8(addr);
    cassette_write_byte(val);
    checksum ^= val;
  }
  cassette_write_byte(checksum);
  // High idle for a little while, make sure all bits cleared
  digitalWrite(SPEAKER_PIN, HIGH);
  delay(10);
  digitalWrite(SPEAKER_PIN, LOW);
}

// Used to track center voltage
float cassette_center_voltage = 512;
// implement zero crossing detector
boolean cassette_read_state() {
  static boolean zerocross_state = false;
  // get value
  short adc = (analogRead(CASSETTE_READ_PIN) - (short)cassette_center_voltage);
  // bias drift correction
  cassette_center_voltage += adc*0.05f;
  // ~7mv hysteresis
  if(zerocross_state && adc < -7) zerocross_state = false;
  else if(!zerocross_state && adc > 7) zerocross_state = true;  
  return zerocross_state;
}

// figure out the duration of zero crossing
short cassette_read_transition() {
  unsigned long start_time;
  static boolean last = false;
  boolean cur = last;
  // loop until state transition
  for(start_time = micros();cur == last;) cur = cassette_read_state();
  // update transition tracking
  last = cur;
  //return duration of transition us
  return micros() - start_time;
}

// Based loosely on steve wozniaks original algorithm
boolean cassette_read_block(unsigned short A1, unsigned short A2) {
  short bitperiod;
  unsigned char val, checksum = 0xFF, datachecksum = 0x00;
  
  // Calibrate the zero crossing detector
  for(short i = 0; i < 10000; ++i) cassette_read_state();
  
  // find tape in edge
  cassette_read_transition();
  cassette_read_transition();
  
  // Small delay to allow things to settle
  delay(500);
  
  //wait for sync bit, short zero
  while(cassette_read_transition() > 300);
  
  // skip second cycle of sync bit
  cassette_read_transition();
  
  // start reading data  
  for(unsigned short addr = A1; addr <= A2; ++addr) {
    // zero our byte of memory
    val = 0;
    for(unsigned char i = 8; i != 0; --i) {
      bitperiod = (cassette_read_transition() + cassette_read_transition()) / 2;
      if(bitperiod > 300) val |= _BV(i-1);
    }
    // write byte to memory
    write8(addr, val);
    // update checksum
    checksum ^= val;
  }
  
  // Read checksum
  for(unsigned char i = 8; i != 0; --i) {
    bitperiod = (cassette_read_transition() + cassette_read_transition()) / 2;
    if(bitperiod > 300) datachecksum |= _BV(i-1);
  }
  
  //return whether the data passes error checking
  return (datachecksum == checksum);
}

void cassette_begin() {
  // ADC prescale, 77khz
  sbi(ADCSRA,ADPS2);
  cbi(ADCSRA,ADPS1);
  cbi(ADCSRA,ADPS0);
  // internal pullup on analog pin
  digitalWrite(CASSETTE_READ_PIN, HIGH);
  // use 1.1v internal analog reference
  analogReference(INTERNAL);
}
