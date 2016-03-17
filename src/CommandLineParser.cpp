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
	OPT_ALGO = NULL;
	OPT_OUTPUT_FORMAT = NULL;
	KEY = NULL;
	OUTPUT_FMT_NORMAL = "normal";
	OUTPUT_FMT_NOSPACE = "wo_space";
	OUTPUT_FMT_FIVE = "five";

	ALGO_VIG_STD = "vig_std";
	ALGO_VIG_EXT = "vig_ext";
	ALGO_PLAYFAIR = "playfair";
}

bool CommandLineParser::PARSE_PARAM(int argc, char **argv) {
	int c;
	while (1) {
		static struct option long_options[] = {
				{ "encrypt", no_argument, 0, 'e' }, { "decrypt", no_argument, 0,
						'd' }, { "binary", no_argument, 0, 'b' }, { "help",
						no_argument, 0, 'h' }, { "input", required_argument, 0,
						'i' }, { "output", required_argument, 0, 'o' }, {
						"algorithm", required_argument, 0, 'a' }, { "format",
						required_argument, 0, 'f' }, { "key", required_argument,
						0, 'k' }, { 0, 0, 0, 0 } };
		/* getopt_long stores the option index here. */
		int option_index = 0;

		c = getopt_long(argc, argv, "edbhi:o:a:f:k:", long_options,
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

		case 'a':
			OPT_ALGO = optarg;
			break;

		case 'f':
			OPT_OUTPUT_FORMAT = optarg;
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
	} else if (stricmp(OPT_ALGO, ALGO_VIG_STD) != 0
			&& stricmp(OPT_ALGO, ALGO_VIG_EXT) != 0
			&& stricmp(OPT_ALGO, ALGO_PLAYFAIR) != 0) {
		std::cerr << "Valid algorithm option is vig_std or vig_ext or playfair"
				<< std::endl;
		return false;
	} else if (stricmp(OPT_OUTPUT_FORMAT, OUTPUT_FMT_NORMAL) != 0
			&& stricmp(OPT_OUTPUT_FORMAT, OUTPUT_FMT_NOSPACE) != 0
			&& stricmp(OPT_OUTPUT_FORMAT, OUTPUT_FMT_FIVE) != 0) {
		std::cerr << "Valid output format option is normal or wo_space or five"
				<< std::endl;
		return false;
	} else if (KEY == NULL) {
		std::cerr << "Please specify key" << std::endl;
		return false;
	} else if (strlen(KEY) > 25) {
		std::cerr << "Key is more than 25 characters" << std::endl;
		return false;
	} else if (BINARY_MODE) {
		OPT_ALGO = "vig_ext";
		OPT_OUTPUT_FORMAT = "normal";
	}
	return true;
}

void CommandLineParser::PRINT_HELP(char *exeName) {
	printf("--HELP--\n");
	printf("USAGE: %s\n", exeName);
	printf("--help, -h \t: Print this help\n");
	printf("--encrypt, -e \t: Encrypt Mode\n");
	printf("--decrypt, -d \t: Decrypt Mode\n");
	printf("--binary, -b \t: Operates in binary mode, algo must be vig_ext\n");
	printf("--input <input_file>, -i <input_file> : Specify input file\n");
	printf("\tUse \"stdin\" for keyboard input\n\n");
	printf("--output <output_file>, -o <output_file> : Specify input file\n");
	printf("\tUse \"stdout\" for screen output\n\n");
	printf(
			"--key <string>, -k <string> : Key for encryption/decryption (max 25 chars)\n\n");
	printf(
			"--algorithm <string>, -a <string> : Available algorithm: vig_std, vig_ext, playfair\n");
	printf("\tvig_std  : Vigenere Cipher Standard (26 Alphabets)\n");
	printf("\tvig_ext  : Vigenere Cipher Extended (256 ASCII Chars)\n");
	printf("\tplayfair : Playfair Cipher\n\n");
	printf(
			"--format <string>, -f <string> : Specify output format: normal, wo_space, five\n");
	printf("\tnormal   : Same as input\n");
	printf("\two_space : Without spaces\n");
	printf("\tfive     : Group five by five\n");
	printf("--****--\n");
}

