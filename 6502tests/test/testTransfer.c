int testTaxImplied() {
	//normal
	X = 0; A = 0x23;
	ram[0] = 0xAA;
	instructions = 1; run();
	if(!(X == 0x23 && !(SR&SR_NEG) && !(SR&SR_ZERO)))return -1;
	//negative
	X = 0; A = 0xFE;
	ram[0] = 0xAA;
	instructions = 1; run();
	if(!(X == 0xFE && SR&SR_NEG && !(SR&SR_ZERO)))return -2;
	return 0;
}

int testTayImplied() {
	//normal
	Y = 0; A = 0x23;
	ram[0] = 0xA8;
	instructions = 1; run();
	if(!(Y == 0x23 && !(SR&SR_NEG) && !(SR&SR_ZERO)))return -1;
	//negative
	Y = 0; A = 0xFE;
	ram[0] = 0xA8;
	instructions = 1; run();
	if(!(Y == 0xFE && SR&SR_NEG && !(SR&SR_ZERO)))return -2;
	return 0;
}

int testTsxImplied() {
	//normal
	X = 0; SP = 0x23;
	ram[0] = 0xBA;
	instructions = 1; run();
	if(!(X == 0x23 && !(SR&SR_NEG) && !(SR&SR_ZERO)))return -1;
	//negative
	X = 0; SP = 0xFE;
	ram[0] = 0xBA;
	instructions = 1; run();
	if(!(X == 0xFE && SR&SR_NEG && !(SR&SR_ZERO)))return -2;
	return 0;
}

int testTxaImplied() {
	//normal
	A = 0; X = 0x23;
	ram[0] = 0x8A;
	instructions = 1; run();
	if(!(A == 0x23 && !(SR&SR_NEG) && !(SR&SR_ZERO)))return -1;
	//negative
	A = 0; X = 0xFE;
	ram[0] = 0x8A;
	instructions = 1; run();
	if(!(A == 0xFE && SR&SR_NEG && !(SR&SR_ZERO)))return -2;
	return 0;
}

int testTxsImplied() {
	//normal
	SR = SR_FIXED_BITS;
	X = 0x00; SP = 0x00;
	ram[0] = 0x9A;
	instructions = 1; run();
	if(!(SP == 0x23 && !(SR&SR_ZERO)))return -1;
	return 0;
}

int testTyaImplied() {
	//normal
	A = 0; Y = 0x23;
	ram[0] = 0x98;
	instructions = 1; run();
	if(!(A == 0x23 && !(SR&SR_NEG) && !(SR&SR_ZERO)))return -1;
	//negative
	A = 0; Y = 0xFE;
	ram[0] = 0x98;
	instructions = 1; run();
	if(!(A == 0xFE && SR&SR_NEG && !(SR&SR_ZERO)))return -2;
	return 0;
}