/**
 * ScriptVariable.h
 *
 *  Created on: Apr 27, 2015
 *      Author: schartz
 */

#ifndef SCRIPTVARIABLE_H_
#define SCRIPTVARIABLE_H_


#include <iostream>
#include <sstream>

#include "../ScriptError.h"
#include "StackData.h"

using namespace std;


enum RegisteredVariable{ REGISTERED_STRING, REGISTERED_DOUBLE };

class ScriptVariable {
	string name;
	string svalue;
	double dvalue;

	//when isRegisted is set, it overrides the value of everything else
	bool  isRegistered;
	void  *address;
	RegisteredVariable type;
public:
	ScriptVariable();
	ScriptVariable(string xName);
	ScriptVariable(string xName, double value);
	ScriptVariable(string xName, string value);
	ScriptVariable(string xName, RegisteredVariable type, void*  xAddress);


	string getName();
	string getStringValue();
	double getNumberValue();

	void setNumberValue(double value);
	void setStringValue(string value);
	void setFromStackData(StackData& sd);

	bool isString();
	bool isNumber();

	virtual ~ScriptVariable();
};


#endif /* SCRIPTVARIABLE_H_ */
