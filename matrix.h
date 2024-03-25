#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class SparseMatrix {
private:

    vector<vector<int>> matrix;
    int rows;
    int cols;

public:

    SparseMatrix(int r, int c) {
        rows = r;
        cols = c;
    }

    void add(int r, int c, int val) {
        if (r < 0 || r >= rows || c < 0 || c >= cols) {
            throw invalid_argument("Invalid row or column index");
        }
        if (val != 0) {
            matrix.push_back({ r, c, val });
        }
    }


    bool operator==(const SparseMatrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            return false;
        }
        if (matrix.size() != other.matrix.size()) {
            return false;
        }
        for (int i = 0; i < matrix.size(); i++) { // порівняння списків елементів двох матриць
            if (matrix[i] != other.matrix[i]) {
                return false;
            }
        }
        return true;
    }

    SparseMatrix multiply(const SparseMatrix& other) const {
        if (cols != other.rows) {
            throw invalid_argument("Invalid matrix dimensions for multiplication");
        }

        SparseMatrix result(rows, other.cols);

        vector<vector<int>> colsInB(other.cols);
        for (int i = 0; i < other.matrix.size(); i++) {
            colsInB[other.matrix[i][1]].push_back(i);
        }

        for (int i = 0; i < matrix.size(); i++) {
            int rowInA = matrix[i][0];
            int colInA = matrix[i][1];
            int valA = matrix[i][2];
            for (int k = 0; k < other.cols; k++) {
                vector<int> colInB = colsInB[k];//зчитуємо індекс елемента у стовпці к
                int val = 0;
                for (int l = 0; l < colInB.size(); l++) {
                    int j = colInB[l];
                    if (other.matrix[j][0] == colInA) {
                        val += valA * other.matrix[j][2];
                    }
                }
                if (val != 0) {
                    result.add(rowInA, k, val);
                }
            }
        }

        return result;
    }

    void print() const {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                bool found = false;
                for (int k = 0; k < matrix.size(); k++) {
                    if (matrix[k][0] == i && matrix[k][1] == j) {
                        cout << matrix[k][2] << " ";
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "0 ";
                }
            }
            cout << endl;
        }
    }

    pair<int, int> find_zero() const {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                bool found = false;
                for (int k = 0; k < matrix.size(); k++) {
                    if (matrix[k][0] == i && matrix[k][1] == j) { //Для кожного елементу перевіряється, чи він присутній у векторі пар, що містять ненульові значення. Якщо елемент не знайдений у векторі пар, то функція повертає пару його індексів як результат пошуку.
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    return make_pair(i, j);
                }
            }
        }
        return make_pair(-1, -1);
    }

    void print_zero_address() const {
        auto zero_address = find_zero();
        if (zero_address.first == -1 && zero_address.second == -1) {
            cout << "Zero element not found" << endl;
        }
        else {
            cout << "Address of first zero element: (" << zero_address.first << ", " << zero_address.second << ")" << endl;
        }
    }



};