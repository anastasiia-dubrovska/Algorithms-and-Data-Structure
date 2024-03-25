#pragma once
#include<iostream>
using namespace std;


const int MAX_LEN = 100;

class MyString {
private:
    char str[MAX_LEN];
public:
    MyString() {//������������ ������ ������ �� �������� ������
        str[0] = '\0';
    }
    MyString(const char* s) {//�������� ����� ��������� ����-������������ ������ ������� s
        int i = 0;
        while (s[i] != '\0') {
            str[i] = s[i];
            i++;
        }
        str[i] = '\0';
    }
    void set(const char* s) {//���������� �������� ����� ����-������������ ������
        int i = 0;
        while (s[i] != '\0') {
            str[i] = s[i];
            i++;
        }
        str[i] = '\0';
    }
    const char* get() const { //������� ����������� �������� �� ��� �����
        return str;
    }
    int length() const {// ������� ������� �����, ������������� ���� ������� �� ���������� ��������� �������
        int len = 0;
        while (str[len] != '\0') {
            len++;
        }
        return len;
    }
    char& operator[](int i) {//�������� ���� ������ ����� ������� � ����� �� ��������� ������� �� ������� ������� ��������� ��������� �� ������ � �������� �
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

