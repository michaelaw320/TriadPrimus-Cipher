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

void TriadPrimus::encrypt(Block* blockToOperate, Key currentKey) {
	int i;
}

void TriadPrimus::decrypt(Block* blockToOperate, Key currentKey) {
}
//ntar algonya
/**
 * For each block do
 * GetLastTwoBits(&blk);
 * di XOR sama bit kunci
 * ModifyLastTwoBits(&blk, xored value);
 * PrimusShift(&blk);
 */
