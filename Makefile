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

program6 : program6.tab.cpp program6.tab.hpp program6_lex.cpp program6.cpp \
           node.hpp symbolTable.hpp symbolTableEntry.hpp
	$(CXX) $(CXXFLAGS) program6.cpp program6.tab.cpp program6_lex.cpp -o program6

program6.tab.cpp : program6.ypp node.hpp
	$(YACC) $(YFLAGS) program6.ypp

program6_lex.cpp : program6.lpp node.hpp
	$(LEXXX) $(LFLAGS) program6.lpp

clean :
	/bin/rm -f program6_lex.cpp
	/bin/rm -f program6
	/bin/rm -f program6.tab.cpp
	/bin/rm -f program6.tab.hpp
	/bin/rm -f program6.output

test : program6
	./program6 < testfile.txt

tarball : 
	tar -czvf program6.tar program6.lpp program6.cpp node.hpp program6.ypp \
	Makefile symbolTable.hpp symbolTableEntry.hpp
