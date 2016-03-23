#include <iostream>

using namespace std;

unsigned char getTwoBits(unsigned long long subkey, int bitPos) {
	unsigned char ret = 0;
	unsigned char mask = 0x3;
	unsigned long long tmp = subkey;
	tmp = tmp & ((unsigned long long) mask << (62-bitPos));
	tmp =  (tmp >> (62-bitPos)) & mask;
	ret = (unsigned char) tmp;
	printf("Subkey: %llx ; BitPos: %d;TwoBits: %x\n", subkey,bitPos, ret);
	return ret;
}

int main() {
	unsigned long long value = 0x656BABAAB56D4D55LL;
	int i;
	for(i = 0; i < 64; i+=2) {
	unsigned char bits = getTwoBits(value, i);
	}

	return 0;
}
