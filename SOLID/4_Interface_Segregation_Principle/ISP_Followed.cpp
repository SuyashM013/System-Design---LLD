#include <bits/stdc++.h>
using namespace std;

class TwoD_Shape
{
public:
    virtual double area() = 0;
};

class ThreeD_Shape
{
public:
    virtual double area() = 0;
    virtual double volume() = 0;
};

class Square : public TwoD_Shape
{
    double a;

public:
    Square(double s) : a(s) {}
    double area() override
    {
        return a * a;
    }
};

class Rectangle : public TwoD_Shape
{
    double l, w;

public:
    Rectangle(double l, double w) : l(l), w(w) {}
    double area() override
    {
        return l * w;
    }
};

class Cube : public ThreeD_Shape
{
    double s;

public:
    Cube(double s) : s(s) {}
    double area() override
    {
        return 6 * s * s;
    }
    double volume() override
    {
        return s * s * s;
    }
};

int main()
{

    TwoD_Shape *square = new Square(5);
    TwoD_Shape *rectangle = new Rectangle(4, 6);

    ThreeD_Shape *cube = new Cube(3);

    cout << "Square Area: " << square->area() << endl;
    cout << "Rectangle Area: " << rectangle->area() << endl;
    cout << "Cube Area: " << cube->area() << endl;
    cout <<"Cube Volume: "<< cube->volume() << endl;
    cout << endl;
    return 0;
}