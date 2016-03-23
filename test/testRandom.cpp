#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
	unsigned char data[8];
	int i;
	srand((unsigned)time(NULL));
	for(i = 0; i < 8; i++) {
		data[i] = rand() % 256;
		printf("%d ", data[i]);
	}
	cout << endl;
	return 0;
}
