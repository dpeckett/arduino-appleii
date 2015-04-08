int testPlaImplied() {
	//no flags
	A = 0x00;
	push8(0x23);
	ram[0] = 0x68;
	instructions = 1; run();
	if(!(A == 0x23 && !(SR&SR_ZERO) && !(SR&SR_NEG))) return -1;

	//zero flag
	A = 0x23;
	push8(0x00);
	ram[0] = 0x68;
	instructions = 1; run();
	if(!(A == 0x00 && SR&SR_ZERO && !(SR&SR_NEG))) return -1;

	return 0;
}