int testCpxImmediate() {
	//no difference
	SR |= SR_ZERO;
	SR |= SR_CARRY;
	SR |= SR_NEG;
	X = 0x10;
	ram[0] = 0xE0;
	ram[1] = 0x10;
	instructions = 2; run();
	if(!(!(SR&SR_NEG) && SR&SR_ZERO && SR&SR_CARRY)) return -1;

	//less
	SR |= SR_ZERO;
	SR |= SR_CARRY;
	SR |= SR_NEG;
	X = 0x10;
	ram[0] = 0xE0;
	ram[1] = 0x04;
	instructions = 2; run();
	if(!(!(SR&SR_NEG) && !(SR&SR_ZERO) && SR&SR_CARRY)) return -2;

	//more
	SR |= SR_ZERO;
	SR |= SR_CARRY;
	SR |= SR_NEG;
	X = 0x04;
	ram[0] = 0xE0;
	ram[1] = 0x10;
	instructions = 2; run();
	if(!(SR&SR_NEG && !(SR&SR_ZERO) && !(SR&SR_CARRY))) return -2;

	return 0;
}

int testCpxZeropage() {
	//no difference
	SR |= SR_ZERO;
	SR |= SR_CARRY;
	SR |= SR_NEG;
	X = 0x10;
	ram[0] = 0xE4;
	ram[1] = 0x02;
	ram[2] = 0x10;
	instructions = 2; run();
	if(!(!(SR&SR_NEG) && SR&SR_ZERO && SR&SR_CARRY)) return -1;

	//less
	SR |= SR_ZERO;
	SR |= SR_CARRY;
	SR |= SR_NEG;
	X = 0x10;
	ram[0] = 0xE4;
	ram[1] = 0x02;
	ram[2] = 0x04;
	instructions = 2; run();
	if(!(!(SR&SR_NEG) && !(SR&SR_ZERO) && SR&SR_CARRY)) return -2;

	//more
	SR |= SR_ZERO;
	SR |= SR_CARRY;
	SR |= SR_NEG;
	X = 0x04;
	ram[0] = 0xE4;
	ram[1] = 0x02;
	ram[2] = 0x10;
	instructions = 2; run();
	if(!(SR&SR_NEG && !(SR&SR_ZERO) && !(SR&SR_CARRY))) return -2;

	return 0;
}

int testCpxAbsolute() {
	//no difference
	SR |= SR_ZERO;
	SR |= SR_CARRY;
	SR |= SR_NEG;
	X = 0x10;
	ram[0] = 0xEC;
	ram[1] = 0x03;
	ram[2] = 0x00;
	ram[3] = 0x10;
	instructions = 2; run();
	if(!(!(SR&SR_NEG) && SR&SR_ZERO && SR&SR_CARRY)) return -1;

	//less
	SR |= SR_ZERO;
	SR |= SR_CARRY;
	SR |= SR_NEG;
	X = 0x10;
	ram[0] = 0xEC;
	ram[1] = 0x03;
	ram[2] = 0x00;
	ram[3] = 0x04;
	instructions = 2; run();
	if(!(!(SR&SR_NEG) && !(SR&SR_ZERO) && SR&SR_CARRY)) return -2;

	//more
	SR |= SR_ZERO;
	SR |= SR_CARRY;
	SR |= SR_NEG;
	X = 0x04;
	ram[0] = 0xEC;
	ram[1] = 0x03;
	ram[2] = 0x00;
	ram[3] = 0x10;
	instructions = 2; run();
	if(!(SR&SR_NEG && !(SR&SR_ZERO) && !(SR&SR_CARRY))) return -2;

	return 0;
}