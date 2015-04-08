int testAdcImmediate() {
	//no carry
	A = 0x00;
	SR&=(~SR_CARRY);
	ram[0] = 0x69;
	ram[1] = 0x01;
	instructions = 1; run();
	if(!(A == 0x01 && !SR&SR_NEG && !SR&SR_ZERO && !SR&SR_CARRY && !SR&SR_OVER)) return -1;

	//with carry
	A = 0x00;
	SR|=SR_CARRY;
	ram[0] = 0x69;
	ram[1] = 0x01;
	instructions = 1; run();
	if(!(A == 0x02 && !(SR&SR_NEG) && !(SR&SR_ZERO) && !(SR&SR_CARRY) && !(SR&SR_OVER))) return -2;

	//negative result
	A = 0xFE;
	SR&=(~SR_CARRY);
	ram[0] = 0x69;
	ram[1] = 0xFE;
	instructions = 1; run();
	if(!(A == 0xFC && SR&SR_NEG && !(SR&SR_ZERO) && SR&SR_CARRY && !(SR&SR_OVER))) return -3;

	//overflow result
	A = 0x80;
	SR&=(~SR_CARRY);
	ram[0] = 0x69;
	ram[1] = 0xFF;
	instructions = 1; run();
	if(!(A == 0x7F && !(SR&SR_NEG) && !(SR&SR_ZERO) && SR&SR_CARRY && SR&SR_OVER)) return -4;

	//zero result
	A = 0xFF; //-1
	SR&=(~SR_CARRY);
	ram[0] = 0x69;
	ram[1] = 0x01; //+1
	instructions = 1; run();
	if(!(A == 0x00 && !(SR&SR_NEG) && SR&SR_ZERO && SR&SR_CARRY && !(SR&SR_OVER))) return -5;

	//carry result
	A = 0xF0; //+70
	SR&=(~SR_CARRY);
	ram[0] = 0x69;
	ram[1] = 0xF0; //+70
	instructions = 1; run();
	if(!(A == 0xE0 && SR&SR_NEG && !(SR&SR_ZERO) && SR&SR_CARRY && !(SR&SR_OVER))) return -6;

	return 0;
}

int testAdcZeropage() {
	//no carry
	A = 0x00;
	SR &= (~SR_CARRY);
	ram[0] = 0x65;
	ram[1] = 0x02;
	ram[2] = 0x01;
	instructions = 1; run();
	if(!(A == 0x01 && !(SR&SR_NEG) && !(SR&SR_ZERO) && !(SR&SR_CARRY) && !(SR&SR_OVER))) return -1;

	//with carry
	A = 0x00;
	SR |= SR_CARRY;
	ram[0] = 0x65;
	ram[1] = 0x02;
	ram[2] = 0x01;
	instructions = 1; run();
	if(!(A == 0x02 && !(SR&SR_NEG) && !(SR&SR_ZERO) && !(SR&SR_CARRY) && !(SR&SR_OVER))) return -2;

	//negative result
	A = 0xFE;
	SR &= (~SR_CARRY);
	ram[0] = 0x65;
	ram[1] = 0x02;
	ram[2] = 0xFE;
	instructions = 1; run();
	if(!(A == 0xFC && SR&SR_NEG && !(SR&SR_ZERO) && SR&SR_CARRY && !(SR&SR_OVER))) return -3;

	//overflow result
	A = 0x80;
	SR &= (~SR_CARRY);
	ram[0] = 0x65;
	ram[1] = 0x02;
	ram[2] = 0xFF;
	instructions = 1; run();
	if(!(A == 0x7F && !(SR&SR_NEG) && !(SR&SR_ZERO) && SR&SR_CARRY && SR&SR_OVER)) return -4;

	//zero result
	A = 0xFF; //-1
	SR &= (~SR_CARRY);
	ram[0] = 0x65;
	ram[1] = 0x02;
	ram[2] = 0x01; //+1
	instructions = 1; run();
	if(!(A == 0x00 && !(SR&SR_NEG) && SR&SR_ZERO && SR&SR_CARRY && !(SR&SR_OVER))) return -5;

	//carry result
	A = 0xF0; //+70
	SR &= (~SR_CARRY);
	ram[0] = 0x65;
	ram[1] = 0x02;
	ram[2] = 0xF0; //+70
	instructions = 1; run();
	if(!(A == 0xE0 && SR&SR_NEG && !(SR&SR_ZERO) && SR&SR_CARRY && !(SR&SR_OVER))) return -6;

	return 0;
}

