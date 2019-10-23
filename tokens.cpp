// tokens.cpp
// Chandler Haukap
// 10/4/19
// COSC 4785 Program 2
// 
// Usefull functions when dealing with tokens.
#include "tokens.hpp"
#include<string.h>

char buf[256];

// Takes a token and returns it's string representation. 
// DON'T WORRY ABOUT FREEING ANYTHING I WILL TAKE CARE OF THAT
char* tokenToString(token t){
  switch(t){
    case IGNORE:
      strcpy(buf, "IGNORE");
      break;
    case ERRORS:
      strcpy(buf, "ERRORS");
      break;
    case ER_WD:
      strcpy(buf, "ER_WD");
      break;
    case ER_CH:
      strcpy(buf, "ER_CH");
      break;
    case COMMA:
      strcpy(buf, "COMMA");
      break;
    case DOT:
      strcpy(buf, "DOT");
      break;
    case RPAREN:
      strcpy(buf, "RPAREN");
      break;
    case LPAREN:
      strcpy(buf, "LPAREN");
      break;
    case THIS:
      strcpy(buf, "THIS");
      break;
    case IF:
      strcpy(buf, "IF");
      break;
    case WHILE:
      strcpy(buf, "WHILE");
      break;
    case RBRACK:
      strcpy(buf, "RBRACK");
      break;
    case LBRACK:
      strcpy(buf, "LBRACK");
      break;
    case NEQ:
      strcpy(buf, "NEQ");
      break;
    case EQ:
      strcpy(buf, "EQ");
      break;
    case LT:
      strcpy(buf, "LT");
      break;
    case GT:
      strcpy(buf, "GT");
      break;
    case LEQ:
      strcpy(buf, "LEQ");
      break;
    case GEQ:
      strcpy(buf, "GEQ");
      break;
    case AND:
      strcpy(buf, "AND");
      break;
    case OR:
      strcpy(buf, "OR");
      break;
    case NOT:
      strcpy(buf, "NOT");
      break;
    case PLUS:
      strcpy(buf, "PLUS");
      break;
    case MINUS:
      strcpy(buf, "MINUS");
      break;
    case TIMES:
      strcpy(buf, "TIMES");
      break;
    case DIV:
      strcpy(buf, "DIV");
      break;
    case MOD:
      strcpy(buf, "MOD");
      break;
    case SEMI:
      strcpy(buf, "SEMI");
      break;
    case ASSIGN:
      strcpy(buf, "ASSIGN");
      break;
    case COMMENT:
      strcpy(buf, "COMMENT");
      break;
    case INT:
      strcpy(buf, "INT");
      break;
    case VOID:
      strcpy(buf, "VOID");
      break;
    case NULLT:
      strcpy(buf, "NULLT");
      break;
    case CLASS:
      strcpy(buf, "CLASS");
      break;
    case NEW:
      strcpy(buf, "NEW");
      break;
    case PRINT:
      strcpy(buf, "PRINT");
      break;
    case READ:
      strcpy(buf, "READ");
      break;
    case RETURN:
      strcpy(buf, "RETURN");
      break;
    case ELSE:
      strcpy(buf, "ELSE");
      break;
    case IDENT:
      strcpy(buf, "IDENT");
      break;
    case LBRACE:
      strcpy(buf, "LBRACE");
      break;
    case RBRACE:
      strcpy(buf, "RBRACE");
      break;
    case NUMBER:
      strcpy(buf, "NUMBER");
      break;
    default:
      strcpy(buf, "Unknown token!");
      break;
  }
  return buf;
}