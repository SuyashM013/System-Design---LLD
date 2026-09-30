#include <bits/stdc++.h>
using namespace std;

class SalaryStrategy
{
public:
    virtual double calculateSalary(double baseSalary) = 0;

    virtual ~SalaryStrategy() {}
};

class SalesSaleryStr : public SalaryStrategy
{
public:
    double calculateSalary(double baseSalary)
    {
        return baseSalary + 10000;
    }
};

class HRSalaryStr : public SalaryStrategy
{
public:
    double calculateSalary(double baseSalary)
    {
        return baseSalary;
    }
};

class CEOSalaryStr : public SalaryStrategy
{
public:
    double calculateSalary(double baseSalary)
    {
        return baseSalary + 50000;
    }
};

// Client class - context

class Employee
{
    double baseSalary;
    SalaryStrategy *strategy;

public:
    Employee(double baseSalary, SalaryStrategy *strategy)
    {
        this->baseSalary = baseSalary;
        this->strategy = strategy;
    }

    double calculateSalary()
    {
        return strategy->calculateSalary(baseSalary);
    }
};

// 2nd - Payments real life eg

class PaymentStrategy
{
public:
    virtual void pay(double amount) = 0;

    virtual ~PaymentStrategy() {}
};

class UPIPayment : public PaymentStrategy
{

public:
    void pay(double amount)
    {
        cout << "Paying " << amount << " using UPI" << endl;
    }
};

class CardPayment : public PaymentStrategy
{

public:
    void pay(double amount)
    {
        cout << "Paying " << amount << " using Card" << endl;
    }
};

class PayPalPayment : public PaymentStrategy
{

public:
    void pay(double amount)
    {
        cout << "Paying " << amount << " using PayPal" << endl;
    }
};

class PaymentService
{
    PaymentStrategy *strategy;

public:
    PaymentService(PaymentStrategy *strategy)
    {
        this->strategy = strategy;
    }

    void makePayment(double amount)
    {
        strategy->pay(amount);
    }
};

int main()
{

    SalesSaleryStr salesSalery;
    HRSalaryStr hrSalery;
    CEOSalaryStr ceoSalery;

    Employee salesEmployee(50000, &salesSalery);
    Employee hrEmployee(50000, &hrSalery);
    Employee ceoEmployee(100000, &ceoSalery);

    cout << "Sales Employee Salary: " << salesEmployee.calculateSalary() << endl;
    cout << "HR Employee Salary: " << hrEmployee.calculateSalary() << endl;
    cout << "CEO Employee Salary: " << ceoEmployee.calculateSalary() << endl;

    UPIPayment upi;
    CardPayment card;
    PayPalPayment payPal;

    PaymentService upiService(&upi);
    PaymentService cardService(&card);
    PaymentService payPalService(&payPal);

    upiService.makePayment(1000);
    cardService.makePayment(1000);
    payPalService.makePayment(1000);

    cout << endl;
    return 0;
}