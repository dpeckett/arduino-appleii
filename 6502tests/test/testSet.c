int testSecImplied() {
	SR &= (~SR_CARRY);
	ram[0] = 0x38;
	instructions = 1; run();
	if(!(SR&SR_CARRY)) return -1;
	return 0;
}

int testSedImplied() {
	SR &= (~SR_DEC);
	ram[0] = 0xF8;
	instructions = 1; run();
	if(!(SR&SR_DEC)) return -1;
	return 0;
}

int testSeiImplied() {
	SR &= (~SR_INT);
	ram[0] = 0x78;
	instructions = 1; run();
	if(!(SR&SR_INT)) return -1;
	return 0;
}