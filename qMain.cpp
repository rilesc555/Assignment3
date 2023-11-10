//
// Created by Riley Connors on 11/9/23.
//

#include <iostream>

#include "queue.h"

using namespace std;

int main() {
    Queue<int> q;

    // Example usage:
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout << "First element: " << q.peek() << endl;
    cout << "Queue size before dequeue: " << q.size() << endl;
    cout << "Removed element: " << q.dequeue() << endl;
    cout << "Queue size after dequeue: " << q.size() << endl;

    return 0;
}

