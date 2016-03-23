/*
 * PrimusKey.cpp
 *
 *  Created on: 18 Mar 2016
 *      Author: Michael
 */

#include "PrimusKey.h"

using namespace std;

unsigned char getTwoKeyBitAt(Key& key, int bytePos, int bitPos) {
	//bitPos: 0,2,4,6
	unsigned char currentByte = key.key[bytePos];
	unsigned char retval;
	int shiftBy = 6 - bitPos;
	unsigned char mask = 0x3 << shiftBy;
	retval = currentByte & mask;
	retval = (retval >> shiftBy) & 0x3;
	return retval;
}

PrimusKey::PrimusKey(std::string _key, int _blkCount) {
	key = _key;
	blkCount = _blkCount;
	expandKey();
}

Key PrimusKey::getKey(int blkNum) {
	return keyList[blkNum];
}

void PrimusKey::reverseKey() {
	//reverse list level
	reverse(keyList.begin(), keyList.end());
	//reverse Key block byte level
	int i,j;
	for(Key& currentKey: keyList) {
		j = 7;
		for (i = 0; i < 3; i++) {
			unsigned char temp;
			temp = currentKey.key[i];
			currentKey.key[i] = currentKey.key[j];
			currentKey.key[j] = temp;
			j--;
		}
	}
	//reverse Key block bit level
	for(Key& currentKey: keyList) {
		for(int i = 0; i < 8; i++) {
			unsigned char currentChar = currentKey.key[i];
			unsigned char ret;
			for (int j = 0; j < 8; ++j) {
				if (currentChar & (1<<j)) ret += 1;
				ret <<= 1;
			}
			currentKey.key[i] = ret;
		}
	}

}

void PrimusKey::expandKey() {
	int targetLen = blkCount*8;
	int currentKeyLen = key.length();
	string newKey = key;
	int i, j;
	j = 0;
	if (currentKeyLen < targetLen) {
		for (i = currentKeyLen; i < targetLen; i++) {
			if (j == currentKeyLen) {
				j = 0;
			}
			newKey += newKey[j];
			j++;
		}

		for (i = 0; i < newKey.length(); i += sizeof(Key)) {
			Key k;
			for (j = 0; j < 8; j++) {
				k.key[j] = newKey[i + j];
			}
			keyList.push_back(k);
		}

	} else if (currentKeyLen == targetLen) {
		for (i = 0; i < key.length(); i += sizeof(Key)) {
			Key k;
			for (j = 0; j < 8; j++) {
				k.key[j] = key[i + j];
			}
			keyList.push_back(k);
		}
	} else {
		//truncate and fit
		Key k;
		j = 0;
		for (i = 0; i < targetLen; i++) {
			k.key[j] = key[i];
			j++;
			if (j == 8) {
				keyList.push_back(k);
				j = 0;
				Key k;
			}
		}
	}
}
