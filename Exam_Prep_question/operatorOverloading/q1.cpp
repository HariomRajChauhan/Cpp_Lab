#include <iostream>
using namespace std;

class Currency
{
private:
    int rupees;
    int paisa;

public:
    Currency()
    {
        rupees = 0;
        paisa = 0;
    }

    void GetCurrency()
    {
        cout << "Enter the currency:\nRupees: ";
        cin >> rupees;
        cout << "Paisa : ";
        cin >> paisa;
    }

    void Display()
    {
        cout << "Rs. " << rupees << "." << paisa;
    }

    bool operator>=(const Currency &t2)
    {
        if (rupees > t2.rupees)
        {
            return true;
        }
        else if (rupees == t2.rupees)
        {
            if (paisa >= t2.paisa)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
};
int main()
{
    Currency c1, c2;

    c1.GetCurrency();
    c2.GetCurrency();

    if (c1 >= c2)
    {
        c1.Display();
        cout << " is greater than ";
        c2.Display();
    }
    else
    {
        c2.Display();
        cout << " is greater than ";
        c1.Display();
    }

    return 0;
}