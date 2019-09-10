
all : program1.cpp program1_lex
	g++ -ggdb -Wall -std=c++11 program1.cpp program1_lex.cpp -o program

program1_lex : program1.lpp
	flex++ --warn program1.lpp

clean :
	rm program1_lex.cpp
	rm program
