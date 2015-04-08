int testRorImplied() {
	//rotate in
	A = 0x81;
	SR |= SR_CARRY;
	ram[0] = 0x6A;
	instructions = 1; run();
	if(!(A == 0xC0 && !(SR&SR_ZERO) && SR&SR_NEG && SR&SR_CARRY)) return -1;

	//rotate out
	A = 0x01;
	SR &= (~SR_CARRY);
	ram[0] = 0x6A;
	instructions = 1; run();
	if(!(A == 0x00 && SR&SR_ZERO && !(SR&SR_NEG) && SR&SR_CARRY)) return -2;

	return 0;
}

int testRorZeropage() {
	//rotate in
	SR |= SR_CARRY;
	ram[0] = 0x66;
	ram[1] = 0x02;
	ram[2] = 0x81;
	instructions = 1; run();
	if(!(ram[2] == 0xC0 && !(SR&SR_ZERO) && SR&SR_NEG && SR&SR_CARRY)) return -1;

	//rotate out
	SR &= (~SR_CARRY);
	ram[0] = 0x66;
	ram[1] = 0x02;
	ram[2] = 0x01;
	instructions = 1; run();
	if(!(ram[2] == 0x00 && SR&SR_ZERO && !(SR&SR_NEG) && SR&SR_CARRY)) return -2;

	return 0;
}

int testRorZeropageX() {
	X = 0x01; Y = 0x00;

	//rotate in
	SR |= SR_CARRY;
	ram[0] = 0x76;
	ram[1] = 0x01;
	ram[2] = 0x81;
	instructions = 1; run();
	if(!(ram[2] == 0xC0 && !(SR&SR_ZERO) && SR&SR_NEG && SR&SR_CARRY)) return -1;

	//rotate out
	SR &= (~SR_CARRY);
	ram[0] = 0x76;
	ram[1] = 0x01;
	ram[2] = 0x01;
	instructions = 1; run();
	if(!(ram[2] == 0x00 && SR&SR_ZERO && !(SR&SR_NEG) && SR&SR_CARRY)) return -2;

	return 0;
}

int testRorAbsolute() {
	//rotate in
	SR |= SR_CARRY;
	ram[0] = 0x6E;
	ram[1] = 0x03;
	ram[2] = 0x00;
	ram[3] = 0x81;
	instructions = 1; run();
	if(!(ram[3] == 0xC0 && !(SR&SR_ZERO) && SR&SR_NEG && SR&SR_CARRY)) return -1;

	//rotate out
	SR &= (~SR_CARRY);
	ram[0] = 0x6E;
	ram[1] = 0x03;
	ram[2] = 0x00;
	ram[3] = 0x01;
	instructions = 1; run();
	if(!(ram[3] == 0x00 && SR&SR_ZERO && !(SR&SR_NEG) && SR&SR_CARRY)) return -2;

	return 0;
}

int testRorAbsoluteX() {
	X = 0x01; Y = 0x00;

	//rotate in
	SR |= SR_CARRY;
	ram[0] = 0x7E;
	ram[1] = 0x02;
	ram[2] = 0x00;
	ram[3] = 0x81;
	instructions = 1; run();
	if(!(ram[3] == 0xC0 && !(SR&SR_ZERO) && SR&SR_NEG && SR&SR_CARRY)) return -1;

	//rotate out
	SR &= (~SR_CARRY);
	ram[0] = 0x7E;
	ram[1] = 0x02;
	ram[2] = 0x00;
	ram[3] = 0x01;
	instructions = 1; run();
	if(!(ram[3] == 0x00 && SR&SR_ZERO && !(SR&SR_NEG) && SR&SR_CARRY)) return -2;

	return 0;
}