log.log: cx src.src
	./$^

C = cpp.cpp ypp.tab.cpp yy.lex.c
H = hpp.hpp ypp.tab.hpp

./cx: $(C) $(H) Makefile
	$(CXX) $(CXXFLAGS) -o $@ $(C)

ypp.tab.cpp ypp.tab.hpp: ypp.ypp
	bison $<

yy.lex.c: lex.lex
	flex $<

