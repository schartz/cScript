/**
 * Tokens.cpp
 *
 *  Created on: Apr 23, 2015
 *      Author: schartz
 */

#include "Tokens.h"
#include <sstream>
Tokens::Tokens() {
	// TODO Auto-generated constructor stub
	tokens.reserve(30);
	type.reserve(30);
	priorty.reserve(30);
}
/**
 * Principle agent
 * Serves to create the token set, add as many as needed
 * @param token
 * @param priortyCode
 * @param tokenType
 */
void Tokens::addToken(string token, int priortyCode, TokenType tokenType) {

	tokens.push_back(token);
	priorty.push_back(priortyCode);
	type.push_back(tokenType);

	if(getSize() > 1){
		int size=getSize();
		//if previous token before this one is a var
		if(isOpenParenthesis(size-1) && isVar(size-2)){
			priorty[size-2]= 2;
		}

	}
}

/**
 * Retrun true or false indicating if the index is a number
 * @param index of token, bound checking is implemented
 * @return true or false
 */
bool Tokens::isNumber(int index) {
	if(index < 0 || index > getSize()-1){
		return false;
	}
	if(type[index] == NUMBER) return true;

	return false;
}
/**
 * Retrun true or false indicating if the index is a delimiter
 * @param index of token, bound checking is implemented
 * @return true or false
 */
bool Tokens::isDelimiter(int index) {
	if(index < 0 || index > getSize()-1){
		return false;
	}
	if(type[index] == DELIMITER) return true;

	return false;
}
/**
 * Retrun true or false indicating if the index is a number
 * @param index of token, bound checking is implemented
 * @return true or false
 */
bool Tokens::isVar(int index) {
	if(index < 0 || index > getSize()-1){
		return false;
	}
	if(type[index] == VAR) return true;

	return false;
}

/**
 * Indicate whether or not the index supplied is that of a closed parenthesis
 * @param index
 * @return
 */
bool Tokens::isCloseParenthesis(int index) {
	bool isDelim = isDelimiter(index);
	if(!isDelim) return false;

	if(tokens[index] == ")"){
		return true;
	}
	return false;
}
/**
 * Indicate whether or not the index supplied is that of an open parenthesis
 * @param index
 * @return
 */
bool Tokens::isOpenParenthesis(int index) {
	bool isDelim = isDelimiter(index);
	if(!isDelim) return false;

	if(tokens[index] == "("){
		return true;
	}
	return false;
}

/**
 *
 * Retract the contents between the two indexes and return everything excluding the values at the indexes
 *
 * example:
 * 		token set of:
 * 		'(' 'varA' + '3244' ')'
 * 		will return tokens
 * 		'VarA' + '3244'
 *
 * After extracting the contents, RST is used to replace the content that was just extracted
 * @param startParenthesisIndex	index of the open parenthesis '('
 * @param endParenthesisIndex	index of the close parenthesis ')'
 * @param extractionCount		place the store the total number of items extracted from this token set
 * @return
 */
Tokens Tokens::extractContentOfParenthesis(int startParenthesisIndex, int endParenthesisIndex, int& extractionCount) {
	Tokens newToken;
	if(startParenthesisIndex < 0 || startParenthesisIndex > getSize()-1){
		stdError("token extraction, startIndex out of bounds");
		return newToken;
	}
	if(endParenthesisIndex < startParenthesisIndex || endParenthesisIndex > getSize()-1){
		stdError("token extraction, endIndex out of bounds");
		return newToken;
	}
	//copy from current tokenset to new tokenset
	int i;
	int count=0;	//the total count of values to extract
	for(i=startParenthesisIndex+1; i < endParenthesisIndex; i++){
		newToken.addToken(tokens[i],priorty[i],type[i]);
		count++;
	}
	//erase
	for(i=0; i<(count+2); i++){	//erase the total number of tokens extracted including what is before and after
		//the contents extracted
		tokens.erase	(tokens.begin()	 + startParenthesisIndex);
		type.erase		(type.begin()	 + startParenthesisIndex);
		priorty.erase	(priorty.begin() + startParenthesisIndex);
	}
	extractionCount = count+2;
	tokens.insert(tokens.begin()+startParenthesisIndex,"RST");
	type.insert(type.begin()+startParenthesisIndex,NONE);
	priorty.insert(priorty.begin()+startParenthesisIndex,0);
	return newToken;
}

