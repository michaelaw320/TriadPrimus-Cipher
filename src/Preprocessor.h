/*
 * Preprocessor.h
 *
 *  Created on: 17 Mar 2016
 *      Author: Michael
 */

/**
 * Content	: Preprocessing routine transforms loaded data to blocks v.v.
 */

#ifndef SRC_PREPROCESSOR_H_
#define SRC_PREPROCESSOR_H_

class Preprocessor {
public:
	Preprocessor(unsigned char* inputData, int inputLen);
	virtual ~Preprocessor();
	std::vector<Block>* getPtrToBlocks();
	void generateOutput();
	unsigned char* getOutputData();
	int getOutputLen();
private:
	void copyToBlock(unsigned char* inputData,int inputLen);
	void doPadding();
	void removePadding();
	unsigned char* inputData;
	int inputLen;
	unsigned char* output;
	int outputLen;
	std::vector<Block> blocks;
};

#endif /* SRC_PREPROCESSOR_H_ */