int testAdcZeropageX() {
	X = 0x01; Y=0x00;

	//no carry
	A = 0x00;
	SR &= (~SR_CARRY);
	ram[0] = 0x75;
	ram[1] = 0x02;
	ram[3] = 0x01;
	instructions = 1; run();
	if(!(A == 0x01 && !(SR&SR_NEG) && !(SR&SR_ZERO) && !(SR&SR_CARRY) && !(SR&SR_OVER))) return -1;

	//with carry
	A = 0x00;
	SR |= SR_CARRY;
	ram[0] = 0x75;
	ram[1] = 0x02;
	ram[3] = 0x01;
	instructions = 1; run();
	if(!(A == 0x02 && !(SR&SR_NEG) && !(SR&SR_ZERO) && !(SR&SR_CARRY) && !(SR&SR_OVER))) return -2;

	//negative result
	A = 0xFE;
	SR &= (~SR_CARRY);
	ram[0] = 0x75;
	ram[1] = 0x02;
	ram[3] = 0xFE;
	instructions = 1; run();
	if(!(A == 0xFC && SR&SR_NEG && !(SR&SR_ZERO) && SR&SR_CARRY && !(SR&SR_OVER))) return -3;

	//overflow result
	A = 0x80;
	SR &= (~SR_CARRY);
	ram[0] = 0x75;
	ram[1] = 0x02;
	ram[3] = 0xFF;
	instructions = 1; run();
	if(!(A == 0x7F && !(SR&SR_NEG) && !(SR&SR_ZERO) && SR&SR_CARRY && SR&SR_OVER)) return -4;

	//zero result
	A = 0xFF; //-1
	SR &= (~SR_CARRY);
	ram[0] = 0x75;
	ram[1] = 0x02;
	ram[3] = 0x01; //+1
	instructions = 1; run();
	if(!(A == 0x00 && !(SR&SR_NEG) && SR&SR_ZERO && SR&SR_CARRY && !(SR&SR_OVER))) return -5;

	//carry result
	A = 0xF0; //+70
	SR &= (~SR_CARRY);
	ram[0] = 0x75;
	ram[1] = 0x02;
	ram[3] = 0xF0; //+70
	instructions = 1; run();
	if(!(A == 0xE0 && SR&SR_NEG && !(SR&SR_ZERO) && SR&SR_CARRY && !(SR&SR_OVER))) return -6;

	return 0;
}

