# TriadPrimus-Cipher
Proof-of-concept of proposed block cipher cryptography: Triad Primus Cipher

--HELP--
USAGE: TriadPrimus-Cipher.exe
--help, -h 	: Print this help
--encrypt, -e 	: Encrypt Mode
--decrypt, -d 	: Decrypt Mode
--input <input_file>, -i <input_file> : Specify input file
	Use "stdin" for keyboard input

--output <output_file>, -o <output_file> : Specify input file
	Use "stdout" for screen output

--key <string>, -k <string> : Key for encryption/decryption 

--rounds <integer>, -r <rounds> : Specify how many rounds for Primus Function (default: 8) 

--mode <string>, -m <string> : Available mode: ECB, CBC, CFB
	ECB  : Electronic Code Book mode
	CBC  : Cipher Block Chaining mode
	CFB : CFB-8bit mode

--****--
