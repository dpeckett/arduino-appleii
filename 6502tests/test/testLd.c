int testLdaImmediate() {
	//zero
	SR &= ~(SR_NEG|SR_ZERO);
	ram[0] = 0xA9;
	ram[1] = 0x00;
	instructions = 1; run();
	if(!(A == 0x00 && SR&SR_ZERO && !(SR&SR_NEG))) return -1;

	//normal
	SR &= ~(SR_NEG|SR_ZERO);
	ram[0] = 0xA9;
	ram[1] = 0x20;
	instructions = 1; run();
	if(!(A == 0x20 && !(SR&SR_ZERO) && !(SR&SR_NEG))) return -2;

	//negative
	SR &= ~(SR_NEG|SR_ZERO);
	ram[0] = 0xA9;
	ram[1] = 0x80;
	instructions = 1; run();
	if(!(A == 0x80 && !(SR&SR_ZERO) && SR&SR_NEG)) return -3;

	return 0;	
}

int testLdaZeropage() {
	//zero
	SR &= ~(SR_NEG|SR_ZERO);
	ram[0] = 0xA5;
	ram[1] = 0x02;
	ram[2] = 0x00;
	instructions = 1; run();
	if(!(A == 0x00 && SR&SR_ZERO && !(SR&SR_NEG))) return -1;

	//normal
	SR &= ~(SR_NEG|SR_ZERO);
	ram[0] = 0xA5;
	ram[1] = 0x02;
	ram[2] = 0x20;
	instructions = 1; run();
	if(!(A == 0x20 && !(SR&SR_ZERO) && !(SR&SR_NEG))) return -2;

	//negative
	SR &= ~(SR_NEG|SR_ZERO);
	ram[0] = 0xA5;
	ram[1] = 0x02;
	ram[2] = 0x80;
	instructions = 1; run();
	if(!(A == 0x80 && !(SR&SR_ZERO) && SR&SR_NEG)) return -3;

	return 0;	
}

int testLdaZeropageX() {
	X = 0x01; Y = 0x00;

	//zero
	SR &= ~(SR_NEG|SR_ZERO);
	ram[0] = 0xB5;
	ram[1] = 0x01;
	ram[2] = 0x00;
	instructions = 1; run();
	if(!(A == 0x00 && SR&SR_ZERO && !(SR&SR_NEG))) return -1;

	//normal
	SR &= ~(SR_NEG|SR_ZERO);
	ram[0] = 0xB5;
	ram[1] = 0x01;
	ram[2] = 0x20;
	instructions = 1; run();
	if(!(A == 0x20 && !(SR&SR_ZERO) && !(SR&SR_NEG))) return -2;

	//negative
	SR &= ~(SR_NEG|SR_ZERO);
	ram[0] = 0xB5;
	ram[1] = 0x01;
	ram[2] = 0x80;
	instructions = 1; run();
	if(!(A == 0x80 && !(SR&SR_ZERO) && SR&SR_NEG)) return -3;

	return 0;	
}

int testLdaAbsolute() {
	//zero
	SR &= ~(SR_NEG|SR_ZERO);
	ram[0] = 0xAD;
	ram[1] = 0x03;
	ram[2] = 0x00;
	ram[3] = 0x00;
	instructions = 1; run();
	if(!(A == 0x00 && SR&SR_ZERO && !(SR&SR_NEG))) return -1;

	//normal
	SR &= ~(SR_NEG|SR_ZERO);
	ram[0] = 0xAD;
	ram[1] = 0x03;
	ram[2] = 0x00;
	ram[3] = 0x20;
	instructions = 1; run();
	if(!(A == 0x20 && !(SR&SR_ZERO) && !(SR&SR_NEG))) return -2;

	//negative
	SR &= ~(SR_NEG|SR_ZERO);
	ram[0] = 0xAD;
	ram[1] = 0x03;
	ram[2] = 0x00;
	ram[3] = 0x80;
	instructions = 1; run();
	if(!(A == 0x80 && !(SR&SR_ZERO) && SR&SR_NEG)) return -3;

	return 0;	
}

int testLdaAbsoluteX() {
	X = 0x01; Y = 0x00;

	//zero
	SR &= ~(SR_NEG|SR_ZERO);
	ram[0] = 0xBD;
	ram[1] = 0x02;
	ram[2] = 0x00;
	ram[3] = 0x00;
	instructions = 1; run();
	if(!(A == 0x00 && SR&SR_ZERO && !(SR&SR_NEG))) return -1;

	//normal
	SR &= ~(SR_NEG|SR_ZERO);
	ram[0] = 0xBD;
	ram[1] = 0x02;
	ram[2] = 0x00;
	ram[3] = 0x20;
	instructions = 1; run();
	if(!(A == 0x20 && !(SR&SR_ZERO) && !(SR&SR_NEG))) return -2;

	//negative
	SR &= ~(SR_NEG|SR_ZERO);
	ram[0] = 0xBD;
	ram[1] = 0x02;
	ram[2] = 0x00;
	ram[3] = 0x80;
	instructions = 1; run();
	if(!(A == 0x80 && !(SR&SR_ZERO) && SR&SR_NEG)) return -3;


	return 0;	
}

