/* node.hpp
 * Chandler Haukap
 * Original author: kbuckner
 * 10/25/19
 * COSC 4785 
 * 
 * Original Node class written by Dr. Kim Buckner. Extended by Chandler
 * Haukap.
 *
 * This defines the "node" class in C++. Do not need this for C because 
 * just use the standard flex "yyxxxxx" variables/functions. 
 * The commented out portions are for debugging.
 */

#ifndef NODE_HPP
#define NODE_HPP
#include<iostream>
#include<string>
#include "symbolTable.hpp"

using std::string;
using std::endl;
using std::ostream;
using std::cout;

extern SymbolTable* baseSymbolTable;
extern int row;
extern int column;

class Node
{
  public:
    // set the pointers to 0 C++ is trying to get away from NULL
    Node(Node *lf=0,Node *rt=0) 
    {
      reset();
      dval=0.0;
      ival=0;
      left=lf;
      right=rt; 
    }
    virtual ~Node()
    {
      if(left) delete left;
      if(right) delete right;
    }
    int getint() const
    {
      return ival;
    }
    double getdbl() const
    {
      return dval;
    }
    virtual string getstring() const
    {
      return sval;
    }
    void setval(const char *v)
    {
      sval=v;
    }
    void setval(const string s)
    {
      sval=s;
    }
    void setval(int i)
    {
      ival=i;
    }
    void setval(double d)
    {
      dval=d;
    }

    void reset() {
      line = row;
      col = column;
    }

    void setleft(Node *p) 
    {
      left=p;
      return;
    }
    void setright(Node *p) 
    {
      right=p;
      return;
    }
    Node* getleft()
    {
      return left;
    }
    Node* getright()
    {
      return right;
    }

    virtual void addSValToVector(vector<string>* vec)
    {
      if(left) left->addSValToVector(vec);
      if(right) right->addSValToVector(vec);
    }

    virtual void print(ostream *out = 0){
      if(left) left->print(out);
      if(right) right->print(out);
    }

    virtual void prettyPrint(ostream *out = 0)
    {
      if(left) left->prettyPrint(out);
      if(right) right->prettyPrint(out);
      //*out << endl;
      return;
    }

    /* Generate a symbol table(s) for this node and all children node.
       This function also type checks for duplicate variable declarations */
    virtual void generateSymbolTable(SymbolTable* parent)
    {
      //cout << "Node: Generating symbol table." << endl;
      if(left) left->generateSymbolTable(parent);
      if(right) right->generateSymbolTable(parent);
    }

    virtual SymbolTableEntry* typeCheck(SymbolTable* parent)
    {
      //cout << "Node: Type checking" << endl;
      if(right) right->typeCheck(parent);
      if(left) left->typeCheck(parent);

      // The default implementation doesn't need to return anything;
      return 0;
    }

    virtual bool hasReturn()
    {
      if(left && right){
        return left->hasReturn() || right->hasReturn() || false;
      } else if(left) {
        return left->hasReturn() || false;
      } else if(right){
        return right->hasReturn() || false;
      } else {
        return false;
      }
    }

    virtual bool isReturnValid(string type)
    {
      if(left && right){
        return left->isReturnValid(type) && right->isReturnValid(type) && true;
      } else if(left) {
        return left->isReturnValid(type) && true;
      } else if(right){
        return right->isReturnValid(type) && true;
      } else {
        return true;
      }
    }

  protected:
    int line;
    int col;
    int ival;
    double dval;
    string sval;
    Node *left,*right;
};

class NodeNull : public Node
{
  public:
    NodeNull() : Node() {};

    virtual SymbolTableEntry* typeCheck(SymbolTable* parent)
    {
      return new SymbolTableEntry("null", "null");
    }
};

/* A class for errors. This class does NOTHING.
 * It exists to prevent segmentation faults in the 
 * event that an error production occurred in the middle
 * of valid code. */
class NodeError : public Node
{
  public:
    NodeError() : Node() {}

    virtual void print(ostream* out)
    {
      return;
    }

    virtual void prettyPrint(ostream* out)
    {
      return;
    }
};

class NodeOr : public Node
{
  public:
    NodeOr(Node* left, Node* right) : Node(left,right) {}

    virtual SymbolTableEntry* typeCheck(SymbolTable* parent)
    {
      SymbolTableEntry* entry1 = left->typeCheck(parent);
      SymbolTableEntry* entry2 = right->typeCheck(parent);

      if(!entry1 || !entry2){
        cout << "Type error (" << line << ", " << col << "): Unknown type in "
          << "conditional statement." << endl;
      }

      string type1 = entry1->getType();
      string type2 = entry2->getType();

      // "numeric value" means a literal integer. In this case we do not care.
      if(type1 == "numeric value"){
        type1 = "int";
      }

      if(type2 == "numeric value"){
        type2 = "int";
      }

      if(type1 == "int" && type2 == "int"){
        return new SymbolTableEntry("conditional", "int");
      } else {
        cout << "Type error (" << line << ", " << col << "): conditionals "
          "require 'int' operands." << endl;
        return 0;
      }
    }
};

class NodeAnd : public Node
{
  public:
    NodeAnd(Node* left, Node* right) : Node(left,right) {}

    virtual SymbolTableEntry* typeCheck(SymbolTable* parent)
    {
      SymbolTableEntry* entry1 = left->typeCheck(parent);
      SymbolTableEntry* entry2 = right->typeCheck(parent);

      if(!entry1 || !entry2){
        cout << "Type error (" << line << ", " << col << "): Unknown type in "
          << "conditional statement." << endl;
      }

      string type1 = entry1->getType();
      string type2 = entry2->getType();

      // "numeric value" means a literal integer. In this case we do not care.
      if(type1 == "numeric value"){
        type1 = "int";
      }

      if(type2 == "numeric value"){
        type2 = "int";
      }

      if(type1 == "int" && type2 == "int"){
        return new SymbolTableEntry("conditional", "int");
      } else {
        cout << "Type error (" << line << ", " << col << "): Conditionals "
          "require 'int' operands." << endl;
        return 0;
      }
    }
};

