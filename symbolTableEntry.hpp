/* symbolTableEntry.hpp
 * Chandler Haukap
 * 11/14/19
 * COSC 4785 
 * 
 * A class to define entries in the symbol table. 
 * 
 * For now each entry is only a name and a type, but eventually I could 
 * need to add more things.
 */

#ifndef SYMBOL_TABLE_ENTRY
#define SYMBOL_TABLE_ENTRY

#include<string>
#include<iostream>
#include "symbolTable.hpp"
#include <vector>

using std::string;
using std::ostream;
using std::endl;
using std::cout;
using std::vector;

/* Unfortunately there is a circular dependecy between SymbolTable and SymbolTableEntry.
   I therefore have to forward-declare it. */
class SymbolTable;

class SymbolTableEntry
{
  public:
    SymbolTableEntry(string ident, string typ)
    {
      mySymbolTable = 0;
      name = ident;
      type = typ;
    }

    /* Return the identifier of this entry */
    string getIdentifier()
    {
      return name;
    }

    /* Return the type of this entry */
    string getType()
    {
      return type;
    }

    /* Print the information stored in this entry */
    virtual void print(ostream* out)
    {
      *out << type << " " << name;
    }

    virtual SymbolTable* getSymbolTable()
    {
      return mySymbolTable;
    }

  protected: 
    string name;
    string type;
    SymbolTable* mySymbolTable;

    SymbolTableEntry(){}
};

class ClassSymbolTableEntry : public SymbolTableEntry
{
  public:
    ClassSymbolTableEntry(string ident, string typ,
                          SymbolTable* symbolTable)
    {
      name = ident;
      type = typ;
      mySymbolTable = symbolTable;
    }
};

class ConstructorSymbolTableEntry : public SymbolTableEntry
{
  public:
    ConstructorSymbolTableEntry(string ident, string typ)
    {
      mySymbolTable = 0;
      type = typ;
      name = ident;
    }

    /* Print the information stored in this entry */
    virtual void print(ostream* out)
    {
      *out << type << " " << name;
    }
};

class MethodSymbolTableEntry : public SymbolTableEntry
{
  public:
    MethodSymbolTableEntry(string ident, string typ,
                           vector<string>* parameterList=0)
    {
      mySymbolTable = 0;
      type = typ;
      name = ident;
      if(parameterList){
        for(int i = 0; i < parameterList->size(); ++i){
          name += " ";
          name += parameterList->at(i);
        }
      }
    }

    /* Print the information stored in this entry */
    virtual void print(ostream* out)
    {
      *out << type << " " << name;
    }
};

#endif