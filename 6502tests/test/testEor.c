int testEorImmediate() {
	A = 0xCE;
	ram[0] = 0x49;
	ram[1] = 0x20;
	instructions = 1; run();
	if(!(A == (0xCE^0x20) && !(SR&SR_ZERO) && SR&SR_NEG)) return -1;
	return 0;
}

int testEorZeropage() {
	A = 0xCE;
	ram[0] = 0x45;
	ram[1] = 0x02;
	ram[2] = 0x20;
	instructions = 1; run();
	if(!(A == (0xCE^0x20) && !(SR&SR_ZERO) && SR&SR_NEG)) return -1;
	return 0;	
}

int testEorZeropageX() {
	X = 0x01; Y = 0x00;
	A = 0xCE;
	ram[0] = 0x55;
	ram[1] = 0x01;
	ram[2] = 0x20;
	instructions = 1; run();
	if(!(A == (0xCE^0x20) && !(SR&SR_ZERO) && SR&SR_NEG)) return -1;
	return 0;
}

int testEorAbsolute() {
	A = 0xCE;
	ram[0] = 0x4D;
	ram[1] = 0x03;
	ram[2] = 0x00;
	ram[3] = 0x20;
	instructions = 1; run();
	if(!(A == (0xCE^0x20) && !(SR&SR_ZERO) && SR&SR_NEG)) return -1;
	return 0;
}

int testEorAbsoluteX() {
	X = 0x01; Y = 0x00;
	A = 0xCE;
	ram[0] = 0x5D;
	ram[1] = 0x02;
	ram[2] = 0x00;
	ram[3] = 0x20;
	instructions = 1; run();
	if(!(A == (0xCE^0x20) && !(SR&SR_ZERO) && SR&SR_NEG)) return -1;
	return 0;	
}

int testEorAbsoluteY() {
	Y = 0x01; X = 0x00;
	A = 0xCE;
	ram[0] = 0x59;
	ram[1] = 0x02;
	ram[2] = 0x00;
	ram[3] = 0x20;
	instructions = 1; run();
	if(!(A == (0xCE^0x20) && !(SR&SR_ZERO) && SR&SR_NEG)) return -1;
	return 0;
}

int testEorIndirectX() {
	X = 0x01; Y = 0x00;
	A = 0xCE;
	ram[0] = 0x41;
	ram[1] = 0x02;
	ram[2] = 0x02;
	ram[3] = 0x20;
	instructions = 1; run();
	if(!(A == (0xCE^0x20) && !(SR&SR_ZERO) && SR&SR_NEG)) return -1;
	return 0;
}

int testEorIndirectY() {
	Y = 0x01; X = 0x00;
	A = 0xCE;
	ram[0] = 0x51;
	ram[1] = 0x02;
	ram[2] = 0x03;
	ram[3] = 0x00;
	ram[4] = 0x20;
	instructions = 1; run();
	if(!(A == (0xCE^0x20) && !(SR&SR_ZERO) && SR&SR_NEG)) return -1;
	return 0;
}