int testBcsImplied() {
	SR|=SR_CARRY;
	SR&=(~SR_DEC);
	ram[0] = 0xB0;
	ram[1] = 0x01;
	ram[2] = 0x00;
	ram[3] = 0xF8; //SED
	instructions = 4;
	run();
	if((SR&SR_DEC) == 0) return -1;

	SR&=(~SR_CARRY);
	SR&=(~SR_DEC);
	ram[0] = 0xB0;
	ram[1] = 0x01;
	ram[2] = 0x00;
	ram[3] = 0xF8;
	instructions = 4;
	run();
	if((SR&SR_DEC) > 0) return -2;

	return 0;
}