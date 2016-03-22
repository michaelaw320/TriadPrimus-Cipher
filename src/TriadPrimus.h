/*
 * TriadPrimus.h
 *
 *  Created on: 17 Mar 2016
 *      Author: Michael
 */

/**
 * Content	: Universal Encryption/Decryption Function
 * Modified Feistel Network (Thorp Shuffle)
 */

#ifndef SRC_TRIADPRIMUS_H_
#define SRC_TRIADPRIMUS_H_

#include "Block.h"
#include "BlockOperations.h"
#include "PrimusKey.h"

class TriadPrimus {
public:
	TriadPrimus(int _rounds);
	virtual ~TriadPrimus();
	void encrypt(Block *blockToOperate, Key currentKey);
	void decrypt(Block *blockToOperate, Key currentKey);
private:
	int rounds;
};

#endif /* SRC_TRIADPRIMUS_H_ */
