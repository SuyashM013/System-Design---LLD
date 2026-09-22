#include <bits/stdc++.h>
using namespace std;

class Shape
{
public:
    virtual double area() = 0;
    virtual double volume() = 0;
};

class Square : public Shape
{
private:
    double side;

public:
    Square(double s) : side(s) {}

    double area() override
    {
        return side * side;
    }

    double volume() override
    {
        throw logic_error("Square has no volume");
    }
};

class Rectangle : public Shape
{
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double area() override
    {
        return length * width;
    }

    double volume() override
    {
        throw logic_error("Rectangle has no volume");
    }
};

class Cube : public Shape
{
private:
    double side;

public:
    Cube(double s) : side(s) {}

    double area() override
    {
        return 6 * side * side;
    }

    double volume() override
    {
        return side * side * side;
    }
};

main()
{
    Shape *square = new Square(5);
    Shape *rectangle = new Rectangle(4, 6);
    Shape *cube = new Cube(3);

    try
    {

        cout << "Square Area: " << square->area() << endl;
        cout << "Rectangle Area: " << rectangle->area() << endl;
        cout << "Cube Area: " << cube->area() << endl;
        cout << "Cube Volume: " << cube->volume() << endl;

        cout << "Square Volume: " << square->volume() << endl;
        cout << "Rectangle Volume: " << rectangle->volume() << endl;
    }catch(logic_error &e)
    {
        cout << e.what() << endl;
    }

    cout << endl;
    return 0;
}