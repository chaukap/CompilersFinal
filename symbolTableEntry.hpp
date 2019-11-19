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
      name = ident;
      type = typ;
    }

    ~SymbolTableEntry()
    {
      delete paramList;
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
      return 0;
    }

    virtual vector<string>* getParamList()
    {
      return 0;
    }

  protected: 
    string name;
    string type;
    vector<string>* paramList;
};

class ClassSymbolTableEntry : public SymbolTableEntry
{
  public:
    ClassSymbolTableEntry(string ident, string typ,
                          SymbolTable* symbolTable) : SymbolTableEntry(ident, typ)
    {
      mySymbolTable = symbolTable;
    }

    virtual SymbolTable* getSymbolTable()
    {
      return mySymbolTable;
    }

  protected:
    SymbolTable* mySymbolTable;
};

class ConstructorSymbolTableEntry : public SymbolTableEntry
{
  public:
    ConstructorSymbolTableEntry(string ident, string typ,
                                vector<string>* parameterList=0) : SymbolTableEntry(ident, typ)
    {
      paramList = parameterList;
    }

    /* Print the information stored in this entry */
    virtual void print(ostream* out)
    {
      *out << type << " " << name;
      *out << " < ";
      if(paramList)
      {
        for(int i = 0; i < paramList->size(); i++)
        {
          *out << paramList->at(i) << " ";
        }
      }
      *out << ">";
    }
};

class MethodSymbolTableEntry : public SymbolTableEntry
{
  public:
    MethodSymbolTableEntry(string ident, string typ,
                           vector<string>* parameterList=0) : SymbolTableEntry(ident, typ)
    {
      paramList = parameterList;
    }

    /* Print the information stored in this entry */
    virtual void print(ostream* out)
    {
      *out << type << " " << name;
      *out << " < ";
      if(paramList)
      {
        for(int i = 0; i < paramList->size(); i++)
        {
          *out << paramList->at(i) << " ";
        }
      }
      *out << ">";
    }
};

#endif