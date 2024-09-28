#include <iostream>
using namespace std;
class destination
{
    float meter;

public:
    destination()
    {
        meter = 0;
    }
    destination(float m)
    {
        meter = m;
    }
    void showdata()
    {
        cout << "in meter is " << meter << endl;
    }
};
class source
{
private:
    float inch;
    float feet;

public:
    source()
    {
        cout << "Enter Data in\nFeet : ";
        cin >> feet;
        cout << "Inch : ";
        cin >> inch;
    }
    operator destination()
    {
        float inch = feet * 12 + inch;
        float m = (0.3048/12) * inch;
        return destination(m);
    }
};
int main()
{
    source src;
    destination dest;
    dest = src;
    dest.showdata();
    return 0;
}