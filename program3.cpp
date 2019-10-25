// program2.cpp
// Chandler Haukap
// 10/4/19
// COSC 4785 Program 2
//
// Driver for the compiler

#include<iostream>
#include "node.hpp"
#include "program3.tab.hpp"
#include <FlexLexer.h>
using std::cout;
using std::endl;

extern int row;
extern int column;
extern bool hasValue;

Node *tree;
yyFlexLexer scanner;

int main()
{

  yyparse();
  cout << "PRINTING TREE\n" << endl;
  tree->print(&cout);
  cout << endl;
  
  /* // Loop through the input file
  while((rtn = myScanner.yylex()) > 0) {
    // White Space
    if (rtn == IGNORE) {
      // The lexer told us to ignore this. I added this block to be certain
      // we do nothing.

    // Over 20 errors
    } else if(rtn == ERRORS) {
      cout << row << "\t" << column << "\t" << tokenToString((yytokentype) rtn);
      cout << endl;

      // I know, breaks are kind of lazy, but I like them.
      break;
            
    // If this is a valid symbols and there is a value associated
    } else if(hasValue) {
      cout << row << "\t" << column << "\t" << tokenToString((yytokentype) rtn)
           << "\t" << myScanner.YYText() << endl;

    // All other symbols
    } else {
      cout << row << "\t" << column << "\t" << tokenToString((yytokentype) rtn);
      cout << endl;
    }
  } */
}
