int testAslImplied() {
	//normal
	A = 0x01;
	ram[0] = 0x0A;
	instructions = 1; run();
	if(!(A == 0x02 && !(SR&SR_NEG) && !(SR&SR_ZERO) && !(SR&SR_CARRY) && !(SR&SR_OVER))) return -1;

	//carry and zero
	A = 0x80;
	ram[0] = 0x0A;
	instructions = 1; run();
	if(!(A == 0x00 && !(SR&SR_NEG) && SR&SR_ZERO && SR&SR_CARRY && !(SR&SR_OVER))) return -2;

	//carry and negative
	A = 0xC0;
	ram[0] = 0x0A;
	instructions = 1; run();
	if(!(A == 0x80 && SR&SR_NEG && !(SR&SR_ZERO) && SR&SR_CARRY && !(SR&SR_OVER))) return -3;

	return 0;
}

int testAslZeropage() {
	//normal
	ram[0] = 0x06;
	ram[1] = 0x02;
	ram[2] = 0x01;
	instructions = 1; run();
	if(!(ram[2] == 0x02 && !(SR&SR_NEG) && !(SR&SR_ZERO) && !(SR&SR_CARRY) && !(SR&SR_OVER))) return -1;

	//carry and zero
	ram[0] = 0x06;
	ram[1] = 0x02;
	ram[2] = 0x80;
	instructions = 1; run();
	if(!(ram[2] == 0x00 && !(SR&SR_NEG) && SR&SR_ZERO && SR&SR_CARRY && !(SR&SR_OVER))) return -2;

	//carry and negative
	ram[0] = 0x06;
	ram[1] = 0x02;
	ram[2] = 0xC0;
	instructions = 1; run();
	if(!(ram[2] == 0x80 && SR&SR_NEG && !(SR&SR_ZERO) && SR&SR_CARRY && !(SR&SR_OVER))) return -3;

	return 0;
}

int testAslZeropageX() {
	X = 0x01; Y = 0x00;

	//normal
	ram[0] = 0x16;
	ram[1] = 0x01;
	ram[2] = 0x01;
	instructions = 1; run();
	if(!(ram[2] == 0x02 && !(SR&SR_NEG) && !(SR&SR_ZERO) && !(SR&SR_CARRY) && !(SR&SR_OVER))) return -1;

	//carry and zero
	ram[0] = 0x16;
	ram[1] = 0x01;
	ram[2] = 0x80;
	instructions = 1; run();
	if(!(ram[2] == 0x00 && !(SR&SR_NEG) && SR&SR_ZERO && SR&SR_CARRY && !(SR&SR_OVER))) return -2;

	//carry and negative
	ram[0] = 0x16;
	ram[1] = 0x01;
	ram[2] = 0xC0;
	instructions = 1; run();
	if(!(ram[2] == 0x80 && SR&SR_NEG && !(SR&SR_ZERO) && SR&SR_CARRY && !(SR&SR_OVER))) return -3;

	return 0;
}

int testAslAbsolute() {
	//normal
	ram[0] = 0x0E;
	ram[1] = 0x03;
	ram[2] = 0x00;
	ram[3] = 0x01;
	instructions = 1; run();
	if(!(ram[3] == 0x02 && !(SR&SR_NEG) && !(SR&SR_ZERO) && !(SR&SR_CARRY) && !(SR&SR_OVER))) return -1;

	//carry and zero
	ram[0] = 0x0E;
	ram[1] = 0x03;
	ram[2] = 0x00;
	ram[3] = 0x80;
	instructions = 1; run();
	if(!(ram[3] == 0x00 && !(SR&SR_NEG) && SR&SR_ZERO && SR&SR_CARRY && !(SR&SR_OVER))) return -2;

	//carry and negative
	ram[0] = 0x0E;
	ram[1] = 0x03;
	ram[2] = 0x00;
	ram[3] = 0xC0;
	instructions = 1; run();
	if(!(ram[3] == 0x80 && SR&SR_NEG && !(SR&SR_ZERO) && SR&SR_CARRY && !(SR&SR_OVER))) return -3;

	return 0;
}

int testAslAbsoluteX() {
	X = 0x01; Y = 0x00;
	
	//normal
	ram[0] = 0x1E;
	ram[1] = 0x02;
	ram[2] = 0x00;
	ram[3] = 0x01;
	instructions = 1; run();
	if(!(ram[3] == 0x02 && !(SR&SR_NEG) && !(SR&SR_ZERO) && !(SR&SR_CARRY) && !(SR&SR_OVER))) return -1;

	//carry and zero
	ram[0] = 0x1E;
	ram[1] = 0x02;
	ram[2] = 0x00;
	ram[3] = 0x80;
	instructions = 1; run();
	if(!(ram[3] == 0x00 && !(SR&SR_NEG) && SR&SR_ZERO && SR&SR_CARRY && !(SR&SR_OVER))) return -2;

	//carry and negative
	ram[0] = 0x1E;
	ram[1] = 0x02;
	ram[2] = 0x00;
	ram[3] = 0xC0;
	instructions = 1; run();
	if(!(ram[3] == 0x80 && SR&SR_NEG && !(SR&SR_ZERO) && SR&SR_CARRY && !(SR&SR_OVER))) return -3;

	return 0;
}