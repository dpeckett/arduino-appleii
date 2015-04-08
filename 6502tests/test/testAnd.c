int testAndImmediate() {
	A = 0xFF;

	//all high
	ram[0] = 0x29;
	ram[1] = 0xFF;
	instructions = 1; run();
	if(!(A == 0xFF && SR&SR_NEG && !(SR&SR_ZERO) && !(SR&SR_CARRY) && !(SR&SR_OVER))) return -1;

	//all low
	ram[0] = 0x29;
	ram[1] = 0x00;
	instructions = 1; run();
	if(!(A == 0x00 && !(SR&SR_NEG) && SR&SR_ZERO && !(SR&SR_CARRY) && !(SR&SR_OVER))) return -2;

	return 0;	
}

int testAndZeropage() {
	A = 0xFF;

	//all high
	ram[0] = 0x25;
	ram[1] = 0x02;
	ram[2] = 0xFF;
	instructions = 1; run();
	if(!(A == 0xFF && SR&SR_NEG && !(SR&SR_ZERO) && !(SR&SR_CARRY) && !(SR&SR_OVER))) return -1;

	//all low
	ram[0] = 0x25;
	ram[1] = 0x02;
	ram[2] = 0x00;
	instructions = 1; run();
	if(!(A == 0x00 && !(SR&SR_NEG) && SR&SR_ZERO && !(SR&SR_CARRY) && !(SR&SR_OVER))) return -2;

	return 0;	
}

int testAndZeropageX() {
	X = 0x01; Y = 0x00;
	A = 0xFF;

	//all high
	ram[0] = 0x35;
	ram[1] = 0x01;
	ram[2] = 0xFF;
	instructions = 1; run();
	if(!(A == 0xFF && SR&SR_NEG && !(SR&SR_ZERO) && !(SR&SR_CARRY) && !(SR&SR_OVER))) return -1;

	//all low
	ram[0] = 0x35;
	ram[1] = 0x01;
	ram[2] = 0x00;
	instructions = 1; run();
	if(!(A == 0x00 && !(SR&SR_NEG) && SR&SR_ZERO && !(SR&SR_CARRY) && !(SR&SR_OVER))) return -2;

	return 0;	
}

int testAndAbsolute() {
	A = 0xFF;

	//all high
	ram[0] = 0x2D;
	ram[1] = 0x03;
	ram[2] = 0x00;
	ram[3] = 0xFF;
	instructions = 1; run();
	if(!(A == 0xFF && SR&SR_NEG && !(SR&SR_ZERO) && !(SR&SR_CARRY) && !(SR&SR_OVER))) return -1;

	//all low
	ram[0] = 0x2D;
	ram[1] = 0x03;
	ram[2] = 0x00;
	ram[3] = 0x00;
	instructions = 1; run();
	if(!(A == 0x00 && !(SR&SR_NEG) && SR&SR_ZERO && !(SR&SR_CARRY) && !(SR&SR_OVER))) return -2;

	return 0;	
}

int testAndAbsoluteX() {
	A = 0xFF;
	X = 0x01; Y = 0x00;

	//all high
	ram[0] = 0x3D;
	ram[1] = 0x02;
	ram[2] = 0x00;
	ram[3] = 0xFF;
	instructions = 1; run();
	if(!(A == 0xFF && SR&SR_NEG && !(SR&SR_ZERO) && !(SR&SR_CARRY) && !(SR&SR_OVER))) return -1;

	//all low
	ram[0] = 0x3D;
	ram[1] = 0x02;
	ram[2] = 0x00;
	ram[3] = 0x00;
	instructions = 1; run();
	if(!(A == 0x00 && !(SR&SR_NEG) && SR&SR_ZERO && !(SR&SR_CARRY) && !(SR&SR_OVER))) return -2;

	return 0;	
}

int testAndAbsoluteY() {
	A = 0xFF;
	Y = 0x01; X = 0x00;

	//all high
	ram[0] = 0x39;
	ram[1] = 0x02;
	ram[2] = 0x00;
	ram[3] = 0xFF;
	instructions = 1; run();
	if(!(A == 0xFF && SR&SR_NEG && !(SR&SR_ZERO) && !(SR&SR_CARRY) && !(SR&SR_OVER))) return -1;

	//all low
	ram[0] = 0x39;
	ram[1] = 0x02;
	ram[2] = 0x00;
	ram[3] = 0x00;
	instructions = 1; run();
	if(!(A == 0x00 && !(SR&SR_NEG) && SR&SR_ZERO && !(SR&SR_CARRY) && !(SR&SR_OVER))) return -2;

	return 0;	
}

int testAndIndirectX() {
	A = 0xFF;
	X = 0x01; Y = 0x00;

	//all high
	ram[0] = 0x21;
	ram[1] = 0x02;
	ram[2] = 0x02;
	ram[3] = 0xFF;
	instructions = 1; run();
	if(!(A == 0xFF && SR&SR_NEG && !(SR&SR_ZERO) && !(SR&SR_CARRY) && !(SR&SR_OVER))) return -1;

	//all low
	ram[0] = 0x21;
	ram[1] = 0x02;
	ram[2] = 0x02;
	ram[3] = 0x00;
	instructions = 1; run();
	if(!(A == 0x00 && !(SR&SR_NEG) && SR&SR_ZERO && !(SR&SR_CARRY) && !(SR&SR_OVER))) return -2;

	return 0;	
}

int testAndIndirectY() {
	A = 0xFF;
	Y = 0x01; X = 0x00;

	//all high
	ram[0] = 0x31;
	ram[1] = 0x02;
	ram[2] = 0x03;
	ram[3] = 0x00;
	ram[4] = 0xFF;
	instructions = 1; run();
	if(!(A == 0xFF && SR&SR_NEG && !(SR&SR_ZERO) && !(SR&SR_CARRY) && !(SR&SR_OVER))) return -1;

	//all low
	ram[0] = 0x31;
	ram[1] = 0x02;
	ram[2] = 0x03;
	ram[3] = 0x00;
	ram[4] = 0x00;
	instructions = 1; run();
	if(!(A == 0x00 && !(SR&SR_NEG) && SR&SR_ZERO && !(SR&SR_CARRY) && !(SR&SR_OVER))) return -2;

	return 0;	
}