// 3. Program to convert Cartesian coordinate to Polar.


#include <iostream>
#include <cmath>
using namespace std;

class CartesianCoordinate {
public:
    double x, y;

    CartesianCoordinate(double x, double y) : x(x), y(y) {}

    void toPolar() {
        double r = sqrt(pow(x, 2) + pow(y, 2));
        double theta = atan(y / x) * 180.0 / M_PI;
        cout << "Cartesian coordinates (x=" << x << ", y=" << y << ") = Polar coordinates (r=" << r << ", theta=" << theta << ")" << endl;
    }
};

int main() {
    double x, y;
    cout << "Enter x: ";
    cin >> x;
    cout << "Enter y: ";
    cin >> y;
    CartesianCoordinate cartesian(x, y);
    cartesian.toPolar();
    return 0;
}
