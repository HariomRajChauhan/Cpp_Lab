// 9. Create a 'MATRIX' class of size m X n. Overload the ‘+’ operator to Add Two MATRIX objects. Write a main function to implement it.

#include <iostream>
using namespace std;

class MATRIX {
private:
    int **matrix;
    int rows, cols;

public:
    MATRIX(int m, int n) : rows(m), cols(n) {
        matrix = new int *[rows];
        for (int i = 0; i < rows; ++i) {
            matrix[i] = new int[cols];
        }
    }

    ~MATRIX() {
        for (int i = 0; i < rows; ++i) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

    void input() {
        cout << "Enter matrix elements:" << endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cin >> matrix[i][j];
            }
        }
    }

    void display() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    MATRIX operator+(const MATRIX &m) const {
        MATRIX result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.matrix[i][j] = matrix[i][j] + m.matrix[i][j];
            }
        }
        return result;
    }
};

int main() {
    int m, n;
    cout << "Enter number of rows and columns: ";
    cin >> m >> n;

    MATRIX mat1(m, n), mat2(m, n);

    cout << "Enter elements for matrix 1:" << endl;
    mat1.input();

    cout << "Enter elements for matrix 2:" << endl;
    mat2.input();

    MATRIX mat3 = mat1 + mat2;

    cout << "Resultant matrix after addition:" << endl;
    mat3.display();

    return 0;
}

