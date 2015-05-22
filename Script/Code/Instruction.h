/**
 * Instruction.h
 *
 *  Created on: Apr 26, 2015
 *      Author: schartz
 */

#ifndef INSTRUCTION_H_
#define INSTRUCTION_H_

#include <string>
#include <iostream>

using namespace std;

enum ByteCode { NOP, //nothing appends
	RET,	//return from a function, change instruction pointer, pop off method from function stack
	ASN, 	//asign value to variable
	GTR,	//greater
	LSR,	//lesser
	LOOP,DONE,
	EIF, 	//end of function
	CMP,
	PUSH, 	//push the value of a variable onto the stack, push immediate string, or push number
	ADD, 	//pop two items off stack and perform operation
	SUB, 	//pop two items off stack and perform operation
	MULT, 	//pop two items off stack and perform operation
	DIV, 	//pop two items off stack and perform operation
	EXPON, 	//pop two items off stack and perform operation
	FUNC, 	//push a method onto the function stack
	DEF,
	ARG, 	//define a variable and assign it a value from the stack
	ARGC, CALL };
extern string byteCode[20];
class Instruction {
	ByteCode code;
	string operand;
	bool  containsQuotes;
public:
	Instruction();
	Instruction(ByteCode inst);
	Instruction(ByteCode inst, string xOperand);

	bool isOperandNumber();
	bool isOperandString();
	bool operandHasQuote();
	double getNumber();
	string getString();

	string getOperand();
	ByteCode getCode();
	string toString();
	virtual ~Instruction();
};

#endif /* INSTRUCTION_H_ */
