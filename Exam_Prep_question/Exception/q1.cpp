#include<iostream>
#include<exception>

using namespace std;

class DivideByZeroException : public runtime_error{
    public:
        DivideByZeroException() : runtime_error("Divide by zero exception"){}
};

class Divide{
    private:
        double num, den;

    public:
        Divide(double n,double d){
            num = n;
            den = d;
        }

        double divide(){
            if (den == 0){
                throw DivideByZeroException();
            }
            return num/den;
        }
};

int main(){
    double num,den;
    cout << "Enter the numerator and denominator: ";
    cin >> num >> den;

    Divide d(num,den);
    try{
        cout << "Result: " << d.divide() << endl;
    }
    catch(DivideByZeroException &e){
        cout << e.what() << endl;
    }
    catch(const exception& e) {
        cout << "An unexpected error occurred: " << e.what() << endl;
    }
    return 0;
}