#include<iostream>
#include<cmath>
#include<stdexcept>  // For standard exceptions
using namespace std;

class Number {
    private:
        double num;
    public:
        void ReadNum();
        double Sqroot();
};

void Number::ReadNum() {
    cout << "Enter a number: ";
    cin >> num;
}

double Number::Sqroot() {
    if(num < 0) {
        throw domain_error("Error: Square root of a negative number is not possible.");
    }
    return sqrt(num);
}

int main() {
    Number n;
    double result;

    n.ReadNum();
    try {
        cout << "\nTrying to find the square root ....\n";
        result = n.Sqroot();
        cout << "\nSquare root is: " << result << endl;
        cout << "Success... Exception is not raised" << endl;
    }
    catch(const domain_error& e) {
        cout << e.what() << endl;  // Print the exception message
    }
    catch(const exception& e) {
        cout << "An unexpected error occurred: " << e.what() << endl;
    }


    cout << "Hello Dost yo lastko lagi ho" << endl;

    return 0;
}