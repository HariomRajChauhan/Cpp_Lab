// 1. Program to convert Nepalese Currency (Rupees and Paisa) to US Currency (Dollar and Cents). (Rs. 98.51=1$)


// class to class data type conversion
// source class = NeplaseCurrency
// destination class = UsCurrency
// source class --> destination class


#include <iostream>
using namespace std;


class NeplaseCurrency
{
private:
    int rupess;
    int paisa;

public:
    NeplaseCurrency() : rupess(0), paisa(0) {}
    NeplaseCurrency(int r,int p) : rupess(r),paisa(p) {}

    int getRupess() const
    {
        return rupess;
    }
    int getPaisa() const
    {
        return paisa;
    }
};

class UsCurrency
{
private:
    int dollars;
    int cents;

public:
    UsCurrency() : dollars(0),cents(0) {}
    UsCurrency(int d,int c) : dollars(d) , cents(c) {}

    void Display(){
        cout << "US Currency: $" << dollars << "." << (cents < 10 ? "0" : "") << cents << endl;
    }

    UsCurrency (const NeplaseCurrency &np ){
        double totalNpCurr = np.getRupess() + (np.getPaisa()/100.0);
        double totalUsCurr = totalNpCurr / 98.51;

        dollars = static_cast<int>(totalUsCurr);
        cents = static_cast<int>((totalUsCurr - dollars)*100);
    }
};

int main()
{
    NeplaseCurrency np(98,51);
    UsCurrency us = np;
    us.Display();

    return 0;
}
