#include <bits/stdc++.h>
using namespace std;

class Singleton
{
    static Singleton *instance;
    static mutex m; // locks for multi threading
    Singleton(int val)
    {
        cout << "Singleton constroctor created, with value " << val << endl;
    }

public:
    static Singleton *getInstance(int val)
    {

        if (instance == NULL)
        {
            lock_guard<mutex> lock(m);
            if (instance == NULL)
                instance = new Singleton(val);
        }
        return instance;
    }
};

Singleton *Singleton::instance = NULL;
mutex Singleton::m;

int main()
{
    Singleton *s1 = Singleton::getInstance(10);
    Singleton *s2 = Singleton::getInstance(20); // This will not create a new instance
    cout << endl;
    return 0;
}