/*
 * TriadPrimus.cpp
 *
 *  Created on: 17 Mar 2016
 *      Author: Michael
 */

#include "TriadPrimus.h"

using namespace std;

TriadPrimus::TriadPrimus(int _rounds) {
	// TODO Auto-generated constructor stub
	rounds = _rounds;
}

TriadPrimus::~TriadPrimus() {
	// TODO Auto-generated destructor stub
}

Block TriadPrimus::encrypt(Block plainBlock, Key currentKey) {
	//Dummy encryption
	Block ret;
	unsigned char leftBits, rightBits, keyBits;
	ret = plainBlock;
	int i,j,n;
	vector<unsigned long long> subkeys = generateSubKeys(currentKey);
	for(i=0; i < rounds; i++) {
		unsigned long long currentSubkey = subkeys[i];
		j = 0;
		for(n=0; n < 32; n++) { //do 32 times
			keyBits = getTwoBits(currentSubkey, j);

			rightBits = GetLastTwoBits(&ret);

			rightBits ^= keyBits;

			leftBits = GetFirstTwoBits(&ret);
			SwitchTwoBitPos(&leftBits);

			leftBits ^= rightBits;
			SwitchTwoBitPos(&leftBits);
			ModifyFirstTwoBits(&ret, leftBits);

			CircularShiftLeft(&ret);
			j+=2;
		}
	}
	return ret;
}

Block TriadPrimus::decrypt(Block cipherBlock, Key currentKey) {
	//Dummy decryption
	Block ret;
		unsigned char leftBits, rightBits, keyBits;
		ret = cipherBlock;
		int i,j,n;
		vector<unsigned long long> subkeys = generateSubKeys(currentKey);
		reverse(subkeys.begin(), subkeys.end());
		for(i=0; i < rounds; i++) {
			unsigned long long currentSubkey = subkeys[i];
			j = 62;
			for(n=0; n < 32; n++) { //do 32 times
				keyBits = getTwoBits(currentSubkey, j);

				CircularShiftRight(&ret);

				leftBits = GetFirstTwoBits(&ret);
				SwitchTwoBitPos(&leftBits);

				rightBits = GetLastTwoBits(&ret);
				rightBits ^= keyBits;

				leftBits ^= rightBits;
				SwitchTwoBitPos(&leftBits);
				ModifyFirstTwoBits(&ret, leftBits);

				j-=2;
			}
		}
		return ret;
}
#include <iostream>
std::vector<unsigned long long> TriadPrimus::generateSubKeys(Key currentKey) {
	unsigned long seed = 0;
	int i,n;
	vector<unsigned long long> subkeys;
	for (i = 0; i < 8; i++) {
		seed += (unsigned long) currentKey.key[i];
	}
	unsigned char data[8];
	srand((unsigned)seed);
	n = rounds;
	for(n = 0; n < rounds; n++) {
		for(i = 0; i < 8; i++) {
			data[i] = rand() % 256;
		}
		unsigned long long subkey = llFromByte(data);
		subkeys.push_back(subkey);
	}
	return subkeys;
}

unsigned long long TriadPrimus::llFromByte(unsigned char* byte) {
	int i;
	unsigned long long subkey = 0;
	for (i = 0; i < 8; i++) {
		subkey |= ((unsigned long long) byte[i]) << (64-8*(i+1));
	}
	return subkey;
}

unsigned char TriadPrimus::getTwoBits(unsigned long long subkey, int bitPos) {
	unsigned char ret = 0;
	unsigned char mask = 0x3;
	unsigned long long tmp = subkey;
	tmp = tmp & ((unsigned long long) mask << (62-bitPos));
	tmp =  (tmp >> (62-bitPos)) & mask;
	ret = (unsigned char) tmp;
	return ret;
}

void TriadPrimus::SwitchTwoBitPos(unsigned char *bits) {
	unsigned char tmp = *bits;
	unsigned char tmp2 = *bits;
	tmp = tmp & 0x2; //get the "MSB"
	tmp = tmp >> 1; //move to back
	*bits = ((tmp2 << 1 ) & 0x3) | tmp;
}

//ntar algonya
/**
 * For each block do
 * GetLastTwoBits(&blk);
 * di XOR sama bit kunci
 * ModifyLastTwoBits(&blk, xored value);
 * PrimusShift(&blk);
 */