class NodeMod : public Node
{
  public:
    NodeMod(Node* left, Node* right) : Node(left,right) {}

    virtual SymbolTableEntry* typeCheck(SymbolTable* parent)
    {
      SymbolTableEntry* entry1 = left->typeCheck(parent);
      SymbolTableEntry* entry2 = right->typeCheck(parent);

      if(!entry1 || !entry2){
        cout << "Type error (" << line << ", " << col << "): Unknown type in "
          << "arithmatic statement." << endl;
      }

      string type1 = entry1->getType();
      string type2 = entry2->getType();

      // "numeric value" means a literal integer. In this case we do not care.
      if(type1 == "numeric value"){
        type1 = "int";
      }

      if(type2 == "numeric value"){
        type2 = "int";
      }

      if(type1 == "int" && type2 == "int"){
        return new SymbolTableEntry("arithmatic", "int");
      } else {
        cout << "Type error (" << line << ", " << col << "): Arithmatics "
          "require 'int' operands." << endl;
        return 0;
      }
    }
};

class NodePlus : public Node
{
  public:
    NodePlus(Node* left, Node* right) : Node(left,right) {}

    virtual SymbolTableEntry* typeCheck(SymbolTable* parent)
    {
      SymbolTableEntry* entry1 = left->typeCheck(parent);
      SymbolTableEntry* entry2 = right->typeCheck(parent);

      if(!entry1 || !entry2){
        cout << "Type error (" << line << ", " << col << "): Unknown type in "
          << "arithmatic statement." << endl;
      }

      string type1 = entry1->getType();
      string type2 = entry2->getType();

      // "numeric value" means a literal integer. In this case we do not care.
      if(type1 == "numeric value"){
        type1 = "int";
      }

      if(type2 == "numeric value"){
        type2 = "int";
      }

      if(type1 == "int" && type2 == "int"){
        return new SymbolTableEntry("arithmatic", "int");
      } else {
        cout << "Type error (" << line << ", " << col << "): Arithmatics "
          "require 'int' operands." << endl;
        return 0;
      }
    }
};

class NodeMinus : public Node
{
  public:
    NodeMinus(Node* left, Node* right) : Node(left,right) {}

    virtual SymbolTableEntry* typeCheck(SymbolTable* parent)
    {
      SymbolTableEntry* entry1 = left->typeCheck(parent);
      SymbolTableEntry* entry2 = right->typeCheck(parent);

      if(!entry1 || !entry2){
        cout << "Type error (" << line << ", " << col << "): Unknown type in "
          << "arithmatic statement." << endl;
      }

      string type1 = entry1->getType();
      string type2 = entry2->getType();

      // "numeric value" means a literal integer. In this case we do not care.
      if(type1 == "numeric value"){
        type1 = "int";
      }

      if(type2 == "numeric value"){
        type2 = "int";
      }

      if(type1 == "int" && type2 == "int"){
        return new SymbolTableEntry("arithmatic", "int");
      } else {
        cout << "Type error (" << line << ", " << col << "): Arithmatics "
          "require 'int' operands." << endl;
        return 0;
      }
    }
};

class NodeTimes : public Node
{
  public:
    NodeTimes(Node* left, Node* right) : Node(left,right) {}

    virtual SymbolTableEntry* typeCheck(SymbolTable* parent)
    {
      SymbolTableEntry* entry1 = left->typeCheck(parent);
      SymbolTableEntry* entry2 = right->typeCheck(parent);

      if(!entry1 || !entry2){
        cout << "Type error (" << line << ", " << col << "): Unknown type in "
          << "arithmatic statement." << endl;
      }

      string type1 = entry1->getType();
      string type2 = entry2->getType();

      // "numeric value" means a literal integer. In this case we do not care.
      if(type1 == "numeric value"){
        type1 = "int";
      }

      if(type2 == "numeric value"){
        type2 = "int";
      }

      if(type1 == "int" && type2 == "int"){
        return new SymbolTableEntry("arithmatic", "int");
      } else {
        cout << "Type error (" << line << ", " << col << "): Arithmatics "
          "require 'int' operands." << endl;
        return 0;
      }
    }
};

class NodeDivide : public Node
{
  public:
    NodeDivide(Node* left, Node* right) : Node(left,right) {}

    virtual SymbolTableEntry* typeCheck(SymbolTable* parent)
    {
      SymbolTableEntry* entry1 = left->typeCheck(parent);
      SymbolTableEntry* entry2 = right->typeCheck(parent);

      if(!entry1 || !entry2){
        cout << "Type error (" << line << ", " << col << "): Unknown type in "
          << "arithmatic statement." << endl;
      }

      string type1 = entry1->getType();
      string type2 = entry2->getType();

      // "numeric value" means a literal integer. In this case we do not care.
      if(type1 == "numeric value"){
        type1 = "int";
      }

      if(type2 == "numeric value"){
        type2 = "int";
      }

      if(type1 == "int" && type2 == "int"){
        return new SymbolTableEntry("arithmatic", "int");
      } else {
        cout << "Type error (" << line << ", " << col << "): Arithmatics "
          "require 'int' operands." << endl;
        return 0;
      }
    }
};

class NodeEquality : public Node
{
  public:
    NodeEquality(Node* left, Node* right) : Node(left,right) {}

