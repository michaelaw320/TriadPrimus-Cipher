/*
 * BlockOperations.cpp
 *
 *  Created on: 17 Mar 2016
 *      Author: Michael
 */

unsigned char GetLastTwoBits (Block *blk) {
	unsigned char byteVal = blk->byte[7];
	unsigned char mask = 0x3; // 00000011
	return byteVal & mask;
}

void ModifyLastTwoBits (Block *blk, unsigned char val){
	unsigned char lastbyte = blk->byte[7];
	unsigned char mask = 0x3; // 00000011
	unsigned char newLastByte = lastbyte & (~mask);
	//sanitize val
	unsigned char newVal = val & mask;
	newLastByte = newLastByte | newVal;
	blk->byte[7] = newLastByte;
}

void PrimusShift (Block *blk) {
	unsigned char firstByte = blk->byte[0];
	unsigned char twoMSBMask = 0xC0; //11000000
	unsigned char twoLSBMask = 0x3; // 00000011

	unsigned char twoMSBFirstByte = firstByte & twoMSBMask;
	unsigned char twoMSBFirstByteLast = (twoMSBFirstByte >> 6) & 0x3; //move msb bit to lsb
	unsigned int i;
	for (i = 0; i < 8; i++) {
		unsigned char currentByteVal = blk->byte[i];
		currentByteVal = currentByteVal << 2; //delete the first 2 bits
		currentByteVal = currentByteVal & ~twoLSBMask; //sanitize last 2 bits
		if (i == 7) { //last Byte modification
			currentByteVal = currentByteVal | twoMSBFirstByteLast;
		} else {
			unsigned char nextByteVal = blk->byte[i+1];
			unsigned char nextMSB = nextByteVal & twoMSBMask;
			unsigned char nextMSBPushed = (nextMSB >> 6) & 0x3;
			currentByteVal = currentByteVal | nextMSBPushed;
		}
		blk->byte[i] = currentByteVal;
	}
}