int testAdcAbsolute() {
	//no carry
	A = 0x00;
	SR &= (~SR_CARRY);
	ram[0] = 0x6D;
	ram[1] = 0x03;
	ram[2] = 0x00;
	ram[3] = 0x01;
	instructions = 1; run();
	if(!(A == 0x01 && !(SR&SR_NEG) && !(SR&SR_ZERO) && !(SR&SR_CARRY) && !(SR&SR_OVER))) return -1;

	//with carry
	A = 0x00;
	SR |= SR_CARRY;
	ram[0] = 0x6D;
	ram[1] = 0x03;
	ram[2] = 0x00;
	ram[3] = 0x01;
	instructions = 1; run();
	if(!(A == 0x02 && !(SR&SR_NEG) && !(SR&SR_ZERO) && !(SR&SR_CARRY) && !(SR&SR_OVER))) return -2;

	//negative result
	A = 0xFE;
	SR &= (~SR_CARRY);
	ram[0] = 0x6D;
	ram[1] = 0x03;
	ram[2] = 0x00;
	ram[3] = 0xFE;
	instructions = 1; run();
	if(!(A == 0xFC && SR&SR_NEG && !(SR&SR_ZERO) && SR&SR_CARRY && !(SR&SR_OVER))) return -3;

	//overflow result
	A = 0x80;
	SR &= (~SR_CARRY);
	ram[0] = 0x6D;
	ram[1] = 0x03;
	ram[2] = 0x00;
	ram[3] = 0xFF;
	instructions = 1; run();
	if(!(A == 0x7F && !(SR&SR_NEG) && !(SR&SR_ZERO) && SR&SR_CARRY && SR&SR_OVER)) return -4;

	//zero result
	A = 0xFF; //-1
	SR &= (~SR_CARRY);
	ram[0] = 0x6D;
	ram[1] = 0x03;
	ram[2] = 0x00;
	ram[3] = 0x01; //+1
	instructions = 1; run();
	if(!(A == 0x00 && !(SR&SR_NEG) && SR&SR_ZERO && SR&SR_CARRY && !(SR&SR_OVER))) return -5;

	//carry result
	A = 0xF0; //+70
	SR &= (~SR_CARRY);
	ram[0] = 0x6D;
	ram[1] = 0x03;
	ram[2] = 0x00;
	ram[3] = 0xF0; //+70
	instructions = 1; run();
	if(!(A == 0xE0 && SR&SR_NEG && !(SR&SR_ZERO) && SR&SR_CARRY && !(SR&SR_OVER))) return -6;

	return 0;
}

int testAdcAbsoluteX() {
	X = 0x01; Y = 0x00;

	//no carry
	A = 0x00;
	SR &= (~SR_CARRY);
	ram[0] = 0x7D;
	ram[1] = 0x02;
	ram[2] = 0x00;
	ram[3] = 0x01;
	instructions = 1; run();
	if(!(A == 0x01 && !(SR&SR_NEG) && !(SR&SR_ZERO) && !(SR&SR_CARRY) && !(SR&SR_OVER))) return -1;

	//with carry
	A = 0x00;
	SR |= SR_CARRY;
	ram[0] = 0x7D;
	ram[1] = 0x02;
	ram[2] = 0x00;
	ram[3] = 0x01;
	instructions = 1; run();
	if(!(A == 0x02 && !(SR&SR_NEG) && !(SR&SR_ZERO) && !(SR&SR_CARRY) && !(SR&SR_OVER))) return -2;

	//negative result
	A = 0xFE;
	SR &= (~SR_CARRY);
	ram[0] = 0x7D;
	ram[1] = 0x02;
	ram[2] = 0x00;
	ram[3] = 0xFE;
	instructions = 1; run();
	if(!(A == 0xFC && SR&SR_NEG && !(SR&SR_ZERO) && SR&SR_CARRY && !(SR&SR_OVER))) return -3;

	//overflow result
	A = 0x80;
	SR &= (~SR_CARRY);
	ram[0] = 0x7D;
	ram[1] = 0x02;
	ram[2] = 0x00;
	ram[3] = 0xFF;
	instructions = 1; run();
	if(!(A == 0x7F && !(SR&SR_NEG) && !(SR&SR_ZERO) && SR&SR_CARRY && SR&SR_OVER)) return -4;

	//zero result
	A = 0xFF; //-1
	SR &= (~SR_CARRY);
	ram[0] = 0x7D;
	ram[1] = 0x02;
	ram[2] = 0x00;
	ram[3] = 0x01; //+1
	instructions = 1; run();
	if(!(A == 0x00 && !(SR&SR_NEG) && SR&SR_ZERO && SR&SR_CARRY && !(SR&SR_OVER))) return -5;

	//carry result
	A = 0xF0; //+70
	SR &= (~SR_CARRY);
	ram[0] = 0x7D;
	ram[1] = 0x02;
	ram[2] = 0x00;
	ram[3] = 0xF0; //+70
	instructions = 1; run();
	if(!(A == 0xE0 && SR&SR_NEG && !(SR&SR_ZERO) && SR&SR_CARRY && !(SR&SR_OVER))) return -6;

	return 0;
}

