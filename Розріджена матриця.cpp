#include"matrix.h"
/*#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "x64/Debug/Розрідже.c15687a5.tlog/doctest.h"

TEST_CASE("Test matrix multiplication") {
    
    SparseMatrix A(3, 3);
    A.add(0, 0, 1);
    A.add(0, 2, 2);
    A.add(1, 1, 3);
    A.add(2, 0, 4);
    A.add(2, 2, 5);

    SparseMatrix B(3, 2);
    B.add(0, 0, 1);
    B.add(1, 0, 2);
    B.add(1, 1, 3);
    B.add(2, 1, 4);

    SparseMatrix C = A.multiply(B);

    SparseMatrix expected(3, 2);
    expected.add(0, 0, 1);
    expected.add(2, 0, 4);
    expected.add(0, 1, 8);
    expected.add(1, 1, 9);
    expected.add(2, 1, 20);

    

}


TEST_CASE("Test invalid row or column index") {
    
    SparseMatrix A(3, 3);
    CHECK_THROWS_AS(A.add(-1, 2, 1), invalid_argument);
    CHECK_THROWS_AS(A.add(3, 2, 1), invalid_argument);
    CHECK_THROWS_AS(A.add(2, -1, 1), invalid_argument);
    CHECK_THROWS_AS(A.add(2, 3, 1), invalid_argument);
}


TEST_CASE("Test invalid matrix dimensions for multiplication") {
    
    SparseMatrix A(2, 2);
    A.add(0, 0, 1);
    A.add(0, 1, 2);
    A.add(1, 0, 3);
    A.add(1, 1, 4);

    SparseMatrix B(3, 2);
    B.add(0, 0, 1);
    B.add(1, 0, 2);
    B.add(1, 1, 3);
    B.add(2, 1, 4);

    CHECK_THROWS_AS(A.multiply(B), invalid_argument);
}*/




int main() {

    SparseMatrix A(3, 3);
    A.add(0, 0, 1);
    A.add(0, 2, 2);
    A.add(1, 1, 3);
    A.add(2, 0, 4);
    A.add(2, 2, 5);

    SparseMatrix B(3, 2);
    B.add(0, 0, 1);
    B.add(1, 0, 2);
    B.add(1, 1, 3);
    B.add(2, 1, 4);

    SparseMatrix C = A.multiply(B);

    cout << "A:" << endl;
    A.print();
    cout << endl;

    cout << "B:" << endl;
    B.print();
    cout << endl;

   

    cout << "C = A*B:" << endl;
    C.print();
    cout << endl;
    cout << "Adress of C matrix zero elements:  "; C.print_zero_address();
    cout << "Zero element of matrix A:  ";
    A.print_zero_address();
   


    

}
