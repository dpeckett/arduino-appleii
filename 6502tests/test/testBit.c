int testBitZeropage() {
	//bits set
	A = 0x00;
	ram[0] = 0x24;
	ram[1] = 0x02;
	ram[2] = 0xFF;
	instructions = 2;
	run();
	if(!(SR&SR_NEG && SR&SR_ZERO && SR&SR_OVER)) return -1;

	//bits unset
	A = 0x01;
	ram[0] = 0x24;
	ram[1] = 0x02;
	ram[2] = 0x01;
	instructions = 2;
	run();
	if(!(!(SR&SR_NEG) && !(SR&SR_ZERO) && !(SR&SR_OVER))) return -2;

	return 0;
}

int testBitAbsolute() {
	//bits set
	A = 0x00;
	ram[0] = 0x24;
	ram[1] = 0x03;
	ram[2] = 0x00;
	ram[3] = 0xFF;
	instructions = 2;
	run();
	if(!(SR&SR_NEG && SR&SR_ZERO && !(SR&SR_CARRY) && SR&SR_OVER)) return -1;

	//bits unset
	A = 0x01;
	ram[0] = 0x24;
	ram[1] = 0x03;
	ram[2] = 0x00;
	ram[3] = 0x01;
	instructions = 2;
	run();
	if(!(!(SR&SR_NEG) && !(SR&SR_ZERO) && !(SR&SR_CARRY) && !(SR&SR_OVER))) return -2;

	return 0;
}