#include"pol.h"
#include<cassert>


int main() {
    string input;

    // Читання вхідного рядка з консолі
    cout << "Введіть арифметичний вираз: ";
    getline(cin, input);

    // Перетворення вхідного рядка в зворотній польський запис
    string rpn = to_rpn(input);

    // Обчислення значення зворотнього польського запису
    double result = calculate_rpn(rpn);

    // Виведення результату на консоль
    cout << "Результат: " << result << endl;

    // Тести
    string test_input[] = { "3+4*2/(1-5)^2", "2*(3+4)-1", "10+(4-2)*6/3", "5-((1+2)*4)-3" };
    double expected_results[] = { 3.5, 13, 12, -14 };

    for (int i = 0; i < 4; i++) {
        string rpn = to_rpn(test_input[i]);
        double result = calculate_rpn(rpn);

        cout << "Тест " << i + 1 << ": " << test_input[i] << " = " << result;
        if (result == expected_results[i]) {
            cout << " (успішний)" << endl;
        }
        else {
            cout << " (невдало)" << endl;
        }
    }

    return 0;
}

