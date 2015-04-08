int testStaZeropage() {
	A = 0x23;
	ram[0] = 0x85;
	ram[1] = 0x02;
	ram[2] = 0x00;
	instructions = 1; run();
	if(ram[2] != 0x23) return -1;
	return 0;
}

int testStaZeropageX() {
	X = 0x01; Y = 0x00;
	A = 0x23;
	ram[0] = 0x95;
	ram[1] = 0x01;
	ram[2] = 0x00;
	instructions = 1; run();
	if(ram[2] != 0x23) return -1;
	return 0;
}

int testStaAbsolute() {
	A = 0x23;
	ram[0] = 0x8D;
	ram[1] = 0x03;
	ram[2] = 0x00;
	ram[3] = 0x00;
	instructions = 1; run();
	if(ram[3] != 0x23) return -1;	
	return 0;
}

int testStaAbsoluteX() {
	X = 0x01; Y = 0x00;
	A = 0x23;
	ram[0] = 0x9D;
	ram[1] = 0x02;
	ram[2] = 0x00;
	ram[3] = 0x00;
	instructions = 1; run();
	if(ram[3] != 0x23) return -1;	
	return 0;
}

int testStaAbsoluteY() {
	Y = 0x01; X = 0x00;
	A = 0x23;
	ram[0] = 0x99;
	ram[1] = 0x02;
	ram[2] = 0x00;
	ram[3] = 0x00;
	instructions = 1; run();
	if(ram[3] != 0x23) return -1;	
	return 0;
}

int testStaIndirectX() {
	X = 0x01; Y = 0x00;
	A = 0x23;
	ram[0] = 0x81;
	ram[1] = 0x02;
	ram[2] = 0x02;
	ram[3] = 0x00;
	instructions = 1; run();
	if(ram[3] != 0x23) return -1;
	return 0;
}

int testStaIndirectY() {
	Y = 0x01; X = 0x00;
	A = 0x23;
	ram[0] = 0x91;
	ram[1] = 0x02;
	ram[2] = 0x03;
	ram[3] = 0x00;
	ram[4] = 0x00;
	instructions = 1; run();
	if(ram[4] != 0x23) return -1;
	return 0;
}
