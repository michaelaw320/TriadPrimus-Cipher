#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef struct {
	unsigned char key[8]; // Key for 1 block length is 64 bit
} Key;

int main() {
	vector<Key> keyList;
	string key =
			"TESTINGTESTINGTESTINGTESTINGTESTINGTESTINGTESTINGTESTINGTESTINGTESTINGTESTINGTESTING";
	int targetLen = 32; // assume 64 byte of data
	int currentKeyLen = key.length();
	string newKey = key;
	int i, j;
	j = 0;
	if (currentKeyLen < targetLen) {
		cout << "Current Key: " << key << endl;
		for (i = currentKeyLen; i < targetLen; i++) {
			if (j == currentKeyLen) {
				j = 0;
			}
			newKey += newKey[j];
			j++;
		}
		cout << "New expanded key: " << newKey << endl;

		for (i = 0; i < newKey.length(); i += sizeof(Key)) {
			Key k;
			for (j = 0; j < 8; j++) {
				k.key[j] = newKey[i + j];
			}
			keyList.push_back(k);
		}
		cout << "Key in blocks: " << endl;
		for (Key& key : keyList) {
			for (i = 0; i < 8; i++) {
				cout << key.key[i] << " ";
			}
			cout << endl;
		}
	} else if (currentKeyLen == targetLen) {
		for (i = 0; i < key.length(); i += sizeof(Key)) {
			Key k;
			for (j = 0; j < 8; j++) {
				k.key[j] = key[i + j];
			}
			keyList.push_back(k);
		}
	} else {
		//truncate and fit
		Key k;
		j = 0;
		for (i = 0; i < targetLen; i++) {
			k.key[j] = key[i];
			j++;
			if (j == 8) {
				keyList.push_back(k);
				j = 0;
				Key k;
			}
		}

		cout << "Key in blocks: " << endl;
		for (Key& key : keyList) {
			for (i = 0; i < 8; i++) {
				cout << key.key[i] << " ";
			}
			cout << endl;
		}
	}

	return 0;
}
