/*
 * testStruct.cpp
 *
 *  Created on: 19 Mar 2016
 *      Author: Michael
 */

#include <iostream>

using namespace std;

typedef struct {
	unsigned char byte[8];
} Block;

int main() {
	unsigned char data[64];
	int i;
	char val;
	val = 'A';
	for(i = 0; i < 64; i++) {
		data[i] =  val;
		val++;
	}
	//data initialized, now reinterpreting for struct
	Block *blk;
	Block *blk2;
	Block cpyBlk;
	blk =  (Block*) data;
	blk2 = blk + 1;
	cpyBlk = *(blk);

	cpyBlk.byte[7] = 'x';

	cout << "Original Data: " << endl;
	for(i = 0; i < 64; i++) {
		cout << data[i] << " ";
	}
	cout << endl;

	cout << "Blk1 data: " << endl;
	for (i = 0; i < sizeof(Block); i++) {
		cout << blk->byte[i] << " ";
	}
	cout << endl;

	cout << "Blk2 data: " << endl;
		for (i = 0; i < sizeof(Block); i++) {
			cout << blk2->byte[i] << " ";
		}
	cout << endl;

	cout << "cpyBlk data: " << endl;
			for (i = 0; i < sizeof(Block); i++) {
				cout << cpyBlk.byte[i] << " ";
			}
	cout << endl;
	return 0;
}
