/*
 * testStruct2.cpp
 *
 *  Created on: 19 Mar 2016
 *      Author: Michael
 */

#include <iostream>
#include <vector>

using namespace std;

typedef struct {
	unsigned char byte[8];
} Block;

int main() {
	unsigned char inputData[67];
	int i;
	char val;
	val = 'A';
	for(i = 0; i < 67; i++) {
		inputData[i] =  val;
		val++;
		if (val > 'z') {
			val = 'A';
		}
	}
	//data initialized, now reinterpreting for struct

	cout << "Original Data: " << endl;
	for(i = 0; i < 67; i++) {
		cout << inputData[i] << " ";
	}
	cout << endl;

	int inputLen = 67;
	vector<Block> blocks;

	int blockCounts = inputLen / 8;
	int blockRemainder = inputLen % 8;
	Block* ptrToFirstBlock = (Block*) inputData; //put beginning address of inputData, then reinterpret as block
	for(i=0; i<blockCounts; i++) {
		Block cpyBlk = *(ptrToFirstBlock + i);
		blocks.push_back(cpyBlk);
	}
	if (blockRemainder != 0) {
		//There's still some data, copy it manually then pad it
		unsigned char tmpData;
		Block lastBlk;
		for(i=0; i<blockRemainder; i++) {
			lastBlk.byte[i] = inputData[(blockCounts*8)+i];
		}
		for(i = blockRemainder; i < 8; i++) {
			lastBlk.byte[i] = 'x'; //padding
		}
		blocks.push_back(lastBlk);
	}

	cout << "Block Data: " << endl;
	int j;
	for(i = 0; i < blocks.size(); i++) {
		cout << "Block num " << i << " :" << endl;
		for(j = 0; j < 8; j++) {
			cout << blocks.at(i).byte[j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	return 0;
}
