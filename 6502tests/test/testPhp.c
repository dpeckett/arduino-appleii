int testPhpImplied() {
	//random pattern
	SR |= SR_NEG; SR &= (~SR_OVER); SR |= SR_DEC; SR &= (~SR_INT); SR |= SR_ZERO; SR &= (~SR_CARRY);
	ram[0] = 0x08;
	instructions = 1; run();
	if(!(pull8() == 0xBA)) return -1;

	//all set
	SR = 0xFF;
	ram[0] = 0x08;
	instructions = 1; run();
	if(!(pull8() == 0xFF)) return -2;

	return 0;
}