/*
 * BlockOperations.h
 *
 *  Created on: 17 Mar 2016
 *      Author: Michael
 */

/**
 * Operates as global function to conserve memory, C like operations
 */

#ifndef SRC_BLOCKOPERATIONS_H_
#define SRC_BLOCKOPERATIONS_H_

#include "Block.h"

unsigned char GetLastTwoBits (Block *blk);
void ModifyLastTwoBits (Block *blk, unsigned char val);
void PrimusShift (Block *blk);

#endif /* SRC_BLOCKOPERATIONS_H_ */
