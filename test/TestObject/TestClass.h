/*
 * TestClass.h
 *
 *  Created on: 19 Mar 2016
 *      Author: Michael
 */

#ifndef TEST_TESTOBJECT_TESTCLASS_H_
#define TEST_TESTOBJECT_TESTCLASS_H_

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class TestClass {
public:
	TestClass();
	virtual ~TestClass();
	vector<string>* getPtrToVec();
	vector<string> getVec();
	void printContent();
private:
	vector<string> theVec;
};

#endif /* TEST_TESTOBJECT_TESTCLASS_H_ */
