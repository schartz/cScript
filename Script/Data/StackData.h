/**
 * StackData.h
 *
 *  Created on: Apr 27, 2015
 *      Author: schartz
 */

#ifndef STACKDATA_H_
#define STACKDATA_H_

#include <iostream>
#include <sstream>

using namespace std;

class StackData {
	string svalue;
	double dvalue;

public:
	StackData(string value);
	StackData(double value);


	bool isString();
	bool isNumber();

	double getNumber();
	string numberValueToString();
	string getString();

	void render();
	virtual ~StackData();
};

#endif /* STACKDATA_H_ */
