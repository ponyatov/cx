all: log.log doxy
log.log: src.src cx$(EXE)
	./cx$(EXE) < $< > $@ && tail $(TAIL) $@

C = cpp.cpp ypp.tab.cpp lex.yy.c
H = hpp.hpp ypp.tab.hpp

CXXFLAGS += -std=gnu++11

cx$(EXE): $(C) $(H) Makefile
	$(CXX) $(CXXFLAGS) -o $@ $(C)

ypp.tab.cpp ypp.tab.hpp: ypp.ypp
	bison $<

lex.yy.c: lpp.lpp
	flex $<

doxy: doxy.gen $(C) $(H)
	rm -rf docs ; doxygen $< 1>/dev/null
