#include <iostream>

using namespace std;

typedef struct {
	unsigned char key[8]; // Key for 1 block length is 64 bit
} Key;

int main() {
	Key currentKey;
	currentKey.key[0] = 'A';
	currentKey.key[1] = 'B';
	currentKey.key[2] = 'C';
	currentKey.key[3] = 'D';
	currentKey.key[4] = 'E';
	currentKey.key[5] = 'F';
	currentKey.key[6] = 'G';
	currentKey.key[7] = 'H';

	int i,j;
	j = 7;
	for (i = 0; i < 3; i++) {
		unsigned char temp;
		temp = currentKey.key[i];
		currentKey.key[i] = currentKey.key[j];
		currentKey.key[j] = temp;
		j--;
	}

	for (i = 0; i < 8; i++) {
		cout << currentKey.key[i] << " ";
	}
	cout << endl;
	return 0;
}
