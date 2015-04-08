int testCmpImmediate() {
	//no difference
	SR |= SR_ZERO;
	SR |= SR_CARRY;
	SR |= SR_NEG;
	A = 0x10;
	ram[0] = 0xC9;
	ram[1] = 0x10;
	instructions = 2; run();
	if(!(!(SR&SR_NEG) && SR&SR_ZERO && SR&SR_CARRY)) return -1;

	//less
	SR |= SR_ZERO;
	SR |= SR_CARRY;
	SR |= SR_NEG;
	A = 0x10;
	ram[0] = 0xC9;
	ram[1] = 0x04;
	instructions = 2; run();
	if(!(!(SR&SR_NEG) && !(SR&SR_ZERO) && SR&SR_CARRY)) return -2;

	//more
	SR |= SR_ZERO;
	SR |= SR_CARRY;
	SR |= SR_NEG;
	A = 0x04;
	ram[0] = 0xC9;
	ram[1] = 0x10;
	instructions = 2; run();
	if(!(SR&SR_NEG && !(SR&SR_ZERO) && !(SR&SR_CARRY))) return -2;

	return 0;
}

int testCmpZeropage() {
	//no difference
	SR |= SR_ZERO;
	SR |= SR_CARRY;
	SR |= SR_NEG;
	A = 0x10;
	ram[0] = 0xC5;
	ram[1] = 0x02;
	ram[2] = 0x10;
	instructions = 2; run();
	if(!(!(SR&SR_NEG) && SR&SR_ZERO && SR&SR_CARRY)) return -1;

	//less
	SR |= SR_ZERO;
	SR |= SR_CARRY;
	SR |= SR_NEG;
	A = 0x10;
	ram[0] = 0xC5;
	ram[1] = 0x02;
	ram[2] = 0x04;
	instructions = 2; run();
	if(!(!(SR&SR_NEG) && !(SR&SR_ZERO) && SR&SR_CARRY)) return -2;

	//more
	SR |= SR_ZERO;
	SR |= SR_CARRY;
	SR |= SR_NEG;
	A = 0x04;
	ram[0] = 0xC5;
	ram[1] = 0x02;
	ram[2] = 0x10;
	instructions = 2; run();
	if(!(SR&SR_NEG && !(SR&SR_ZERO) && !(SR&SR_CARRY))) return -2;

	return 0;
}

int testCmpZeropageX() {
	X = 0x01; Y = 0x00;

	//no difference
	SR |= SR_ZERO;
	SR |= SR_CARRY;
	SR |= SR_NEG;
	A = 0x10;
	ram[0] = 0xD5;
	ram[1] = 0x01;
	ram[2] = 0x10;
	instructions = 2; run();
	if(!(!(SR&SR_NEG) && SR&SR_ZERO && SR&SR_CARRY)) return -1;

	//less
	SR |= SR_ZERO;
	SR |= SR_CARRY;
	SR |= SR_NEG;
	A = 0x10;
	ram[0] = 0xD5;
	ram[1] = 0x01;
	ram[2] = 0x04;
	instructions = 2; run();
	if(!(!(SR&SR_NEG) && !(SR&SR_ZERO) && SR&SR_CARRY)) return -2;

	//more
	SR |= SR_ZERO;
	SR |= SR_CARRY;
	SR |= SR_NEG;
	A = 0x04;
	ram[0] = 0xD5;
	ram[1] = 0x01;
	ram[2] = 0x10;
	instructions = 2; run();
	if(!(SR&SR_NEG && !(SR&SR_ZERO) && !(SR&SR_CARRY))) return -2;

	return 0;
}

int testCmpAbsolute() {
	//no difference
	SR |= SR_ZERO;
	SR |= SR_CARRY;
	SR |= SR_NEG;
	A = 0x10;
	ram[0] = 0xCD;
	ram[1] = 0x03;
	ram[2] = 0x00;
	ram[3] = 0x10;
	instructions = 2; run();
	if(!(!(SR&SR_NEG) && SR&SR_ZERO && SR&SR_CARRY)) return -1;

	//less
	SR |= SR_ZERO;
	SR |= SR_CARRY;
	SR |= SR_NEG;
	A = 0x10;
	ram[0] = 0xCD;
	ram[1] = 0x03;
	ram[2] = 0x00;
	ram[3] = 0x04;
	instructions = 2; run();
	if(!(!(SR&SR_NEG) && !(SR&SR_ZERO) && SR&SR_CARRY)) return -2;

	//more
	SR |= SR_ZERO;
	SR |= SR_CARRY;
	SR |= SR_NEG;
	A = 0x04;
	ram[0] = 0xCD;
	ram[1] = 0x03;
	ram[2] = 0x00;
	ram[3] = 0x10;
	instructions = 2; run();
	if(!(SR&SR_NEG && !(SR&SR_ZERO) && !(SR&SR_CARRY))) return -2;

	return 0;
}

