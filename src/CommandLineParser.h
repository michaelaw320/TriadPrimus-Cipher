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
#include <cstdlib>

class CommandLineParser {
public:

	bool ENCRYPT_FLAG;
	bool DECRYPT_FLAG;
	bool BINARY_MODE;
	char* INPUT_FILE;
	char* OUTPUT_FILE;
	char* OPT_MODE;
	char* KEY;
	int PRIMUS_ROUNDS;

	const char* MODE_ECB;
	const char* MODE_CBC;
	const char* MODE_CFB;

	CommandLineParser();
	bool PARSE_PARAM(int argc, char **argv);
	bool CHECK_PARAM();
	void PRINT_HELP(char *exeName);
};
#endif /* COMMANDLINEPARSER_H_ */
