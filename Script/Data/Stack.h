/**
 * Stack.h
 *
 *  Created on: May 1, 2015
 *      Author: schartz
 */

#ifndef STACK_H_
#define STACK_H_

#include "StackData.h"
#include "ScriptVariable.h"


#include <iostream>
#include <vector>
using namespace std;


/**
 * The stack functions to only contains immediate values, never variable names or reference pointers to variables.
 *
 * Therefore, any string contained on the stack is a value only, not an alais for some variable.
 */
class Stack {
	static vector<StackData> stack;
public:
	Stack();

	static void push(double data);
	static void push(string data);
	static void push(StackData data);
	static void push(ScriptVariable& data);
	static int size();;

	static void render();
	static StackData pop();
	virtual ~Stack();
};

#endif /* STACK_H_ */
