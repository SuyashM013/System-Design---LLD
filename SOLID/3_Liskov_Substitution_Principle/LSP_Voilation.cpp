#include <bits/stdc++.h>
using namespace std;

class Account
{
public:
    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;
};

class SavingAccount : public Account
{
private:
    double balance;

public:
    SavingAccount()
    {
        balance = 0;
    }

    void deposit(double amount) override
    {
        balance += amount;
        cout << "Deposited " << amount << " to Saving Account. New balance: " << balance << endl;
    }

    void withdraw(double amount) override
    {
        if (balance >= amount)
        {
            balance -= amount;
            cout << "Withdrawn " << amount << " from Saving Account. New balance: " << balance << endl;
        }
        else
        {
            cout << "Insufficient balance in Saving Account." << endl;
        }
    }
};

class CurrentAccount : public Account
{
private:
    double balance;

public:
    CurrentAccount()
    {
        balance = 0;
    }

    void deposit(double amount)
    {
        balance += amount;
        cout << "Deposited " << amount << " to Current Savings Account. New balance: " << balance << endl;
    }

    void withdraw(double amount)
    {
        if (balance >= amount)
        {
            balance -= amount;
            cout << "Withdrawn " << amount << " from Current Savings Account. New balance: " << balance << endl;
        }
        else
        {
            cout << "Insufficient balance in Current Saving Account." << endl;
        }
    }
};

class FixedAccount : public Account
{
private:
    double balance;

public:
    FixedAccount() { balance = 0; }
    void deposit(double amount) { balance += amount; }
    void withdraw(double amount)
    {
        throw logic_error("Cannot withdraw from Fixed Account");
    }
};

class BankClient
{
private:
    vector<Account *> accounts;

public:
    BankClient(vector<Account *> _accounts) { accounts = _accounts; }

    void processTransactions()
    {
        for (auto a : accounts)
        {
            a->deposit(1000);

            try
            {
                a->withdraw(500);
            }
            catch (logic_error &e)
            {
                cout << "Exception caught: " << e.what() << endl;
            }
        }
    }
};

main()
{
    vector<Account *> accounts;
    accounts.push_back(new SavingAccount());
    accounts.push_back(new CurrentAccount());
    accounts.push_back(new FixedAccount());

    BankClient *client = new BankClient(accounts);

    client->processTransactions();
    cout << endl;
    return 0;
}