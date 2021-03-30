#include "utilities.hpp"
#include "../string/string.hpp" 
#include <iostream>
#include "stack.hpp"
#include <stdlib.h>
#include <cstdio>
#include <vector>


// Given cp as the current char pointer within an infix expression, 
// 1: cp will advance to after next token
// 2: next token will be returned
String nextToken(const char* &cp) {
  switch(*cp) {
  case '+':
  case '-': 
  case '*': 
  case '/':
  case ' ':
  case '(':
  case ')':
    return String(*cp++);
  default:
    String result;
    while(*cp != ' ') 
      result += String(*cp++);
    return result;
  }
}

// Given expr is fully parenthesized valid infix expression,
// return expression converted to postfix.
String infix_to_postfix(char const *expr) {
  if (*expr == 0)
    return String();
  stack<String> s;
  String token;
  String lhs, rhs, op;
  char const *cur = expr;
  while(*cur != 0 && *cur != ';') {
    token = nextToken(cur);
    if (token == ")") {
      rhs = s.pop();
      op = s.pop();
      lhs = s.pop();
      s.push(lhs + " " + rhs + " " + op);
    } else if (token != "(" && token != " ")
      s.push(token);
  }
  return s.pop();
}

bool isOperator(String token) {
  return (token == "+" || token == "-" || token == "*" || token == "/");
}


String intToString(int i) {
  char buf[1024];
  sprintf(buf,"%d", i);
  return String(buf);
}

/*
String intToString(int i) {
  char buf[1024];
  return itoa(i, buf, 10);
}
*/

String operatorToOpcode(String op) {
  if (op == "+") 
    return "AD";
  else if (op == "-")
    return "SB";
  else if (op == "*")
    return "MU";
  else if (op == "/")
    return "DV";
  else 
    return "unexpected operator: " + op;
}

String generateAssembly(String lhs, String token, String rhs, String tmp) {
  return "   LD     " + lhs + "\n" 
    + "   " + operatorToOpcode(token) + "     " + rhs + "\n"
    + "   ST     " + tmp + "\n";
}


String postfix_to_assembly(String expr) {
  if (expr == "")
    return String();
  stack<String> s;
  String lhs, rhs, op;
  String result;
  int tmpCounter = 1;
  std::vector<String> exprVector = expr.split(' ');
  for (size_t i = 0; i < exprVector.size(); ++i) {
    String token = exprVector[i];
    if (isOperator(token)) {
      rhs = s.pop();
      lhs = s.pop();
      //      String tmp = "TMP" + tmpCounter++;      
      String tmp = "TMP" + intToString(tmpCounter++);
      result += generateAssembly(lhs, token, rhs, tmp);
      s.push(tmp);
    } else if (token != " ")
      s.push(token); // push operand
  }
  return result;
}
