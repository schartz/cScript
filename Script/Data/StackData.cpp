/**
 * StackData.cpp
 *
 *  Created on: Apr 27, 2015
 *      Author: schartz
 */

#include "StackData.h"

#define NAN -3231307.6790
StackData::StackData(string value) {
	svalue = value;
	dvalue = NAN;
}

StackData::StackData(double value) {
	dvalue = value;
	svalue = "null";
}

StackData::~StackData() {

}

bool StackData::isNumber() {
	if(dvalue != NAN){
		return true;
	}else
		return false;
}
bool StackData::isString() {
	if(dvalue == NAN){
		return true;
	}else
		return false;
}

double StackData::getNumber() {
	return dvalue;
}
void StackData::render(){
	if(isNumber()){
		cout << getNumber();
	}else
		cout << getString();
}
string StackData::getString() {
	return svalue;
}

string StackData::numberValueToString() {
	stringstream s;
	s << dvalue;
	return s.str();
}



