//
// Created by Riley Connors on 11/9/23.
//

#include <iostream>
#include <stack>
#include <string>

#include "itpFunctions.h"

// Function to check if a character is an operator
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '%';
}

// Function to return precedence of operators
int precedence(char c) {
    if(c == '+' || c == '-') {
        return 1;
    } else if(c == '*' || c == '/' || c == '%') {
        return 2;
    }
    return -1;
}

// Function to check if an expression is balanced
bool isBalanced(const string &expression) {
    stack<char> stack;
    for (char c : expression) {
        switch (c) {
            case '{': case '(': case '[':
                stack.push(c);
                break;
            case '}':
                if (stack.empty() || stack.top() != '{') return false;
                stack.pop();
                break;
            case ')':
                if (stack.empty() || stack.top() != '(') return false;
                stack.pop();
                break;
            case ']':
                if (stack.empty() || stack.top() != '[') return false;
                stack.pop();
                break;
        }
    }
    return stack.empty();
}

// Function to convert infix expression to postfix expression. Returns either "expression not balanced" or the postfix expression. Uses stack.
string infixToPostfix(const string &expression) {
    if (!isBalanced(expression)) {
        return "The expression is invalid: Unbalanced parentheses.";
    }
    stack<char> stack;
    string postfix = "The postfix expression is: ";
    for (char c: expression) {
        if (isalpha(c) || isdigit(c)) {
            postfix += c;
        } else if (c == '(') {
            stack.push(c);
        } else if (c == ')') {
            while (!stack.empty() && stack.top() != '(') {
                postfix += stack.top();
                stack.pop();
            }
            stack.pop();
        } else if (isOperator(c)) {
            while (!stack.empty() && precedence(c) <= precedence(stack.top())) {
                postfix += stack.top();
                stack.pop();
            }
            stack.push(c);
        }
    }
    while (!stack.empty()) {
        postfix += stack.top();
        stack.pop();
    }
    return postfix;
}