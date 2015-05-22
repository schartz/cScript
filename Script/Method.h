/**
 * Method.h
 *
 *  Created on: May 1, 2015
 *      Author: schartz
 */

#ifndef METHOD_H_
#define METHOD_H_

#include "Data/ScriptVariable.h"
#include <vector>

using namespace std;
class Method {
	vector<ScriptVariable> var;
	int retAddress;
public:
	Method();
	Method(int xRetAddress);
	virtual ~Method();

	void addVariable(string name, string value);
	void addVariable(string name, double value);
	void addVariable(string name);
	int getReturnAddress();

	ScriptVariable *getVariable(string name);
};

#endif /* METHOD_H_ */
