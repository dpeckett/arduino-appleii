int testBrkImplied() {
	SR &= (~SR_INT);
	SP = 0xFF;
	ram[0] = 0x00;
	instructions = 4; run();
	if(!(SR&SR_INT) || PC != (read8(0xFFFE)|((unsigned short)read8(0xFFFF)<<8)) || SP != 0xFC) return -1;
	return 0;
}