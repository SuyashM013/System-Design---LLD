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

class BurgerFactory
{
public:
    static Burger *createBurger(string &type)
    {
        if (type == "basic")
        {
            return new BasicBurger();
        }
        else if (type == "standard")
        {
            return new StandardBurger();
        }
        else if (type == "deluxe")
        {
            return new DeluxeBurger();
        }
        else
        {
            cout << "Invalid Burger Type" << endl;
            return NULL;
        }
    };
};


int main()
{

    string type = "basic";

    Burger *burger = BurgerFactory::createBurger(type);
    burger->prepare();

    // BurgerFactory* myBurger = new BurgerFactory();
    // myBurger->createBurger(type)->prepare();

    delete burger;

    cout << endl;
    return 0;
}