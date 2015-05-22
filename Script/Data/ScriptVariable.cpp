/**
 * ScriptVariable.cpp
 *
 *  Created on: Apr 27, 2015
 *      Author: schartz
 */

#include "ScriptVariable.h"

#define NAN -3231307.6790

string ScriptVariable::getName() {
	return name;
}

string ScriptVariable::getStringValue() {
	if(!isRegistered)
		return svalue;
	else{
		if(type != REGISTERED_STRING){
			ScriptError::msg("ScriptVariable is register is not of type string, symbol -" + name);
			return "NULL";
		}else{
			string v = *(static_cast<string*>(address));
			return v;
		}
	}
}

double ScriptVariable::getNumberValue() {
	if(!isRegistered)
		return dvalue;
	else{
		if(type != REGISTERED_DOUBLE){
			ScriptError::msg("ScriptVariable is register is not of type double, symbol -" + name);
		}else{
			double v = *(static_cast<double*>(address));
			return v;
		}
	}
	return 0;
}


ScriptVariable::ScriptVariable(){
	svalue = "null";
	dvalue = NAN;
	name   = ".invalid.null.initialize.";
	isRegistered= false;
	address = NULL;
}
ScriptVariable::ScriptVariable(string xName, double value) {
	svalue = "null";
	dvalue = value;
	name   = xName;
	isRegistered =false;
	address = NULL;
}

ScriptVariable::ScriptVariable(string xName, string value) {
	svalue = value;
	dvalue = NAN;
	name   = xName;
	isRegistered =false;
	address = NULL;
}
ScriptVariable::ScriptVariable(string xName, RegisteredVariable xType, void* xAddress) {
	svalue = "NULL";
	dvalue = NAN;
	name   = xName;
	isRegistered = true;
	address = xAddress;
	type = xType;
}
ScriptVariable::ScriptVariable(string xName) {
	svalue = "NULL";
	dvalue = NAN;
	name   = xName;
	isRegistered = false;
	address = NULL;

}


bool ScriptVariable::isString() {
	if(!isRegistered){
		if(svalue != "null"){
			return true;
		}else
			return false;
	} else{
		if(type == REGISTERED_STRING)
			return true;
		else
			return false;
	}
}

bool ScriptVariable::isNumber() {
	if(!isRegistered){
		if(dvalue != NAN){
			return true;
		}else
			return false;
	}else{
		if(type == REGISTERED_DOUBLE)
			return true;
		else
			return false;
	}
}


void ScriptVariable::setNumberValue(double xValue) {
	svalue = "NULL";

	if(!isRegistered){
		dvalue = xValue;
	}else{
		if(type != REGISTERED_DOUBLE){
			ScriptError::msg("script variable is registered but can only accept double value");
		}else{
			double* v = static_cast<double*>(address);
			*v = xValue;
		}
	}
}

void ScriptVariable::setStringValue(string xValue) {
	dvalue = NAN;

	if(!isRegistered){
		svalue = xValue;
	}else{
		if(type != REGISTERED_STRING){
			ScriptError::msg("script variable is registered but can only accept double value");
		}else{
			string* s = static_cast<string*>(address);
			*s = xValue;
		}
	}
}


void ScriptVariable::setFromStackData(StackData& sd) {
	if(sd.isNumber()) {
		this->setNumberValue(sd.getNumber());
	} else {
		this->setStringValue(sd.getString());
	}
}


ScriptVariable::~ScriptVariable() {

}