    virtual SymbolTableEntry* typeCheck(SymbolTable* parent)
    {
      SymbolTableEntry* entry1 = left->typeCheck(parent);
      SymbolTableEntry* entry2 = right->typeCheck(parent);

      if(!entry1 || !entry2){
        cout << "Type error (" << line << ", " << col << "): Unknown type in "
          << "comparison." << endl;
      }

      string type1 = entry1->getType();
      string type2 = entry2->getType();

      // "numeric value" means a literal integer. In this case we do not care.
      if(type1 == "numeric value"){
        type1 = "int";
      }

      if(type2 == "numeric value"){
        type2 = "int";
      }

      // ints can only be compared to ints.
      if(type1 == "int" || type2 == "int"){
        if(type1 == "int" && type2 == "int"){
          return new SymbolTableEntry("equality", "int");
        } else {
          cout << "Type error (" << line <<", "<< col << "): An 'int' can only"
            << " be compared to another 'int'." << endl;
            return 0;
        }
      }

      // If we made it this far we can compare anything.
      return new SymbolTableEntry("comparison", type1);
    }
};

class NodeNotEquality : public Node
{
  public:
    NodeNotEquality(Node* left, Node* right) : Node(left,right) {}

    virtual SymbolTableEntry* typeCheck(SymbolTable* parent)
    {
      SymbolTableEntry* entry1 = left->typeCheck(parent);
      SymbolTableEntry* entry2 = right->typeCheck(parent);

      if(!entry1 || !entry2){
        cout << "Type error (" << line << ", " << col << "): Unknown type in "
          << "comparison." << endl;
      }

      string type1 = entry1->getType();
      string type2 = entry2->getType();

      if(type1 == "numeric value"){
        type1 = "int";
      }

      if(type2 == "numeric value"){
        type2 = "int";
      }

      // ints can only be compared to ints.
      if(type1 == "int" || type2 == "int"){
        if(type1 == "int" && type2 == "int"){
          return new SymbolTableEntry("equality", "int");
        } else {
          cout << "Type error (" << line << ", " << col << "): 'int' can only"
            << " be compared to another 'int'." << endl;
            return 0;
        }
      }

      // If we made it this far we can compare anything.
      return new SymbolTableEntry("comparison", type1);
    }
};

class NodeNegative : public Node
{
  public:
    NodeNegative(Node *lf):Node(lf){}

    virtual void print(ostream* out)
    {
      *out << "<UnaryOP> --> MINUS <expression>" << endl;
    }

    virtual void prettyPrint(ostream *out = 0)
    {
      if(left) {
        *out << "-";
        left->prettyPrint(out);
      }
      return;
    }

    virtual SymbolTableEntry* typeCheck(SymbolTable* parent)
    {
      //cout << "NodeNegative: Type checking. " << endl;
      return left->typeCheck(parent);
    }
};

class NodePositive : public Node
{
  public:
   NodePositive(Node* lf) : Node(lf) {}

    virtual void print(ostream* out)
    {
      *out << "<UnaryOP> -> PLUS <expression>" << endl;
    }

   virtual void prettyPrint(ostream* out)
   {
     *out << "+";
     left->prettyPrint(out);
   }
};

class nodeNum : public Node
{
  public:
    nodeNum(int i)
    {
      ival=i;
      sval = std::to_string(ival);
    };

    virtual void print(ostream* out)
    {
      *out << "<expression> --> NUM" << endl;
      *out << "NUM --> " << ival << endl;
    }

    virtual void prettyPrint(ostream *out = 0)
    {
      *out << " " << ival;
    }

    virtual SymbolTableEntry* typeCheck(SymbolTable* parent)
    {
      return new SymbolTableEntry(sval, "numeric value");
    }
};

class nodeParExp : public Node
{
  public:
    nodeParExp(Node *lf=0) : Node(lf) {}

    virtual void print(ostream* out)
    {
      *out << "<expression> --> LPAREN <expression> RPAREN" << endl;
      if(left) left->print(out);
    }

    virtual void prettyPrint(ostream *out = 0)
    {
      *out << "Parameter expression;" << endl;
      *out << "( ";
      if(left) left->prettyPrint(out);
      if(right) right->prettyPrint(out);
      *out << " )" ;
      *out << "END parameter expression" << endl;
    }
};

class NodeIdentifier : public Node
{
  public:
    NodeIdentifier(string* name) : Node(0, 0)
    {
      identifier = *name;
      sval = *name;
    }

    NodeIdentifier(string name) : Node(0, 0)
    {
      identifier = name;
      sval = name;
    }

    virtual void print(ostream* out)
    {
      *out << "<identifier> --> IDENT" << endl;
      *out << "IDENT --> " << identifier << endl;
    }

    virtual void prettyPrint(ostream* out = 0)
    {
      *out << " " << identifier;
    }

    virtual SymbolTableEntry* typeCheck(SymbolTable* parent)
    {
      SymbolTableEntry* thisEntry = parent->find(sval);
      if(thisEntry){
        return thisEntry;
      } else {
        cout << "Type error (" << line << ", " << col 
          << "): Unknown identifier " << identifier << endl;
        return 0;
      }
    }

    string identifier;
};

class nodeVardec : public Node 
{
  public:
    nodeVardec(Node* lf, Node* rt) : Node(lf,rt) {}

    virtual void print(ostream* out)
    {
      *out << "<Variable Declaration>" << endl;
      *out << "<Variable Declaration> --> ";
    }

    virtual void prettyPrint(ostream* out = 0)
    {
      *out << "Vardec:" << endl;
      if(left) left->prettyPrint(out);
      if(right) right->prettyPrint(out);
      *out << endl << "END vardec" << endl;
    }

    virtual void generateSymbolTable(SymbolTable* parent)
    {
      //cout << "nodeVardec: Generating symbol table." << endl;
      SymbolTableEntry* entry = new SymbolTableEntry(right->getstring(),
                                                     left->getstring());

      if(!parent->insert(entry)){
        /* If insert failed there must alreay be an entry with the 
           same identifier */
        cout << "Type error (" << line << ", " << col 
          << "): '" << entry->getIdentifier() << "' declared twice"
          << " in the same scope." << endl 
          << "\tIgnoring the second declaration." << endl;
      }
    } 
};

