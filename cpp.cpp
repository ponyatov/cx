#include "hpp.hpp"

#define YYERR "\n\n"<<yylineno<<":"<<msg<<"["<<yytext<<"]\n\n"
void yyerror(string msg) { cout<<YYERR; cerr<<YYERR; exit(-1); }

int main() { return yyparse(); }

Frame::Frame(string T, string V) { tag = T; val = V; }
Frame::Frame(string V):Frame("frame",V) {}


string Frame::dump(int depth, string prefix) { return head(prefix); }
string Frame::head(string prefix) { return prefix+"<"+tag+":"+val+">"; }
