#include <bits/stdc++.h>
using namespace std;

class Bird{
    public:
    virtual void fly(){
        cout << "I can fly" << endl;
    }
    void sleep(){
        cout << "I can sleep" << endl;
    }
};
//pure virtual function - abstract class
class Color{
    public:
    virtual void birdColor() = 0;
};

class Penguin : public Bird, public Color{
    public:
    void fly(){
        cout << "I can't fly" << endl;
    }
    void birdColor(){
        cout << "I am white" << endl;
    }
};


int main()
{
//     Penguin p;
//     p.fly();
//     p.sleep();

    Color *c = new Penguin();
    c->birdColor();

    Bird *b = new Penguin();
    b->fly();
    b->sleep();

    cout << endl;
    return 0;
}