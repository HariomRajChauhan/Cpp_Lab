#include <iostream>
#include <cmath>
using namespace std;

class PolarCoordinate {
public:
    double r, theta;

    PolarCoordinate(double r, double theta) : r(r), theta(theta) {}

    void toCartesian() {
        double thetaRadians = theta * M_PI / 180.0;
        double x = r * cos(thetaRadians);
        double y = r * sin(thetaRadians);
        cout << "Polar coordinates (r=" << r << ", theta=" << theta << ") = Cartesian coordinates (x=" << x << ", y=" << y << ")" << endl;
    }
};

int main() {
    int r, theta;
    cout << "Enter r: ";
    cin >> r;
    cout << "Enter theta: ";
    cin >> theta;
    PolarCoordinate polar(r, theta);
    polar.toCartesian();
    return 0;
}
