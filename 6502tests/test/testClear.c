int testClcImplied() {
	SR |= SR_CARRY;
	ram[0] = 0x18;
	instructions = 1; run();
	if(SR&SR_CARRY) return -1;
	return 0;
}

int testCldImplied() {
	SR |= SR_DEC;
	ram[0] = 0xD8;
	instructions = 1; run();
	if(SR&SR_DEC) return -1;
	return 0;
}

int testCliImplied() {
	SR |= SR_INT;
	ram[0] = 0x58;
	instructions = 1; run();
	if(SR&SR_INT) return -1;
	return 0;
}

int testClvImplied() {
	SR |= SR_OVER;
	ram[0] = 0xB8;
	instructions = 1; run();
	if(SR&SR_OVER) return -1;
	return 0;
}