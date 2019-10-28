// program3.cpp
// Chandler Haukap
// 10/25/19
// COSC 4785 Program 3
//
// Driver for the compiler

#include<iostream>
#include "node.hpp"
#include "program3.tab.hpp"
#include <FlexLexer.h>
#include "stack"
using std::cout;
using std::endl;
using std::stack;

extern int row;
extern int column;
extern bool hasValue;

stack<string> derivations;
Node *tree;
yyFlexLexer scanner;

int main()
{
  cout << "----------- ERRORS -------------" << endl;

  yyparse();

  cout << endl << endl << "--------- PARSE TREE -----------" << endl;
  
  while(!derivations.empty()){
    cout << derivations.top() << endl;
    derivations.pop();
  }
  //cout << "PRINTING TREE\n" << endl;
  //tree->print(&cout);
}
