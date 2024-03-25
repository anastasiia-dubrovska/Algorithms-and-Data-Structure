#include <string>
#include <vector>
#include<cmath>


using namespace std;
int Priority(char c)
{
    if (c == '+' || c == '-')
        return 0;
    if (c == '#')
        return -1;
    if (c == '*' || c == '/')
        return 1;
    if (c == '^')
        return 2;
}
class Stack
{
private:
    vector <char> Vector;
    int push_index = 0;
public:
    void init(int);
    bool is_empty();
    void push(char value);
    char pop();
    char top();
};
void Stack::init(int k)
{
    Vector.resize(k);
    return;
}
bool Stack::is_empty()
{
    if (push_index == 0)
        return true;
    else
        return false;
}
void Stack::push(char value)
{
    Vector[push_index] = value;
    ++push_index;
    return;
}
char Stack::pop()
{
    if (push_index == 0)
        return 0;
    else
    {
        --push_index;
        return Vector[push_index];
    }
}
char Stack::top()
{
    if (push_index == 0)
        return 0;
    else
    {
        int i = push_index - 1;
        return Vector[i];
    }
}
string strOp(string a, string b, char c)
{
    string s = "";
    if (c == '*' || c == '/' || c == '^')
    {
        s += a;

        s += c;
        s += b;
        return s;
    }
    else
    {
        s += '(';
        s += a;

        s += c;
        s += b;
        s += ')';
        return s;
    }
}
double op(double a, double b, char c)
{
    if (c == '*')
    {
        return a * b;
    }
    if (c == '/')
    {
        return a / b;
    }
    if (c == '+')
    {
        return a + b;
    }
    if (c == '-')
    {
        return a - b;
    }
    if (c == '^')
    {
        return pow(a, b);
    }
}
class StackForRes
{
private:
    vector <double> Vector;
    int push_index = 0;
public:
    void init(int);
    bool is_empty();
    void push(double value);
    double pop();
};
void StackForRes::init(int k)
{
    Vector.resize(k);
    return;
}
bool StackForRes::is_empty()
{
    if (push_index == 0)
        return true;
    else
        return false;
}
void StackForRes::push(double value)
{
    Vector[push_index] = value;
    ++push_index;
    return;
}
double StackForRes::pop()
{
    if (push_index == 0)
        return 0;
    else
    {
        --push_index;
        return Vector[push_index];
    }
}
class StackForExp
{
private:
    vector <string> Vector;
    int push_index = 0;
public:
    void init(int);
    bool is_empty();
    void push(string value);
    string pop();
};
void StackForExp::init(int k)
{
    Vector.resize(k);
    return;
}
bool StackForExp::is_empty()
{
    if (push_index == 0)
        return true;
    else
        return false;
}
void StackForExp::push(string value)
{
    Vector[push_index] = value;
    ++push_index;
    return;
}
string StackForExp::pop()
{
    if (push_index == 0)
        return 0;
    else
    {
        --push_index;
        return Vector[push_index];
    }
}
class StackForStr
{
private:
    vector <string> Vector;
    int push_index = 0;
public:
    void init(int);
    bool is_empty();
    void push(string value);
    string pop();
    string top();
};
void StackForStr::init(int k)
{
    Vector.resize(k);
    return;
}
bool StackForStr::is_empty()
{
    if (push_index == 0)
        return true;
    else
        return false;
}
void StackForStr::push(string value)
{
    Vector[push_index] = value;
    ++push_index;
    return;
}
string StackForStr::pop()
{
    if (push_index == 0)
        return 0;
    else
    {
        --push_index;
        return Vector[push_index];
    }
}
string StackForStr::top()
{
    if (push_index == 0)
        return 0;
    else
    {
        int i = push_index - 1;
        return Vector[i];
    }
}