int testLdaAbsoluteY() {
	Y = 0x01; X = 0x00;

	//zero
	SR &= ~(SR_NEG|SR_ZERO);
	ram[0] = 0xB9;
	ram[1] = 0x02;
	ram[2] = 0x00;
	ram[3] = 0x00;
	instructions = 1; run();
	if(!(A == 0x00 && SR&SR_ZERO && !(SR&SR_NEG))) return -1;

	//normal
	SR &= ~(SR_NEG|SR_ZERO);
	ram[0] = 0xB9;
	ram[1] = 0x02;
	ram[2] = 0x00;
	ram[3] = 0x20;
	instructions = 1; run();
	if(!(A == 0x20 && !(SR&SR_ZERO) && !(SR&SR_NEG))) return -2;

	//negative
	SR &= ~(SR_NEG|SR_ZERO);
	ram[0] = 0xB9;
	ram[1] = 0x02;
	ram[2] = 0x00;
	ram[3] = 0x80;
	instructions = 1; run();
	if(!(A == 0x80 && !(SR&SR_ZERO) && SR&SR_NEG)) return -3;

	return 0;	
}

int testLdaIndirectX() {
	X = 0x01; Y = 0x00;

	//zero
	SR &= ~(SR_NEG|SR_ZERO);
	ram[0] = 0xA1;
	ram[1] = 0x02;
	ram[2] = 0x02;
	ram[3] = 0x00;
	instructions = 1; run();
	if(!(A == 0x00 && SR&SR_ZERO && !(SR&SR_NEG))) return -1;

	//normal
	SR &= ~(SR_NEG|SR_ZERO);
	ram[0] = 0xA1;
	ram[1] = 0x02;
	ram[2] = 0x02;
	ram[3] = 0x20;
	instructions = 1; run();
	if(!(A == 0x20 && !(SR&SR_ZERO) && !(SR&SR_NEG))) return -2;

	//negative
	SR &= ~(SR_NEG|SR_ZERO);
	ram[0] = 0xA1;
	ram[1] = 0x02;
	ram[2] = 0x02;
	ram[3] = 0x80;
	instructions = 1; run();
	if(!(A == 0x80 && !(SR&SR_ZERO) && SR&SR_NEG)) return -3;

	return 0;	
}

int testLdaIndirectY() {
	Y = 0x01; X = 0x00;

	//zero
	SR &= ~(SR_NEG|SR_ZERO);
	ram[0] = 0xB1;
	ram[1] = 0x02;
	ram[2] = 0x03;
	ram[3] = 0x00;
	ram[4] = 0x00;
	instructions = 1; run();
	if(!(A == 0x00 && SR&SR_ZERO && !(SR&SR_NEG))) return -1;

	//normal
	SR &= ~(SR_NEG|SR_ZERO);
	ram[0] = 0xB1;
	ram[1] = 0x02;
	ram[2] = 0x03;
	ram[3] = 0x00;
	ram[4] = 0x20;
	instructions = 1; run();
	if(!(A == 0x20 && !(SR&SR_ZERO) && !(SR&SR_NEG))) return -2;

	//negative
	SR &= ~(SR_NEG|SR_ZERO);
	ram[0] = 0xB1;
	ram[1] = 0x02;
	ram[2] = 0x03;
	ram[3] = 0x00;
	ram[4] = 0x80;
	instructions = 1; run();
	if(!(A == 0x80 && !(SR&SR_ZERO) && SR&SR_NEG)) return -3;

	return 0;	
}

int testLdxImmediate() {
	//zero
	SR &= ~(SR_NEG|SR_ZERO);
	ram[0] = 0xA2;
	ram[1] = 0x00;
	instructions = 1; run();
	if(!(X == 0x00 && SR&SR_ZERO && !(SR&SR_NEG))) return -1;

	//normal
	SR &= ~(SR_NEG|SR_ZERO);
	ram[0] = 0xA2;
	ram[1] = 0x20;
	instructions = 1; run();
	if(!(X == 0x20 && !(SR&SR_ZERO) && !(SR&SR_NEG))) return -2;

	//negative
	SR &= ~(SR_NEG|SR_ZERO);
	ram[0] = 0xA2;
	ram[1] = 0x80;
	instructions = 1; run();
	if(!(X == 0x80 && !(SR&SR_ZERO) && SR&SR_NEG)) return -3;

	return 0;
}

