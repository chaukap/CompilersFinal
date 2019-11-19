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

program5 : program5.tab.cpp program5.tab.hpp program5_lex.cpp program5.cpp \
           node.hpp symbolTable.hpp symbolTableEntry.hpp
	$(CXX) $(CXXFLAGS) program5.cpp program5.tab.cpp program5_lex.cpp -o program5

program5.tab.cpp : program5.ypp node.hpp
	$(YACC) $(YFLAGS) program5.ypp

program5_lex.cpp : program5.lpp node.hpp
	$(LEXXX) $(LFLAGS) program5.lpp

clean :
	/bin/rm -f program5_lex.cpp
	/bin/rm -f program5
	/bin/rm -f program5.tab.cpp
	/bin/rm -f program5.tab.hpp
	/bin/rm -f program5.output

test : program5
	./program5 < testfile.txt

tarball : 
	tar -czvf program5.tar program5.lpp program5.cpp node.hpp program5.ypp \
	Makefile program5.odt symbolTable.hpp symbolTableEntry.hpp
