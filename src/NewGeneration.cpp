/*
 * NewGeneration.cpp
 *
 *  Created on: 17 Mar 2016
 *      Author: Michael
 */

#include "NewGeneration.h"

using namespace std;

Block generateRandomIVBlock() {
	Block randomBlock;
	int i;
	srand((unsigned)time(NULL));
	for(i = 0; i < 8; i++) {
		randomBlock.byte[i] = rand() % 256;
	}
	return randomBlock;
}

NewGeneration::NewGeneration(std::string _key, std::vector<Block>* blockToModify) {
	key = _key;
	workingBlock = blockToModify;
}

NewGeneration::~NewGeneration() {
	// TODO Auto-generated destructor stub
}

void NewGeneration::scramble() {
	generateTableOfDataPlacement();
	int i, j;
	for (i=0; i < workingBlock->size(); i++) {
		j = tableOfDataPlacement.at(i);
		//swap block
		Block tmp;
		tmp = workingBlock->at(i);
		workingBlock->at(i) = workingBlock->at(j);
		workingBlock->at(j) = tmp;
	}
}

void NewGeneration::descramble() {
	generateTableOfDataPlacement();
	int i, j;
	//for (i=0; i < workingBlock->size(); i++) {
	for(i = workingBlock->size()-1 ; i >= 0; i--) {
		j = tableOfDataPlacement.at(i);
		//swap block
		Block tmp;
		tmp = workingBlock->at(j);
		workingBlock->at(j) = workingBlock->at(i);
		workingBlock->at(i) = tmp;
	}
}

void NewGeneration::generateTableOfDataPlacement() {
	long seed = 0;
	int i;
	for (i = 0; i < key.length(); i++) {
		seed += (long) key[i];
	}
	int blockCounts = workingBlock->size();

	//initialize arrayContent
	vector<int> arrayToShuffle;
	for (i = 0; i < blockCounts; i++) {
		arrayToShuffle.push_back(i);
	}

	//shuffle with C++11 functions
	shuffle(arrayToShuffle.begin(), arrayToShuffle.end(), default_random_engine(seed));

	tableOfDataPlacement = arrayToShuffle;

}

void NewGeneration::substitute(bool isEncryptMode) {
	int i,j,k;
	generateSubstitutionTable();
	if (isEncryptMode) {
		for(i=0; i < workingBlock->size(); i++) {

			for(j=0; j < 8; j++) {
				unsigned char currentChar = workingBlock->at(i).byte[j];
				currentChar = subsTable.at(currentChar); //substitute current char
				workingBlock->at(i).byte[j] = currentChar;
			}
		}
	} else {
		for(i=0; i < workingBlock->size(); i++) {
			for(j=0; j < 8; j++) {
				unsigned char value = workingBlock->at(i).byte[j];
				unsigned char idx;
				for(k = 0; k < 256; k++) { //lookup table for the particular value
					if (subsTable.at(k) == value) {
						idx = k;
						break;
					}
				}
				workingBlock->at(i).byte[j] = idx;
			}
		}
	}
}

void NewGeneration::generateSubstitutionTable() {
	long seed = 0;
	int i;
	for (i = 0; i < key.length(); i++) {
		seed += (long) key[i];
	}

	//initialize arrayContent
	vector<unsigned char> arrayToShuffle;
	for (i = 0; i < 256; i++) {
		arrayToShuffle.push_back(i);
	}

	//shuffle with C++11 functions
	shuffle(arrayToShuffle.begin(), arrayToShuffle.end(), default_random_engine(seed));

	subsTable = arrayToShuffle;
}
