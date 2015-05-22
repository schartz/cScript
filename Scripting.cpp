//============================================================================
// Name        : Scripting.cpp
// Author      : schartz
// Version     :
// Copyright   : MIT
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "Script/Parse/Parser.h"

int globalValue = 434;


int main() {

	Script s;

	s.load("src/example.scs");


	double offset = 100;
	s.registerVariable("offset",REGISTERED_DOUBLE,&offset);

	s.execute("equation(60,offset)");
	s.unregisterVariable("offset");

	return 0;
}
















