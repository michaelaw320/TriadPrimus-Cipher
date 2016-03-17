/*
 * CipherAlgorithms.h
 *
 *  Created on: 1 Feb 2016
 *      Author: Michael
 */

#ifndef CIPHERALGORITHMS_H_
#define CIPHERALGORITHMS_H_

#include <cstring>
#include <string>
#include <iostream>

class CipherAlgorithms {
public:
	CipherAlgorithms();
	virtual ~CipherAlgorithms();
	void setPlainText(char* data, int len);
	char* getCipherText();
private:
	char* plainText;
	int plainTextLen;
	char* cipherText;
};

#endif /* CIPHERALGORITHMS_H_ */
