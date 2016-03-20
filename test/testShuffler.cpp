#include <vector>
#include <iostream>
#include <algorithm>
#include <random>
#include <string>

using namespace std;

int main() {
	string key = "Testing Key";
	long seed = 0;
	int i;
	for (i = 0; i < key.length(); i++) {
		seed += (long) key[i];
	}
	int blockCounts = 15;

	//initialize arrayContent
	vector<int> arrayToShuffle;
	for (i = 0; i < blockCounts; i++) {
		arrayToShuffle.push_back(i);
	}

	//shuffle with C++11 functions
	shuffle(arrayToShuffle.begin(), arrayToShuffle.end(), default_random_engine(seed));

	cout << "shuffled elements: ";
	for (int& x: arrayToShuffle) cout << ' ' << x;
	cout << endl;
}