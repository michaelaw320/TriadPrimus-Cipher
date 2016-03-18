/*
 * ModeSelector.h
 *
 *  Created on: 17 Mar 2016
 *      Author: Michael
 */

/**
 * Content	: Main Algorithm for ECB, CBC, and CFB
 */

#ifndef SRC_MODESELECTOR_H_
#define SRC_MODESELECTOR_H_

#include "Block.h"

class ModeSelector {
public:
	ModeSelector(std::vector<Block>* ptrToBlocks);
	virtual ~ModeSelector();
};

#endif /* SRC_MODESELECTOR_H_ */
