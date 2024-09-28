#include<iostream>
#include<cmath>
using namespace std;

class Number{
    private:
        double num;
    public:
        class NEG{};
        void ReadNum();
        double Sqroot();
};

void Number::ReadNum(){
    cout << "Enter a number: ";
    cin >> num;
}

double Number::Sqroot(){
    if(num < 0){
        throw NEG();
    }
    else{
        return (sqrt(num));
    }
}


int main(){
    Number n;
    double result;

    n.ReadNum();
    try
    {
        cout << "\nTrying to find the square root ....\n";
        result = n.Sqroot();
        cout << "\nSquare root is: " << result<<endl;
        cout << "Success... Exception is not raised"<< endl;
    }

    catch(Number::NEG){
        cout << "\nSquare Root of negative number not Possible!" << endl;
    }


    return 0;
}