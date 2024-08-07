// 1. Program to convert Nepalese Currency (Rupees and Paisa) to US Currency (Dollar and Cents). (Rs. 98.51=1$)

#include <iostream>
using namespace std;

class CurrencyConverter {
public:
    static const double conversionRate;

    void convertNepaleseToUSD(double rupees, double paisa) {
        double totalRupees = rupees + (paisa / 100);
        double usd = totalRupees / conversionRate;
        int dollars = static_cast<int>(usd);
        int cents = static_cast<int>((usd - dollars) * 100);
        cout << rupees << " Rupees and " << paisa << " Paisa = " << dollars << " Dollars and " << cents << " Cents" << endl;
    }

    void convertUSDToNepalese(double dollars, double cents) {
        double totalUSD = dollars + (cents / 100);
        double rupees = totalUSD * conversionRate;
        int rupeesInt = static_cast<int>(rupees);
        int paisa = static_cast<int>((rupees - rupeesInt) * 100);
        cout << dollars << " Dollars and " << cents << " Cents = " << rupeesInt << " Rupees and " << paisa << " Paisa" << endl;
    }
};

const double CurrencyConverter::conversionRate = 98.51;

int main() {
    CurrencyConverter converter;
    double rupees ;
    double dolors ;
    double cents ;
    double paisa ;
    int num;

    cout << "1. Convert Nepalese Currency to USD" << endl;
    cout << "2. Convert USD to Nepalese Currency" << endl;
    cout << "Enter your choice: ";
    cin >> num;

    while(num != 1 && num != 2) {
        cout << "Invalid Input" << endl;
        cout << "Enter your choice: ";
        cin >> num;
    }
    switch (num)
    {
    case 1:
        cout << "Enter Rupees: ";   
        cin >> rupees;
        cout << "Enter Paisa: ";
        cin >> paisa;

        converter.convertNepaleseToUSD(rupees, paisa);       
        break;
    case 2:
        cout << "Enter Dollars: ";   
        cin >> dolors;
        cout << "Enter Cents: ";
        cin >> cents;   

        converter.convertUSDToNepalese(dolors, cents);     
        break;

    default:
        cout << "Invalid Input" << endl;

        break;
    }

    return 0;
}
