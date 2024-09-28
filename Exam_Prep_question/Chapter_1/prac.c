#include <stdio.h>
#include <math.h>

float Area(float b, float y, float z)
{
    float A = (b + (z * y)) * y;
    return A;
}

float Perimeter(float b, float y, float z)
{
    float rootpart = 1 + (pow(z, 2.0));
    float P = b + (2 * y * pow(rootpart, 0.5));
    return P;
}

float Radius(float area, float perimeter)
{
    float r = area / perimeter;
    return r;
}

float Discharge(float n, float s, float r, float a)
{
    float Q = (1 / n) * a * pow(r, 0.667) * pow(s, 0.5);
    return Q;
}

int main()
{
    float b, y, z, n, s;
    float area, perimeter, radius, discharge;

    printf("Enter the value of b, y, z, n, s: ");
    scanf("%f %f %f %f %f", &b, &y, &z, &n, &s);

    area = Area(b, y, z);
    perimeter = Perimeter(b, y, z);
    radius = Radius(area, perimeter);
    discharge = Discharge(n, s, radius, area);

    printf("Area: %f\n", area);
    printf("Perimeter: %f\n", perimeter);
    printf("Radius: %f\n", radius);
    printf("Discharge: %f\n", discharge);

    return 0;
}