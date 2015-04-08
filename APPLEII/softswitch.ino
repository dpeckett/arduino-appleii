unsigned char softSwitch(unsigned short address) {
  switch(address&0x00FF) {
  case 0x00: // Keyboard Data
   return keyboard_read();
  case 0x10: // Keyboard Strobe
   keyboard_strobe();
   return 0xFF;
  case 0x30: // Speaker toggle
   speaker_toggle();
   return 0xFF;
  default:
   return 0xFF;
  }
}
