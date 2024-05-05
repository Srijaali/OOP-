#include <iostream>
#include<string>
using namespace std;
template <class T, int row, int col>
class Matrix {
protected:
    T matrix[row][col];

public:
    Matrix() {}

    T get(int i, int j) const {
        return matrix[i][j];
    }

    void set(int i, int j, T value) {
        matrix[i][j] = value;
    }

    virtual void display() const {}

    const T* operator[](int index)  {
        return matrix[index];
    }
};

class IntMatrix : public Matrix<int, 2, 2> {
public:
    IntMatrix() {}

    IntMatrix operator+(const Matrix<int, 2, 2>& other) const {
        IntMatrix result;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                int val =  this->matrix[i][j] + other.get(i, j);
                result.set(i, j,val);
            }
        }
        return result;
    }

    IntMatrix operator-(const Matrix<int, 2, 2>& other) const {
        IntMatrix result;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
               int val =  this->matrix[i][j] - other.get(i, j);
                result.set(i, j,val);
            }
        }
        return result;
    }

    IntMatrix operator*(const Matrix<int, 2, 2>& other) const {
        IntMatrix result;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                int sum = 0;
                for (int k = 0; k < 2; k++) {
                    sum += this->matrix[i][k] * other.get(k, j);
                }
                result.set(i, j, sum);
            }
        }
        return result;
    }

    void display() const override {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                cout << this->matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

class DoubleMatrix : public Matrix<double, 2, 2> {
public:
    DoubleMatrix() {}

    DoubleMatrix operator+(const Matrix<double, 2, 2>& other) const {
        DoubleMatrix result;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                double val =  this->matrix[i][j] + other.get(i, j);
                result.set(i, j,val);
            }
        }
        return result;
    }

    DoubleMatrix operator-(const Matrix<double, 2, 2>& other) const {
        DoubleMatrix result;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                result.set(i, j, this->matrix[i][j] - other.get(i, j));
            }
        }
        return result;
    }

    DoubleMatrix operator*(const Matrix<double, 2, 2>& other) const {
        DoubleMatrix result;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                double sum = 0;
                for (int k = 0; k < 2; k++) {
                    sum += this->matrix[i][k] * other.get(k, j);
                }
                result.set(i, j, sum);
            }
        }
        return result;
    }

    void display() const override {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                cout << this->matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    cout << "SYEDA RIJA ALI [23K-0057]" <<endl<< endl;

    IntMatrix intMatrix;
    DoubleMatrix doubleMatrix;

    intMatrix.set(0, 0, 0);
    intMatrix.set(0, 1, 7);
    intMatrix.set(1, 0, 5);
    intMatrix.set(1, 1, 4);

    doubleMatrix.set(0, 0, 4.6);
    doubleMatrix.set(0, 1, 2.4);
    doubleMatrix.set(1, 0, 7.7);
    doubleMatrix.set(1, 1, 4.9);
    cout<<"Int matrix: "<<endl;
    intMatrix.display();
    cout << endl;
    cout<<"Double matrix: "<<endl;
    
    doubleMatrix.display();
    cout << endl;

    IntMatrix addResultInt = intMatrix + intMatrix;
    cout<<"Int Matrix addition:"<<endl;
    addResultInt.display();
    cout << endl;

    IntMatrix subResultInt = intMatrix - intMatrix;
    cout<<"Int Matrix subtraction:"<<endl;
    
    subResultInt.display();
    cout << endl;

    IntMatrix multResultInt = intMatrix * intMatrix;
    cout<<"Int Matrix Multiplication:"<<endl;
    multResultInt.display();
    
    cout << endl;

    DoubleMatrix addResultDouble = doubleMatrix + doubleMatrix;
    
    cout<<"Double Matrix addtion:"<<endl;
    addResultDouble.display();

    cout << endl;

    DoubleMatrix subResultDouble = doubleMatrix - doubleMatrix;
    
    cout<<"Double Matrix subtraction:"<<endl;
    subResultDouble.display();
    cout << endl;

    DoubleMatrix multResultDouble = doubleMatrix * doubleMatrix;
    
    cout<<"Double Matrix multiplication:"<<endl;
    multResultDouble.display();
    cout << endl;

    return 0;
}
