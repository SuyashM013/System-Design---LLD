#include <bits/stdc++.h>
using namespace std;

// Polymorphism - many forms
// Run Time / Dynamic Polymorphism
class Shape 
{
public:
    virtual void draw() 
    {
        cout << "Drawing Shape" << endl;
    }
};

class Circle : public Shape
{
public:
    void draw() override
    {
        cout << "Drawing Circle" << endl;
    }
};

class Rectangle : public Shape
{
public:
    void draw()
    {
        cout << "Drawing Rectangle" << endl;
    }
};

void drawShape(Shape *s)
{
    s->draw();
}

// Compile Time / Static Polymorphism -
//   1. Function Overloading
class Add
{
public:
    int sum(int a, int b)
    {
        return a + b;
    }
    int sum(int a, int b, int c)
    {
        return a + b + c;
    }
    int sum(int a, int b, int c, int d)
    {
        return a + b + c + d;
    }
    double sum(double a, double b)
    {
        return a + b;
    }
};

// 2. Operator Overloading
class Complex
{
    int real;
    int img;

public:
    // Complex(int real, int img){
    //     this->real = real;
    //     this->img = img;
    // }

    Complex() : real(0), img(0) {}
    Complex(int real, int img) : real(real), img(img) {}

    void print()
    {

        cout << real << " + " << img << "i" << endl;
    }

    Complex operator+(const Complex &c)
    {
        Complex temp;
        temp.real = real + c.real;
        temp.img = img + c.img;
        // cout << __FUNCTION__ << endl;
        return temp;
    }

    Complex operator-(const Complex &c)
    {
        Complex temp;
        temp.real = real - c.real;
        temp.img = img - c.img;
        // cout << __FUNCTION__ << endl;
        return temp;
    }
};

int main()
{
    // Run time poly --------------------

    Circle c;
    Rectangle r;
    // Shape *s1 = &c;
    // Shape *s2 = &r;
    // s1->draw();
    // s2->draw();

    drawShape(&c);
    drawShape(&r);
    

    // Compile time poly --------------------
    // Add a;
    // cout << a.sum(1, 2) << endl;
    // cout << a.sum(1.1, 2.1) << endl;
    // cout << a.sum(1, 2, 3) << endl;
    // cout << a.sum(1, 2, 3, 4) << endl;
    // cout << endl;

    // Complex c1(1, 2), c2(3, 4), c3;
    // c1.print();
    // c2.print();
    // c3.print();

    // c3 = c1 + c2;
    // c3.print();

    return 0;
}