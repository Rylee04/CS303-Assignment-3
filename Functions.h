// Functions.h : This file contains function declarations and some implementations
#pragma once
#include <string>
#include <queue>
using namespace std;

// The ExpressionManager class: contains declarations for the postfix conversion functions
class ExpressionManager {

private:
    static bool isOperator(char c);
    static bool isOperand(char c);
    static int pemdas(char op);
    static bool balanced(const string& expression);
    static string convertInfix(const string& infix);

public:
    static void checkLine();

};

// The Queue class: contains declarations for the queue functions
template <typename T>
class Queue {

private:
    queue<T> elements;

public:
    void enqueue(const T& element);
    T dequeue();
    T front();
    bool isEmpty();
    size_t size();

};

// The enqueue function: adds an element to the queue
template <typename T>
void Queue<T>::enqueue(const T& element) {
    elements.push(element);
}

// The dequeue function: removes the first element of the queue and returns it
template <typename T>
T Queue<T>::dequeue() {
    // Checks if the queue is empty; returns the default value for the queue type if so
    if (isEmpty()) {
        cerr << "Queue is empty. Cannot dequeue. Returning default value: ";
        return T();
    }

    // If the queue isn't empty sets a temporary variable to return the front element and deletes the original
    T frontElem = elements.front();
    elements.pop();
    return frontElem;
}

// The front function: returns the first element in the queue
template <typename T>
T Queue<T>::front() {
    // Checks if the queue is empty; returns the default value for the queue type if so
    if (isEmpty()) {
        cerr << "Queue is empty. No front element. Returning default value: ";
        return T();
    }

    return elements.front();
}

// The isEmpty function: checks if the queue is empty
template <typename T>
bool Queue<T>::isEmpty() {
    return elements.empty();
}

// The size function: returns the number of elements in the queue
template <typename T>
size_t Queue<T>::size() {
    return elements.size();
}
