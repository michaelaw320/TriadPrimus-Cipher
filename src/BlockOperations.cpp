/*
 * BlockOperations.cpp
 *
 *  Created on: 17 Mar 2016
 *      Author: Michael
 */

#include "BlockOperations.h"

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

void CircularShiftLeft (Block *blk) {
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

void CircularShiftRight (Block *blk) {
	unsigned char lastByte = blk->byte[7];
	unsigned char twoMSBMask = 0xC0;
	unsigned char twoLSBMask = 0x3;

	unsigned char twoLSBLastByte = lastByte & twoLSBMask;
	unsigned char twoLSBTOMSB = twoLSBLastByte << 6;
	unsigned int i;
	for(i = 7; i > 0; i--) {
		//7 last bytes
		unsigned char currentByteVal = blk->byte[i];
		currentByteVal = currentByteVal >> 2; //move to right, delete LSB
		currentByteVal = currentByteVal & ~twoMSBMask; //sanitize first 2 bits
		unsigned char prevByteVal = blk->byte[i-1];
		unsigned char prevLSB = prevByteVal & twoLSBMask;
		unsigned char prevLSBTOMSB = (prevLSB << 6) & twoMSBMask;
		currentByteVal = currentByteVal | prevLSBTOMSB;
		blk->byte[i] = currentByteVal;
	}
	//special condition for first byte done last
	unsigned char currentByteVal = blk->byte[0];
	currentByteVal = currentByteVal >> 2;
	currentByteVal = currentByteVal & ~twoMSBMask;
	currentByteVal = currentByteVal | twoLSBTOMSB;
	blk->byte[0] = currentByteVal;
}

void XorEntireBlock(Block* targetBlock, Block withBlock) {
	int i;
	for (i = 0 ; i < 8; i++) {
		targetBlock->byte[i] ^= withBlock.byte[i];
	}
}
