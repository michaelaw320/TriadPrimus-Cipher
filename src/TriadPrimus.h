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
#include <vector>
#include <string>

class TriadPrimus {
public:
	TriadPrimus(int _rounds);
	virtual ~TriadPrimus();
	Block encrypt(Block plainBlock, Key currentKey);
	Block decrypt(Block cipherBlock, Key currentKey);
private:
	std::vector<unsigned long long> generateSubKeys(Key currentKey);
	unsigned long long llFromByte(unsigned char* byte);
	unsigned char getTwoBits(unsigned long long subkey, int bitPos);
	void SwitchTwoBitPos(unsigned char *bits);
	int rounds;
};

#endif /* SRC_TRIADPRIMUS_H_ */