class NodeEmptyBrackets : public Node
{
  public:
    NodeEmptyBrackets(Node* moreBrackets=0) : Node(moreBrackets) 
    {
      sval = "[]";
    }

    virtual void prettyPrint(ostream* out)
    {
      if(left) left->prettyPrint(out);
      *out << "[]";
    }

    virtual string getstring() const
    {
      if(left) return sval + left->getstring();
      else return sval;
    }
};

class nodeComparatorExp : public Node
{
  public:
    enum Comparator{
      GT,
      LT,
      EQ,
      NEQ,
      GEQ,
      LEQ
    };

    nodeComparatorExp(Comparator cp, Node* lf, Node*rt):Node(lf,rt)
    {
      myComparator = cp;
    }

    virtual void prettyPrint(ostream* out = 0)
    {
      if(left) left->prettyPrint(out);
      *out << getComparatorString();
      if(right) right->prettyPrint(out);
      *out << " ";
    }
  
  protected:
    Comparator myComparator;

  private:
    string getComparatorString()
    {
      switch (myComparator) 
      {
        case GT:
          return " > ";
          break;
        case LT:
          return " < ";
          break;
        case EQ:
          return " == ";
          break;
        case NEQ:
          return " != ";
          break;
        case GEQ:
          return " >= ";
          break;
        case LEQ: 
          return " <= ";
          break;
        default:
          return "";
          break;
      }
    }

    virtual SymbolTableEntry* typeCheck(SymbolTable* parent)
    {
      SymbolTableEntry* entry1 = left->typeCheck(parent);
      SymbolTableEntry* entry2 = right->typeCheck(parent);

      if(!entry1 || !entry2){
        cout << "Type error (" << line << ", " << col << "): Unknown type in "
          << "comparison." << endl;
      }

      string type1 = entry1->getType();
      string type2 = entry2->getType();

      // "numeric value" means a literal integer. In this case we do not care.
      if(type1 == "numeric value"){
        type1 = "int";
      }

      if(type2 == "numeric value"){
        type2 = "int";
      }

      if(type1 == "int" && type2 == "int"){
        return new SymbolTableEntry("comparison", "int");
      } else {
        cout << "Type error (" << line << ", " << col << "): Comparisons "
          "require 'int' operands." << endl;
        return 0;
      }
    }
};

class nodeDot : public Node
{
  public:
    nodeDot(Node* lf, Node* rt) : Node(lf,rt){}

    virtual void prettyPrint(ostream* out = 0)
    {
      if(left) left->prettyPrint(out);
      *out << ".";
      if(right) right->prettyPrint(out);
    }

    /* This was by far the hardest algorithm to implement. 
     * Here is pseudocode to help understand it:
     * 
     * 1) Get the entry for the variable to the left of this one.
     * 2) If the entry is a class (i.e. it has a symbol table) then
     *    find this node's entry in it.
     * 3) If this node is a variable (i.e. has no symbol table) then
     *    it must be in aother class. Find it's symbol table entry by searching
     *    for the type.
     * 4) If we could find an entry in either step 2 or 3 return it. 
     *    Otherwise, log an error and return 0.
     */
    virtual SymbolTableEntry* typeCheck(SymbolTable* parent)
    {
      //cout << "NodeDot: Type checking." << endl;
      SymbolTableEntry* entry = 0; 
      SymbolTableEntry* myIdent = 0;
      entry = left->typeCheck(parent);

      // `entry` is either a class or a variable
      if(entry){
        // If entry is a class we need to find the variable entry.
        if(entry->getSymbolTable()) {
          myIdent = entry->getSymbolTable()->find(right->getstring());

        // If entry is a variable we need to find the class entry,
        // THEN the variable entry.
        } else {
          myIdent = parent->find(entry->getType());
          if(myIdent->getSymbolTable()){
            myIdent = myIdent->getSymbolTable()->find(right->getstring());
          }
        }
      }

      if(myIdent){
        return myIdent;
      } else {
        cout << "Type error (" << line << ", " << col 
          << "): Unrecognized identifier '" << right->getstring()
          << "'" << endl;
        return 0;
      }
    }
};

class NodeNameBrack : public Node
{
  public:
    NodeNameBrack(Node* name, Node* bracket) : Node(name, bracket) {}

    virtual SymbolTableEntry* typeCheck(SymbolTable* parent)
    {
      right->typeCheck(parent);
      SymbolTableEntry* thisEntry = left->typeCheck(parent);
      
      if(!thisEntry){
        return 0;
      }

      string thisType = thisEntry->getType();
      int size = thisType.size();

      if(size < 2 || thisType.substr(size - 2, size - 1) != "[]"){
        cout << "Type error (" << line << ", " << col << "): Too many "
          << "dimensions in bracket expression." << endl;
        return 0;
      }

      return new SymbolTableEntry("name", thisType.substr(0, thisType.size() - 2));
    }
};

class nodeBracketExp : public Node
{
  public:
    nodeBracketExp(Node* exp) : Node(exp, 0){}

    virtual void prettyPrint(ostream* out = 0)
    {
      *out << "[";
      if(left) left->prettyPrint(out);
      *out << "]";
      return;
    }

    virtual SymbolTableEntry* typeCheck(SymbolTable* parent)
    {
      SymbolTableEntry* thisEntry = left->typeCheck(parent);

      if(!thisEntry){
        return 0;
      }

      if(thisEntry->getType() == "numeric value"){
        return new SymbolTableEntry("int", "int");
      }

      if(thisEntry->getType() != "int"){
        cout << "Type error (" << line << ", " << col << "): int value "
          << "required inside brackets.";
        return 0;
      }

      return thisEntry;
    }
};

class nodeNewExp : public Node
{
  public:
    nodeNewExp(Node* lf, Node* rt) : Node(lf,rt) {}

