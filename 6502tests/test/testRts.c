int testRtsImplied() {
	push8(0x00); //high byte pc
	push8(0x02); // low byte pc
	ram[0] = 0x60;
	instructions = 1; run();
	if(!(PC == 0x03)) return -1;
	return 0;
}