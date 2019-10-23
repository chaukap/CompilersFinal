CXX=g++

.PHONY : all clean test

all : program3.cpp program3_lex.cpp tokens.cpp program3_bison.cpp
	g++ -ggdb -Wall -std=c++11 program3.cpp program3_lex.cpp \
	tokens.cpp -o program3

program3_lex.cpp : program3.lpp
	flex++ --warn program3.lpp

program3_bison.cpp : program3.ypp
	bison -d -o program3_bison.cpp program3.ypp

clean :
	/bin/rm -f program3_lex.cpp
	/bin/rm -f program3
	/bin/rm -f program3_bison.cpp

test : all
	./program3 < testfile.txt
