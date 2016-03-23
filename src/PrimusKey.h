/*
 * PrimusKey.h
 *
 *  Created on: 18 Mar 2016
 *      Author: Michael
 */

#ifndef SRC_PRIMUSKEY_H_
#define SRC_PRIMUSKEY_H_

#include <vector>
#include <string>
#include <algorithm>

typedef struct {
	unsigned char key[8]; // Key for 1 block length is 64 bit
} Key;

unsigned char getTwoKeyBitAt(Key &key, int bytePos, int bitPos);

class PrimusKey {
public:
	PrimusKey(std::string _key, int _blkCount);
	Key getKey(int blkNum);

private:
	void expandKey();
	std::vector<Key> keyList; //its final length should be equal to blocks count
	std::string key;
	int blkCount;

};


#endif /* SRC_PRIMUSKEY_H_ */
