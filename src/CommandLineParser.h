/*
 * CommandLineParser.h
 *
 *  Created on: 30 Jan 2016
 *      Author: Michael
 */

#ifndef COMMANDLINEPARSER_H_
#define COMMANDLINEPARSER_H_

#include <getopt.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>

class CommandLineParser {
public:

	bool ENCRYPT_FLAG;
	bool DECRYPT_FLAG;
	bool BINARY_MODE;
	char* INPUT_FILE;
	char* OUTPUT_FILE;
	char* OPT_ALGO;
	char* OPT_OUTPUT_FORMAT;
	char* KEY;

	const char* OUTPUT_FMT_NORMAL;
	const char* OUTPUT_FMT_NOSPACE;
	const char* OUTPUT_FMT_FIVE;

	const char* ALGO_VIG_STD;
	const char* ALGO_VIG_EXT;
	const char* ALGO_PLAYFAIR;

	CommandLineParser();
	bool PARSE_PARAM(int argc, char **argv);
	bool CHECK_PARAM();
	void PRINT_HELP(char *exeName);
};
#endif /* COMMANDLINEPARSER_H_ */
