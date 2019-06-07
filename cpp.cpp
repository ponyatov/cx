#include "hpp.hpp"

#define YYERR "\n\n"<<yylineno<<":"<<msg<<"["<<yytext<<"]\n\n"
void yyerror(string msg) { cout<<YYERR; cerr<<YYERR; exit(-1); }

int main() { return yyparse(); }

Frame::Frame(string T, string V) { tag = T; val = V; ref=0; }
Frame::Frame(string V):Frame("frame",V) {}

string Frame::dump(int depth, string prefix) {
	string tree = pad(depth) + head(prefix);
	for (auto it=nest.begin(),e=nest.end(); it!=e; it++)
		tree += (*it)->dump(depth+1);
	return tree;
}

string Frame::head(string prefix) {
	ostringstream os;
	os << prefix << "<" << tag << ":" << val << ">";
	os << " #" << ref;
	os << " @" << this;
	return os.str(); }

string Frame::pad(int depth) {
	string tabs = "\n";
	for (int i = 0; i < depth; i++) tabs += "\t";
	return tabs;
}

void Frame::push(Frame *o) { nest.push_back(o); }

Sym::Sym(string V):Frame("sym",V) {}

Str::Str(string V):Frame("str",V) {}

Op::Op(string V):Frame("op",V) {}
