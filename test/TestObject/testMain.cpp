/*
 * testMain.cpp
 *
 *  Created on: 19 Mar 2016
 *      Author: Michael
 */

#include "TestClass.h"

#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

void printer(string el) {
	cout << el << " ; ";
}

int main() {
	TestClass test;
	cout << "Original Value: ";
	test.printContent();
	vector<string> isItCopy;
	vector<string>* ptrToVec;
	ptrToVec = test.getPtrToVec();
	isItCopy = test.getVec();
	ptrToVec->push_back("ME POINTER");
	isItCopy.push_back("COPY?");
	cout << "Pointer: ";
	for_each(ptrToVec->begin(), ptrToVec->end(), printer);
	cout << endl;
	cout << "Copy?: ";
	for_each(isItCopy.begin(), isItCopy.end(), printer);
	cout << endl;
	cout << "Class final value: ";
	test.printContent();
	return 0;
}
