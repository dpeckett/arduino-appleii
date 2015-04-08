int testStxZeropage() {
	X = 0x23;
	ram[0] = 0x86;
	ram[1] = 0x02;
	ram[2] = 0x00;
	instructions = 1; run();
	if(ram[2] != 0x23) return -1;	
	return 0;
}

int testStxZeropageY() {
	Y = 0x01;
	X = 0x23;
	ram[0] = 0x96;
	ram[1] = 0x01;
	ram[2] = 0x00;
	instructions = 1; run();
	if(ram[2] != 0x23) return -1;	
	return 0;
}

int testStxAbsolute() {
	X = 0x23;
	ram[0] = 0x8E;
	ram[1] = 0x03;
	ram[2] = 0x00;
	ram[3] = 0x00;
	instructions = 1; run();
	if(ram[3] != 0x23) return -1;		
	return 0;
}

int testStyZeropage() {
	Y = 0x23;
	ram[0] = 0x84;
	ram[1] = 0x02;
	ram[2] = 0x00;
	instructions = 1; run();
	if(ram[2] != 0x23) return -1;	
	return 0;
}

int testStyZeropageX() {
	X = 0x01;
	Y = 0x23;
	ram[0] = 0x94;
	ram[1] = 0x01;
	ram[2] = 0x00;
	instructions = 1; run();
	if(ram[2] != 0x23) return -1;	
	return 0;
}

int testStyAbsolute() {
	Y = 0x23;
	ram[0] = 0x8C;
	ram[1] = 0x03;
	ram[2] = 0x00;
	ram[3] = 0x00;
	instructions = 1; run();
	if(ram[3] != 0x23) return -1;		
	return 0;
}