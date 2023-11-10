#include <iostream>
#include <stack>
#include <string>

#include "itpFunctions.h"
#include "queue.h"

using namespace std;

//tests infix to postfix and queue
int main() {

    string expression;
    cout << "Enter an infix expression, or \"quit\" to exit: ";
    getline(cin, expression);
    while (expression != "quit") {
        string postfix = infixToPostfix(expression);
        cout << postfix << endl;

        cout << "Enter an infix expression, or \"quit\" to exit: ";
        getline(cin, expression);
    }

    Queue<int> q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout << "First element: " << q.peek() << endl;
    cout << "Queue size before dequeue: " << q.size() << endl;
    cout << "Removed element: " << q.dequeue() << endl;
    cout << "Queue size after dequeue: " << q.size() << endl;
    return 0;
}

