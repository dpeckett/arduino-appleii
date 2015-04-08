void inline flagZero(unsigned char value) {
  if(!value) SR |= SR_ZERO;
  else SR &= ~SR_ZERO;
}

void inline flagNegative(unsigned char value) {
  if(value&0x80) SR |= SR_NEG;
  else SR &= ~SR_NEG;
}

void inline flagCarry(unsigned short value) {
  if(value&0xFF00) SR |= SR_CARRY;
  else SR &= ~SR_CARRY;
}


