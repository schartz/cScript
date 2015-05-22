/**
 * Stack.cpp
 *
 *  Created on: May 1, 2015
 *      Author: schartz
 */

#include "Stack.h"
#include "../ScriptError.h"

vector<StackData> Stack::stack;

Stack::Stack() {
	// TODO Auto-generated constructor stub

}

void Stack::push(double data) {
	push(StackData(data));
}

void Stack::push(string data) {

	push(StackData(data));
}

void Stack::push(StackData data) {

	stack.push_back(data);
}

void Stack::push(ScriptVariable& data) {

	//cout << "\tGoing to push variable '" << data.getName() << "' ";

	if(data.isNumber()){
		//cout << "\t" << data.getNumberValue() <<endl;
		push(data.getNumberValue());
	}else if(data.isString()){
		//cout << "\t" << data.getStringValue() <<endl;
		push(data.getStringValue());
	}
}

StackData Stack::pop() {
	if(stack.size() == 0){
		ScriptError::msg("stack is zero as vm is instructed to pop value off the stack");
		return StackData("NULL");
	}
	StackData sd = stack[stack.size()-1];	//the the last item on the stack
	stack.pop_back();	//remove the item on the stack
	return sd;			//return that data
}

void Stack::render() {
	cout << "Stack("<< stack.size() << "):\n";
	for(int i=(int)stack.size()-1; i > -1; i--){
		cout << "Stack [" << i << "] = ";
		stack[i].render();
		cout << endl;
	}
}

int Stack::size() {
	return stack.size();
}

Stack::~Stack() {
	// TODO Auto-generated destructor stub
}

