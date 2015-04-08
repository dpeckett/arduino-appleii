void writeCharacter(unsigned char row, unsigned char col, unsigned char val) {
  unsigned char buf[4] = {0xFD, 0, 0, 0};
  buf[1] = col;
  buf[2] = row;
  buf[3] = val;
  Serial.write(buf, 4);
}

unsigned char readCharacter(unsigned char row, unsigned char col) {
  unsigned long transaction_begin;
  unsigned char buf[4] = {0xFA, 0, 0};
  buf[1] = col;
  buf[2] = row;
  Serial.write(buf, 3);
  for(transaction_begin = millis(); !Serial.available(); millis() < (transaction_begin+50));
  return Serial.read();
}

void clearScreen() {
  unsigned char cmd = 0xFC;
  Serial.write(&cmd, 1);
  delay(20);
}

void screenScroll() {
  unsigned char cmd = 0xFB;
  Serial.write(&cmd, 1);
  delay(20);
}
