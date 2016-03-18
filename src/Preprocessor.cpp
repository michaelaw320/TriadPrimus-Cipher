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
	copyToBlock(inputData, inputLen);
}

Preprocessor::~Preprocessor() {
	// TODO Auto-generated destructor stub
}

std::vector<Block>* Preprocessor::getPtrToBlocks() {
	return &blocks;
}

void Preprocessor::copyToBlock(unsigned char* inputData, int inputLen) {
	// Do the copying process from input array into block, and if not in block size, note: PADDING
}

void Preprocessor::doPadding() {
	// Check the input len, need padding? if yes, check last block, do padding there
	// TODO think of padding scheme (note for binary files)
}
