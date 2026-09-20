#include <bits/stdc++.h>
using namespace std;

class DepositeOnlyAccount
{
public:
    virtual void deposit(double amount) = 0;
    // virtual void withdraw(double amount) = 0;
};

class WithdrawalAccount : public DepositeOnlyAccount
{
public:
    virtual void withdraw(double amount) = 0;
};

class SavingAccount : public WithdrawalAccount
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

class CurrentAccount : public WithdrawalAccount
{
private:
    double balance;

public:
    CurrentAccount()
    {
        balance = 0;
    }

    void deposit(double amount) override
    {
        balance += amount;
        cout << "Deposited " << amount << " to Current Savings Account. New balance: " << balance << endl;
    }

    void withdraw(double amount) override
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

class FixedAccount : public DepositeOnlyAccount
{
private:
    double balance;

public:
    FixedAccount() { balance = 0; }
    void deposit(double amount) override
    {
        balance += amount;
        cout << "Deposited " << amount << " to Fixed Account. New balance: " << balance << endl;
    }

    // void withdraw(double amount)
    // {
    //     throw logic_error("Cannot withdraw from Fixed Account");
    // }
};

class BankClient
{
private:
    vector<WithdrawalAccount *> WithdrawalAccounts;
    vector<DepositeOnlyAccount *> DepositeOnlyAccounts;

public:
    BankClient(vector<WithdrawalAccount *> _WithdrawalAccounts,
               vector<DepositeOnlyAccount *> _DepositeOnlyAccounts)
    {
        WithdrawalAccounts = _WithdrawalAccounts;
        DepositeOnlyAccounts = _DepositeOnlyAccounts;
    }

    void processTransactions()
    {
        for (auto a : WithdrawalAccounts)
        {
            a->deposit(1000);
            a->withdraw(500);
        }
        for (auto a : DepositeOnlyAccounts)
        {
            a->deposit(1000);
        }
    }
};

main()
{
    vector<WithdrawalAccount *> accounts;

    accounts.push_back(new SavingAccount());
    accounts.push_back(new CurrentAccount());
    
    vector<DepositeOnlyAccount *> DepositeOnlyAccounts;
    DepositeOnlyAccounts.push_back(new FixedAccount());

    BankClient *client = new BankClient(accounts, DepositeOnlyAccounts);

    client->processTransactions();
    cout << endl;
    return 0;
}