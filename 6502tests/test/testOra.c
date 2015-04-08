int testOraImmediate() {	
	//all set
	A = 0xFF;
	ram[0] = 0x09;
	ram[1] = 0x0F;
	instructions = 1; run();
	if(!(A == 0xFF && SR&SR_NEG && !(SR&SR_ZERO))) return -1;

	//zero
	A = 0x00;
	ram[0] = 0x09;
	ram[1] = 0x00;
	instructions = 1; run();
	if(!(A == 0x00 && !(SR&SR_NEG) && SR&SR_ZERO)) return -2;

	return 0;
}

int testOraZeropage() {
	//all set
	A = 0xFF;
	ram[0] = 0x05;
	ram[1] = 0x02;
	ram[2] = 0x0F;
	instructions = 1; run();
	if(!(A == 0xFF && SR&SR_NEG && !(SR&SR_ZERO))) return -1;

	//zero
	A = 0x00;
	ram[0] = 0x05;
	ram[1] = 0x02;
	ram[2] = 0x00;
	instructions = 1; run();
	if(!(A == 0x00 && !(SR&SR_NEG) && SR&SR_ZERO)) return -2;

	return 0;
}

int testOraZeropageX() {
	X = 0x01; Y = 0x00;

	//all set
	A = 0xFF;
	ram[0] = 0x15;
	ram[1] = 0x01;
	ram[2] = 0x0F;
	instructions = 1; run();
	if(!(A == 0xFF && SR&SR_NEG && !(SR&SR_ZERO))) return -1;

	//zero
	A = 0x00;
	ram[0] = 0x15;
	ram[1] = 0x01;
	ram[2] = 0x00;
	instructions = 1; run();
	if(!(A == 0x00 && !(SR&SR_NEG) && SR&SR_ZERO)) return -2;
	
	return 0;
}

int testOraAbsolute() {
	//all set
	A = 0xFF;
	ram[0] = 0x0D;
	ram[1] = 0x03;
	ram[2] = 0x00;
	ram[3] = 0x0F;
	instructions = 1; run();
	if(!(A == 0xFF && SR&SR_NEG && !(SR&SR_ZERO))) return -1;

	//zero
	A = 0x00;
	ram[0] = 0x0D;
	ram[1] = 0x03;
	ram[2] = 0x00;
	ram[3] = 0x00;
	instructions = 1; run();
	if(!(A == 0x00 && !(SR&SR_NEG) && SR&SR_ZERO)) return -2;

	return 0;
}

int testOraAbsoluteX() {
	X = 0x01; Y = 0x00;

	//all set
	A = 0xFF;
	ram[0] = 0x1D;
	ram[1] = 0x02;
	ram[2] = 0x00;
	ram[3] = 0x0F;
	instructions = 1; run();
	if(!(A == 0xFF && SR&SR_NEG && !(SR&SR_ZERO))) return -1;

	//zero
	A = 0x00;
	ram[0] = 0x1D;
	ram[1] = 0x02;
	ram[2] = 0x00;
	ram[3] = 0x00;
	instructions = 1; run();
	if(!(A == 0x00 && !(SR&SR_NEG) && SR&SR_ZERO)) return -2;
	
	return 0;
}

int testOraAbsoluteY() {
	X = 0x00; Y = 0x01;

	//all set
	A = 0xFF;
	ram[0] = 0x19;
	ram[1] = 0x02;
	ram[2] = 0x00;
	ram[3] = 0x0F;
	instructions = 1; run();
	if(!(A == 0xFF && SR&SR_NEG && !(SR&SR_ZERO))) return -1;

	//zero
	A = 0x00;
	ram[0] = 0x19;
	ram[1] = 0x02;
	ram[2] = 0x00;
	ram[3] = 0x00;
	instructions = 1; run();
	if(!(A == 0x00 && !(SR&SR_NEG) && SR&SR_ZERO)) return -2;

	return 0;
}

int testOraIndirectX() {
	X = 0x01; Y = 0x00;

	//all set
	A = 0xFF;
	ram[0] = 0x01;
	ram[1] = 0x02;
	ram[2] = 0x02;
	ram[3] = 0x0F;
	instructions = 1; run();
	if(!(A == 0xFF && SR&SR_NEG && !(SR&SR_ZERO))) return -1;

	//zero
	A = 0x00;
	ram[0] = 0x01;
	ram[1] = 0x02;
	ram[2] = 0x02;
	ram[3] = 0x00;
	instructions = 1; run();
	if(!(A == 0x00 && !(SR&SR_NEG) && SR&SR_ZERO)) return -2;
	
	return 0;
}

int testOraIndirectY() {
	Y = 0x01; X = 0x00;

	//all set
	A = 0xFF;
	ram[0] = 0x11;
	ram[1] = 0x02;
	ram[2] = 0x03;
	ram[3] = 0x00;
	ram[4] = 0x0F;
	instructions = 1; run();
	if(!(A == 0xFF && SR&SR_NEG && !(SR&SR_ZERO))) return -1;

	//zero
	A = 0x00;
	ram[0] = 0x11;
	ram[1] = 0x02;
	ram[2] = 0x02;
	ram[3] = 0x00;
	instructions = 1; run();
	if(!(A == 0x00 && !(SR&SR_NEG) && SR&SR_ZERO)) return -2;

	return 0;
}