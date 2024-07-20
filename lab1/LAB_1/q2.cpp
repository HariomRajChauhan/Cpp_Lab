#include <iostream>

using namespace std;

class MaxMin
{
private:
    int First, Second, Third;

public:
    void SetValue()
    {
        cout << "Enter First :";
        cin >> First;

        cout << "Enter Second :";
        cin >> Second;

        cout << "Enter Third :";
        cin >> Third;
    }

    void Min()
    {
        if ((First > Third) && (Second > Third))
        {
            cout << Third << " is Minimum" << endl;
        }
        else if ((First > Second) && (Third > Second))
        {
            cout << Second << " is Minimum" << endl;
        }
        else
        {
            cout << First << " is Minimum" << endl;
        }
    }

    void Max()
    {
        if ((First < Third) && (Second < Third))
        {
            cout << Third << " is Maximum" << endl;
        }
        else if ((First < Second) && (Third < Second))
        {
            cout << Second << " is Maximum" << endl;
        }
        else
        {
            cout << First << " is Maximum" << endl;
        }
    }
};

int main()
{

    MaxMin m1;
    m1.SetValue();

    m1.Min();
    m1.Max();

    return 0;
}