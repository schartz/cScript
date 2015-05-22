/**
 * Script.h
 *
 *  Created on: Apr 26, 2015
 *      Author: schartz  
 */

#ifndef SCRIPT_H_
#define SCRIPT_H_


#include "Code/Instruction.h"
#include "Method.h"
#include "Data/Stack.h"
#include "ScriptConsole.h"
#include <map>
#include <vector>


class Script {
	friend class Parser;
	/**
	 * The complete listing of instructions that define this script
	 */
	vector<Instruction> code;
	/**
	 * Created as instructions are added to the Script vid addInstruction
	 */
	map<string, int> functionTable;
	/**
	 * only registered variables can be registered
	 */
	map<string, ScriptVariable> variables;

	/**
	 * As a function is executed more reference to it is pushed onto this variabes
	 */
	vector<Method> functions;
	/**
	 * Used to as a tag to remind vm of the method that is being executing
	 * Helpful when exiting a function, so we can clean up variables defined in that function
	 */
	string currentExecutingMethod;
	void	popActiveMethod();
	void	pushMethod(int retAddress);
	int		executeInstruction(Instruction code, int& instructionPointer);
	int 	getFunctionAddress(string funcName);
	Method*  getActiveMethod();

	int 	injectScript(Script* script);

	bool 	isSystemCall(string object, string functionName);

	ScriptVariable *getVariable(string varName);
	void 	addInstruction(Instruction I);

public:
	Script();

	void 	registerVariable(string varName, RegisteredVariable type, void* address);
	void	unregisterVariable(string varName);

	void 	render();

	void	execute(string funcCall);

	bool	load(string filename);
	int getSize();
	virtual ~Script();
};

#endif /* SCRIPT_H_ */
