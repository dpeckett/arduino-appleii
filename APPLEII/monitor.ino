// Hook routines for the apple II monitor program
// Used to trick the apple code into working on this hardware
// Ideally should patch the ROM itself, will do in future.
void program_hooks(unsigned short addr) {
  // hook screen scroll, monitor command
  if(addr == 0xFC70) {
    screenScroll();
    PC = 0xFC95;
  } 
  // hook cassette write commnand
  else if (addr == 0xFECD || addr == 0xFECF) {
    // Header length
    cassette_header((addr==0xFECD)?64:A);
    // Write Data Block
    cassette_write_block(read16(0x3C), read16(0x3E));
    // Emulate counter behaviour
    write16(0x003C, read16(0x3E));
    PC = 0xFEF5;
  }
  // hook cassette read command
  else if (addr == 0xFEFD) {
      // Read Data Block
      boolean success = cassette_read_block(read16(0x3C), read16(0x3E));
      // Emulate counter behaviour
      write16(0x003C, read16(0x3E));
      if(success) PC = 0xFF3A; 
      else PC = 0xFF2D;
  }
}
