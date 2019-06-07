#ifndef _H_CX
#define _H_CX

#include <iostream>

using namespace std;

struct Frame {
	string tag;
	string val;
};

extern int yylex();
extern int yylineno;
extern char *yytext;
extern int yyparse();
extern void yyerror(string msg);
#include "ypp.tab.hpp"

#endif // _H_CX

