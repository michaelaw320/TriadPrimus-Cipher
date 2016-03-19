/*
 * TriadPrimusCipher.cpp
 *
 *  Created on: 17 Mar 2016
 *      Author: Michael
 */

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include "CommandLineParser.h"
#include "IOUtil.h"
#include "Preprocessor.h"
#include "Block.h"
#include "TriadPrimus.h"
#include "NewGeneration.h"
#include "ModeSelector.h"
using namespace std;

int main(int argc, char **argv) {
	//Command line parameter checking
	CommandLineParser parser;
	if (argc <= 1) {
		cout << "Run " << argv[0] << " -h for help" << endl;
		return 1;
	} else {
		if (!parser.PARSE_PARAM(argc, argv)) {
			return 1;
		}
	}
	//Passed parameter checking, begin main routine
	IOUtil utils;

	//Load data
	if (stricmp(parser.INPUT_FILE, "stdin") == 0) {
		utils.readFromStdin(parser.ENCRYPT_FLAG);
	} else {
		try {
			utils.readFromFile(parser.INPUT_FILE, parser.BINARY_MODE);
		} catch (char const* e) {
			cerr << e << endl;
			return 1;
		}
	}
	//Add main code for cipher here
	unsigned char* ptrToData = (unsigned char*) utils.getInputData();
	int inputDataLen = utils.getInputLen();
	string key(parser.KEY);

	Preprocessor dataProcessor(ptrToData, inputDataLen);
	vector<Block>* ptrToBlocks = dataProcessor.getPtrToBlocks();

	unsigned char* outputData;
	if(parser.ENCRYPT_FLAG) {
		//Encrypt Mode
		if(stricmp(parser.OPT_MODE, parser.MODE_ECB)) {

		}
		//last stage, scramble before write
		NewGeneration generation(key, ptrToBlocks);
		generation.scramble();

		dataProcessor.generateOutput(false);
	} else {
		//Decrypt Mode
		//Descramble before doing anything
		NewGeneration generation(key, ptrToBlocks);
		generation.descramble();

		dataProcessor.generateOutput(true);
	}


	outputData = dataProcessor.getOutputData();

	//Set output data
	utils.setOutputData((char*) outputData);

	//Output data
	if (stricmp(parser.OUTPUT_FILE, "stdout") == 0) {
		utils.outputStdout(parser.ENCRYPT_FLAG);
	} else {
		try {
			utils.outputFile(parser.OUTPUT_FILE, parser.BINARY_MODE);
		} catch (char const* e) {
			cerr << e << endl;
			return 1;
		}
	}

	return 0;
}
