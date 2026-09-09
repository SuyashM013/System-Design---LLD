#include <bits/stdc++.h>
using namespace std;

class A
{
private:
    int a;

public:
    A(int _val) : a(_val) {};

    friend class B;
    friend void getA(const A &a);

    int getX() const { return a; }
    void setX(int _val) { a = _val; }
};

class B
{
public:
    void print(A &obj)
    {
        cout << obj.a << endl;
        // cout << obj.getX();
    }
};

void getA(const A &a)
{
    cout << a.a << endl;
}

main()
{
    A obj(10);
    cout << obj.getX();
    cout << endl;
    obj.setX(100);
    cout << obj.getX();

    B b;
    b.print(obj);

    getA(obj);

    return 0;
}