int testIncZeropage() {
	ram[0] = 0xE6;
	ram[1] = 0x02;
	ram[2] = 0xFE;
	instructions = 1; run();
	if(!(ram[2] == 0xFF && SR&SR_NEG && !(SR&SR_ZERO))) return -1;

	//wrap
	ram[0] = 0xE6;
	ram[1] = 0x02;
	ram[2] = 0xFF;
	instructions = 1; run();
	if(!(ram[2] == 0x00 && !(SR&SR_NEG) && SR&SR_ZERO)) return -2;

	return 0;
}

int testIncZeropageX() {
	X = 0x01; Y = 0x00;

	ram[0] = 0xF6;
	ram[1] = 0x01;
	ram[2] = 0xFE;
	instructions = 1; run();
	if(!(ram[2] == 0xFF && SR&SR_NEG && !(SR&SR_ZERO))) return -1;

	//wrap
	ram[0] = 0xF6;
	ram[1] = 0x01;
	ram[2] = 0xFF;
	instructions = 1; run();
	if(!(ram[2] == 0x00 && !(SR&SR_NEG) && SR&SR_ZERO)) return -2;

	return 0;
}

int testIncAbsolute() {
	ram[0] = 0xEE;
	ram[1] = 0x03;
	ram[2] = 0x00;
	ram[3] = 0xFE;
	instructions = 1; run();
	if(!(ram[3] == 0xFF && SR&SR_NEG && !(SR&SR_ZERO))) return -1;

	//wrap
	ram[0] = 0xEE;
	ram[1] = 0x03;
	ram[2] = 0x00;
	ram[3] = 0xFF;
	instructions = 1; run();
	if(!(ram[3] == 0x00 && !(SR&SR_NEG) && SR&SR_ZERO)) return -2;

	return 0;
}

int testIncAbsoluteX() {
	X = 0x01; Y = 0x00;

	ram[0] = 0xFE;
	ram[1] = 0x02;
	ram[2] = 0x00;
	ram[3] = 0xFE;
	instructions = 1; run();
	if(!(ram[3] == 0x02 && SR&SR_NEG && !(SR&SR_ZERO))) return -1;

	//wrap
	ram[0] = 0xFE;
	ram[1] = 0x02;
	ram[2] = 0x00;
	ram[3] = 0xFF;
	instructions = 1; run();
	if(!(ram[3] == 0x00 && !(SR&SR_NEG) && SR&SR_ZERO)) return -2;

	return 0;
}

int testInxImplied() {
	X = 0xFE;
	ram[0] = 0xE8;
	instructions = 1; run();
	if(!(X == 0xFF && SR&SR_NEG && !(SR&SR_ZERO))) return -1;

	//wrap
	X = 0xFF;
	ram[0] = 0xE8;
	instructions = 1; run();
	if(!(X == 0x00 && !(SR&SR_NEG) && SR&SR_ZERO)) return -2;

	return 0;
}

int testInyImplied() {
	Y = 0xFE;
	ram[0] = 0xC8;
	instructions = 1; run();
	if(!(Y == 0xFF && SR&SR_NEG && !(SR&SR_ZERO))) return -1;

	//wrap
	Y = 0xFF;
	ram[0] = 0xC8;
	instructions = 1; run();
	if(!(Y == 0x00 && !(SR&SR_NEG) && SR&SR_ZERO)) return -2;

	return 0;
}