/**
 * ScriptError.cpp
 *
 *  Created on: Apr 30, 2015
 *      Author: schartz
 */

#include "ScriptError.h"

ScriptError::ScriptError() {
	// TODO Auto-generated constructor stub

}

void ScriptError::msg(string event) {
	cout << "ScriptRuntimeError: " << event << endl;
}

ScriptError::~ScriptError() {
	// TODO Auto-generated destructor stub
}

