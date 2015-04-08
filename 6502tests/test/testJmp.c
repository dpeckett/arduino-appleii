int testJmpAbsolute() {
	SR &= (~SR_DEC);
	ram[0] = 0x4C;
	ram[1] = 0x04;
	ram[2] = 0x00;
	ram[3] = 0x00;
	ram[4] = 0xF8;
	instructions = 5; run();
	if(!(SR&SR_DEC)) return -1;
	return 0;
}

int testJmpIndirect() {
	SR &= (~SR_DEC);
	ram[0] = 0x4C;
	ram[1] = 0x04;
	ram[2] = 0x00;
	ram[3] = 0x00;
	ram[4] = 0x06;
	ram[5] = 0x00;
	ram[6] = 0xF8;
	instructions = 7; run();
	if(!(SR&SR_DEC)) return -1;
	return 0;
}

int testJsrAbsolute() {
	SR &= (~SR_DEC);
	ram[0] = 0x20;
	ram[1] = 0x04;
	ram[2] = 0x00;
	ram[3] = 0x00;
	ram[4] = 0xF8;
	instructions = 5; run();
	if(!(SR&SR_DEC && pull16() == 0x0002)) return -1;
	return 0;
}