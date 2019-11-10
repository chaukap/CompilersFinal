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

using std::string;
using std::endl;
using std::ostream;
using std::cout;


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
    string getstring() const
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

    virtual void print(ostream *out = 0)
    {
      if(left) left->print(out);
      if(right) right->print(out);
      //*out << endl;
      return;
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

class NodeNegative : public Node
{
  public:
    NodeNegative(Node *lf):Node(lf){}

    virtual void print(ostream *out = 0)
    {
      if(left) {
        *out << "-";
        left->print(out);
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
     *out << "+";
     left->print(out);
   }
};

class nodeNum : public Node
{
  public:
    nodeNum(int i)
    {
      ival=i;
    };

    virtual void print(ostream *out = 0)
    {
      *out << " " << ival;
    }
};

class nodeParExp : public Node
{
  public:
    nodeParExp(Node *lf=0,Node *rt=0):Node(lf,rt){}

    virtual void print(ostream *out = 0)
    {
      *out << "Parameter expression;" << endl;
      *out << "( ";
      if(left) left->print(out);
      if(right) right->print(out);
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
    }

    NodeIdentifier(string name) : Node(0, 0)
    {
      identifier = name;
    }

    virtual void print(ostream* out = 0)
    {
      *out << " " << identifier;
    }

  protected:
    string identifier;
};

class nodeVardec : public Node 
{
  public:
    nodeVardec(Node* lf=0, Node* md=0, Node* rt=0) : Node(lf,rt)
    {
      middle = md;
    }

    virtual void print(ostream* out = 0)
    {
      *out << "Vardec:" << endl;
      if(left) left->print(out);
      if(middle) middle->print(out);
      if(right) right->print(out);
      *out << endl << "END vardec" << endl;
    }

  protected:
    Node* middle;
};

class NodeEmptyBrackets : public Node
{
  public:
    NodeEmptyBrackets(Node* moreBrackets=0) : Node(moreBrackets) {}

    virtual void print(ostream* out)
    {
      if(left) left->print(out);
      *out << "[]";
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

    virtual void print(ostream* out = 0)
    {
      if(left) left->print(out);
      *out << getComparatorString();
      if(right) right->print(out);
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

    virtual void print(ostream* out = 0)
    {
      if(left) left->print(out);
      *out << ".";
      if(right) right->print(out);
    }
};

class nodeBracketExp : public Node
{
  public:
    nodeBracketExp(Node* exp) : Node(exp, 0){}

    virtual void print(ostream* out = 0)
    {
      *out << "[";
      if(left) left->print(out);
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

    virtual void print(ostream* out = 0)
    {
      *out << "new ";
      if(left) left->print(out);
      if(middle) middle->print(out);
      if(right) right->print(out);
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

    virtual void print(ostream* out)
    {
      *out << "!";
      if(left) left->print(out);
      return;
    }
};

class NodeFunctionCall : public Node
{
  public:
    NodeFunctionCall(Node* name, Node* params) : Node(name, params){}

    virtual void print(ostream* out)
    {
      if(left) left->print(out);
      *out << "( ";
      if(right) right->print(out);
      *out << " )" << endl;
    }
};

class NodeClass : public Node
{
  public:
    NodeClass(Node* lf, Node* rt) : Node(lf, rt){}

    virtual void print(ostream* out)
    {
      *out << "Class:" << endl;
      if(left) left->print(out);
      if(right) right->print(out);
      *out << "END class" << endl;
    }
};

class NodeClassBody : public Node
{
  public: 
    NodeClassBody(Node* lf=0, Node* md=0, Node* rt=0) : Node(lf, rt) 
    {
      middle = md;
    }

    virtual void print(ostream* out)
    {
      *out << "Class body:" << endl;
      if(left) left->print(out);
      if(middle) middle->print(out);
      if(right) right->print(out);
      *out << "END Class body" << endl;
    }

  protected:
    Node* middle;
};

class NodeSimpleType : public Node
{
  public:
    NodeSimpleType() {}

    virtual void print(ostream* out)
    {
      *out << "int ";
    }
};

class NodeTypeBracket : public Node
{
  public:
    NodeTypeBracket(Node* type) : Node(type) {}

    virtual void print(ostream* out)
    {
      left->print(out);
      *out << "[]";
    }
};

class NodeConstructorDec : public Node
{
  public:
    NodeConstructorDec(Node* lf=0, Node* rt=0) : Node(lf, rt) {}

    virtual void print(ostream* out)
    {
      *out << "Constructor Declaration:" << endl;
      if(left) left->print(out);
      *out << endl;
      if(right) right->print(out);
      *out << "END Constructor Declaration" << endl;
    }
};

class NodeMethodDec : public Node
{
  public:
    NodeMethodDec(Node* lf=0, Node* md=0, Node* rt=0) : Node(lf, rt)
    {
      middle = md;
    }

    virtual void print(ostream* out)
    {
      *out << "Method Declaration:" << endl;
      if(left) left->print(out);
      if(middle) middle->print(out);
      if(right) right->print(out);
      *out << "END Method Declaration" << endl;
    }

  protected:
    Node* middle;
};

class NodeParameterList : public Node
{
  public: 
    NodeParameterList(Node* lf=0, Node* rt=0) : Node(lf, rt) {}

    virtual void print(ostream* out)
    {
      *out << "Parameter List:" << endl;
      if(left) left->print(out);
      if(right) right->print(out);
      *out << "END Parameter List" << endl;
    }
};

class NodeParameter : public Node
{
  public:
    NodeParameter(Node* lf, Node* rt) : Node(lf, rt) {}

    virtual void print(ostream* out)
    {
      *out << "Parameter:" << endl;
      if(left) left->print(out);
      if(right) right->print(out);
      *out << endl << "END Parameter" << endl;
    }
};

class NodeBlock : public Node
{
  public: 
    NodeBlock(Node* block) : Node(block){}

    virtual void print(ostream* out)
    {
      *out << "Block:" << endl;
      if(left) left->print(out);
      *out << "END block" << endl;
    }
};

class NodeAssign : public Node
{
  public:
    NodeAssign(Node* lf, Node* rt) : Node(lf, rt) {}

    virtual void print(ostream* out)
    {
      *out << "Assignment" << endl;
      if(left) left->print(out);
      *out << " = ";
      if(right) {
        right->print(out);
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

    virtual void print(ostream* out)
    {
      if(left) {
        left->print(out);
      } else {
        *out << "void";
      }
    }
};

class NodePrint : public Node
{
  public:
    NodePrint(Node* exp) : Node(exp) {}

    virtual void print(ostream* out)
    {
      *out << "Print" << endl;
      if(left) left->print(out);
      *out << "END print" << endl;
    }
};

class NodeRead : public Node
{
  public:
    NodeRead() : Node() {}

    virtual void print(ostream *out)
    {
      *out << "read()" << endl;
    }
};

class NodeFunct : public Node
{
  public:
    NodeFunct(Node* name, Node* paramList) : Node(name, paramList) {}

    virtual void print(ostream* out)
    {
      *out << "Function Declaration:" << endl;
      if(left) left->print(out);
      *out << "END function declaration" << endl;
    }
};

class NodeWhile : public Node
{
  public:
    NodeWhile(Node* exp, Node* statement) : Node(exp, statement) {}

    virtual void print(ostream* out)
    {
      *out << "While:" << endl;
      if(left) left->print(out);
      if(right) right->print(out);
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

    virtual void print(ostream* out)
    {
      *out << "If:" << endl;
      if(left) left->print(out);
      *out << "Then:" << endl;
      if(right) right->print(out);
      if(optionalElse){
        *out << "Else:" << endl;
        optionalElse->print(out);
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

    virtual void print(ostream* out)
    {
      *out << "Option:" << endl;
      if(left) {
        if(left) left->print(out);
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

    virtual void print(ostream* out)
    {
      *out << "void" << endl;
    }
};

class NodeThis : public Node
{
  public:
    NodeThis() : Node() {}

    virtual void print(ostream* out)
    {
      *out << " this";
    }
};

#endif