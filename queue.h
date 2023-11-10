//
// Created by Riley Connors on 11/9/23.
//

#ifndef ASSIGNMENT3_QUEUE_H
#define ASSIGNMENT3_QUEUE_H

using namespace std;

template <typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;
        Node(T d) : data(d), next(nullptr) {}
    };

    Node* front;  // pointer to the front of the queue
    Node* rear;   // pointer to the rear of the queue
    int count;    // number of elements in the queue

public:
    Queue() : front(nullptr), rear(nullptr), count(0) {}

    // Function to insert a new element at the rear of the queue
    void enqueue(T data) {
        Node* newNode = new Node(data);
        if (rear != nullptr) {
            rear->next = newNode;
        }
        rear = newNode;
        if (front == nullptr) {
            front = rear;
        }
        count++;
    }

    // Function to remove the front element of the queue and return it
    T dequeue() {
        if (isEmpty()) {
            throw out_of_range("Queue is empty");
        }
        Node* temp = front;
        T data = front->data;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
        count--;
        return data;
    }

    // Function to return the front element present in the queue without removing it
    T peek() const {
        if (isEmpty()) {
            throw out_of_range("Queue is empty");
        }
        return front->data;
    }

    // Function to check if the queue is empty
    bool isEmpty() const {
        return count == 0;
    }

    // Function to return the total number of elements present in the queue
    int size() const {
        return count;
    }

    // Destructor to clean up the memory of nodes
    ~Queue() {
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }
};

#endif //ASSIGNMENT3_QUEUE_H