int testAdcAbsoluteY() {
	Y = 0x01; X = 0x00;

	//no carry
	A = 0x00;
	SR &= (~SR_CARRY);
	ram[0] = 0x79;
	ram[1] = 0x02;
	ram[2] = 0x00;
	ram[3] = 0x01;
	instructions = 1; run();
	if(!(A == 0x01 && !(SR&SR_NEG) && !(SR&SR_ZERO) && !(SR&SR_CARRY) && !(SR&SR_OVER))) return -1;

	//with carry
	A = 0x00;
	SR |= SR_CARRY;
	ram[0] = 0x79;
	ram[1] = 0x02;
	ram[2] = 0x00;
	ram[3] = 0x01;
	instructions = 1; run();
	if(!(A == 0x02 && !(SR&SR_NEG) && !(SR&SR_ZERO) && !(SR&SR_CARRY) && !(SR&SR_OVER))) return -2;

	//negative result
	A = 0xFE;
	SR &= (~SR_CARRY);
	ram[0] = 0x79;
	ram[1] = 0x02;
	ram[2] = 0x00;
	ram[3] = 0xFE;
	instructions = 1; run();
	if(!(A == 0xFC && SR&SR_NEG && !(SR&SR_ZERO) && SR&SR_CARRY && !(SR&SR_OVER))) return -3;

	//overflow result
	A = 0x80;
	SR &= (~SR_CARRY);
	ram[0] = 0x79;
	ram[1] = 0x02;
	ram[2] = 0x00;
	ram[3] = 0xFF;
	instructions = 1; run();
	if(!(A == 0x7F && !(SR&SR_NEG) && !(SR&SR_ZERO) && SR&SR_CARRY && SR&SR_OVER)) return -4;

	//zero result
	A = 0xFF; //-1
	SR &= (~SR_CARRY);
	ram[0] = 0x79;
	ram[1] = 0x02;
	ram[2] = 0x00;
	ram[3] = 0x01; //+1
	instructions = 1; run();
	if(!(A == 0x00 && !(SR&SR_NEG) && SR&SR_ZERO && SR&SR_CARRY && !(SR&SR_OVER))) return -5;

	//carry result
	A = 0xF0; //+70
	SR &= (~SR_CARRY);
	ram[0] = 0x79;
	ram[1] = 0x02;
	ram[2] = 0x00;
	ram[3] = 0xF0; //+70
	instructions = 1; run();
	if(!(A == 0xE0 && SR&SR_NEG && !(SR&SR_ZERO) && SR&SR_CARRY && !(SR&SR_OVER))) return -6;

	return 0;
}

int testAdcIndirectX() {
	X = 0x01; Y = 0x00;

	//no carry
	A = 0x00;
	SR &= (~SR_CARRY);
	ram[0] = 0x61;
	ram[1] = 0x02;
	ram[2] = 0x02;
	ram[3] = 0x01;
	instructions = 1; run();
	if(!(A == 0x01 && !(SR&SR_NEG) && !(SR&SR_ZERO) && !(SR&SR_CARRY) && !(SR&SR_OVER))) return -1;

	//with carry
	A = 0x00;
	SR |= SR_CARRY;
	ram[0] = 0x61;
	ram[1] = 0x02;
	ram[2] = 0x02;
	ram[3] = 0x01;
	instructions = 1; run();
	if(!(A == 0x02 && !(SR&SR_NEG) && !(SR&SR_ZERO) && !(SR&SR_CARRY) && !(SR&SR_OVER))) return -2;

	//negative result
	A = 0xFE;
	SR &= (~SR_CARRY);
	ram[0] = 0x61;
	ram[1] = 0x02;
	ram[2] = 0x02;
	ram[3] = 0xFE;
	instructions = 1; run();
	if(!(A == 0xFC && SR&SR_NEG && !(SR&SR_ZERO) && SR&SR_CARRY && !(SR&SR_OVER))) return -3;

	//overflow result
	A = 0x80;
	SR &= (~SR_CARRY);
	ram[0] = 0x61;
	ram[1] = 0x02;
	ram[2] = 0x02;
	ram[3] = 0xFF;
	instructions = 1; run();
	if(!(A == 0x7F && !(SR&SR_NEG) && !(SR&SR_ZERO) && SR&SR_CARRY && SR&SR_OVER)) return -4;

	//zero result
	A = 0xFF; //-1
	SR &= (~SR_CARRY);
	ram[0] = 0x61;
	ram[1] = 0x02;
	ram[2] = 0x02;
	ram[3] = 0x01; //+1
	instructions = 1; run();
	if(!(A == 0x00 && !(SR&SR_NEG) && SR&SR_ZERO && SR&SR_CARRY && !(SR&SR_OVER))) return -5;

	//carry result
	A = 0xF0; //+70
	SR &= (~SR_CARRY);
	ram[0] = 0x61;
	ram[1] = 0x02;
	ram[2] = 0x02;
	ram[3] = 0xF0; //+70
	instructions = 1; run();
	if(!(A == 0xE0 && SR&SR_NEG && !(SR&SR_ZERO) && SR&SR_CARRY && !(SR&SR_OVER))) return -6;

	return 0;
}

