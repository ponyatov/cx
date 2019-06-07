log.log: src.src cx$(EXE)
	./cx$(EXE) < $< > $@ && tail $(TAIL) $@

C = cpp.cpp ypp.tab.cpp lex.yy.c
H = hpp.hpp ypp.tab.hpp

cx$(EXE): $(C) $(H) Makefile
	$(CXX) $(CXXFLAGS) -o $@ $(C)

ypp.tab.cpp ypp.tab.hpp: ypp.ypp
	bison $<

lex.yy.c: lpp.lpp
	flex $<

