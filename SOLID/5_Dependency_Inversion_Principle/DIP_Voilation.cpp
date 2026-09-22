#include <bits/stdc++.h>
using namespace std;

class MySQLDatabase
{
public:
    void savetoDB(string data)
    {
        cout << "Saving to MySQL DB, Data: " << data << endl;
    }
};

class MongoDatabase
{
public:
    void savetoDB(string data)
    {
        cout << "Saving to mongo DB, Data: " << data << endl;
    }
};

class UserService
{
private:
    MySQLDatabase mySQLDatabase;
    MongoDatabase mongoDatabase;

public:
    void storetoSQL(string name){
        mySQLDatabase.savetoDB(name);
    }

    void storetomongo(string name){
        mongoDatabase.savetoDB(name);
    }
};

int main()
{

    UserService userService;
    userService.storetoSQL("Suyash");
    userService.storetomongo("Suyash");
    cout << endl;
    return 0;
}