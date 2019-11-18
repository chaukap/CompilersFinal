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
      yyline=yycol=nextline=nextcol=1;
      sval.clear();
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

    virtual void generateSymbolTable(SymbolTable* parent)
    {
      if(left) left->generateSymbolTable(parent);
      if(right) right->generateSymbolTable(parent);
    }

  protected:
    int yyline;
    int yycol;
    int ival;
    double dval;
    string sval;
    int nextcol;// not needed?
    int nextline;// not needed?
    Node *left,*right;
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
      SymbolTableEntry* entry = new SymbolTableEntry(right->getstring(),
                                                     left->getstring());
      parent->insert(entry);
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
};

class nodeNewExp : public Node
{
  public:
    nodeNewExp(Node* lf, Node* mid=0, Node* rt=0) : Node(lf,rt) 
    {
      middle = mid; 
    }

    virtual void prettyPrint(ostream* out = 0)
    {
      *out << "new ";
      if(left) left->prettyPrint(out);
      if(middle) middle->prettyPrint(out);
      if(right) right->prettyPrint(out);
      *out << endl;
      return;
    }

  protected:
    Node* middle;
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
      SymbolTable* table = new SymbolTable(left->getstring(), parent);
      ClassSymbolTableEntry* entry = new ClassSymbolTableEntry(left->getstring(),
                                                               "class", 
                                                               table);
      parent->insert(entry);

      if(right) right->generateSymbolTable(table);
    }
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
      if(left) left->generateSymbolTable(parent);
      if(right) right->generateSymbolTable(parent);
      if(middle) middle->generateSymbolTable(parent);
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
      SymbolTable* table = new SymbolTable(left->getstring(), parent);
      ConstructorSymbolTableEntry* entry = new ConstructorSymbolTableEntry(left->getstring(),
                                                                           "constructor",
                                                                           table);
      parent->insert(entry);
      
      if(right) right->generateSymbolTable(table);
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
      SymbolTable* table = new SymbolTable(right->getstring(),
                                           parent);
      MethodSymbolTableEntry* entry = new MethodSymbolTableEntry(right->getstring(),
                                                                left ? 
                                                                left->getstring() :
                                                                "void",
                                                                table);
      parent->insert(entry);
      
      
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
    NodeParameter(Node* lf, Node* rt) : Node(lf, rt) {}

    virtual void prettyPrint(ostream* out)
    {
      *out << "Parameter:" << endl;
      if(left) left->prettyPrint(out);
      if(right) right->prettyPrint(out);
      *out << endl << "END Parameter" << endl;
    }
};

class NodeBlock : public Node
{
  public: 
    NodeBlock(Node* block) : Node(block){}

    virtual void prettyPrint(ostream* out)
    {
      *out << "Block:" << endl;
      if(left) left->prettyPrint(out);
      *out << "END block" << endl;
    }
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
};

class NodeRead : public Node
{
  public:
    NodeRead() : Node() {}

    virtual void prettyPrint(ostream *out)
    {
      *out << "read()" << endl;
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
};

#endif