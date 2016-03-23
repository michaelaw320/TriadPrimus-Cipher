/*
 * NewGeneration.h
 *
 *  Created on: 17 Mar 2016
 *      Author: Michael
 */

/**
 * Content	: Scrambler/Descramble Module
 * 			: S-box generator
 */

#ifndef SRC_NEWGENERATION_H_
#define SRC_NEWGENERATION_H_

#include "Block.h"
#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include <ctime>
#include <cstdlib>

Block generateRandomIVBlock();

class NewGeneration {
public:
	NewGeneration(std::string _key, std::vector<Block>* blockToModify);
	virtual ~NewGeneration();
	void scramble();
	void descramble();
private:
	void generateTableOfDataPlacement();
	std::string key;
	std::vector<Block>* workingBlock; //modifying content will modify blocks content directly
	std::vector<int> tableOfDataPlacement; //scramble descramble purpose

};

#endif /* SRC_NEWGENERATION_H_ */
