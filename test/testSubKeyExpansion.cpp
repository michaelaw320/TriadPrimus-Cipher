#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

using namespace std;

unsigned long long llFromChar(unsigned char* data) {
	int i;
	unsigned long long subkey = 0;
	for (i = 0; i < 8; i++) {
		subkey |= ((unsigned long long) data[i]) << (64-8*(i+1));
	}
	return subkey;
}

int main() {
	string key = "Testing Key";
	int rounds = 3;
	unsigned long seed = 0;
	int i,n;
	vector<unsigned long long> subkeys;
	for (i = 0; i < key.length(); i++) {
		seed += (unsigned long) key[i];
	}
	unsigned char data[8];
	srand((unsigned)seed);
	n = rounds;
	for(n = 0; n < rounds; n++) {
		for(i = 0; i < 8; i++) {
			data[i] = rand() % 256;
			printf("%x ", data[i]);
		}
		cout << endl;
		unsigned long long subkey = llFromChar(data);
		subkeys.push_back(subkey);
	}

	for(unsigned long long x : subkeys) {
		printf("%llx ", x);
	}
	return 0;
}
