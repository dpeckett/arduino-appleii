// In fastcpu ino
extern unsigned short PC;
extern unsigned char X, Y;

// Addressing Modes
unsigned short inline a_abs() {
  PC += 2;
  return read16(PC-2);
}

unsigned short inline a_absx() {
  PC += 2;
  return (read16(PC-2) + (unsigned short)X);
}

unsigned short inline a_absy() {
  PC += 2;
  return (read16(PC-2) + (unsigned short)Y);
}

unsigned short inline a_imm() {
  return PC++; 
}

//ignore page wrap bug
unsigned short inline a_ind() {
  PC += 2;
  return read16(read16(PC-2));
}

unsigned short inline a_indx() {
  return read16(((unsigned short)read8(PC++) + (unsigned short)X)&0xFF);
}

unsigned short inline a_indy() {
  return read16(((unsigned short)read8(PC++) + (unsigned short)Y)&0xFF);
}

unsigned short inline a_rel() {
  unsigned short addr = (unsigned short)read8(PC++);
  return addr | ((addr&0x80)?0xFF00:0x0000);
}

unsigned short inline a_zpg() {
  return (unsigned short)read8(PC++);
}

unsigned short inline a_zpgx() {
  return  ((unsigned short)read8(PC++) + (unsigned short)X)&0xFF;
}

unsigned short inline a_zpgy() {
  return  ((unsigned short)read8(PC++) + (unsigned short)Y)&0xFF;
}
