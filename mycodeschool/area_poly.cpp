#include <iostream>
#include <cmath>
using namespace std;

struct Point
{
    double x;
    double y;
};

double cross_product(Point a, Point b)
{
    return (a.x * b.y - a.y * b.x);
}

double area_poly_naive(Point a, Point b, Point c)
{
    double area = abs(cross_product(a, b) + cross_product(b, c) + cross_product(c, a)) / 2.0;
    return area;
}

double area_poly(Point vertices[], int n)
{
    double sum = 0.0;
    for (int i = 0; i < n; i++)
    {
        sum += cross_product(vertices[i], vertices[(i + 1) % n]);
    }
    double area = abs(sum) / 2.0;
    return area;
}

int main()
{
    Point a;
    Point b;
    Point c;
    a.x = 3.0;
    a.y = 1.0;
    b.x = 2.0;
    b.y = 3.0;
    c.x = -1.0;
    c.y = -10.0;

    Point vertices[] = {a,
                        b,
                        c};

    double area = area_poly(vertices, 3);
    printf("%f\n", area);
}