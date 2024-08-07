// 2. Program to convert Polar Coordinate to Cartesian.

// class to class data type conversion
// source class = PolarCoordinate
// destination class = CartesianCoordinate

#include <iostream>
#include <cmath>

using namespace std;

class PolarCoordinate
{
private:
    double radius;
    double angle;

public:
    PolarCoordinate() : radius(0), angle(0) {}
    PolarCoordinate(double r, double a) : radius(r), angle(a) {}

    double getRadius() const
    {
        return radius;
    }
    double getAngle() const
    {
        return angle;
    }
};

class CartesianCoordinate
{
private:
    double x;
    double y;

public:
    CartesianCoordinate() : x(0), y(0) {}
    CartesianCoordinate(double x, double y) : x(x), y(y) {}

    void Display()
    {
        cout << "Cartesian Coordinate: (" << x << "," << y << ")" << endl;
    }

    CartesianCoordinate(const PolarCoordinate &p)
    {
        const double PI = 3.14159;
        x = p.getRadius() * cos(p.getAngle() * PI / 180);
        y = p.getRadius() * sin(p.getAngle() * PI / 180);
    }
};

int main()
{
    PolarCoordinate p(5, 0);
    CartesianCoordinate c = p;
    c.Display();
}
