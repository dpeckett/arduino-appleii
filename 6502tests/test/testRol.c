int testRolImplied() {
	//rotate in
	A = 0x81;
	SR |= SR_CARRY;
	ram[0] = 0x2A;
	instructions = 1; run();
	if(!(A == 0x03 && !(SR&SR_ZERO) && !(SR&SR_NEG) && SR&SR_CARRY)) return -1;

	//rotate out
	A = 0x80;
	SR &= (~SR_CARRY);
	ram[0] = 0x2A;
	instructions = 1; run();
	if(!(A == 0x00 && SR&SR_ZERO && !(SR&SR_NEG) && SR&SR_CARRY)) return -2;

	return 0;
}

int testRolZeropage() {
	//rotate in
	SR |= SR_CARRY;
	ram[0] = 0x26;
	ram[1] = 0x02;
	ram[2] = 0x81;
	instructions = 1; run();
	if(!(ram[2] == 0x03 && !(SR&SR_ZERO) && !(SR&SR_NEG) && SR&SR_CARRY)) return -1;

	//rotate out
	SR &= (~SR_CARRY);
	ram[0] = 0x26;
	ram[1] = 0x02;
	ram[2] = 0x80;
	instructions = 1; run();
	if(!(ram[2] == 0x00 && SR&SR_ZERO && !(SR&SR_NEG) && SR&SR_CARRY)) return -2;

	return 0;
}

int testRolZeropageX() {
	X = 0x01; Y = 0x00;

	//rotate in
	SR |= SR_CARRY;
	ram[0] = 0x36;
	ram[1] = 0x01;
	ram[2] = 0x81;
	instructions = 1; run();
	if(!(ram[2] == 0x03 && !(SR&SR_ZERO) && !(SR&SR_NEG) && SR&SR_CARRY)) return -1;

	//rotate out
	SR &= (~SR_CARRY);
	ram[0] = 0x36;
	ram[1] = 0x01;
	ram[2] = 0x80;
	instructions = 1; run();
	if(!(ram[2] == 0x00 && SR&SR_ZERO && !(SR&SR_NEG) && SR&SR_CARRY)) return -2;

	return 0;
}

int testRolAbsolute() {
	//rotate in
	SR |= SR_CARRY;
	ram[0] = 0x2E;
	ram[1] = 0x03;
	ram[2] = 0x00;
	ram[3] = 0x81;
	instructions = 1; run();
	if(!(ram[3] == 0x03 && !(SR&SR_ZERO) && !(SR&SR_NEG) && SR&SR_CARRY)) return -1;

	//rotate out
	SR &= (~SR_CARRY);
	ram[0] = 0x2E;
	ram[1] = 0x03;
	ram[2] = 0x00;
	ram[3] = 0x80;
	instructions = 1; run();
	if(!(ram[3] == 0x00 && SR&SR_ZERO && !(SR&SR_NEG) && SR&SR_CARRY)) return -2;

	return 0;
}

int testRolAbsoluteX() {
	X = 0x01; Y = 0x00;

	//rotate in
	SR |= SR_CARRY;
	ram[0] = 0x3E;
	ram[1] = 0x02;
	ram[2] = 0x00;
	ram[3] = 0x81;
	instructions = 1; run();
	if(!(ram[3] == 0x03 && !(SR&SR_ZERO) && !(SR&SR_NEG) && SR&SR_CARRY)) return -1;

	//rotate out
	SR &= (~SR_CARRY);
	ram[0] = 0x3E;
	ram[1] = 0x02;
	ram[2] = 0x00;
	ram[3] = 0x80;
	instructions = 1; run();
	if(!(ram[3] == 0x00 && SR&SR_ZERO && !(SR&SR_NEG) && SR&SR_CARRY)) return -2;

	return 0;
}