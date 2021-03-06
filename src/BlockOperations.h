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
unsigned char GetFirstTwoBits (Block *blk);
void ModifyLastTwoBits (Block *blk, unsigned char val);
void ModifyFirstTwoBits (Block *blk, unsigned char val);
void CircularShiftLeft (Block *blk);
void CircularShiftRight (Block *blk);

void XorEntireBlock(Block *targetBlock, Block withBlock);

#endif /* SRC_BLOCKOPERATIONS_H_ */
