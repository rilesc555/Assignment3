//
// Created by Riley Connors on 11/9/23.
//

#include <iostream>
#include <stack>
#include <string>

#include "itpFunctions.h"

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '%';
}

int precedence(char c) {
    if(c == '+' || c == '-') {
        return 1;
    } else if(c == '*' || c == '/' || c == '%') {
        return 2;
    }
    return -1;
}

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

string infixToPostfix(const string &expression) {
    stack<char> stack;
    string postfix;
    for (char c : expression) {
        if (isalpha(c) || isdigit(c)) {
            postfix += c;
        } else if (c == '(') {
            stack.push(c);
        } else if (c == ')') {
            while (!stack.empty() && stack.top() != '(') {
                postfix += stack.top();
                stack.pop();
            }
            stack.pop(); // Remove the '(' from stack
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