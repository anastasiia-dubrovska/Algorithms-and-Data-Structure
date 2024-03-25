#include <iostream>
#include"Pol_zapys.h"
/*#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include"x64/Debug/pol zapys.tlog/doctest.h"

// tests operators
TEST_CASE("Multiplication") {
    CHECK(op(2, 3, '*') == 6);
}

TEST_CASE("Division") {
    CHECK(op(6, 2, '/') == 3);
}

TEST_CASE("Addition") {
    CHECK(op(2, 3, '+') == 5);
}

TEST_CASE("Subtraction") {
    CHECK(op(3, 2, '-') == 1);
}

TEST_CASE("Power") {
    CHECK(op(2, 3, '^') == 8);
}
// test priority
TEST_CASE("Plus and Minus have priority 0") {
    CHECK(Priority('+') == 0);
    CHECK(Priority('-') == 0);
}

TEST_CASE("Hash has priority -1") {
    CHECK(Priority('#') == -1);
}

TEST_CASE("Multiplication and Division have priority 1") {
    CHECK(Priority('*') == 1);
    CHECK(Priority('/') == 1);
}

TEST_CASE("Power has priority 2") {
    CHECK(Priority('^') == 2);
}
//test strOp
TEST_CASE("Multiplication operator returns the expected string") {
    CHECK(strOp("2", "3", '*') == "2*3");
}

TEST_CASE("Division operator returns the expected string") {
    CHECK(strOp("4", "2", '/') == "4/2");
}

TEST_CASE("Power operator returns the expected string") {
    CHECK(strOp("2", "3", '^') == "2^3");
}

TEST_CASE("Addition operator returns the expected string") {
    CHECK(strOp("2", "3", '+') == "(2+3)");
}

TEST_CASE("Subtraction operator returns the expected string") {
    CHECK(strOp("4", "2", '-') == "(4-2)");
}*/

int main()
{

  int j;
  cout << "Enter your formula"<< endl;




  string Nexp;
  cin >> Nexp;
  Stack Symb;
  string Res;
  Symb.init(size(Nexp));
  Symb.push('#');
  int n = size(Nexp);
  for (int i = 0; i < n; ++i)
  {
    if (Nexp[i] != '/' && Nexp[i] != '*' && Nexp[i] != '-' && Nexp[i] != '+' && Nexp[i] != '^')
    {
      if (Nexp[i] == '(')
      {
        Symb.push(Nexp[i]);
        continue;
      }
      else if (Nexp[i] == ')')
      {
        char TempChar = ' ';
        while (TempChar != '(')
        {
          TempChar = Symb.pop();
          if (TempChar != '(')
          {
            Res += TempChar;
          }
        }
        continue;
      }
      else
      {
        Res += Nexp[i];
        continue;
      }
    }
    else
    {
      char TempChar = Symb.top();
      if (Priority(TempChar) <= Priority(Nexp[i]) || TempChar == '(')
      {
        Symb.push(Nexp[i]);
        continue;
      }
      else
      {
        while (Symb.top() != '#' && Symb.top() != '(')
        {
          if (Symb.top() != '#' && Symb.top() != '(')
          {
            Res += Symb.pop();
          }
        }
        Symb.push(Nexp[i]);
        continue;
      }
    }
  }
  string PolishExpr = "";
  while (Symb.top() != '#')
  {
    Res += Symb.pop();
  }
  for (int i = 0; i < size(Res); ++i)
  {
    PolishExpr += Res[i];
  }
  cout << endl;
  cout<< PolishExpr << endl;
  StackForRes St;
  StackForExp Exp;
  St.init(size(PolishExpr));
  Exp.init(size(PolishExpr));
  int i = 0;
  while (i < size(PolishExpr))
  {
    if (PolishExpr[i] != '*' && PolishExpr[i] != '^' && PolishExpr[i] != '-' && PolishExpr[i] != '+' && PolishExpr[i] != '/')
    {
      int temp = PolishExpr[i] - '0';
      St.push(temp);
      Exp.push(to_string(temp));
      ++i;
    }
    else
    {
      double a = St.pop();
      double b = St.pop();
      St.push(op(b, a, PolishExpr[i]));
      string l = Exp.pop();
      string m = Exp.pop();
      Exp.push(strOp(m, l, PolishExpr[i]));
      ++i;
    }
  }
  double l = St.pop();
  string t = to_string(l);
  cout << l;
  cout<< endl;

  system("pause");
  return 0;

}