int testLdxZeropage() {
	//zero
	SR &= ~(SR_NEG|SR_ZERO);
	ram[0] = 0xA6;
	ram[1] = 0x02;
	ram[2] = 0x00;
	instructions = 1; run();
	if(!(X == 0x00 && SR&SR_ZERO && !(SR&SR_NEG))) return -1;

	//normal
	SR &= ~(SR_NEG|SR_ZERO);
	ram[0] = 0xA6;
	ram[1] = 0x02;
	ram[2] = 0x20;
	instructions = 1; run();
	if(!(X == 0x20 && !(SR&SR_ZERO) && !(SR&SR_NEG))) return -2;

	//negative
	SR &= ~(SR_NEG|SR_ZERO);
	ram[0] = 0xA6;
	ram[1] = 0x02;
	ram[2] = 0x80;
	instructions = 1; run();
	if(!(X == 0x80 && !(SR&SR_ZERO) && SR&SR_NEG)) return -3;

	return 0;
}

int testLdxZeropageY() {
	Y = 0x01; X = 0x00;

	//zero
	SR &= ~(SR_NEG|SR_ZERO);
	ram[0] = 0xB6;
	ram[1] = 0x01;
	ram[2] = 0x00;
	instructions = 1; run();
	if(!(X == 0x00 && SR&SR_ZERO && !(SR&SR_NEG))) return -1;

	//normal
	Y = 0x01;
	SR &= ~(SR_NEG|SR_ZERO);
	ram[0] = 0xB6;
	ram[1] = 0x01;
	ram[2] = 0x20;
	instructions = 1; run();
	if(!(X == 0x20 && !(SR&SR_ZERO) && !(SR&SR_NEG))) return -2;

	//negative
	SR &= ~(SR_NEG|SR_ZERO);
	ram[0] = 0xB6;
	ram[1] = 0x01;
	ram[2] = 0x80;
	instructions = 1; run();
	if(!(X == 0x80 && !(SR&SR_ZERO) && SR&SR_NEG)) return -3;

	return 0;
}

int testLdxAbsolute() {
	//zero
	SR &= ~(SR_NEG|SR_ZERO);
	ram[0] = 0xAE;
	ram[1] = 0x03;
	ram[2] = 0x00;
	ram[3] = 0x00;
	instructions = 1; run();
	if(!(X == 0x00 && SR&SR_ZERO && !(SR&SR_NEG))) return -1;

	//normal
	SR &= ~(SR_NEG|SR_ZERO);
	ram[0] = 0xAE;
	ram[1] = 0x03;
	ram[2] = 0x00;
	ram[3] = 0x20;
	instructions = 1; run();
	if(!(X == 0x20 && !(SR&SR_ZERO) && !(SR&SR_NEG))) return -2;

	//negative
	SR &= ~(SR_NEG|SR_ZERO);
	ram[0] = 0xAE;
	ram[1] = 0x03;
	ram[2] = 0x00;
	ram[3] = 0x80;
	instructions = 1; run();
	if(!(X == 0x80 && !(SR&SR_ZERO) && SR&SR_NEG)) return -3;

	return 0;	
}

int testLdxAbsoluteY() {
	Y = 0x01; X = 0x00;

	//zero
	SR &= ~(SR_NEG|SR_ZERO);
	ram[0] = 0xBE;
	ram[1] = 0x02;
	ram[2] = 0x00;
	ram[3] = 0x00;
	instructions = 1; run();
	if(!(X == 0x00 && SR&SR_ZERO && !(SR&SR_NEG))) return -1;

	//normal
	SR &= ~(SR_NEG|SR_ZERO);
	ram[0] = 0xBE;
	ram[1] = 0x02;
	ram[2] = 0x00;
	ram[3] = 0x20;
	instructions = 1; run();
	if(!(X == 0x20 && !(SR&SR_ZERO) && !(SR&SR_NEG))) return -2;

	//negative
	SR &= ~(SR_NEG|SR_ZERO);
	ram[0] = 0xBE;
	ram[1] = 0x02;
	ram[2] = 0x00;
	ram[3] = 0x80;
	instructions = 1; run();
	if(!(X == 0x80 && !(SR&SR_ZERO) && SR&SR_NEG)) return -3;

	return 0;	
}

