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
	int i;
	for(i=0; i < 8; i++) {
		ret.byte[i] = plainBlock.byte[i] ^ currentKey.key[i];
	}
	return ret;
}

Block TriadPrimus::decrypt(Block cipherBlock, Key currentKey) {
	//Dummy decryption
	Block ret;
	int i;
	for(i=0; i < 8; i++) {
		ret.byte[i] = cipherBlock.byte[i] ^ currentKey.key[i];
	}
	return ret;
}
//ntar algonya
/**
 * For each block do
 * GetLastTwoBits(&blk);
 * di XOR sama bit kunci
 * ModifyLastTwoBits(&blk, xored value);
 * PrimusShift(&blk);
 */
