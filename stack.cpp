#include <iostream>
#include <cassert>
#include <stack> // stack STL

#include "./lab2.h"

int main() {
    // our custom stack
    Stack customStack;

    customStack.push(5);

    assert(customStack.lastElement() == 5);

    customStack.push(10);
    customStack.push(15);
    customStack.push(20); // output: Stack overflow cause of length of array is 3 and we try to insert fourth element

    assert(customStack.isFull() == 1);

    customStack.pop();

    assert(customStack.lastElement() == 10);

    customStack.pop();
    customStack.pop();
    customStack.pop(); // output: Stack underflow cause of array is empty cause of previously we remove 3 elements and we try to remove one more element

    assert(customStack.isEmpty() == 1);

    // ***********************************

    // stack STL
    std::stack<int> stackSTL;

    stackSTL.push(5);
    stackSTL.push(10);
    stackSTL.push(15);

    assert(stackSTL.top() == 15);

    stackSTL.pop();

    assert(stackSTL.top() == 10);

    stackSTL.pop();
    stackSTL.pop();

    assert(stackSTL.empty() == 1);

    std::cout << "all tests are passed!";

    return 0;
}