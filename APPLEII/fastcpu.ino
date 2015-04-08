// μ6502 v2.0 - Barebones 6502 Emulator By Damian Peckett
// dpeckett.com, <damian.peckett@gmail.com>

//Other constants
#define SR_FIXED_BITS 0x20
#define SR_CARRY      0x01
#define SR_ZERO       0x02
#define SR_INT        0x04
#define SR_DEC        0x08
#define SR_BRK        0x10
#define SR_OVER       0x40
#define SR_NEG        0x80

//Stack pointer base address
#define STP_BASE       0x100

// CPU registers
unsigned short PC;
unsigned char STP = 0xFD, A = 0x00, X = 0x00, Y = 0x00, SR = SR_FIXED_BITS;

void run() {
  // Opcode Addresses, Labels As Values
  static const void* opcodes[] = {
    &&BRK, &&ORA_INDX, &&UNDF, &&UNDF, &&UNDF, &&ORA_ZPG, &&ASL_ZPG, &&UNDF, &&PHP, &&ORA_IMM, &&ASL_A, &&UNDF, &&UNDF, &&ORA_ABS, &&ASL_ABS, &&UNDF,
    &&BPL_REL, &&ORA_INDY, &&UNDF, &&UNDF, &&UNDF, &&ORA_ZPGX, &&ASL_ZPGX, &&UNDF, &&CLC, &&ORA_ABSY, &&UNDF, &&UNDF, &&UNDF, &&ORA_ABSX, &&ASL_ABSX, &&UNDF,
    &&JSR_ABS, &&AND_INDX, &&UNDF, &&UNDF, &&BIT_ZPG, &&AND_ZPG, &&ROL_ZPG, &&UNDF, &&PLP, &&AND_IMM, &&ROL_A, &&UNDF, &&BIT_ABS, &&AND_ABS, &&ROL_ABS, &&UNDF
  };
  
  unsigned char value8, result8;
  unsigned short value16, result16;
  unsigned short ptr;
 
  // Load the reset vector
  PC = read16(0xFFFC);
  
  // Begin Execution
  goto *opcodes[read8(PC++)];
  
  // Instruction interpreter
  BRK:
    push16(PC+1);
    push8(SR|SR_BRK);
    SR |= SR_INT;
    PC = read16(0xFFFE);
    goto *opcodes[read8(PC++)];
  ORA_INDX:
    A |= read8(a_indx());
    flagZero(A);
    flagNegative(A);      
    goto *opcodes[read8(PC++)];
  ORA_ZPG:
    A |= read8(a_zpg());
    flagZero(A);
    flagNegative(A);      
    goto *opcodes[read8(PC++)];
  ASL_ZPG:
    ptr = a_zpg();
    value16 = read8(ptr);
    result16 = value16<<1;
    flagZero(result16&0x00FF);
    flagNegative(result16&0x00FF);
    flagCarry(result16);
    write8(ptr, result16&0x00FF);
    goto *opcodes[read8(PC++)];
  PHP:
    push8(SR|SR_BRK);
    goto *opcodes[read8(PC++)];
  ORA_IMM:
    A |= read8(a_imm());
    flagZero(A);
    flagNegative(A);      
    goto *opcodes[read8(PC++)];
  ASL_A:
    value16 = A;
    result16 = value16<<1;
    flagZero(result16&0x00FF);
    flagNegative(result16&0x00FF);
    flagCarry(result16);
    A = result16&0x00FF;
    goto *opcodes[read8(PC++)];
 ORA_ABS:
    A |= read8(a_abs());
    flagZero(A);
    flagNegative(A);      
    goto *opcodes[read8(PC++)];
 ASL_ABS:
    ptr = a_abs();
    value16 = read8(ptr);
    result16 = value16<<1;
    flagZero(result16&0x00FF);
    flagNegative(result16&0x00FF);
    flagCarry(result16);
    write8(ptr, result16&0x00FF);
    goto *opcodes[read8(PC++)];
  BPL_REL:
    if(!(SR&SR_NEG)) PC += a_rel();
    goto *opcodes[read8(PC++)];
  ORA_INDY:
    A |= read8(a_indy());
    flagZero(A);
    flagNegative(A);      
    goto *opcodes[read8(PC++)];
  ORA_ZPGX:
    A |= read8(a_zpgx());
    flagZero(A);
    flagNegative(A);      
    goto *opcodes[read8(PC++)];  
  ASL_ZPGX:
    ptr = a_zpgx();
    value16 = read8(ptr);
    result16 = value16<<1;
    flagZero(result16&0x00FF);
    flagNegative(result16&0x00FF);
    flagCarry(result16);
    write8(ptr, result16&0x00FF);
    goto *opcodes[read8(PC++)];
  CLC:
    SR &= ~SR_CARRY;
    goto *opcodes[read8(PC++)];
  ORA_ABSY:
    A |= read8(a_absy());
    flagZero(A);
    flagNegative(A);      
    goto *opcodes[read8(PC++)];
  ORA_ABSX:
    A |= read8(a_absx());
    flagZero(A);
    flagNegative(A);      
    goto *opcodes[read8(PC++)];
  ASL_ABSX:
    ptr = a_absx();
    value16 = read8(ptr);
    result16 = value16<<1;
    flagZero(result16&0x00FF);
    flagNegative(result16&0x00FF);
    flagCarry(result16);
    write8(ptr, result16&0x00FF);
    goto *opcodes[read8(PC++)];
  JSR_ABS:
    push16(PC-1);
    PC = a_abs();
    goto *opcodes[read8(PC++)];
  AND_INDX:
    A &= read8(a_indx());
    flagZero(A);
    flagNegative(A);      
    goto *opcodes[read8(PC++)];
  BIT_ZPG:
    value8 = read8(a_zpg());
    result8 = A & value8;
    flagZero(result8);
    SR = (SR&0x3F) | (value8&0xC0);
    goto *opcodes[read8(PC++)];
  AND_ZPG:
    A &= read8(a_zpg());
    flagZero(A);
    flagNegative(A);      
    goto *opcodes[read8(PC++)];
  ROL_ZPG:
    ptr = a_zpg();
    value16 = read8(ptr);
    result16 = (value16 << 1) | (SR&SR_CARRY);
    flagZero(result16&0x00FF);
    flagNegative(result16&0x00FF);
    flagCarry(result16);
    write8(ptr, result16&0x00FF);
    goto *opcodes[read8(PC++)];
  PLP:
    SR = pull8() | SR_FIXED_BITS;
    goto *opcodes[read8(PC++)];
  AND_IMM:
    A &= read8(a_imm());
    flagZero(A);
    flagNegative(A);      
    goto *opcodes[read8(PC++)];
  ROL_A:
    value16 = A;
    result16 = (value16 << 1) | (SR&SR_CARRY);
    flagZero(result16&0x00FF);
    flagNegative(result16&0x00FF);
    flagCarry(result16);
    A = result16&0x00FF;
    goto *opcodes[read8(PC++)];
  BIT_ABS:
    value8 = read8(a_abs());
    result8 = A & value8;
    flagZero(result8);
    SR = (SR&0x3F) | (value8&0xC0);
    goto *opcodes[read8(PC++)];
  AND_ABS:
    A &= read8(a_abs());
    flagZero(A);
    flagNegative(A);      
    goto *opcodes[read8(PC++)];  
  ROL_ABS:
    ptr = a_abs();
    value16 = read8(ptr);
    result16 = (value16 << 1) | (SR&SR_CARRY);
    flagZero(result16&0x00FF);
    flagNegative(result16&0x00FF);
    flagCarry(result16);
    write8(ptr, result16&0x00FF);
    goto *opcodes[read8(PC++)];
  
  // -- Undefined Opcodes
  UNDF:
    // Raise an error
    goto *opcodes[read8(PC++)];
}
