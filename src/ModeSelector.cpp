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
	rounds = 32;
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
	IV = ptrToBlock->at(0);
	//Erase the IV from block
	ptrToBlock->erase(ptrToBlock->begin());
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
	TriadPrimus E(rounds);
	PrimusKey K(key, ptrToBlock->size());
	for (i = 0; i < ptrToBlock->size(); i++) {
		// Ciphertext = E(K, Block Plaintext)
		Block plaintext = ptrToBlock->at(i);
		Block ciphertext =  E.encrypt(plaintext, K.getKey(i));
		ptrToBlock->at(i) = ciphertext;

	}
}

void ModeSelector::ECBDecrypt() {
	int i;
	TriadPrimus D(rounds);
	PrimusKey K(key, ptrToBlock->size());
	//K.reverseKey();
	for (i = 0; i < ptrToBlock->size(); i++) {
		// Plaintext = D(K, Block ciphertext)
		Block ciphertext = ptrToBlock->at(i);
		Block plaintext =  D.decrypt(ciphertext, K.getKey(i));
		ptrToBlock->at(i) = plaintext;
	}
}

void ModeSelector::CBCEncrypt() {
	int i;
	TriadPrimus E(rounds);
	PrimusKey K(key, ptrToBlock->size());
	Block prevCipher;
	prevCipher = IV;

	for (i = 0; i < ptrToBlock->size(); i++) {
		//First block is to be xored with IV
		//XorEntireBlock(&ptrToBlock[i], prevCipher);
		// Ciphertext = E(K, Block plaintext)
		// prevCipher = cipherText, repeat


		Block currentBlock = ptrToBlock->at(i);
		XorEntireBlock(&currentBlock, prevCipher);
		Block ciphertext = E.encrypt(currentBlock, K.getKey(i));
		ptrToBlock->at(i) = ciphertext;
		prevCipher = ciphertext;
	}

	//last: put the IV block in front of the blocks
	ptrToBlock->insert(ptrToBlock->begin(), IV);
}

void ModeSelector::CBCDecrypt() {
	int i;
	TriadPrimus D(rounds);
	PrimusKey K(key, ptrToBlock->size());
	Block prevCipher;
	prevCipher = IV;

	for (i = 0; i < ptrToBlock->size(); i++) {
		//Plaintext = D(K, Block ciphertext)
		//XorEntireBlock(ptrToBlock[i], prevPlaintext);
		// prevPlaintext = ptrToBlock[i];
		Block currentBlock = ptrToBlock->at(i);
		Block plaintext = D.decrypt(currentBlock, K.getKey(i));
		XorEntireBlock(&plaintext, prevCipher);
		ptrToBlock->at(i) = plaintext;
		prevCipher = currentBlock;


	}
}

void ModeSelector::CFBEncrypt() {
}

void ModeSelector::CFBDecrypt() {
}

