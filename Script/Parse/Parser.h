/**
 * Parser.h
 *
 *  Created on: Apr 10, 2015
 *      Author: schartz
 */

#ifndef PARSER_H_
#define PARSER_H_



#include <iostream>
#include <fstream>
#include <stdio.h>
#include <sstream>
#include <sstream>

using namespace std;

#include "Tokens.h"
#include "../Script.h"


/**
 *
 * Parser functions as the workhorse of our script compilation
 *
 * It takes an expression and determines meaning
 */
class Parser {
	string expression;		//expression to evaluate and compile
	int expressionIndex;	//the index into the expression; i.e expression[expressionIndex]
	string currentToken;	//the currentToken as a function of expression

	vector<int> marks;		//helps to group related code branches: functions, if, while

	TokenType currentTokenType;	//describes the current type type

	//---------------------------------------------------------
	// vital workers
	//---------------------------------------------------------
	void 	tokenize(string& exp,Tokens& token);
	int   	compiler(Script* script, Tokens& token, int rCount);
	string 	getToken();
	void 	mark(int markType);
	int  	unmark();
	//----------------------------------------------------------
	// Aux- helper functions
	//----------------------------------------------------------
	bool whileNotDelimiter(int currentPos);
	bool isDelimiter(const char& c);
	bool isSpace(const char& c);
	bool isLetter(const char& c);
	bool isDigit(const char& c);
	int  getDelimiterPriorty();
	bool isKeyword(string s);
	bool isDelimiter(const string& c);
	bool hasCommas(Tokens& token);
public:
	Parser();

	//main work horse
	int compile(Script* script, string expression);
	virtual ~Parser();
};

#endif /* PARSER_H_ */
