#ifndef _H_CX
#define _H_CX

#include <iostream>
#include <string>

using namespace std;

/// @defgroup frame extended Marvin Minsky frame model
/// @{

						/// base frame class
struct Frame {
						/// type/class tag
	string tag;
						/// value
	string val;

								/// frame constructor with given type
	Frame(string T, string V);
								/// frome constructor from value only
	Frame(string V);

	string dump(int depth=0, string prefix="");
	string head(string prefix="");

};

/// @}

/// @defgroup parser parser interface
/// @{
									/// @name flex
									/// lexer call gives single token
extern int yylex();
									/// current line number
extern int yylineno;
									/// current lexeme sleected by lexer
extern char *yytext;
									/// @name bison
									/// parser start /bison/
extern int yyparse();
									/// parser error callback
extern void yyerror(string msg);
#include "ypp.tab.hpp"

/// @}

#endif // _H_CX

