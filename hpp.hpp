#ifndef _H_CX
#define _H_CX

#include <iostream>
#include <ostream>
#include <map>
#include <vector>

using namespace std;

/// @defgroup frame extended Marvin Minsky frame model

/// @ingroup frame
								/// base frame class (generic object)
struct Frame {
								/// type/class tag
	string tag;
								/// value
	string val;
								/// slot{}s = attributes
	map<string,Frame*> slot;
								/// nest[]ed elements
	vector<Frame*> nest;
								/// ref.counter for GC
	long ref;

								/// frame constructor with given type
	Frame(string T, string V);
								/// frome constructor from value only
	Frame(string V);

	/// dump in full tree form
	string dump(int depth=0, string prefix="");

	/// dump header only
	string head(string prefix="");

	/// left pad with tabs
	string pad(int depth);
									/// push into @ref nest as a stack
	void push(Frame *o);

};

/// @defgroup prim Primitives
/// @ingroup frame
/// @{
									/// symbol
struct Sym: Frame { Sym(string); };
									/// string
struct Str: Frame { Str(string); };

/// @}

/// @defgroup meta Metaprogramming
/// @ingroup frame
/// @{
									/// operator
struct Op: Frame { Op(string); };

/// @}

/// @defgroup parser parser interface

									/// @name flex

									/// lexer call gives single token
extern int yylex();
									/// current line number
extern int yylineno;
									/// current lexeme selected by lexer
extern char *yytext;
									/// @name bison

									/// parser start /bison/
extern int yyparse();
									/// parser error callback
extern void yyerror(string msg);
#include "ypp.tab.hpp"

#endif // _H_CX