int testCmpAbsoluteX() {
	X = 0x01; Y = 0x00;

	//no difference
	SR |= SR_ZERO;
	SR |= SR_CARRY;
	SR |= SR_NEG;
	A = 0x10;
	ram[0] = 0xDD;
	ram[1] = 0x02;
	ram[2] = 0x00;
	ram[3] = 0x10;
	instructions = 2; run();
	if(!(!(SR&SR_NEG) && SR&SR_ZERO && SR&SR_CARRY)) return -1;

	//less
	SR |= SR_ZERO;
	SR |= SR_CARRY;
	SR |= SR_NEG;
	A = 0x10;
	ram[0] = 0xDD;
	ram[1] = 0x02;
	ram[2] = 0x00;
	ram[3] = 0x04;
	instructions = 2; run();
	if(!(!(SR&SR_NEG) && !(SR&SR_ZERO) && SR&SR_CARRY)) return -2;

	//more
	SR |= SR_ZERO;
	SR |= SR_CARRY;
	SR |= SR_NEG;
	A = 0x04;
	ram[0] = 0xDD;
	ram[1] = 0x02;
	ram[2] = 0x00;
	ram[3] = 0x10;
	instructions = 2; run();
	if(!(SR&SR_NEG && !(SR&SR_ZERO) && !(SR&SR_CARRY))) return -2;

	return 0;
}

int testCmpAbsoluteY() {
	Y = 0x01; X = 0x00;

	//no difference
	SR |= SR_ZERO;
	SR |= SR_CARRY;
	SR |= SR_NEG;
	A = 0x10;
	ram[0] = 0xD9;
	ram[1] = 0x02;
	ram[2] = 0x00;
	ram[3] = 0x10;
	instructions = 2; run();
	if(!(!(SR&SR_NEG) && SR&SR_ZERO && SR&SR_CARRY)) return -1;

	//less
	SR |= SR_ZERO;
	SR |= SR_CARRY;
	SR |= SR_NEG;
	A = 0x10;
	ram[0] = 0xD9;
	ram[1] = 0x02;
	ram[2] = 0x00;
	ram[3] = 0x04;
	instructions = 2; run();
	if(!(!(SR&SR_NEG) && !(SR&SR_ZERO) && SR&SR_CARRY)) return -2;

	//more
	SR |= SR_ZERO;
	SR |= SR_CARRY;
	SR |= SR_NEG;
	A = 0x04;
	ram[0] = 0xD9;
	ram[1] = 0x02;
	ram[2] = 0x00;
	ram[3] = 0x10;
	instructions = 2; run();
	if(!(SR&SR_NEG && !(SR&SR_ZERO) && !(SR&SR_CARRY))) return -2;

	return 0;
}

int testCmpIndirectX() {
	X = 0x01; Y = 0x00;

	//no difference
	SR |= SR_ZERO;
	SR |= SR_CARRY;
	SR |= SR_NEG;
	A = 0x10;
	ram[0] = 0xC1;
	ram[1] = 0x02;
	ram[2] = 0x02;
	ram[3] = 0x10;
	instructions = 2; run();
	if(!(!(SR&SR_NEG) && SR&SR_ZERO && SR&SR_CARRY)) return -1;

	//less
	SR |= SR_ZERO;
	SR |= SR_CARRY;
	SR |= SR_NEG;
	A = 0x10;
	ram[0] = 0xC1;
	ram[1] = 0x02;
	ram[2] = 0x02;
	ram[3] = 0x04;
	instructions = 2; run();
	if(!(!(SR&SR_NEG) && !(SR&SR_ZERO) && SR&SR_CARRY)) return -2;

	//more
	SR |= SR_ZERO;
	SR |= SR_CARRY;
	SR |= SR_NEG;
	A = 0x04;
	ram[0] = 0xC1;
	ram[1] = 0x02;
	ram[2] = 0x02;
	ram[3] = 0x10;
	instructions = 2; run();
	if(!(SR&SR_NEG && !(SR&SR_ZERO) && !(SR&SR_CARRY))) return -2;

	return 0;
}

int testCmpIndirectY() {
	Y = 0x01; X = 0x00;

	//no difference
	SR |= SR_ZERO;
	SR |= SR_CARRY;
	SR |= SR_NEG;
	A = 0x10;
	ram[0] = 0xD1;
	ram[1] = 0x02;
	ram[2] = 0x03;
	ram[3] = 0x00;
	ram[4] = 0x10;
	instructions = 2; run();
	if(!(!(SR&SR_NEG) && SR&SR_ZERO && SR&SR_CARRY)) return -1;

	//less
	SR |= SR_ZERO;
	SR |= SR_CARRY;
	SR |= SR_NEG;
	A = 0x10;
	ram[0] = 0xD1;
	ram[1] = 0x02;
	ram[2] = 0x03;
	ram[3] = 0x00;
	ram[4] = 0x04;
	instructions = 2; run();
	if(!(!(SR&SR_NEG) && !(SR&SR_ZERO) && SR&SR_CARRY)) return -2;

	//more
	SR |= SR_ZERO;
	SR |= SR_CARRY;
	SR |= SR_NEG;
	A = 0x04;
	ram[0] = 0xD1;
	ram[1] = 0x02;
	ram[2] = 0x03;
	ram[3] = 0x00;
	ram[4] = 0x10;
	instructions = 2; run();
	if(!(SR&SR_NEG && !(SR&SR_ZERO) && !(SR&SR_CARRY))) return -2;

	return 0;
}