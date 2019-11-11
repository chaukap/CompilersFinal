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
#include<string>
#include<stack>
using std::cout;
using std::endl;
using std::queue;
using std::stack;

extern int row;
extern int column;
extern bool hasValue;

queue<Node*> classes;
stack<string> derivations;
yyFlexLexer scanner;

int main()
{
  yyparse();

  cout << endl << endl;
  
//  Node* top;
//  while(!classes.empty()){
//    top = classes.front();
//    top->prettyPrint(&cout);
//    cout << endl;
//    classes.pop();
//  }

  while(!derivations.empty()){
    cout << derivations.top();
    cout << endl;
    derivations.pop();
  }
}
