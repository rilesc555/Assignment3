#include <iostream>
#include <stack>
#include <string>

#include "itpFunctions.h"

using namespace std;



int main() {
    string expression;
    cout << "Enter an infix expression, or \"quit\" to exit: ";
    getline(cin, expression);
    while (expression != "quit") {
        if (!isBalanced(expression)) {
            cout << "The expression is invalid: Unbalanced parentheses." << endl;
        } else {
            string postfix = infixToPostfix(expression);
            cout << "The postfix expression is: " << postfix << endl;
        }
        cout << "Enter an infix expression, or \"quit\" to exit: ";
        getline(cin, expression);
    }
    return 0;
}
