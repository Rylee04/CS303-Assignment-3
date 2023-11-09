// Functions.cpp : This file contains function implementations
#include <iostream>
#include <stack>
#include "Functions.h"
using namespace std;

// The isOperator function: checks if a character is a valid mathematical operator
bool ExpressionManager::isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%');
}

// The isOperand function: checks if a character is a valid letter or number
bool ExpressionManager::isOperand(char c) {
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'));
}

// The pemdas function: gives greater priority to multiplicative operations rather than addition/subtraction
int ExpressionManager::pemdas(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/' || op == '%') return 2;
    return 0;
}

// The balanced function: checks if there are the same amount of the same type of brackets
bool ExpressionManager::balanced(const string& expression) {

    stack<char> brackets;

    for (char c : expression) {

        // Finds opening brackets and pushes them onto a stack
        if (c == '(' || c == '[' || c == '{') {
            brackets.push(c);
        }
        // Finds closing brackets and compares them to the bracket on the stack; returns false if they're different or if the stack is empty
        else if (c == ')' || c == ']' || c == '}') {
            if (brackets.empty() || ((c == ')' && brackets.top() != '(') || (c == ']' && brackets.top() != '[') || (c == '}' && brackets.top() != '{'))) {
                return false;
            }

            // Removes the bracket on top of the stack after a successful comparison
            brackets.pop();

        }
    }

    return brackets.empty();

}

// The conversion function: performs the infix to post fix converstion
string ExpressionManager::convertInfix(const string& infix) {

    stack<char> operators;
    string postfix;

    for (char c : infix) {
        // Calls the isOperand function to check if a character is a valid letter or number and adds it to a string
        if (isOperand(c)) {
            postfix += c;
        }
        // Calls the isOperator function to check if a character is a valid operator
        else if (isOperator(c)) {
            // Checks priority
            while (!operators.empty() && pemdas(operators.top()) >= pemdas(c)) {

                // Adds the operator to the string and removes it from the stack
                postfix += operators.top();
                operators.pop();

            }

            // If lower priority or stack is empty pushes it to the stack
            operators.push(c);

        }
        // Finds an opening bracket and pushes it onto the stack
        else if (c == '(' || c == '[' || c == '{') {
            operators.push(c);
        }
        // Finds a closing bracket
        else if (c == ')' || c == ']' || c == '}') {
            // Checks that the top element of the stack is not an opening bracket
            while (!operators.empty() && operators.top() != '(' && operators.top() != '[' && operators.top() != '{') {
                
                // Adds elements to the string and removes from stack
                postfix += operators.top();
                operators.pop();

            }

            operators.pop();

        }
    }

    // After completing iterating through infix adds the rest of the stack onto the string
    // which should be operators in order of priority
    while (!operators.empty()) {

        postfix += operators.top();
        operators.pop();

    }

    return postfix;

}

void ExpressionManager::checkLine() {

    string infix;

    // Read infix expression from the user
    cout << "Enter the infix expression: ";
    getline(cin, infix);

    // Check for balanced brackets
    if (!balanced(infix)) {

        cerr << "Error: The expression has unbalanced parentheses." << endl;
        return;

    }

    // Convert infix to postfix
    string postfix = convertInfix(infix);
    cout << "Postfix Expression: " << postfix << endl;

}
