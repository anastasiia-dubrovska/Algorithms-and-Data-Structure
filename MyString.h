#pragma once
#include<iostream>
using namespace std;


const int MAX_LEN = 100;

class MyString {
private:
    char str[MAX_LEN];
public:
    MyString() {//встановлюємо перший символ на нульовий символ
        str[0] = '\0';
    }
    MyString(const char* s) {//ініціалізує рядок значенням нуль-термінованого масиву символів s
        int i = 0;
        while (s[i] != '\0') {
            str[i] = s[i];
            i++;
        }
        str[i] = '\0';
    }
    void set(const char* s) {//встановлює значення рядка нуль-термінованого масиву
        int i = 0;
        while (s[i] != '\0') {
            str[i] = s[i];
            i++;
        }
        str[i] = '\0';
    }
    const char* get() const { //повертає константний вказівник на дані рядка
        return str;
    }
    int length() const {// повертає довжину рядка, перераховуючи його символи до досягнення нульового символу
        int len = 0;
        while (str[len] != '\0') {
            len++;
        }
        return len;
    }
    char& operator[](int i) {//дозволяє лише читати окремі символи у рядку за допомогою індексу ію функція повертає контантне посилання на символ з індексом і
        return str[i];
    }
    const char& operator[](int i) const {
        return str[i];
    }
    MyString apply_rules() const {
        MyString output;
        int i = 0;
        int j = 0;

        while (str[i] != '\0') {
            char c = str[i];
            if (c == 'a') {
                output[j] = 'b';
            }
            else if (c == 'b') {
                output[j] = 'c';
            }
            else if (c == 'c') {
                output[j] = 'd';
            }
            else if (c == 'd') {
                output[j] = 'e';
            }
            else if (c == 'e') {
                output[j] = 'f';
            }
            else {
                output[j] = c;
            }
            i++;
            j++;
        }

        output[j] = '\0';
        return output;
    }
};

