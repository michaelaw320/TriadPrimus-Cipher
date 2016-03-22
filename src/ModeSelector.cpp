/*
 * ModeSelector.cpp
 *
 *  Created on: 17 Mar 2016
 *      Author: Michael
 */

#include "ModeSelector.h"


ModeSelector::ModeSelector(bool _isEncryptMode, std::string _key, std::vector<Block>* ptrToBlk) {
	isEncryptMode = _isEncryptMode;
	key = _key;
	ptrToBlock = ptrToBlk;
}

ModeSelector::~ModeSelector() {
	// TODO Auto-generated destructor stub
}

void ModeSelector::ECB() {
	if (isEncryptMode) {
		ECBEncrypt();
	} else {
		ECBDecrypt();
	}
}

void ModeSelector::CBC(Block _IV) {
	//encrypt
	IV = _IV;
	CBCEncrypt();
}

void ModeSelector::CBC() {
	//decrypt
	IV = ptrToBlock[0];
	CBCDecrypt();
}

void ModeSelector::CFB() {
	if (isEncryptMode) {
		CFBEncrypt();
	} else {
		CFBDecrypt();
	}
}

void ModeSelector::ECBEncrypt() {
	int i;
	TriadPrimus E;
	PrimusKey K(key, ptrToBlock->size());
	for (i = 0; i < ptrToBlock->size(); i++) {
		// Ciphertext = E(K, Block Plaintext)
	}
}

void ModeSelector::ECBDecrypt() {
	int i;
	TriadPrimus D;
	PrimusKey K(key, ptrToBlock->size());
	K.reverseKey();
	for (i = 0; i < ptrToBlock->size(); i++) {
		// Plaintext = D(K, Block ciphertext)
	}
}

void ModeSelector::CBCEncrypt() {
	int i;
	TriadPrimus E;
	PrimusKey K(key, ptrToBlock->size());
	Block prevCipher;
	prevCipher = IV;
	for (i = 0; i < ptrToBlock->size(); i++) {
		//First block is to be xored with IV
		//XorEntireBlock(&ptrToBlock[i], prevCipher);
		// Ciphertext = E(K, Block plaintext)
		// prevCipher = cipherText, repeat
	}

	//last: put the IV block in front of the blocks
	ptrToBlock->insert(ptrToBlock->begin(), IV);
}

void ModeSelector::CBCDecrypt() {
	int i;
	TriadPrimus D;
	PrimusKey K(key, ptrToBlock->size());
	Block prevPlaintext;
	prevPlaintext = IV;
	for (i = 1; i < ptrToBlock->size(); i++) {
		//Plaintext = D(K, Block ciphertext)
		//XorEntireBlock(ptrToBlock[i], prevPlaintext);
		// prevPlaintext = ptrToBlock[i];
	}
	//Erase the IV from result block
	ptrToBlock->erase(ptrToBlock->begin());
}

void ModeSelector::CFBEncrypt() {
}

void ModeSelector::CFBDecrypt() {
}

