// program4.cpp
// Chandler Haukap
// 10/25/19
// COSC 4785 Program 3
//
// Driver for the compiler

#include<iostream>
#include "node.hpp"
#include "program4.tab.hpp"
#include <FlexLexer.h>
#include<queue>
using std::cout;
using std::endl;
using std::queue;

extern int row;
extern int column;
extern bool hasValue;

queue<Node*> tree;
yyFlexLexer scanner;

int main()
{
  cout << "----------- ERRORS -------------" << endl;

  yyparse();

  cout << endl << endl << "--------- PARSE TREE -----------" << endl;
  
  Node* top;
  while(!tree.empty()){
    top = tree.front();
    top->print(&cout);
    cout << endl;
    tree.pop();
  }
  //cout << "PRINTING TREE\n" << endl;
  //tree->print(&cout);
}