int testLdyImmediate() {
	//zero
	SR &= ~(SR_NEG|SR_ZERO);
	ram[0] = 0xA0;
	ram[1] = 0x00;
	instructions = 1; run();
	if(!(Y == 0x00 && SR&SR_ZERO && !(SR&SR_NEG))) return -1;

	//normal
	SR &= ~(SR_NEG|SR_ZERO);
	ram[0] = 0xA0;
	ram[1] = 0x20;
	instructions = 1; run();
	if(!(Y == 0x20 && !(SR&SR_ZERO) && !(SR&SR_NEG))) return -2;

	//negative
	SR &= ~(SR_NEG|SR_ZERO);
	ram[0] = 0xA0;
	ram[1] = 0x80;
	instructions = 1; run();
	if(!(Y == 0x80 && !(SR&SR_ZERO) && SR&SR_NEG)) return -3;

	return 0;
}

int testLdyZeropage() {
	//zero
	SR &= ~(SR_NEG|SR_ZERO);
	ram[0] = 0xA4;
	ram[1] = 0x02;
	ram[2] = 0x00;
	instructions = 1; run();
	if(!(Y == 0x00 && SR&SR_ZERO && !(SR&SR_NEG))) return -1;

	//normal
	SR &= ~(SR_NEG|SR_ZERO);
	ram[0] = 0xA4;
	ram[1] = 0x02;
	ram[2] = 0x20;
	instructions = 1; run();
	if(!(Y == 0x20 && !(SR&SR_ZERO) && !(SR&SR_NEG))) return -2;

	//negative
	SR &= ~(SR_NEG|SR_ZERO);
	ram[0] = 0xA4;
	ram[1] = 0x02;
	ram[2] = 0x80;
	instructions = 1; run();
	if(!(Y == 0x80 && !(SR&SR_ZERO) && SR&SR_NEG)) return -3;

	return 0;
}

int testLdyZeropageX() {
	X = 0x01; Y = 0x00;

	//zero
	SR &= ~(SR_NEG|SR_ZERO);
	ram[0] = 0xB4;
	ram[1] = 0x01;
	ram[2] = 0x00;
	instructions = 1; run();
	if(!(Y == 0x00 && SR&SR_ZERO && !(SR&SR_NEG))) return -1;

	//normal
	SR &= ~(SR_NEG|SR_ZERO);
	ram[0] = 0xB4;
	ram[1] = 0x01;
	ram[2] = 0x20;
	instructions = 1; run();
	if(!(Y == 0x20 && !(SR&SR_ZERO) && !(SR&SR_NEG))) return -2;

	//negative
	SR &= ~(SR_NEG|SR_ZERO);
	ram[0] = 0xB4;
	ram[1] = 0x01;
	ram[2] = 0x80;
	instructions = 1; run();
	if(!(Y == 0x80 && !(SR&SR_ZERO) && SR&SR_NEG)) return -3;

	return 0;
}

int testLdyAbsolute() {
	X = 0x01;

	//zero
	SR &= ~(SR_NEG|SR_ZERO);
	ram[0] = 0xAC;
	ram[1] = 0x03;
	ram[2] = 0x00;
	ram[3] = 0x00;
	instructions = 1; run();
	if(!(Y == 0x00 && SR&SR_ZERO && !(SR&SR_NEG))) return -1;

	//normal
	SR &= ~(SR_NEG|SR_ZERO);
	ram[0] = 0xAC;
	ram[1] = 0x03;
	ram[2] = 0x00;
	ram[3] = 0x20;
	instructions = 1; run();
	if(!(Y == 0x20 && !(SR&SR_ZERO) && !(SR&SR_NEG))) return -2;

	//negative
	SR &= ~(SR_NEG|SR_ZERO);
	ram[0] = 0xAC;
	ram[1] = 0x03;
	ram[2] = 0x00;
	ram[3] = 0x80;
	instructions = 1; run();
	if(!(Y == 0x80 && !(SR&SR_ZERO) && SR&SR_NEG)) return -3;

	return 0;
}

int testLdyAbsoluteX() {
	X = 0x01; Y = 0x00;

	//zero
	SR &= ~(SR_NEG|SR_ZERO);
	ram[0] = 0xBC;
	ram[1] = 0x02;
	ram[2] = 0x00;
	ram[3] = 0x00;
	instructions = 1; run();
	if(!(Y == 0x00 && SR&SR_ZERO && !(SR&SR_NEG))) return -1;

	//normal
	SR &= ~(SR_NEG|SR_ZERO);
	ram[0] = 0xBC;
	ram[1] = 0x02;
	ram[2] = 0x00;
	ram[3] = 0x20;
	instructions = 1; run();
	if(!(Y == 0x20 && !(SR&SR_ZERO) && !(SR&SR_NEG))) return -2;

	//negative
	SR &= ~(SR_NEG|SR_ZERO);
	ram[0] = 0xBC;
	ram[1] = 0x02;
	ram[2] = 0x00;
	ram[3] = 0x80;
	instructions = 1; run();
	if(!(Y == 0x80 && !(SR&SR_ZERO) && SR&SR_NEG)) return -3;

	return 0;
}