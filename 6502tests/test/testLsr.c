int testLsrImplied() {
	SR &= (~SR_DEC);
	SR &= (~SR_NEG);

	//zero
	SR |= SR_CARRY;
	A = 0x01;
	ram[0] = 0x4A;
	instructions = 1; run();
	if(!(A == 0x00 && SR&SR_ZERO && SR&SR_CARRY && !(SR&SR_NEG))) return -1;

	//carry out
	A = 0x80;
	ram[0] = 0x4A;
	instructions = 1; run();
	if(!(A == 0x40 && !(SR&SR_ZERO) && !(SR&SR_CARRY) && !(SR&SR_NEG))) return -2;

	return 0;
}

int testLsrZeropage() {
	//zero
	SR |= SR_CARRY;
	ram[0] = 0x46;
	ram[1] = 0x02;
	ram[2] = 0x01;
	instructions = 1; run();
	if(!(ram[2] == 0x00 && SR&SR_ZERO && SR&SR_CARRY && !(SR&SR_NEG))) return -1;

	//carry out
	ram[0] = 0x46;
	ram[1] = 0x02;
	ram[2] = 0x80;
	instructions = 1; run();
	if(!(ram[2] == 0x40 && !(SR&SR_ZERO) && !(SR&SR_CARRY) && !(SR&SR_NEG))) return -2;
	
	return 0;
}

int testLsrZeropageX() {
	X = 0x01; Y = 0x00;

	//zero
	SR |= SR_CARRY;
	ram[0] = 0x56;
	ram[1] = 0x01;
	ram[2] = 0x01;
	instructions = 1; run();
	if(!(ram[2] == 0x00 && SR&SR_ZERO && SR&SR_CARRY && !(SR&SR_NEG))) return -1;

	//carry out
	ram[0] = 0x56;
	ram[1] = 0x01;
	ram[2] = 0x80;
	instructions = 1; run();
	if(!(ram[2] == 0x40 && !(SR&SR_ZERO) && !(SR&SR_CARRY) && !(SR&SR_NEG))) return -2;
	
	return 0;
}

int testLsrAbsolute() {
	//zero
	SR |= SR_CARRY;
	ram[0] = 0x4E;
	ram[1] = 0x03;
	ram[2] = 0x00;
	ram[3] = 0x01;
	instructions = 1; run();
	if(!(ram[3] == 0x00 && SR&SR_ZERO && SR&SR_CARRY && !(SR&SR_NEG))) return -1;

	//carry out
	ram[0] = 0x4E;
	ram[1] = 0x03;
	ram[2] = 0x00;
	ram[3] = 0x80;
	instructions = 1; run();
	if(!(ram[3] == 0x40 && !(SR&SR_ZERO) && !(SR&SR_CARRY) && !(SR&SR_NEG))) return -2;

	return 0;
}

int testLsrAbsoluteX() {
	X = 0x01; Y = 0x00;

	//zero
	SR |= SR_CARRY;
	ram[0] = 0x5E;
	ram[1] = 0x02;
	ram[2] = 0x00;
	ram[3] = 0x01;
	instructions = 1; run();
	if(!(ram[3] == 0x00 && SR&SR_ZERO && SR&SR_CARRY && !(SR&SR_NEG))) return -1;

	//carry out
	ram[0] = 0x5E;
	ram[1] = 0x02;
	ram[2] = 0x00;
	ram[3] = 0x80;
	instructions = 1; run();
	if(!(ram[3] == 0x40 && !(SR&SR_ZERO) && !(SR&SR_CARRY) && !(SR&SR_NEG))) return -2;

	return 0;
}