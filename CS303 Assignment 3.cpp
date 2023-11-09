// CS303 Assignment 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <string>
#include "Functions.h"
using namespace std;

int main() {
    
    // Creation of a new queue that can contain integers
    Queue<int> intQueue;
    intQueue.enqueue(12);
    intQueue.enqueue(24);
    intQueue.enqueue(32);
    cout << "Front element: " << intQueue.front() << endl;
    cout << "Dequeuing element: " << intQueue.dequeue() << endl;
    cout << (intQueue.isEmpty() ? "Queue is empty" : "Queue is not empty") << endl;
    cout << "Number of elements in the queue: " << intQueue.size() << endl << endl;

    // Creation of a new queue that can contain strings
    Queue<string> stringQueue;
    stringQueue.enqueue("Hello");
    stringQueue.enqueue("World");
    cout << "New string queue" << endl;
    cout << "Front element: " << stringQueue.front() << endl << endl;

    // Creation of a new empty queue
    Queue<int> emptyQueue;
    cout << "New empty queue" << endl;
    cout << emptyQueue.front() << endl;
    cout << emptyQueue.dequeue() << endl;
    cout << (emptyQueue.isEmpty() ? "Queue is empty" : "Queue is not empty") << endl << endl;

    // Activating the expression manager for infix to postfix conversion
    cout << "Moving to Balanced Parentheses Check" << endl;
    ExpressionManager::checkLine();

}
