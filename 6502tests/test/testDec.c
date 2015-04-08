int testDecZeropage() {
	ram[0] = 0xC6;
	ram[1] = 0x02;
	ram[2] = 0x01;
	instructions = 1; run();
	if(!(ram[2] == 0x00 && !(SR&SR_NEG) && SR&SR_ZERO)) return -1;

	//wrap
	ram[0] = 0xC6;
	ram[1] = 0x02;
	ram[2] = 0x00;
	instructions = 1; run();
	if(!(ram[2] == 0xFF && SR&SR_NEG && !(SR&SR_ZERO))) return -2;

	return 0;
}

int testDecZeropageX() {
	X = 0x01; Y = 0x00;

	ram[0] = 0xD6;
	ram[1] = 0x01;
	ram[2] = 0x01;
	instructions = 1; run();
	if(!(ram[2] == 0x00 && !(SR&SR_NEG) && SR&SR_ZERO)) return -1;

	//wrap
	ram[0] = 0xD6;
	ram[1] = 0x01;
	ram[2] = 0x00;
	instructions = 1; run();
	if(!(ram[2] == 0xFF && SR&SR_NEG && !(SR&SR_ZERO))) return -2;

	return 0;
}

int testDecAbsolute() {
	ram[0] = 0xCE;
	ram[1] = 0x03;
	ram[2] = 0x00;
	ram[3] = 0x01;
	instructions = 1; run();
	if(!(ram[3] == 0x00 && !(SR&SR_NEG) && SR&SR_ZERO)) return -1;

	//wrap
	ram[0] = 0xCE;
	ram[1] = 0x03;
	ram[2] = 0x00;
	ram[3] = 0x00;
	instructions = 1; run();
	if(!(ram[3] == 0xFF && SR&SR_NEG && !(SR&SR_ZERO))) return -2;

	return 0;
}

int testDecAbsoluteX() {
	X = 0x01; Y = 0x00;

	ram[0] = 0xDE;
	ram[1] = 0x02;
	ram[2] = 0x00;
	ram[3] = 0x01;
	instructions = 1; run();
	if(!(ram[3] == 0x00 && !(SR&SR_NEG) && SR&SR_ZERO)) return -1;

	//wrap
	ram[0] = 0xDE;
	ram[1] = 0x02;
	ram[2] = 0x00;
	ram[3] = 0x00;
	instructions = 1; run();
	if(!(ram[3] == 0xFF && SR&SR_NEG && !(SR&SR_ZERO))) return -2;

	return 0;
}

int testDexImplied() {
	X = 0x01;
	ram[0] = 0xCA;
	instructions = 1; run();
	if(!(X == 0x00 && !(SR&SR_NEG) && SR&SR_ZERO)) return -1;

	//wrap
	X = 0x00;
	ram[0] = 0xCA;
	instructions = 1; run();
	if(!(X == 0xFF && SR&SR_NEG && !(SR&SR_ZERO))) return -2;

	return 0;
}

int testDeyImplied() {
	Y = 0x01;
	ram[0] = 0x88;
	instructions = 1; run();
	if(!(Y == 0x00 && !(SR&SR_NEG) && SR&SR_ZERO)) return -1;

	//wrap
	X = 0x00;
	ram[0] = 0x88;
	instructions = 1; run();
	if(!(Y == 0xFF && SR&SR_NEG && !(SR&SR_ZERO))) return -2;

	return 0;
}