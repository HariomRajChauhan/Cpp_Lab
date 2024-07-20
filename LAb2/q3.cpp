// 3. To write a C++ program to manipulate complex numbers using operator
// overloading. (addition,subtraction,multiplication,division)




#include <iostream>
using namespace std;

class Complex {
private:
    float real;
    float imag;

public:
    Complex() : real(0), imag(0) {}
    Complex(float r, float i) : real(r), imag(i) {}

    Complex operator+(const Complex &c) const {
        return Complex(real + c.real, imag + c.imag);
    }

    Complex operator-(const Complex &c) const {
        return Complex(real - c.real, imag - c.imag);
    }

    Complex operator*(const Complex &c) const {
        return Complex(real * c.real - imag * c.imag, real * c.imag + imag * c.real);
    }

    Complex operator/(const Complex &c) const {
        float denominator = c.real * c.real + c.imag * c.imag;
        return Complex((real * c.real + imag * c.imag) / denominator, (imag * c.real - real * c.imag) / denominator);
    }

    void display() const {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex c1(3, 2);
    Complex c2(1, 7);

    Complex c3 = c1 + c2;
    Complex c4 = c1 - c2;
    Complex c5 = c1 * c2;
    Complex c6 = c1 / c2;

    cout << "c1 + c2 = "; c3.display();
    cout << "c1 - c2 = "; c4.display();
    cout << "c1 * c2 = "; c5.display();
    cout << "c1 / c2 = "; c6.display();

    return 0;
}
