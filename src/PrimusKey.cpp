/*
 * PrimusKey.cpp
 *
 *  Created on: 18 Mar 2016
 *      Author: Michael
 */

#include "PrimusKey.h"

using namespace std;

PrimusKey::~PrimusKey() {
	// TODO Auto-generated destructor stub
}

PrimusKey::PrimusKey(std::string _key, int _blkCount) {
	key = _key;
	blkCount = _blkCount;
}

Key PrimusKey::getKey(int blkNum) {
}

void PrimusKey::reverseKey() {
}

unsigned char PrimusKey::getTwoKeyBitAt(Key& key, int bytePos, int bitPos) {
}

void PrimusKey::expandKey() {
}