/**
 * Extract , inclusively, everything between startIndex and endIndex
 *
 * After extracting the contents, RST is used to replace the content that was just extracted
 *
 * @param startIndex
 * @param endIndex
 * @param extractionCount
 * @return
 */
Tokens Tokens::extractInclusive(int startIndex, int endIndex, int& extractionCount) {
	Tokens newToken;
	if(startIndex < 0 || startIndex > getSize()-1){
		stdError("token extraction, startIndex out of bounds");
		return newToken;
	}
	if(endIndex < startIndex || endIndex > getSize()-1){
		stdError("token extraction, endIndex out of bounds");
		return newToken;
	}
	//copy from current tokenset to new tokenset
	int i;
	int count=0;	//the total count of values to extract
	for(i=startIndex; i < endIndex+1; i++){
		newToken.addToken(tokens[i],priorty[i],type[i]);
		count++;
	}
	//erase
	for(i=0; i<(count); i++){	//erase the total number of tokens extracted including what is before and after
		//the contents extracted
		tokens.erase	(tokens.begin()	 + startIndex);
		type.erase		(type.begin()	 + startIndex);
		priorty.erase	(priorty.begin() + startIndex);
	}
	extractionCount = count;
	tokens.insert(tokens.begin()+startIndex,"RST");
	type.insert(type.begin()+startIndex,NONE);
	priorty.insert(priorty.begin()+startIndex,0);
	return newToken;
}

/**
 * Report error to user
 * @param msg
 */
void Tokens::stdError(string msg) {
	cout << "error: "<< msg << endl;
}

void Tokens::renderTokens() {
	cout << "{ ";
	for(int i=0; i<getSize(); i++){
		cout << "'" << tokens[i] << "' ";
	}
	cout << "}"<< endl;
}
void Tokens::renderTokenType(){
	string str;
	cout << "{ ";
	for(int i=0; i<getSize(); i++){

		switch(type[i]){
		case DELIMITER: str="DLM";	break;
		case NUMBER:	str="NUM"; break;
		case VAR:		str="VAR"; break;
		case KEYWORD:	str="KEY"; break;
		case NONE:		str="NON"; break;
		}
		cout << "'" << str << "' ";
	}
	cout <<"}" << endl;
}
void Tokens::renderTokenPriorty(){
	string str;
	cout << "{ ";
	for(int i=0; i<getSize(); i++){

		cout << "[" << priorty[i] << "] ";
	}
	cout <<"}" << endl;
}

/**
 * Return the priorty/weight associated with token at said index
 * @param index
 * @return
 */
int Tokens::getTokenPriorty(int index) {
	if(index < 0 || index > getSize()-1){
		stdError("getToken priorty out of bounds");
		return 0;
	}
	return priorty[index];
}
/**
 * Search for the highest priorty value and return its index
 * @param priortyCode
 * @return
 */
int Tokens::getHighestOperatorPriorityIndex(int& priortyCode) {
	int index=0;
	int highest=-10;

	for(int i=0; i<getSize(); i++){
		if(priorty[i] > highest){
			highest = priorty[i];
			priortyCode=highest;
			index=i;
		}
	}
	return index;
}

string Tokens::getToken(int index) {
	if(index < 0 || index >= getSize()){
		cout << index << "/" << getSize()-1 <<endl;
		stringstream s;
		s << index;
		stringstream ss;
		ss<< getSize();
		stdError("get token, index(" + s.str() + ") is out of range, token size currently " + ss.str());
		return ".none.";


	}
	return tokens[index];
}

int Tokens::getMatchingCloseParenthesis(int openIndex) {

	int i;
	for( i=openIndex; i<getSize(); i++){
		if(tokens[i]==")"){
			return i;
			break;
		}

	}
	return openIndex;
}
/**
 * Remove token at index
 * @param index
 */
void Tokens::pop(int index) {
	if(index < 0 || index > getSize()-1){
		stdError("pop index out of range");
		return;
	}

	tokens.erase(tokens.begin()+index);
	type.erase(type.begin()+index);
	priorty.erase(priorty.begin()+index);
}

bool Tokens::isKeyWord(int index) {
	if(index < 0 || index >= getSize()){
		stdError("index for keyword check is out of bounds");
		return false;
	}
	if(type[index] == KEYWORD){
		return true;
	}else
		return false;
}


Tokens::~Tokens() {
	clear();
}
void Tokens::clear() {

	type.clear();
	priorty.clear();
	tokens.clear();
}

int Tokens::getSize(){
	return (int)tokens.size();
}
