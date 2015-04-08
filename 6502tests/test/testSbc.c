int testSbcImmediate() {
	SR &= (~SR_DEC);

	//no overflow
	SR |= SR_CARRY;
	A = 0x00;
	ram[0] = 0xE9;
	ram[1] = 0x01;
	instructions = 1; run();
	if(!(A == 0xFF && SR&SR_NEG && !(SR&SR_ZERO) && !(SR&SR_CARRY) && !(SR&SR_OVER))) return -1;

	//overflow
	SR |= SR_CARRY;
	A = 0x7F;
	ram[0] = 0xE9;
	ram[1] = 0xFF;
	instructions = 1; run();
	if(!(A == 0x80 && SR&SR_NEG && !(SR&SR_ZERO) && !(SR&SR_CARRY) && SR&SR_OVER)) return -2;

	//no borrow
	SR &= (~SR_CARRY);
	A = 0xC0;
	ram[0] = 0xE9;
	ram[1] = 0x40;
	instructions = 1; run();
	//overflow differs from 2nd sim ...
	if(!(A == 0x7F && !(SR&SR_NEG) && !(SR&SR_ZERO) && SR&SR_CARRY && SR&SR_OVER)) return -3;

	return 0;
}

int testSbcZeropage() {
	//no overflow
	SR |= SR_CARRY;
	A = 0x00;
	ram[0] = 0xE5;
	ram[1] = 0x02;
	ram[2] = 0x01;
	instructions = 1; run();
	if(!(A == 0xFF && SR&SR_NEG && !(SR&SR_ZERO) && !(SR&SR_CARRY) && !(SR&SR_OVER))) return -1;

	//overflow
	SR |= SR_CARRY;
	A = 0x7F;
	ram[0] = 0xE5;
	ram[1] = 0x02;
	ram[2] = 0xFF;
	instructions = 1; run();
	if(!(A == 0x80 && SR&SR_NEG && !(SR&SR_ZERO) && !(SR&SR_CARRY) && SR&SR_OVER)) return -2;

	//no borrow
	SR &= (~SR_CARRY);
	A = 0xC0;
	ram[0] = 0xE5;
	ram[1] = 0x02;
	ram[2] = 0x40;
	instructions = 1; run();
	//overflow differs from 2nd sim ...
	if(!(A == 0x7F && !(SR&SR_NEG) && !(SR&SR_ZERO) && SR&SR_CARRY && SR&SR_OVER)) return -3;

	return 0;
}

int testSbcZeropageX() {
	X = 0x01; Y = 0x00;

	//no overflow
	SR |= SR_CARRY;
	A = 0x00;
	ram[0] = 0xF5;
	ram[1] = 0x01;
	ram[2] = 0x01;
	instructions = 1; run();
	if(!(A == 0xFF && SR&SR_NEG && !(SR&SR_ZERO) && !(SR&SR_CARRY) && !(SR&SR_OVER))) return -1;

	//overflow
	SR |= SR_CARRY;
	A = 0x7F;
	ram[0] = 0xF5;
	ram[1] = 0x01;
	ram[2] = 0xFF;
	instructions = 1; run();
	if(!(A == 0x80 && SR&SR_NEG && !(SR&SR_ZERO) && !(SR&SR_CARRY) && SR&SR_OVER)) return -2;

	//no borrow
	SR &= (~SR_CARRY);
	A = 0xC0;
	ram[0] = 0xF5;
	ram[1] = 0x01;
	ram[2] = 0x40;
	instructions = 1; run();
	//overflow differs from 2nd sim ...
	if(!(A == 0x7F && !(SR&SR_NEG) && !(SR&SR_ZERO) && SR&SR_CARRY && SR&SR_OVER)) return -3;

	return 0;
}

int testSbcAbsolute() {
	//no overflow
	SR |= SR_CARRY;
	A = 0x00;
	ram[0] = 0xED;
	ram[1] = 0x03;
	ram[2] = 0x00;
	ram[3] = 0x01;
	instructions = 1; run();
	if(!(A == 0xFF && SR&SR_NEG && !(SR&SR_ZERO) && !(SR&SR_CARRY) && !(SR&SR_OVER))) return -1;

	//overflow
	SR |= SR_CARRY;
	A = 0x7F;
	ram[0] = 0xED;
	ram[1] = 0x03;
	ram[2] = 0x00;
	ram[3] = 0xFF;
	instructions = 1; run();
	if(!(A == 0x80 && SR&SR_NEG && !(SR&SR_ZERO) && !(SR&SR_CARRY) && SR&SR_OVER)) return -2;

	//no borrow
	SR &= (~SR_CARRY);
	A = 0xC0;
	ram[0] = 0xED;
	ram[1] = 0x03;
	ram[2] = 0x00;
	ram[3] = 0x40;
	instructions = 1; run();
	//overflow differs from 2nd sim ...
	if(!(A == 0x7F && !(SR&SR_NEG) && !(SR&SR_ZERO) && SR&SR_CARRY && SR&SR_OVER)) return -3;

	return 0;
}

