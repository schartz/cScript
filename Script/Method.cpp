/**
 * Method.cpp
 *
 *  Created on: May 1, 2015
 *      Author: schartz
 */

#include "Method.h"

Method::Method() {
	var.reserve(4);
}

Method::~Method() {
	var.clear();
}

void Method::addVariable(string name, string value) {
	ScriptVariable sv = ScriptVariable(name,value);
	var.push_back(sv);
}

void Method::addVariable(string name) {
	ScriptVariable sv = ScriptVariable(name);
	var.push_back(sv);
}

void Method::addVariable(string name, double value) {
	ScriptVariable sv = ScriptVariable(name,value);
	var.push_back(sv);
}

ScriptVariable* Method::getVariable(string name) {
	for(int i=0; i<(int)var.size(); i++){
		if(var[i].getName() == name){
			return &var[i];
		}
	}

	return NULL;
}

Method::Method(int xRetAddress) {
	var.reserve(4);
	retAddress = xRetAddress;
}

int Method::getReturnAddress() {
	return retAddress;
}