    virtual void prettyPrint(ostream* out = 0)
    {
      *out << "new ";
      if(left) left->prettyPrint(out);
      if(right) right->prettyPrint(out);
      *out << endl;
      return;
    }

    virtual SymbolTableEntry* typeCheck(SymbolTable* parent)
    {
      Node* brackExps = right;
      SymbolTableEntry* type = left->typeCheck(parent);

      if(!type){
        // I could print another error here, but there's no point.
        return 0;
      }

      string typeString = type->getType();
      if(typeString != "int"){
        typeString = type->getIdentifier();
      }

      // Add up all of the brackets
      while(brackExps->getleft()){
        // Can't forget to type check the expressions inside the brackets.
        // If the expressions error out I'll still let this function proceed.
        // Why not?
        brackExps->typeCheck(parent);
        typeString += "[]";
        brackExps = brackExps->getleft();
      }

      return new SymbolTableEntry("issa expression", typeString);
    }
};

class NodeNewExpBrack : public Node
{
  public:
    NodeNewExpBrack(Node* newType, Node* brackExp, Node* multiBrack) 
                    : Node(newType, multiBrack)
    {
      middle = brackExp;
    }

    virtual SymbolTableEntry* typeCheck(SymbolTable* parent)
    {
      Node* brackExps = middle;
      Node* multiBrack = right;
      SymbolTableEntry* type = left->typeCheck(parent);
      bool isOneEmpty = false;

      if(!type){
        // I could print another error here, but there's no point.
        return 0;
      }

      string typeString = type->getType();
      if(typeString != "int"){
        typeString = type->getIdentifier();
      }

      // Add up all of the brackets
      while(brackExps->getleft()){
        // Can't forget to type check the expressions inside the brackets.
        // If the expressions error out I'll still let this function proceed.
        // Why not?
        brackExps->typeCheck(parent);
        typeString += "[]";
        brackExps = brackExps->getleft();
      }

      while(multiBrack){
        typeString += "[]";
        multiBrack = multiBrack->getleft();
        if(isOneEmpty){
          cout << "Type error (" << line << ", " << col << "): only one "
            << "bracket can be empty." << endl;
          return 0;
        }
        isOneEmpty = true;
      }

      return new SymbolTableEntry("issa expression", typeString);
    }

  protected:
    Node* middle;
};

class NodeNewBrack : public Node
{
  public: 
    NodeNewBrack(Node* newType, Node* bracks) : Node(newType, bracks) {}

    virtual SymbolTableEntry* typeCheck(SymbolTable* parent)
    {
      Node* multiBrack = right;
      SymbolTableEntry* type = left->typeCheck(parent);

      if(!type){
        // I could print another error here, but there's no point.
        return 0;
      }

      string typeString = type->getType();
      if(typeString != "int"){
        typeString = type->getIdentifier();
      }

      while(multiBrack){
        typeString += "[]";
        multiBrack = multiBrack->getleft();
      }

      return new SymbolTableEntry("issa expression", typeString);
    }
};

class NodeNewConstructor : public Node
{
  public:
    NodeNewConstructor(Node* identifier, Node* paramList) 
                            : Node(identifier, paramList) {}
    
    virtual SymbolTableEntry* typeCheck(SymbolTable* parent)
    {
      SymbolTableEntry* entry = parent->find(left->getstring());
      SymbolTable* myTable;
      string type;

      // If the class doesn't exist
      if(!entry || !entry->getSymbolTable()){
        cout << "Type error (" <<line<< ", " <<col<< "): Unknown constructor '"
          << left->getstring() << "'" << endl;
      }

      myTable = entry->getSymbolTable();
      entry = right->typeCheck(parent);

      // Concatinate parameters string;
      type += left->getstring();
      type += " ";
      if(entry){
        type += entry->getType();
      }

      if(myTable->find(type)){
        // Return a temporary entry where the type is the identifier
        return new SymbolTableEntry("constructor", left->getstring());
      } else {
        // Couldn't find a constructor entry that takes these arguments
        cout << "Type error (" << line << ", " << col 
          << "): Couldn't find constructor '" << type << "'" << endl;
        return 0;
      }
    }
};

class NodeNot : public Node
{
  public:
    NodeNot(Node* lf) : Node(lf){}

    virtual void prettyPrint(ostream* out)
    {
      *out << "!";
      if(left) left->prettyPrint(out);
      return;
    }

    virtual SymbolTableEntry* typeCheck(SymbolTable* parent)
    {
      return left->typeCheck(parent);
    }
};

class NodeFunctionCall : public Node
{
  public:
    NodeFunctionCall(Node* name, Node* params) : Node(name, params){}

    virtual void prettyPrint(ostream* out)
    {
      if(left) left->prettyPrint(out);
      *out << "( ";
      if(right) right->prettyPrint(out);
      *out << " )" << endl;
    }

    virtual SymbolTableEntry* typeCheck(SymbolTable* parent)
    {
      string type;

      // Get the arguments
      SymbolTableEntry* arglist = right->typeCheck(parent);

      // Concatinate the string;
      type += left->getstring();
      type += " ";
      if(arglist){
        type += arglist->getType();
      }

      if(parent->find(type)){
        return parent->find(type);
      } else {
        cout << "Type error (" << line << ", " << col 
          << "): Invalid function call : " << type << endl;
        return 0;
      }
    }
};

class NodeClass : public Node
{
  public:
    NodeClass(Node* lf, Node* rt) : Node(lf, rt){}

    virtual void prettyPrint(ostream* out)
    {
      *out << "Class:" << endl;
      if(left) left->prettyPrint(out);
      if(right) right->prettyPrint(out);
      *out << "END class" << endl;
    }

