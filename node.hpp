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
      *out << sval ;
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

class nodeMinus : public Node
{
  public:
    nodeMinus(Node *lf=0,Node *rt=0):Node(lf,rt){}

    virtual void print(ostream *out = 0)
    {
      if(left) {
        *out << "-";
        left->print(out);
      }
      //*out << endl;
      return;
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
      *out << ival;
      return;
    }
};

class nodeParExp : public Node
{
  public:
    nodeParExp(Node *lf=0,Node *rt=0):Node(lf,rt){}

    virtual void print(ostream *out = 0)
    {
      *out << "( ";
      if(left) left->print(out);
      if(right) right->print(out);
      *out << " )" ;
      return;
    }
};

class nodeIdentifier : public Node
{
  public:
    nodeIdentifier(string* name) : Node(0, 0)
    {
      identifier = *name;
    }

    nodeIdentifier(string name) : Node(0, 0)
    {
      identifier = name;
    }

    virtual void print(ostream* out = 0)
    {
      *out << identifier << " ";
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
      if(left) left->print(out);
      if(middle) middle->print(out);
      if(right) right->print(out);
      return;
    }

  protected:
    Node* middle;
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
      left->print(out);
      *out << getComparatorString();
      right->print(out);
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
      left->print(out);
      *out << ".";
      right->print(out);
    }
};

class nodeBracketExp : public Node
{
  public:
    nodeBracketExp(Node* exp) : Node(exp, 0){}

    virtual void print(ostream* out = 0)
    {
      *out << "[";
      left->print();
      *out << "]";
      return;
    }
};

class nodeNewExp : public Node
{
  public:
    nodeNewExp(bool hasParens, Node* lf, Node* mid=0, Node* rt=0) : Node(lf,rt) 
    {
      middle = mid; 
      parenthesis = hasParens;
    }

    virtual void print(ostream* out = 0)
    {
      *out << "new ";
      left->print(out);
      if(middle) middle->print(out);
      if(right) right->print(out);
      if(parenthesis) *out << "()";
      return;
    }

  protected:
    Node* middle;
    bool parenthesis;
};

class nodeNot : public Node
{
  public:
    nodeNot(Node* lf) : Node(lf){}

    virtual void print(ostream* out)
    {
      *out << "!";
      left->print(out);
      return;
    }
};

class nodeNameParen : public Node
{
  public:
    nodeNameParen(Node* lf) : Node(lf){}

    virtual void print(ostream* out)
    {
      left->print();
      *out << "()";
    }
};

#endif