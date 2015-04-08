int testPhaImplied() {
	unsigned short beginSp = SP;
	A = 0x23;
	ram[0] = 0x48;
	instructions = 1; run();
	if(!((beginSp-SP) == 1 && pull8() == 0x23)) return -1;
	return 0;
}