int testAdcIndirectY() {
	Y = 0x01; X = 0x00;

	//no carry
	A = 0x00;
	SR &= (~SR_CARRY);
	ram[0] = 0x71;
	ram[1] = 0x02;
	ram[2] = 0x03;
	ram[3] = 0x00;
	ram[4] = 0x01;
	instructions = 1; run();
	if(!(A == 0x01 && !(SR&SR_NEG) && !(SR&SR_ZERO) && !(SR&SR_CARRY) && !(SR&SR_OVER))) return -1;

	//with carry
	A = 0x00;
	SR |= SR_CARRY;
	ram[0] = 0x71;
	ram[1] = 0x02;
	ram[2] = 0x03;
	ram[3] = 0x00;
	ram[4] = 0x01;
	instructions = 1; run();
	if(!(A == 0x02 && !(SR&SR_NEG) && !(SR&SR_ZERO) && !(SR&SR_CARRY) && !(SR&SR_OVER))) return -2;

	//negative result
	A = 0xFE;
	SR &= (~SR_CARRY);
	ram[0] = 0x71;
	ram[1] = 0x02;
	ram[2] = 0x03;
	ram[3] = 0x00;
	ram[4] = 0xFE;
	instructions = 1; run();
	if(!(A == 0xFC && SR&SR_NEG && !(SR&SR_ZERO) && SR&SR_CARRY && !(SR&SR_OVER))) return -3;

	//overflow result
	A = 0x80;
	SR &= (~SR_CARRY);
	ram[0] = 0x71;
	ram[1] = 0x02;
	ram[2] = 0x03;
	ram[3] = 0x00;
	ram[4] = 0xFF;
	instructions = 1; run();
	if(!(A == 0x7F && !(SR&SR_NEG) && !(SR&SR_ZERO) && SR&SR_CARRY && SR&SR_OVER)) return -4;

	//zero result
	A = 0xFF; //-1
	SR &= (~SR_CARRY);
	ram[0] = 0x71;
	ram[1] = 0x02;
	ram[2] = 0x03;
	ram[3] = 0x00;
	ram[4] = 0x01;
	instructions = 1; run();
	if(!(A == 0x00 && !(SR&SR_NEG) && SR&SR_ZERO && SR&SR_CARRY && !(SR&SR_OVER))) return -5;

	//carry result
	A = 0xF0; //+70
	SR &= (~SR_CARRY);
	ram[0] = 0x71;
	ram[1] = 0x02;
	ram[2] = 0x03;
	ram[3] = 0x00;
	ram[4] = 0xF0;
	instructions = 1; run();
	if(!(A == 0xE0 && SR&SR_NEG && !(SR&SR_ZERO) && SR&SR_CARRY && !(SR&SR_OVER))) return -6;

	return 0;
}