    virtual void generateSymbolTable(SymbolTable* parent)
    {
      //cout << "NodeClass: Generating symbol table." << endl;
      myTable = new SymbolTable(left->getstring(), parent);
      ClassSymbolTableEntry* entry = new ClassSymbolTableEntry(left->getstring(),
                                                               "class", 
                                                               myTable);

      if(!parent->insert(entry)){
        /* If insert failed there must alreay be an entry with the 
           same identifier */
        cout << "Type error (" << line << ", " << col 
          << "): '" << entry->getIdentifier() << "' declared twice"
          << " in the same scope." << endl 
          << "\tIgnoring the second declaration." << endl;
      }

      if(right) right->generateSymbolTable(myTable);
    }

    virtual SymbolTableEntry* typeCheck(SymbolTable* parent)
    {
      //cout << "NodeClass: Type checking." << endl;
      if(myTable && right) {
        return right->typeCheck(myTable);
      } else {
        return 0;
      }
    }

  private:
    SymbolTable* myTable;
};

class NodeClassBody : public Node
{
  public: 
    NodeClassBody(Node* lf=0, Node* md=0, Node* rt=0) : Node(lf, rt) 
    {
      middle = md;
    }

    virtual void prettyPrint(ostream* out)
    {
      *out << "Class body:" << endl;
      if(left) left->prettyPrint(out);
      if(middle) middle->prettyPrint(out);
      if(right) right->prettyPrint(out);
      *out << "END Class body" << endl;
    }

    virtual void generateSymbolTable(SymbolTable* parent)
    {
      //cout << "NodeClassBody: Generating symbol table." << endl;
      if(left) left->generateSymbolTable(parent);
      if(right) right->generateSymbolTable(parent);
      if(middle) middle->generateSymbolTable(parent);
    }

    virtual SymbolTableEntry* typeCheck(SymbolTable* parent)
    {
      //cout << "NodeClassBody: Type checking." << endl;
      if(left) left->typeCheck(parent);
      if(right) right->typeCheck(parent);
      if(middle) middle->typeCheck(parent);

      // Classes don't really need to return anything here.
      return 0;
    }

  protected:
    Node* middle;
};

class NodeType : public Node
{
  public:
    NodeType(Node* lf=0, Node* rt=0) : Node(lf,rt) 
    {
      if(!lf)
      {
        if(!rt)
        {
          sval = "int";
        }
        else
        {
          sval = "int" + right->getstring();
        }
      } 
      else if(!rt)
      {
        sval = left->getstring();
      }
      else
      {
        sval = left->getstring() + right->getstring();
      }
    }

    virtual void prettyPrint(ostream* out)
    {
      *out << "int ";
    }
};

class NodeNewType : public Node
{
  public:
    NodeNewType(Node* ident=0) : Node(ident) {}

    virtual SymbolTableEntry* typeCheck(SymbolTable* parent)
    {
      if(!left){
        return new SymbolTableEntry("issa int", "int");
      } else {
        SymbolTableEntry* thisEntry = parent->find(left->getstring());
        if(!thisEntry){
          cout << "Type error (" << line << ", " << col << "): Unknown type '"
            << left->getstring() << "'" << endl; 
          return 0;
        }
        return thisEntry;
      }
    }
};

class NodeConstructorDec : public Node
{
  public:
    NodeConstructorDec(Node* lf, Node* rt) : Node(lf, rt) {}

    virtual void prettyPrint(ostream* out)
    {
      *out << "Constructor Declaration:" << endl;
      if(left) left->prettyPrint(out);
      *out << endl;
      if(right) right->prettyPrint(out);
      *out << "END Constructor Declaration" << endl;
    }

    virtual void generateSymbolTable(SymbolTable* parent)
    {
      //cout << "NodeConstructorDec: Generating symbol table." << endl;
      vector<string>* paramList = 0;
      string blockName = left->getstring();
      blockName += " <";

      if(right->getleft())
      {
        paramList = new vector<string>();
        right->getleft()->addSValToVector(paramList);
        
        for(int i = 0; i < paramList->size(); ++i)
        {
          blockName += " " + paramList->at(i);
        }
      }
      blockName += " >";

      ConstructorSymbolTableEntry* entry = new ConstructorSymbolTableEntry(blockName,
                                                                           "constructor");
      if(parent->insert(entry)){
        right->setval(blockName);
      } else {
        /* If insert failed there must alreay be an entry with the 
           same identifier */
        cout << "Type error (" << line << ", " << col 
          << "): '" << entry->getIdentifier() << "' declared twice"
          << " in the same scope." << endl 
          << "\tIgnoring the second declaration." << endl;
      }

      right->generateSymbolTable(parent);
    }

    virtual SymbolTableEntry* typeCheck(SymbolTable* parent)
    {
      if(hasReturn()){
        cout << "Type error (" << line << ", " << col << "): Constructors"
          << " are not allowed to have non-void return statements." << endl;
      }
      //cout << "NodeConstructorDec: Type checking." << endl;
      if(right) {
        return right->typeCheck(parent);
      } else {
        return 0;
      }
    }    
};

class NodeMethodDec : public Node
{
  public:
    NodeMethodDec(Node* lf, Node* rt) : Node(lf, rt) {}

    virtual void prettyPrint(ostream* out)
    {
      *out << "Method Declaration:" << endl;
      if(left) left->prettyPrint(out);
      if(right) right->prettyPrint(out);
      *out << "END Method Declaration" << endl;
    }

    virtual void generateSymbolTable(SymbolTable* parent)
    {
      //cout << "NodeMethodDec: Generating symbol table." << endl;
      vector<string>* paramList = 0;
      string blockName = right->getstring();

      blockName += " <";
      if(right->getright()->getleft()){
        paramList = new vector<string>();
        right->getright()->getleft()->addSValToVector(paramList);

        for(int i = 0; i < paramList->size(); ++i)
        {
          blockName += " " + paramList->at(i);
        }
      }
      blockName += " >";
      
      MethodSymbolTableEntry* entry = new MethodSymbolTableEntry(blockName,
                                                                left ? 
                                                                left->getstring() :
                                                                "void");

      if(parent->insert(entry)){
        right->getright()->setval(blockName);
      } else {
        /* If insert failed there must already be an entry with the 
           same identifier */
        cout << "Type error (" << line << ", " << col 
          << "): '" << entry->getIdentifier() << "' declared twice"
          << " in the same scope." << endl 
          << "\tIgnoring the second declaration." << endl;
      }

      right->generateSymbolTable(parent);
    }

