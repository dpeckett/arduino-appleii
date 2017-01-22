/*

Bunch of unit tests I wrote during the development of the emulator.
These are very nasty and not really release worthy but someone might
find them useful!

Copyright (c) 2015, Damian Peckett <damian@pecke.tt>
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer. 
2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

//TEST Functions

#include "test/testAdc.c"
#include "test/testAnd.c"
#include "test/testAsl.c"
#include "test/testBcc.c"
#include "test/testBcs.c"
#include "test/testBeq.c"
#include "test/testBit.c"
#include "test/testBmi.c"
#include "test/testBne.c"
#include "test/testBpl.c"
#include "test/testBrk.c"
#include "test/testBvc.c"
#include "test/testBvs.c"
#include "test/testClear.c"
#include "test/testCmp.c"
#include "test/testCpx.c"
#include "test/testCpy.c"
#include "test/testDec.c"
#include "test/testEor.c"
#include "test/testInc.c"
#include "test/testJmp.c"
#include "test/testLd.c"
#include "test/testLsr.c"
#include "test/testOra.c"
#include "test/testPha.c"
#include "test/testPhp.c"
#include "test/testPla.c"
#include "test/testPlp.c"
#include "test/testRol.c"
#include "test/testRor.c"
#include "test/testRti.c"
#include "test/testRts.c"
#include "test/testSbc.c"
#include "test/testSet.c"
#include "test/testSta.c"
#include "test/testSt.c"
#include "test/testTransfer.c"

void testAdc() {
	printf("testAdcImmediate: %d\r\n", testAdcImmediate());
	printf("testAdcZeropage: %d\r\n", testAdcZeropage());
	printf("testAdcZeropageX: %d\r\n", testAdcZeropageX());
	printf("testAdcAbsolute: %d\r\n", testAdcAbsolute());
	printf("testAdcAbsoluteX: %d\r\n", testAdcAbsoluteX());
	printf("testAdcAbsoluteY: %d\r\n", testAdcAbsoluteY());
	printf("testAdcIndirectX: %d\r\n", testAdcIndirectX());
	printf("testAdcIndirectY: %d\r\n", testAdcIndirectY());
}

void testAnd() {
	printf("testAndImmediate: %d\r\n", testAndImmediate());
	printf("testAndZeropage: %d\r\n", testAndZeropage());
	printf("testAndZeropageX: %d\r\n", testAndZeropageX());
	printf("testAndAbsolute: %d\r\n", testAndAbsolute());
	printf("testAndAbsoluteX: %d\r\n", testAndAbsoluteX());
	printf("testAndAbsoluteY: %d\r\n", testAndAbsoluteY());
	printf("testAndIndirectX: %d\r\n", testAndIndirectX());
	printf("testAndIndirectY: %d\r\n", testAndIndirectY());
}

void testAsl() {
	printf("testAslImplied: %d\r\n", testAslImplied());
	printf("testAslZeropage: %d\r\n", testAslZeropage());
	printf("testAslZeropageX: %d\r\n", testAslZeropageX());
	printf("testAslAbsolute: %d\r\n", testAslAbsolute());
	printf("testAslAbsoluteX: %d\r\n", testAslAbsoluteX());
}

void testBranches() {
	printf("testBccImplied: %d\r\n", testBccImplied());
	printf("testBcsImplied: %d\r\n", testBcsImplied());
	printf("testBeqImplied: %d\r\n", testBeqImplied());
	printf("testBmiImplied: %d\r\n", testBmiImplied());
	printf("testBneImplied: %d\r\n", testBneImplied());
	printf("testBplImplied: %d\r\n", testBplImplied());
	printf("testBvcImplied: %d\r\n", testBvcImplied());
	printf("testBvsImplied: %d\r\n", testBvsImplied());
}

void testBit() {
	printf("testBitZeropage: %d\r\n", testBitZeropage());
	printf("testBitAbsolute: %d\r\n", testBitAbsolute());	
}

void testBrk() {
	printf("testBrkImplied: %d\r\n", testBrkImplied());
}

void testClear() {
	printf("testClcImplied: %d\r\n", testClcImplied());
	printf("testCldImplied: %d\r\n", testCldImplied());
	printf("testCliImplied: %d\r\n", testCliImplied());
	printf("testClvImplied: %d\r\n", testClvImplied());
}

void testCompare() {
	printf("testCmpImmediate: %d\r\n", testCmpImmediate());
	printf("testCmpZeropage: %d\r\n", testCmpZeropage());
	printf("testCmpZeropageX: %d\r\n", testCmpZeropageX());
	printf("testCmpAbsolute: %d\r\n", testCmpAbsolute());
	printf("testCmpAbsoluteX: %d\r\n", testCmpAbsoluteX());
	printf("testCmpAbsoluteY: %d\r\n", testCmpAbsoluteY());
	printf("testCmpIndirectX: %d\r\n", testCmpIndirectX());
	printf("testCmpIndirectY: %d\r\n", testCmpIndirectY());
	printf("testCpxImmediate: %d\r\n", testCpxImmediate());
	printf("testCpxZeropage: %d\r\n", testCpxZeropage());
	printf("testCpxAbsolute: %d\r\n", testCpxAbsolute());
	printf("testCpyImmediate: %d\r\n", testCpyImmediate());
	printf("testCpyZeropage: %d\r\n", testCpyZeropage());
	printf("testCpyAbsolute: %d\r\n", testCpyAbsolute());
}

void testDec() {
	printf("testDecZeropage: %d\r\n", testDecZeropage());
	printf("testDecZeropageX: %d\r\n", testDecZeropageX());
	printf("testDecAbsolute: %d\r\n", testDecAbsolute());
	printf("testDexImplied: %d\r\n", testDexImplied());
	printf("testDeyImplied: %d\r\n", testDeyImplied());
}

void testEor() {
	printf("testEorImmediate: %d\r\n", testEorImmediate());
	printf("testEorZeropage: %d\r\n", testEorZeropage());
	printf("testEorZeropageX: %d\r\n", testEorZeropageX());
	printf("testEorAbsolute: %d\r\n", testEorAbsolute());
	printf("testEorAbsoluteX: %d\r\n", testEorAbsoluteX());
	printf("testEorAbsoluteY: %d\r\n", testEorAbsoluteY());
	printf("testEorIndirectX: %d\r\n", testEorIndirectX());
	printf("testEorIndirectY: %d\r\n", testEorIndirectY());
}

void testInc() {
	printf("testIncZeropage: %d\r\n", testIncZeropage());
	printf("testIncZeropageX: %d\r\n", testIncZeropageX());
	printf("testIncAbsolute: %d\r\n", testIncAbsolute());
	printf("testInxImplied: %d\r\n", testInxImplied());
	printf("testInyImplied: %d\r\n", testInyImplied());
}

void testJmp() {
	printf("testJmpAbsolute: %d\r\n", testJmpAbsolute());
	printf("testJmpIndirect: %d\r\n", testJmpIndirect());
	printf("testJsrAbsolute: %d\r\n", testJsrAbsolute());
}

void testLoads() {
	printf("testLdaImmediate: %d\r\n", testLdaImmediate());
	printf("testLdaZeropage: %d\r\n", testLdaZeropage());
	printf("testLdaZeropageX: %d\r\n", testLdaZeropageX());
	printf("testLdaAbsolute: %d\r\n", testLdaAbsolute());
	printf("testLdaAbsoluteX: %d\r\n", testLdaAbsoluteX());
	printf("testLdaAbsoluteY: %d\r\n", testLdaAbsoluteY());
	printf("testLdaIndirectX: %d\r\n", testJmpAbsolute());
	printf("testLdaIndirectY: %d\r\n", testLdaIndirectY());	
	printf("testLdxImmediate: %d\r\n", testLdxImmediate());
	printf("testLdxZeropage: %d\r\n", testLdxZeropage());
	printf("testLdxZeropageY: %d\r\n", testLdxZeropageY());
	printf("testLdxAbsolute: %d\r\n", testLdxAbsolute());
	printf("testLdxAbsoluteY: %d\r\n", testLdxAbsoluteY());
	printf("testLdyImmediate: %d\r\n", testLdyImmediate());	
	printf("testLdyZeropage: %d\r\n", testLdyZeropage());	
	printf("testLdyZeropageX: %d\r\n", testLdyZeropageX());
	printf("testLdyAbsolute: %d\r\n", testLdyAbsolute());
	printf("testLdyAbsoluteX: %d\r\n", testLdyAbsoluteX());
}

void testLsr() {
	printf("testLsrImplied: %d\r\n", testLsrImplied());	
	printf("testLsrZeropage: %d\r\n", testLsrZeropage());	
	printf("testLdyZeropageX: %d\r\n", testLsrZeropageX());
	printf("testLsrAbsolute: %d\r\n", testLsrAbsolute());
	printf("testLsrAbsoluteX: %d\r\n", testLsrAbsoluteX());
}

void testOra() {
	printf("testOraImmediate: %d\r\n", testOraImmediate());
	printf("testOraZeropage: %d\r\n", testOraZeropage());
	printf("testOraZeropageX: %d\r\n", testOraZeropageX());
	printf("testOraAbsolute: %d\r\n", testOraAbsolute());
	printf("testOraAbsoluteX: %d\r\n", testOraAbsoluteX());
	printf("testOraAbsoluteY: %d\r\n", testOraAbsoluteY());
	printf("testOraIndirectX: %d\r\n", testOraIndirectX());
	printf("testOraIndirectY: %d\r\n", testOraIndirectY());
}

void testStack() {
	printf("testPhaImplied: %d\r\n", testPhaImplied());
	printf("testPhpImplied: %d\r\n", testPhpImplied());
	printf("testPlaImplied: %d\r\n", testPlaImplied());
	printf("testPlpImplied: %d\r\n", testPlpImplied());
}

void testRotate() {
	printf("testRolImplied: %d\r\n", testRolImplied());
	printf("testRolZeropage: %d\r\n", testRolZeropage());
	printf("testRolZeropageX: %d\r\n", testRolZeropageX());
	printf("testRolAbsolute: %d\r\n", testRolAbsolute());
	printf("testRolAbsoluteX: %d\r\n", testRolAbsoluteX());
	printf("testRorImplied: %d\r\n", testRorImplied());
	printf("testRorZeropage: %d\r\n", testRorZeropage());
	printf("testRorZeropageX: %d\r\n", testRorZeropageX());
	printf("testRorAbsolute: %d\r\n", testRorAbsolute());
	printf("testRorAbsoluteX: %d\r\n", testRorAbsoluteX());
}

void testReturn() {
	printf("testRtiImplied: %d\r\n", testRtiImplied());
	printf("testRtsImplied: %d\r\n", testRtsImplied());
}

void testSbc() {
	printf("testSbcImmediate: %d\r\n", testSbcImmediate());
	printf("testSbcZeropage: %d\r\n", testSbcZeropage());
	printf("testSbcZeropageX: %d\r\n", testSbcZeropageX());
	printf("testSbcAbsolute: %d\r\n", testSbcAbsolute());
	printf("testSbcAbsoluteX: %d\r\n", testSbcAbsoluteX());
	printf("testSbcAbsoluteY: %d\r\n", testSbcAbsoluteY());
	printf("testSbcIndirectX: %d\r\n", testSbcIndirectX());
	printf("testSbcIndirectY: %d\r\n", testSbcIndirectY());
}

void testSet() {
	printf("testSecImplied: %d\r\n", testSecImplied());
	printf("testSedImplied: %d\r\n", testSedImplied());
	printf("testSeiImplied: %d\r\n", testSeiImplied());	
}

void testSta() {
	printf("testStaZeropage: %d\r\n", testStaZeropage());
	printf("testStaZeropageX: %d\r\n", testStaZeropageX());
	printf("testStaAbsolute: %d\r\n", testStaAbsolute());
	printf("testStaAbsoluteX: %d\r\n", testStaAbsoluteX());
	printf("testStaAbsoluteY: %d\r\n", testStaAbsoluteY());
	printf("testStaIndirectX: %d\r\n", testStaIndirectX());
	printf("testStaIndirectY: %d\r\n", testStaIndirectY());
}

void testStores() {
	printf("testStxZeropage: %d\r\n", testStxZeropage());
	printf("testStxZeropageY: %d\r\n", testStxZeropageY());
	printf("testStxAbsolute: %d\r\n", testStxAbsolute());
	printf("testStyZeropage: %d\r\n", testStyZeropage());
	printf("testStyZeropageX: %d\r\n", testStyZeropageX());
	printf("testStyAbsolute: %d\r\n", testStyAbsolute());
}

void testTransfer() {
	printf("testTaxImplied: %d\r\n", testTaxImplied());	
	printf("testTayImplied: %d\r\n", testTayImplied());
	printf("testTsxImplied: %d\r\n", testTsxImplied());	
	printf("testTxaImplied: %d\r\n", testTxaImplied());	
	printf("testTxsImplied: %d\r\n", testTxsImplied());
	printf("testTyaImplied: %d\r\n", testTyaImplied());	
}

int main() {
	testAnd();
	testAdc();
	testAsl();
	testBranches();
	testBit();
	testBrk();
	testClear();
	testCompare();
	testDec();
	testEor();
	testInc();
	testJmp();
	testLoads();
	testLsr();
	testOra();
	testStack();
	testRotate();
	testReturn();
	testSbc();
	testSet();
	testSta();
	testStores();
	testTransfer();
	return 0;
}