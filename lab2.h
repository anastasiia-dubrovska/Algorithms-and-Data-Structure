#include <iostream>
const int MAX_SIZE = 3; // length of array

class Stack {
private:
    int top;
    int arr[MAX_SIZE];
public:
    Stack() {
        top = -1; // index of last element
    }

    void push(int x) { // add new element
        if (top == MAX_SIZE - 1) {
            std::cout << "Stack overflow\n";
            return;
        }
        arr[++top] = x;
    }

    void pop() { // remove last element
        if (top == -1) {
            std::cout << "Stack underflow\n";
            return;
        }
        top--;
    }

    int lastElement() { // show last element
        if (top == -1) {
            std::cout << "Stack is empty\n";
            return -1;
        }
        return arr[top];
    }

    bool isEmpty() { // check if stack has no elements
        return top == -1;
    }

    bool isFull() { // check if stack has number of elements that is equals to max size of array
        return top == MAX_SIZE - 1;
    }
};

