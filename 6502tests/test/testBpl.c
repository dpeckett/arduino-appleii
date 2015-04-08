int testBplImplied() {
	SR |= SR_NEG;
	SR &= (~SR_DEC);
	ram[0] = 0x10;
	ram[1] = 0x01;
	ram[2] = 0x00;
	ram[3] = 0xF8; //SED
	instructions = 4; run();
	if(SR&SR_DEC) return -1;

	SR &= (~SR_NEG);
	SR &= (~SR_DEC);
	ram[0] = 0x10;
	ram[1] = 0x01;
	ram[2] = 0x00;
	ram[3] = 0xF8;
	instructions = 4; run();
	if(!(SR&SR_DEC)) return -2;

	return 0;
}