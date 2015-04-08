int testPlpImplied() {
	SR = 0x20;
	push8(0xBA);
	ram[0] = 0x28;
	instructions = 1; run();
	if(!(SR&SR_NEG && !(SR&SR_OVER) && SR&SR_DEC && !(SR&SR_INT) && SR&SR_ZERO && !(SR&SR_CARRY))) return -1;
	return 0;
}