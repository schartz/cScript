/**
 * ScriptConsole.cpp
 *
 *  Created on: May 8, 2015
 *      Author: schartz
 */

#include "ScriptConsole.h"

ScriptConsole::ScriptConsole() {
	// TODO Auto-generated constructor stub

}

/**
 * Write to the console
 * @param msg
 */
void ScriptConsole::print(string msg) {
	cout << ">>"<< msg <<endl;
}

string ScriptConsole::toString(double number) {
	stringstream ss;
	ss << number;
	return ss.str();
}

ScriptConsole::~ScriptConsole() {
	// TODO Auto-generated destructor stub
}

