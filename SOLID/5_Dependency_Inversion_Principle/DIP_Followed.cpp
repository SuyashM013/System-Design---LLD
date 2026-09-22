#include <bits/stdc++.h>
using namespace std;

class Database
{
public:
    virtual void save(string data) = 0;
};

class MySQLDatabase : public Database
{
public:
    void save(string data) override
    {
        cout << "Saving to MySQL DB, Data: " << data << endl;
    }
};

class MongoDBDatabase : public Database
{
public:
    void save(string data) override
    {
        cout << "Saving to MongoDB DB, Data: " << data << endl;
    }
};

class UserService
{
    Database *database;

public:
    UserService(Database *database)
    {
        this->database = database;
    }
    void storeDB(string name)
    {
        database->save(name);
    }
};

int main()
{

    MySQLDatabase mySQLDatabase;
    MongoDBDatabase mongoDatabase;

    UserService userService(&mongoDatabase);
    userService.storeDB("Suyash");

    userService = UserService(&mySQLDatabase);
    userService.storeDB("Suyash");
    cout << endl;
    return 0;
}