int testSbcAbsoluteX() {
	X = 0x01; Y = 0x00;

	//no overflow
	SR |= SR_CARRY;
	A = 0x00;
	ram[0] = 0xFD;
	ram[1] = 0x02;
	ram[2] = 0x00;
	ram[3] = 0x01;
	instructions = 1; run();
	if(!(A == 0xFF && SR&SR_NEG && !(SR&SR_ZERO) && !(SR&SR_CARRY) && !(SR&SR_OVER))) return -1;

	//overflow
	SR |= SR_CARRY;
	A = 0x7F;
	ram[0] = 0xFD;
	ram[1] = 0x02;
	ram[2] = 0x00;
	ram[3] = 0xFF;
	instructions = 1; run();
	if(!(A == 0x80 && SR&SR_NEG && !(SR&SR_ZERO) && !(SR&SR_CARRY) && SR&SR_OVER)) return -2;

	//no borrow
	SR &= (~SR_CARRY);
	A = 0xC0;
	ram[0] = 0xFD;
	ram[1] = 0x02;
	ram[2] = 0x00;
	ram[3] = 0x40;
	instructions = 1; run();
	//overflow differs from 2nd sim ...
	if(!(A == 0x7F && !(SR&SR_NEG) && !(SR&SR_ZERO) && SR&SR_CARRY && SR&SR_OVER)) return -3;

	return 0;
}

int testSbcAbsoluteY() {
	Y = 0x01; X = 0x00;

	//no overflow
	SR |= SR_CARRY;
	A = 0x00;
	ram[0] = 0xF9;
	ram[1] = 0x02;
	ram[2] = 0x00;
	ram[3] = 0x01;
	instructions = 1; run();
	if(!(A == 0xFF && SR&SR_NEG && !(SR&SR_ZERO) && !(SR&SR_CARRY) && !(SR&SR_OVER))) return -1;

	//overflow
	SR |= SR_CARRY;
	A = 0x7F;
	ram[0] = 0xF9;
	ram[1] = 0x02;
	ram[2] = 0x00;
	ram[3] = 0xFF;
	instructions = 1; run();
	if(!(A == 0x80 && SR&SR_NEG && !(SR&SR_ZERO) && !(SR&SR_CARRY) && SR&SR_OVER)) return -2;

	//no borrow
	SR &= (~SR_CARRY);
	A = 0xC0;
	ram[0] = 0xF9;
	ram[1] = 0x02;
	ram[2] = 0x00;
	ram[3] = 0x40;
	instructions = 1; run();
	//overflow differs from 2nd sim ...
	if(!(A == 0x7F && !(SR&SR_NEG) && !(SR&SR_ZERO) && SR&SR_CARRY && SR&SR_OVER)) return -3;

	return 0;
}

int testSbcIndirectX() {
	X = 0x01; Y = 0x00;

	//no overflow
	SR |= SR_CARRY;
	A = 0x00;
	ram[0] = 0xE1;
	ram[1] = 0x02;
	ram[2] = 0x02;
	ram[3] = 0x01;
	instructions = 1; run();
	if(!(A == 0xFF && SR&SR_NEG && !(SR&SR_ZERO) && !(SR&SR_CARRY) && !(SR&SR_OVER))) return -1;

	//overflow
	SR |= SR_CARRY;
	A = 0x7F;
	ram[0] = 0xE1;
	ram[1] = 0x02;
	ram[2] = 0x02;
	ram[3] = 0xFF;
	instructions = 1; run();
	if(!(A == 0x80 && SR&SR_NEG && !(SR&SR_ZERO) && !(SR&SR_CARRY) && SR&SR_OVER)) return -2;

	//no borrow
	SR &= (~SR_CARRY);
	A = 0xC0;
	ram[0] = 0xE1;
	ram[1] = 0x02;
	ram[2] = 0x02;
	ram[3] = 0x40;
	instructions = 1; run();
	//overflow differs from 2nd sim ...
	if(!(A == 0x7F && !(SR&SR_NEG) && !(SR&SR_ZERO) && SR&SR_CARRY && SR&SR_OVER)) return -3;
	
	return 0;
}

int testSbcIndirectY() {
	Y = 0x01; X = 0x00;

	//no overflow
	SR |= SR_CARRY;
	A = 0x00;
	ram[0] = 0xF1;
	ram[1] = 0x02;
	ram[2] = 0x03;
	ram[3] = 0x00;
	ram[4] = 0x01;
	instructions = 1; run();
	if(!(A == 0xFF && SR&SR_NEG && !(SR&SR_ZERO) && !(SR&SR_CARRY) && !(SR&SR_OVER))) return -1;

	//overflow
	SR |= SR_CARRY;
	A = 0x7F;
	ram[0] = 0xF1;
	ram[1] = 0x02;
	ram[2] = 0x03;
	ram[3] = 0x00;
	ram[4] = 0xFF;
	instructions = 1; run();
	if(!(A == 0x80 && SR&SR_NEG && !(SR&SR_ZERO) && !(SR&SR_CARRY) && SR&SR_OVER)) return -2;

	//no borrow
	SR &= (~SR_CARRY);
	A = 0xC0;
	ram[0] = 0xF1;
	ram[1] = 0x02;
	ram[2] = 0x03;
	ram[3] = 0x00;
	ram[4] = 0x40;
	instructions = 1; run();
	//overflow differs from 2nd sim ...
	if(!(A == 0x7F && !(SR&SR_NEG) && !(SR&SR_ZERO) && SR&SR_CARRY && SR&SR_OVER)) return -3;


	return 0;
}