/*
 * CommandLineParser.cpp
 *
 *  Created on: 30 Jan 2016
 *      Author: Michael
 */

#include "CommandLineParser.h"

CommandLineParser::CommandLineParser() {
	ENCRYPT_FLAG = false;
	DECRYPT_FLAG = false;
	BINARY_MODE = false;
	INPUT_FILE = NULL;
	OUTPUT_FILE = NULL;
	OPT_MODE = NULL;
	KEY = NULL;

	MODE_ECB = "ECB";
	MODE_CBC = "CBC";
	MODE_CFB = "CFB";
}

bool CommandLineParser::PARSE_PARAM(int argc, char **argv) {
	int c;
	while (1) {
		static struct option long_options[] = {
				{ "encrypt", no_argument, 0, 'e' },
				{ "decrypt", no_argument, 0, 'd' },
				{ "binary", no_argument, 0, 'b' },
				{ "help", no_argument, 0, 'h' },
				{ "input", required_argument, 0, 'i' },
				{ "output", required_argument, 0, 'o' },
				{ "mode", required_argument, 0, 'm' },
				{ "key", required_argument, 0, 'k' },
				{ 0, 0, 0, 0 } };
		/* getopt_long stores the option index here. */
		int option_index = 0;

		c = getopt_long(argc, argv, "edbhi:o:m:f:k:", long_options,
				&option_index);

		/* Detect the end of the options. */
		if (c == -1)
			break;

		switch (c) {

		case 'e':
			ENCRYPT_FLAG = true;
			break;

		case 'd':
			DECRYPT_FLAG = true;
			break;

		case 'b':
			BINARY_MODE = true;
			break;

		case 'h':
			CommandLineParser::PRINT_HELP(argv[0]);
			break;

		case 'i':
			INPUT_FILE = optarg;
			break;

		case 'o':
			OUTPUT_FILE = optarg;
			break;

		case 'm':
			OPT_MODE = optarg;
			break;

		case 'k':
			KEY = optarg;
			break;

		case '?':
			/* getopt_long already printed an error message. */
			return false;

		default:
			abort();
		}
	}
	if (CommandLineParser::CHECK_PARAM()) {
		return true;
	} else {
		return false;
	}
}

bool CommandLineParser::CHECK_PARAM() {
	if (ENCRYPT_FLAG == true && DECRYPT_FLAG == true) {
		std::cerr << "Please select one mode only" << std::endl;
		return false;
	} else if (ENCRYPT_FLAG == false && DECRYPT_FLAG == false) {
		std::cerr << "Please select mode" << std::endl;
		return false;
	} else if (INPUT_FILE == NULL) {
		std::cerr << "Please specify input" << std::endl;
		return false;
	} else if (OUTPUT_FILE == NULL) {
		std::cerr << "Please specify output" << std::endl;
		return false;
	} else if (stricmp(OPT_MODE, MODE_ECB) != 0
			&& stricmp(OPT_MODE, MODE_CBC) != 0
			&& stricmp(OPT_MODE, MODE_CFB) != 0) {
		std::cerr << "Valid algorithm option is ECB or CBC or CFB"
				<< std::endl;
		return false;
	} else if (KEY == NULL) {
		std::cerr << "Please specify key" << std::endl;
		return false;
	}
	return true;
}

void CommandLineParser::PRINT_HELP(char *exeName) {
	printf("--HELP--\n");
	printf("USAGE: %s\n", exeName);
	printf("--help, -h \t: Print this help\n");
	printf("--encrypt, -e \t: Encrypt Mode\n");
	printf("--decrypt, -d \t: Decrypt Mode\n");
	printf("--binary, -b \t: Operates in binary mode, algo must be CBC\n");
	printf("--input <input_file>, -i <input_file> : Specify input file\n");
	printf("\tUse \"stdin\" for keyboard input\n\n");
	printf("--output <output_file>, -o <output_file> : Specify input file\n");
	printf("\tUse \"stdout\" for screen output\n\n");
	printf("--key <string>, -k <string> : Key for encryption/decryption (max 25 chars)\n\n");
	printf("--mode <string>, -m <string> : Available mode: ECB, CBC, CFB\n");
	printf("\tECB  : Electronic Code Book mode\n");
	printf("\tCBC  : Cipher Block Chaining mode\n");
	printf("\tCFB : CFB-8bit mode\n\n");

	printf("--****--\n");
}

