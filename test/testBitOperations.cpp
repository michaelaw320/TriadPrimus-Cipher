#include <iostream>
#include <cstdio>

typedef struct {
	//should be 8 bytes / 64 bit
	unsigned char byte[8];
} Block;

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

unsigned char GetFirstTwoBits (Block *blk) {
	unsigned char byteVal = blk->byte[0];
	unsigned char twoMSBMask = 0xC0; // 11000000
	unsigned char pushMask = 0x3; // 00000011
	byteVal = byteVal & twoMSBMask; // get the 2 msb
	byteVal = byteVal >> 6; //push it to LSB
	return byteVal & pushMask; //return sanitized first 2 bits
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

void ModifyFirstTwoBits (Block *blk, unsigned char val){
	unsigned char firstByte = blk->byte[0];
	unsigned char mask = 0xC0; // 11000000
	unsigned char newFirstByte = firstByte & (~mask); //delete first 2 bits
	//set proper val and sanitize val
	unsigned char newVal = (val << 6) & mask;
	newFirstByte = newFirstByte | newVal;
	blk->byte[0] = newFirstByte;
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


void printBits(unsigned char n)
{
	unsigned char i;
	i = 1<<(sizeof(n) * 8 - 1);

	while (i > 0) {
		if (n & i)
			printf("1");
		else
			printf("0");
		i >>= 1;
	}
	printf (" ");
}

int main() {
	Block blk;
	int i;
	for (i = 0; i < 8; i++) {
		blk.byte[i] = 0xFE;
	}
	printf("Original Data: \n");
	for (i = 0; i < 8; i++) {
		printBits(blk.byte[i]);
	}
	printf("\n");
	
	unsigned char lastBits = GetLastTwoBits(&blk);
	unsigned char exFKey = 0xFF;
	unsigned char firstBits = GetFirstTwoBits(&blk);
	
	//we try to xor the last bits with feistel key, then xor the first bits with the resulting feisteled
	lastBits = lastBits ^ exFKey;
	firstBits = firstBits ^ lastBits;
	
	ModifyLastTwoBits(&blk, lastBits);
	ModifyFirstTwoBits(&blk, firstBits);
	printf("Using ex Feistel Key 0xFF\n");
	
	printf("Result before shift: \n");
	for (i = 0; i < 8; i++) {
		printBits(blk.byte[i]);
	}
	printf("\n");
	
	printf("Result after shift: \n");
	PrimusShift(&blk);
	for (i = 0; i < 8; i++) {
		printBits(blk.byte[i]);
	}
	printf("\n");
}