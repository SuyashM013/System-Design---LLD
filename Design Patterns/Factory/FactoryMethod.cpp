#include <bits/stdc++.h>
using namespace std;

class Burger
{
public:
    virtual void prepare() = 0;
    virtual ~Burger()
    {
        cout << "Burger Destroyed" << endl;
    }
};

class BasicBurger : public Burger
{
public:
    void prepare() override
    {
        cout << "Preparing Basic Burger" << endl;
    }
};

class StandardBurger : public Burger
{
public:
    void prepare() override
    {
        cout << "Preparing Standard Burger" << endl;
    }
};

class DeluxeBurger : public Burger
{
public:
    void prepare() override
    {
        cout << "Preparing Deluxe Burger" << endl;
    }
};

class BasicWheet : public Burger
{
public:
    void prepare() override
    {
        cout << "Preparing Basic Wheet" << endl;
    }
};

class StandardWheet : public Burger
{
public:
    void prepare() override
    {
        cout << "Preparing Standard Wheet" << endl;
    }
};

class DeluxeWheet : public Burger
{
public:
    void prepare() override
    {
        cout << "Preparing Deluxe Wheet" << endl;
    }
};

class BurgerFactory{
    public:
    virtual Burger* createBurger(const string& type) = 0;
};

class SinghBurger : public BurgerFactory{
    public:
    Burger* createBurger(const string& type) override{
        if(type == "basic"){
            return new BasicBurger();
        }
        else if(type == "standard"){
            return new StandardBurger();
        }
        else if(type == "deluxe"){
            return new DeluxeBurger();
        }
        else{
            return NULL;
        }
    }
};

class WheetFactory : public BurgerFactory{
    public:
    Burger* createBurger(const string& type) override{
        if(type == "basic"){
            return new BasicWheet();
        }
        else if(type == "standard"){
            return new StandardWheet();
        }
        else if(type == "deluxe"){
            return new DeluxeWheet();
        }
        else{
            return NULL;
        }
    }
};


int main()
{
     string type = "standard";

     BurgerFactory* myBurger = new WheetFactory();

     Burger* myBurger1 = myBurger->createBurger(type);

     myBurger1->prepare();

     delete myBurger1;
    cout << endl;
    return 0;
}