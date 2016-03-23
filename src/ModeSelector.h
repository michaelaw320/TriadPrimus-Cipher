/*
 * ModeSelector.h
 *
 *  Created on: 17 Mar 2016
 *      Author: Michael
 */

/**
 * Content	: Main Algorithm for ECB, CBC, and CFB
 */

#ifndef SRC_MODESELECTOR_H_
#define SRC_MODESELECTOR_H_

#include "Block.h"
#include "PrimusKey.h"
#include "BlockOperations.h"
#include "TriadPrimus.h"
#include <vector>
#include <string>

class ModeSelector {
public:
	ModeSelector(bool _isEncryptMode, std::string _key, std::vector<Block> *ptrToBlk, int _rounds);
	virtual ~ModeSelector();
	void ECB();
	void CBC(Block _IV);
	void CBC();
	void CFB();
private:
	void ECBEncrypt();
	void ECBDecrypt();
	void CBCEncrypt();
	void CBCDecrypt();
	void CFBEncrypt();
	void CFBDecrypt();
	bool isEncryptMode;
	std::string key;
	std::vector<Block> *ptrToBlock;
	Block IV;
	int rounds;
};

#endif /* SRC_MODESELECTOR_H_ */
