//
// Created by Riley Connors on 11/9/23.
//

#ifndef ASSIGNMENT3_ITPFUNCTIONS_H
#define ASSIGNMENT3_ITPFUNCTIONS_H

#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isOperator(char c);

int precedence(char c);

bool isBalanced(const string &expression);

string infixToPostfix(const string &expression);
#endif //ASSIGNMENT3_ITPFUNCTIONS_H
