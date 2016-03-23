#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	string key = "TESTKEY";
	long seed = 0;
	int i;
	for (i = 0; i < key.length(); i++) {
		seed += (long) key[i];
	}

	//initialize arrayContent
	vector<unsigned char> arrayToShuffle;
	for (i = 0; i < 256; i++) {
		arrayToShuffle.push_back(i);
	}

	//shuffle with C++11 functions
	shuffle(arrayToShuffle.begin(), arrayToShuffle.end(), default_random_engine(seed));

	for(unsigned char& x: arrayToShuffle) {
		printf("%x ", x);
	}
	printf("\n %x", arrayToShuffle.at(255));
	return 0;
}
