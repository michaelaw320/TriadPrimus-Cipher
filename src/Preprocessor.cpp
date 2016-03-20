/*
 * Preprocessor.cpp
 *
 *  Created on: 17 Mar 2016
 *      Author: Michael
 */

#include "Preprocessor.h"


Preprocessor::Preprocessor(unsigned char* inputData, int inputLen) {
	// Construct the vector of Block by copying value 1 by 1 with copyToBlock
	this->inputData = inputData;
	this->inputLen = inputLen;
	copyToBlock();
}

Preprocessor::~Preprocessor() {
	// TODO Auto-generated destructor stub
}

std::vector<Block>* Preprocessor::getPtrToBlocks() {
	return &blocks;
}

void Preprocessor::copyToBlock() {
	// Do the copying process from input array into block, and if not in block size, note: PADDING
	int blockCounts = inputLen / 8;
	int blockRemainder = inputLen % 8;
	int i;
	Block* ptrToFirstBlock = (Block*) inputData; //put beginning address of inputData, then reinterpret as block
	for(i=0; i<blockCounts; i++) {
		Block cpyBlk = *(ptrToFirstBlock + i);
		blocks.push_back(cpyBlk);
	}
	if (blockRemainder != 0) {
		//There's still some data, copy it manually then pad it
		Block lastBlk;
		for(i=0; i<blockRemainder; i++) {
			lastBlk.byte[i] = inputData[(blockCounts*8)+i];
		}
		//do padding, ISO/IEC 7816-4
		for(i = blockRemainder; i < 8; i++) {
			if (i == blockRemainder) {
				lastBlk.byte[i] = 0x80;
			} else {
				lastBlk.byte[i] = 0x1; //padding
			}

		}
		blocks.push_back(lastBlk);
	}
}

void Preprocessor::generateOutput(bool removePaddingFlag) {
	int size = blocks.size() * sizeof(Block); // size in bytes
	if (removePaddingFlag) {
		if (isPadded()) {
			size = size - paddingCount;
		}
	}
	output = (unsigned char*) calloc(size, sizeof(unsigned char));
	unsigned int i, j, n;
	n = 0;
	for (i = 0; i < blocks.size(); i++) {
		for (j = 0; j < 8; j ++) {
			if (n < (unsigned int) size) {
				output[n] = blocks.at(i).byte[j];
				n++;
			}
		}
	}

	outputLen = size;
}

unsigned char* Preprocessor::getOutputData() {
	return output;
}

int Preprocessor::getOutputLen() {
	return outputLen;
}

bool Preprocessor::isPadded() {
	Block lastblk = blocks.at(blocks.size()-1);
	int i,j;
	for (i = 0; i < 8; i++) { //scans for 0x80 occurence
		if (lastblk.byte[i] == 0x80) {
			bool isZero = true; //asume next byte is 0
			for (j = i+1; j < 8; j++) { //check bytes after 0x80 must be all 0 to return true
				if (lastblk.byte[j] != 0) {
					isZero = false; //byte is not 0 till the end, return false
					break;
				}
			}
			if (isZero) {
				paddingCount = 8 - i;
				return true;
			}
			else return false;
		}
	}
	return false;
}
