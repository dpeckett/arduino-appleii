int testRtiImplied() {
	push8(0x00); //high byte pc
	push8(0x02); // low byte pc
	push8(0xBA); //SR
	ram[0] = 0x40;
	instructions = 1; run();
	if(!(SR&SR_NEG && !(SR&SR_OVER) && SR&SR_DEC && !(SR&SR_INT) && SR&SR_ZERO && !(SR&SR_CARRY) && PC == 0x02)) return -1;
	return 0;
}