/*
 * IOUtil.h
 *
 *  Created on: 1 Feb 2016
 *      Author: Michael
 */

#ifndef IOUTIL_H_
#define IOUTIL_H_

#include <cstring>
#include <string>
#include <iostream>
#include <fstream>

class IOUtil {
public:
	IOUtil();
	virtual ~IOUtil();
	char* getInputData();
	int getInputLen();
	void setOutputLen(int len);
	void setOutputData(char* data);
	void readFromStdin(bool isEncrypt);
	void readFromFile(char* filename, bool isBinaryMode);
	void outputStdout(bool isEncrypt);
	void outputFile(char* filename, bool isBinaryMode);
private:
	char* inputData;
	int inputLen;
	char* outputData;
	int outputLen;
};

#endif /* IOUTIL_H_ */
