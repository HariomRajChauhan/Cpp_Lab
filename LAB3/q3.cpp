// 3. Program to convert Cartesian coordinate to Polar.

// class to class data type conversion
// source class = CartesianCoordinate
// destination class = PolarCoordinate

// source class --> destination class


#include <iostream>
#include <cmath>

using namespace std;

class CartesianCoordinate
{
private:
    double x;
    double y;

public:
    CartesianCoordinate() : x(0), y(0) {}
    CartesianCoordinate(double x, double y) : x(x), y(y) {}

    double getX() const
    {
        return x;
    }
    double getY() const
    {
        return y;
    }
};

class PolarCoordinate
{
private:
    double radius;
    double angle;

public:
    PolarCoordinate() : radius(0), angle(0) {}
    PolarCoordinate(double r, double a) : radius(r), angle(a) {}

    void Display()
    {
        cout << "Polar Coordinate: (" << radius << "," << angle << ")" << endl;
    }

    PolarCoordinate(const CartesianCoordinate &c)
    {
        radius = sqrt(pow(c.getX(), 2) + pow(c.getY(), 2));
        angle = atan(c.getY() / c.getX()) * 180 / 3.14159;
    }
};

int main()
{
    CartesianCoordinate c(3, 3);
    PolarCoordinate p = c;
    p.Display();

    return 0;
}
