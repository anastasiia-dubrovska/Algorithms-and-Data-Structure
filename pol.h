#include <iostream>
#include <stack>
#include <string>
#include <sstream>
using namespace std;

// Перевірка, чи є символ оператором
bool is_operator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

// Отримання пріоритету оператора
int get_priority(char c) {
    if (c == '+' || c == '-') {
        return 1;
    }
    else if (c == '*' || c == '/') {
        return 2;
    }
    else {
        return 0;
    }

}
double calculate_rpn(const std::string& rpn) {
    stack<double> operands;
    for (char c : rpn) {
        if (isdigit(c)) {
            operands.push(c - '0');
        }
        else if (is_operator(c)) {
            double operand2 = operands.top();
            operands.pop();
            double operand1 = operands.top();
            operands.pop();

            switch (c) {
            case '+':
                operands.push(operand1 + operand2);
                break;
            case '-':
                operands.push(operand1 - operand2);
                break;
            case '*':
                operands.push(operand1 * operand2);
                break;
            case '/':
                operands.push(operand1 / operand2);
                break;
            }
        }
    }

    return operands.top();
}


