#ifndef SYMBOL_TABLE
#define SYMBOL_TABLE

#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
#include "symbolTableEntry.hpp"

using std::unordered_map;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class SymbolTable
{
  public:
    /* Constructor for class and function variables. */
    SymbolTable(string classOrFunctionName, SymbolTable* parentTable=0)
    {
      parent = 0;
      if(parentTable) {
        parent = parentTable;
        parent->registerChild(this);
      }
      name = classOrFunctionName;
    }

    /* Constructor for blocks */
    SymbolTable(SymbolTable* parentTable=0)
    {
      parent = 0;
      if(parentTable) {
        parent = parentTable;
        parent->registerChild(this);
      }
      /* I'm using this name because identifiers cannot start with numbers. */
      name = "1Block";
    }

    void registerChild(SymbolTable* child)
    {
      children.push_back(child);
    }

    /* Insert an entry into the table.

       @param entry the symbol table entry 

       @return true if the identifier didn't already exist.
       @return false if the identifier did already exist.
    */
    bool insert(SymbolTableEntry* entry)
    {
      if(table.find(entry->getIdentifier()) == table.end()){
        table[entry->getIdentifier()] = entry;
        return true;
      } else {
        return false;
      }
    }

    virtual SymbolTableEntry* find(string identifier,
                                   vector<string>* parameterList = 0)
    {
      auto entry = table.find(identifier);

      if(entry != table.end()){
        return entry->second;
      } else if (parent) {
        return parent->find(identifier);
      } else {
        return 0;
      }
    }

    virtual bool hasOneMain(){
      bool mainFound = false;
      for(auto child = 0; child < children.size(); child++)
      {
        if(children[child]->find("main < >")){
          if(mainFound){
            // If main was already found we have 2 mains
            cout << "Type error: Multiple definitions of main." << endl;
            return false;
          } else {
            mainFound = true;
          }
        }
      }

      // If we have one and only one main.
        if(mainFound){
          return true;
        } else {
          cout << "Type error: No definition for main found." << endl;
          return false;
        }
    }

    virtual void print(ostream* out, int spaces)
    {
      for(auto i = 0; i < spaces; i++)
      {
        *out << " ";
      }
      *out << "--------- " << name << " ---------" << endl;

      for (auto itr = table.begin(); itr != table.end(); itr++) 
      {
        for(auto i = 0; i < spaces; i++)
        {
          *out << " ";
        }
        itr->second->print(out);
        *out << endl;
      }
      
      for(auto child = 0; child < children.size(); child++)
      {
        children[child]->print(out, spaces + 2);
      }
    }

    string getClassName()
    {
      if(parent->parent){
        return parent->getClassName();
      }
      return name;
    }

  protected:
    SymbolTable* parent;
    unordered_map<string, SymbolTableEntry*> table;
    vector<SymbolTable*> children;
    string name;
};

#endif