    virtual SymbolTableEntry* typeCheck(SymbolTable* parent)
    {
      SymbolTableEntry* thisEntry = right->typeCheck(parent);
      if(!left){
        if(hasReturn()){
          cout << "Type error (" << line << ", " << col << "): Void function "
            << "cannot return a non-void value." << endl;
        }
      } else {
        isReturnValid(left->getstring());
      }
      return thisEntry;
    }
};

class NodeParameterList : public Node
{
  public: 
    NodeParameterList(Node* lf=0, Node* rt=0) : Node(lf, rt) {}

    virtual void prettyPrint(ostream* out)
    {
      *out << "Parameter List:" << endl;
      if(left) left->prettyPrint(out);
      if(right) right->prettyPrint(out);
      *out << "END Parameter List" << endl;
    }
};

class NodeParameter : public Node
{
  public:
    NodeParameter(Node* type, Node* identifier) : Node(type, identifier) {}

    virtual void prettyPrint(ostream* out)
    {
      *out << "Parameter:" << endl;
      if(left) left->prettyPrint(out);
      if(right) right->prettyPrint(out);
      *out << endl << "END Parameter" << endl;
    }

    virtual void addSValToVector(vector<string>* vec)
    {
      vec->push_back(left->getstring());
    }

    virtual void generateSymbolTable(SymbolTable* parent){
      SymbolTableEntry* newEntry = new SymbolTableEntry(right->getstring(), 
                                                        left->getstring());

      parent->insert(newEntry);
    }
};

class NodeBlock : public Node
{
  public: 
    NodeBlock(Node* block) : Node(block)
    {
      myTable = 0;
    }

    virtual void prettyPrint(ostream* out)
    {
      if(left) left->prettyPrint(out);
      *out << "END block" << endl;
    }

    virtual void generateSymbolTable(SymbolTable* parent)
    {
      //cout << "NodeBlock: Generating symbol table." << endl;
      myTable = new SymbolTable(sval.empty() ? "Inner Block" : sval, parent);
      left->generateSymbolTable(myTable);
    }

    virtual SymbolTableEntry* typeCheck(SymbolTable* parent)
    {
      //cout << "NodeBlock: Type Checking " << endl;
      if(myTable) {
        return left->typeCheck(myTable);
      } else {
        return 0;
      }
    }
  
  private:
    SymbolTable* myTable;
};

class NodeAssign : public Node
{
  public:
    NodeAssign(Node* lf, Node* rt) : Node(lf, rt) {}

    virtual void prettyPrint(ostream* out)
    {
      *out << "Assignment" << endl;
      if(left) left->prettyPrint(out);
      *out << " = ";
      if(right) {
        right->prettyPrint(out);
      } else {
        *out << "null" << endl;
      }
      *out << endl << "END assignment" << endl;
    }

    virtual SymbolTableEntry* typeCheck(SymbolTable* parent)
    {
      //cout << "NodeAssign: Type checking" << endl;

      SymbolTableEntry* leftEntry = left->typeCheck(parent);
      SymbolTableEntry* rightEntry = right->typeCheck(parent);

      if(!leftEntry || !rightEntry){
        cout << "Type error (" << line << ", " << col 
          << "): Unknown type in assignment." << endl;
        return 0;
      }

      string leftType = leftEntry->getType();
      string rightType = rightEntry->getType();

      // We cannot assign to null or to a literal value.
      if(leftType == "null" || leftType == "numeric value"){
        cout << "Type error (" << line << ", " << col 
          << "): Invalid lvalue in assignment." << endl;
        return 0;
      }

      // "numeric value" means a literal integer. In this case we do not care.
      if(rightType == "numeric value"){
        rightType = "int";
      }

      if(leftType == rightType){
        return new SymbolTableEntry("assignment", leftType);
      } else {
        cout << "Type error (" << line << ", " << col << "): Cannot assign '" 
          << rightType << "' to '" << leftType << "'"<< endl;
      }

      return 0;
    }
};

class NodeParamList : public Node
{
  public: 
    NodeParamList(Node* params) : Node(params) {}

    virtual void prettyPrint(ostream* out)
    {
      if(left) {
        left->prettyPrint(out);
      } else {
        *out << "void";
      }
    }

    virtual SymbolTableEntry* typeCheck(SymbolTable* parent)
    {
      string types;
      Node* arglist = left;
      SymbolTableEntry* thisEntry;

      if(!arglist){
        return new SymbolTableEntry("arglist", "< >");
      }

      types = ">";
      while(arglist){
        thisEntry = arglist->getright()->typeCheck(parent);

        if(thisEntry){
          types = " " + types;
          if(thisEntry->getType() == "numeric value"){
            types = "int" + types;
          } else {
            types = thisEntry->getType() + types;
          }
        } else {
          cout << "Type error (" << line << ", " << col 
            << "): Invalid parameters." << endl;
          return 0;
        }
        arglist = arglist->getleft();
      }
      types = "< " + types;

      return new SymbolTableEntry("arglist", types);
    }
};

class NodePrint : public Node
{
  public:
    NodePrint(Node* exp) : Node(exp) {}

    virtual void prettyPrint(ostream* out)
    {
      *out << "Print" << endl;
      if(left) left->prettyPrint(out);
      *out << "END prettyPrint" << endl;
    }

