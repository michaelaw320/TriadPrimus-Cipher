/*
 * CipherAlgorithms.cpp
 *
 *  Created on: 1 Feb 2016
 *      Author: Michael
 */

#include "CipherAlgorithms.h"

using namespace std;

CipherAlgorithms::CipherAlgorithms() {

}

CipherAlgorithms::~CipherAlgorithms() {
}

void CipherAlgorithms::setPlainText(char* data, int len) {
	plainText = new char[len];
	memcpy(plainText, data, len);
	plainTextLen = len;
	plainText[len] = 0;
}

char* CipherAlgorithms::getCipherText() {
	return cipherText;
}
