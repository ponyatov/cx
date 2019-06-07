#ifndef _H_CX
#define _H_CX

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <map>
#include <vector>

using namespace std;

/// @defgroup frame extended Marvin Minsky frame model
/// @{


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

	/// @defgroup gc Garbage Collector
	/// @ingroup vm
	/// @{
										/// ref.counter for GC
	long ref;
										/// global object pool
	static vector<Frame*> pool;
										/// print object pool
	string pool_dump(void);
	/// @}

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

/// @defgroup prim Primitive
/// @ingroup frame
/// @{
										/// symbol
struct Sym: Frame { Sym(string); };
										/// string
struct Str: Frame { Str(string); };

/// @}

/// @defgroup cont Containter
/// @ingroup frame
/// @{
										/// stack
struct Stack: Frame { Stack(string); };

										/// dict
struct Dict: Frame { Dict(string); };
/// @}

/// @defgroup meta Metaprogramming
/// @ingroup frame
/// @{
										/// operator
struct Op: Frame { Op(string); };

/// @}

/// @defgroup vm Virtual Machine
/// @{
										/// virtual machine command
struct Cmd: Frame { Cmd(string); };
										/// virtual machine
struct VM: Frame { VM(string); };
										/// global system VM
extern VM* vm;

/// @}

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