    virtual SymbolTableEntry* typeCheck(SymbolTable* parent)
    {
      Node* argument = left->getleft();
      SymbolTableEntry* entry;

      // Make sure all of the arguments are numbers.
      while(argument){
        entry = argument->getright()->typeCheck(parent);
        if(entry->getType() != "int" && entry->getType() != "numeric value"){
          cout << "Type error (" << line << ", " << col << "): print() only "
            << "accepts int arguments." << endl;
          return 0;
        }
        argument = argument->getleft();
      }

      return new SymbolTableEntry("print", "void");
    }
};

class NodeRead : public Node
{
  public:
    NodeRead() : Node() {}

    virtual void prettyPrint(ostream *out)
    {
      *out << "read()" << endl;
    }

    virtual SymbolTableEntry* typeCheck(SymbolTable* parent)
    {
      return new SymbolTableEntry("read", "int");
    }
};

class NodeFunct : public Node
{
  public:
    NodeFunct(Node* name, Node* paramList) : Node(name, paramList) {}

    virtual void prettyPrint(ostream* out)
    {
      *out << "Function Declaration:" << endl;
      if(left) left->prettyPrint(out);
      *out << "END function declaration" << endl;
    }

    virtual SymbolTableEntry* typeCheck(SymbolTable* parent)
    {
      SymbolTableEntry* classEntry = left->getleft()->typeCheck(parent);
      SymbolTableEntry* thisEntry = right->typeCheck(parent);

      if(!classEntry){
        cout << "Type error (" << line << ", " << col << "): Unknown type."
          << endl;
        return 0;
      }

      classEntry = parent->find(classEntry->getType());
      if(!classEntry->getSymbolTable()){
        cout << "Type error (" << line << ", " << col << "): Call does not "
          << "reference a class." << endl;
        return 0;
      }

      string type = left->getright()->getstring() + " " + thisEntry->getType();
      thisEntry = classEntry->getSymbolTable()->find(type);

      if(!thisEntry){
        cout << "Type error (" << line << ", " << col << "): Couldn't find '"
          << type << "' in " << classEntry->getIdentifier() << endl;
      }

      return thisEntry;
    }
};

class NodeWhile : public Node
{
  public:
    NodeWhile(Node* exp, Node* statement) : Node(exp, statement) {}

    virtual void prettyPrint(ostream* out)
    {
      *out << "While:" << endl;
      if(left) left->prettyPrint(out);
      if(right) right->prettyPrint(out);
      *out << "END while" << endl;
    }
};

class NodeConditional : public Node
{
  public:
    NodeConditional(Node* cond, Node* thn, Node* els=0) : Node(cond, thn) 
    {
      optionalElse = els;
    }

    virtual void prettyPrint(ostream* out)
    {
      *out << "If:" << endl;
      if(left) left->prettyPrint(out);
      *out << "Then:" << endl;
      if(right) right->prettyPrint(out);
      if(optionalElse){
        *out << "Else:" << endl;
        optionalElse->prettyPrint(out);
      }
      *out << "END if" << endl;
    }
  
  protected:
    Node* optionalElse;
};

class NodeOptional : public Node
{
  public:
    NodeOptional(Node* opt) : Node(opt) {}

    virtual void prettyPrint(ostream* out)
    {
      *out << "Option:" << endl;
      if(left) {
        if(left) left->prettyPrint(out);
      } else {
        *out << "void" << endl;
      }
      *out << "END option:" << endl;
    }

    virtual SymbolTableEntry* typeCheck(SymbolTable* parent)
    {
      if(left){
        if(left->typeCheck(parent)){
          myType = left->typeCheck(parent)->getType();
        }
        return left->typeCheck(parent);
      } else {
        return new SymbolTableEntry("void", "void");
      }
    }

    virtual bool hasReturn(){
      if(left) return true;
      else return false;
    }

    virtual bool isReturnValid(string type)
    {
      if(left){
        if(myType == "numeric value"){
          myType = "int";
        }

        if(myType != type){
          cout << "Type error (" << line << ", " << col << "): Return types"
            << " for function do not match declaration." << endl;
          return false;
        } else {
          return true;
        }
      } else {
        return true;
      }
    }

  protected:
    string myType;
};

class NodeEmptyParam : public Node
{
  public:
    NodeEmptyParam() : Node() {}

    virtual void prettyPrint(ostream* out)
    {
      *out << "void" << endl;
    }
};

class NodeThis : public Node
{
  public:
    NodeThis() : Node() {}

    virtual void prettyPrint(ostream* out)
    {
      *out << " this";
    }

    virtual SymbolTableEntry* typeCheck(SymbolTable* parent)
    {
      //cout << "NodeThis: Type checking" << endl;
      return parent->find(parent->getClassName());
    }
};

class NodeTemp : public Node
{
  public:
    NodeTemp(Node* ident, Node* block) : Node(ident, block) {}

    virtual void prettyPrint(ostream* out)
    {
      left->prettyPrint(out);
      right->prettyPrint(out);
    }

    virtual string getstring() const
    {
      return left->getstring();
    }

    virtual SymbolTableEntry* typeCheck(SymbolTable* parent)
    {
      return right->typeCheck(parent);
    }
};

class NodeParamListAndBlock : public Node
{
  public:
    NodeParamListAndBlock(Node* paramList, Node* Block) : Node(paramList, Block) {}

    virtual void generateSymbolTable(SymbolTable* parent)
    {
      // cout << "NodeParamListAndBlock: Generating symbol table." << endl;
      myTable = new SymbolTable(sval.empty() ? "Inner Block" : sval, parent);
      if(left) left->generateSymbolTable(myTable);
      if(right && right->getleft()) right->getleft()->generateSymbolTable(myTable);
    }

    virtual SymbolTableEntry* typeCheck(SymbolTable* parent)
    {
      // cout << "NodeParamListAndBlock: Type Checking " << endl;
      if(myTable) {
        if(right->getleft()){
          return right->getleft()->typeCheck(myTable);
        }
        else {
          return 0;
        }
      } else {
        return 0;
      }
    }
  
  private:
    SymbolTable* myTable;
};

#endif