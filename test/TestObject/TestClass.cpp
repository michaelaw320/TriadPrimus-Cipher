/*
 * TestClass.cpp
 *
 *  Created on: 19 Mar 2016
 *      Author: Michael
 */

#include "TestClass.h"

using namespace std;

TestClass::TestClass() {
	// TODO Auto-generated constructor stub
	//generate vector members
	theVec.push_back("ASD");
	theVec.push_back("DEF");
	theVec.insert(theVec.begin(), "ZAQ");
	theVec.push_back("GHI");
}

TestClass::~TestClass() {
	// TODO Auto-generated destructor stub
}

vector<string>* TestClass::getPtrToVec() {
	return &theVec;
}

vector<string> TestClass::getVec() {
	return theVec;
}

void TestClass::printContent() {
	cout << "Print from class: ";
	int i;
	for (i = 0; i < theVec.size(); i++) {
		cout << theVec.at(i) << " ; ";
	}
	cout << endl;
}
