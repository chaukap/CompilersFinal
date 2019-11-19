# Makefile
# Chandler Haukap
# 10/25/19
# COSC 4785

CXX=g++
CXXFLAGS=-ggdb -std=c++11 -Wall -Wno-sign-compare
YACC=bison
YFLAGS=--report=state -W -d -v
LEX=flex
LEXXX=flex++
LFLAGS=--warn

.PHONY : clean test tarball

program4 : program4.tab.cpp program4.tab.hpp program4_lex.cpp program4.cpp \
           node.hpp symbolTable.hpp symbolTableEntry.hpp
	$(CXX) $(CXXFLAGS) program4.cpp program4.tab.cpp program4_lex.cpp -o program4

program4.tab.cpp : program4.ypp node.hpp
	$(YACC) $(YFLAGS) program4.ypp

program4_lex.cpp : program4.lpp node.hpp
	$(LEXXX) $(LFLAGS) program4.lpp

clean :
	/bin/rm -f program4_lex.cpp
	/bin/rm -f program4
	/bin/rm -f program4.tab.cpp
	/bin/rm -f program4.tab.hpp
	/bin/rm -f program4.output

test : program4
	./program4 < testfile.txt

tarball : 
	tar -czvf program4.tar program4.lpp program4.cpp node.hpp program4.ypp \
	Makefile program4.odt
