#include <iostream>

using namespace std;

void SwitchTwoBitPos(unsigned char *bits) {
	unsigned char tmp = *bits;
	unsigned char tmp2 = *bits;
	tmp = tmp & 0x2; //get the "MSB"
	tmp = tmp >> 1; //move to back
	*bits = ((tmp2 << 1 ) & 0x3) | tmp;
}

int main() {
	unsigned char dummy = 0x2;
	printf("Orig val: %x\n", dummy);
	SwitchTwoBitPos(&dummy);
	printf("Output val: %x\n", dummy);
	return 0;
}
