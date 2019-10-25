CXX=g++
CXXFLAGS=-ggdb -std=c++11 -Wall
YACC=bison
YFLAGS=--report=state -W -d
LEX=flex
LEXXX=flex++
LFLAGS=--warn

.PHONY : all clean test

all : program3.tab.cpp program3.tab.hpp program3_lex.cpp program3.cpp node.hpp
	$(CXX) $(CXXFLAGS) program3.cpp program3.tab.cpp program3_lex.cpp -o program3

program3.tab.cpp : program3.ypp node.hpp
	$(YACC) $(YFLAGS) program3.ypp

program3_lex.cpp : program3.lpp node.hpp
	$(LEXXX) $(LFLAGS) program3.lpp

clean :
	/bin/rm -f program3_lex.cpp
	/bin/rm -f program3
	/bin/rm -f program3.tab.cpp
	/bin/rm -f program3.tab.hpp

test : all
	./program3 < testfile.txt
