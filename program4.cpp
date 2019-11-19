// program4.cpp
// Chandler Haukap
// 10/25/19
// COSC 4785 Program 3
//
// Driver for the compiler

#include "symbolTable.hpp"
#include "node.hpp"
#include "program4.tab.hpp"
#include<iostream>
#include<FlexLexer.h>
#include<queue>
#include<string>
#include<stack>
using std::cout;
using std::endl;
using std::queue;
using std::stack;
using std::string;

extern int row;
extern int column;
extern bool hasValue;

queue<Node*> classes;
stack<string> derivations;
SymbolTable* baseSymbolTable;
yyFlexLexer scanner;

void symbolTableTest();

int main()
{
  baseSymbolTable = new SymbolTable("Classes");

  yyparse();
  cout << endl << endl;


  Node* top;
  while(!classes.empty()){
    top = classes.front();
    top->generateSymbolTable(baseSymbolTable);
    classes.pop();
  }

  baseSymbolTable->print(&cout, 0);

  /*
  while(!derivations.empty()){
    cout << derivations.top();
    cout << endl;
    derivations.pop();
  }
  */
}

void symbolTableTest()
{
  cout << "------------- SYMBOL TABLE TEST --------------" << endl << endl;

  SymbolTableEntry* entry1 = new SymbolTableEntry("entry1", "int");
  SymbolTableEntry* entry2 = new SymbolTableEntry("entry2", "class2");
  SymbolTableEntry* entry3 = new SymbolTableEntry("entry3", "class3");
  SymbolTableEntry* entry4 = new SymbolTableEntry("entry4", "class4");
  SymbolTableEntry* entry5 = new SymbolTableEntry("entry5", "class5");
  SymbolTableEntry* entry6 = new SymbolTableEntry("entry6", "class6");
  SymbolTableEntry* entry7 = new SymbolTableEntry("entry7", "class7");
  SymbolTableEntry* entry8 = new SymbolTableEntry("entry8", "class8");

  SymbolTable* table = new SymbolTable();
  SymbolTable* childTable = new SymbolTable(table);
  SymbolTable* childChildTable = new SymbolTable(childTable);
  SymbolTable* child2Table = new SymbolTable(table);

  SymbolTableEntry* lookup;

  table->insert(entry1);
  table->insert(entry3);

  childTable->insert(entry2);
  childTable->insert(entry4);

  child2Table->insert(entry7);
  child2Table->insert(entry8);

  childChildTable->insert(entry5);
  childChildTable->insert(entry6);

  cout << "Printing the entire table: " << endl;
  /* Print the tables */
  table->print(&cout, 0);

  cout << endl << endl << "------ Testing Lookup ------" << endl;
  cout << "Looking for entry1 in childChildTable (should be found)" << endl;
  lookup = childChildTable->find(entry1->getIdentifier());
  lookup->print(&cout);

  cout << "Looking for entry1 in child2Table (should be found)" << endl;
  lookup = child2Table->find(entry1->getIdentifier());
  lookup->print(&cout);

  cout << "Looking for entry7 in childChildTable (should NOT be found)" << endl;
  lookup = childChildTable->find(entry7->getIdentifier());
  if(lookup) lookup->print(&cout);
  else cout << "NOT FOUND" << endl;

  cout << endl << endl << "-------- Printing one more time --------" << endl;
  table->print(&cout, 0);
}
