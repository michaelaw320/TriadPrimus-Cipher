/*
 * TriadPrimus.cpp
 *
 *  Created on: 17 Mar 2016
 *      Author: Michael
 */

#include "TriadPrimus.h"

TriadPrimus::TriadPrimus() {
	// TODO Auto-generated constructor stub

}

TriadPrimus::~TriadPrimus() {
	// TODO Auto-generated destructor stub
}

//ntar algonya
/**
 * For each block do
 * GetLastTwoBits(&blk);
 * di XOR sama bit kunci
 * ModifyLastTwoBits(&blk, xored value);
 * PrimusShift(&blk);
 */
