/**
 * Tokens.h
 *
 *  Created on: Apr 23, 2015
 *      Author: schartz
 */

#ifndef TOKENS_H_
#define TOKENS_H_

#include <iostream>
#include <vector>

/**
 *
 * schartz Eleanya
 */
using namespace std;


enum TokenType { NONE,NUMBER,DELIMITER,VAR,KEYWORD };


/**
 * Functions to hold script terms that characterize a line
 */
class Tokens {
private:
	//! contains the dynamic array of indiviudal string tokens
	vector<string> tokens;
	//! contains priorty values for each token; purpose is to allow for faster compilation
	//! functions as a weighting system for each token
	vector<int>		priorty;
	//! describe what the token is: string/variable, number, delimiter
	vector<TokenType>		type;
public:
	Tokens();


	void addToken(string token, int priortyCode, TokenType tokenType);


	bool isNumber(int index);
	bool isDelimiter(int index);
	bool isVar(int index);
	bool isCloseParenthesis(int index);
	bool isOpenParenthesis(int index);
	bool isKeyWord(int index);
	int  getTokenPriorty(int index);

	void clear();
	Tokens extractContentOfParenthesis(int startIndex, int endIndex, int& extractionCount);
	Tokens extractInclusive(int startIndex, int endIndex,int& extractionCount);

	int getHighestOperatorPriorityIndex(int& priortyCod);
	int getMatchingCloseParenthesis(int openIndex);
	string getToken(int index);


	void renderTokens();
	void renderTokenType();
	void renderTokenPriorty();

	void pop(int index);
	static void stdError(string msg);
	int getSize();
	virtual ~Tokens();
};

#endif /* TOKENS_H_ */
