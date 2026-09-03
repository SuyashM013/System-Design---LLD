#include <iostream>
#include <string>
using namespace std;

/*
===========================================================
        INHERITANCE IN C++ — COMPANY EXAMPLE
===========================================================

Base Class:
                Employee
                   |
        -------------------------
        |           |           |
   SalesManager  Marketing   HRManager
                   |
               BDOManager

Other relationships are used to demonstrate:
- Single Inheritance
- Multilevel Inheritance
- Multiple Inheritance
- Hierarchical Inheritance
- Hybrid Inheritance
- Diamond Problem / Virtual Inheritance
===========================================================
*/

// ========================================================
// 1. SINGLE INHERITANCE
// ========================================================

/*
Employee
   |
SalesManager

One child inherits from one parent.

Employee -> SalesManager
*/

class Employee
{
protected:
    string name;
    int employeeId;

public:
    Employee(string name, int employeeId)
        : name(name), employeeId(employeeId) {}

    void showEmployee()
    {
        cout << "Name: " << name << endl;
        cout << "Employee ID: " << employeeId << endl;
    }
};

class SalesManager : public Employee
{
public:
    SalesManager(string name, int id)
        : Employee(name, id) {}

    void manageSales()
    {
        cout << name << " manages the Sales Department." << endl;
    }
};

// ========================================================
// 2. MULTILEVEL INHERITANCE
// ========================================================

/*
Employee
   |
MarketingManager
   |
BDOManager

A class inherits from a class which itself inherits
from another class.

Employee -> MarketingManager -> BDOManager
*/

class MarketingManager : public Employee
{
public:
    MarketingManager(string name, int id)
        : Employee(name, id) {}

    void manageMarketing()
    {
        cout << name << " manages the Marketing Department." << endl;
    }
};

class BDOManager : public MarketingManager
{
public:
    BDOManager(string name, int id)
        : MarketingManager(name, id) {}

    void handleBusinessDevelopment()
    {
        cout << name << " handles Business Development." << endl;
    }
};

// ========================================================
// 3. HIERARCHICAL INHERITANCE
// ========================================================

/*
                    Employee
                  /    |     \
                 /     |      \
        SalesManager  HRManager  MarketingManager

Multiple classes inherit from the SAME base class.

Employee -> SalesManager
Employee -> MarketingManager
Employee -> HRManager
*/

class HRManager : public Employee
{
public:
    HRManager(string name, int id)
        : Employee(name, id) {}

    void manageHR()
    {
        cout << name << " manages Human Resources." << endl;
    }
};

// ========================================================
// 4. MULTIPLE INHERITANCE
// ========================================================

/*
        HRManager       Lead
             \          /
              \        /
               HRDirector

One class inherits from MORE THAN ONE parent.

HRDirector -> HRManager + Lead
*/

class Lead
{
protected:
    string project;

public:
    Lead(string project)
        : project(project) {}

    void manageTeam()
    {
        cout << "Managing team for project: "
             << project << endl;
    }
};

class HRDirector : public HRManager, public Lead
{
public:
    HRDirector(string name, int id, string project)
        : HRManager(name, id), Lead(project) {}

    void directHR()
    {
        cout << name << " is the HR Director." << endl;
    }
};

// ========================================================
// 5. HYBRID INHERITANCE
// ========================================================

/*
Hybrid inheritance = combination of two or more
types of inheritance.

Here:

                    Employee
                    /      \
                   /        \
          MarketingManager   HRManager
                  |             |
             BDOManager     HRDirector
                                |
                               Lead

And HRDirector also inherits from Lead.

This combines:
- Hierarchical inheritance
- Multilevel inheritance
- Multiple inheritance

Therefore it is HYBRID inheritance.
*/

// ========================================================
// 6. DIAMOND PROBLEM
// ========================================================

/*
Without virtual inheritance:

                 Employee
                 /      \
                /        \
       SalesManager    MarketingManager
                \        /
                 \      /
                 BDOManager

BDOManager gets TWO copies of Employee.

                 Employee
                /        \
          copy #1       copy #2
              \          /
               BDOManager

Problem:

BDOManager obj(...);

obj.showEmployee();

Which Employee::showEmployee() should be called?

The left Employee or the right Employee?

This creates ambiguity.
*/

// --------------------------------------------------------
// Solving Diamond Problem using VIRTUAL INHERITANCE
// --------------------------------------------------------

class VirtualEmployee
{
protected:
    string name;
    int employeeId;

public:
    VirtualEmployee(string name, int id)
        : name(name), employeeId(id) {}

    void showDetails()
    {
        cout << "Name: " << name << endl;
        cout << "Employee ID: " << employeeId << endl;
    }
};

class VirtualSalesManager : virtual public VirtualEmployee
{
public:
    VirtualSalesManager(string name, int id)
        : VirtualEmployee(name, id) {}

    void salesWork()
    {
        cout << name << " manages sales." << endl;
    }
};

class VirtualMarketingManager : virtual public VirtualEmployee
{
public:
    VirtualMarketingManager(string name, int id)
        : VirtualEmployee(name, id) {}

    void marketingWork()
    {
        cout << name << " manages marketing." << endl;
    }
};

class VirtualBDOManager
    : public VirtualSalesManager,
      public VirtualMarketingManager
{

public:
    /*
    IMPORTANT:

    Because VirtualSalesManager and
    VirtualMarketingManager use virtual inheritance,

    BDOManager has only ONE copy of VirtualEmployee.

    Therefore the MOST DERIVED class
    (VirtualBDOManager) initializes VirtualEmployee.
    */

    VirtualBDOManager(string name, int id)
        : VirtualEmployee(name, id),
          VirtualSalesManager(name, id),
          VirtualMarketingManager(name, id) {}

    void bdoWork()
    {
        cout << name
             << " handles Business Development."
             << endl;
    }
};

// ========================================================
// MAIN
// ========================================================

int main()
{

    cout << "\n========================================\n";
    cout << "1. SINGLE INHERITANCE\n";
    cout << "========================================\n";

    SalesManager sales("Rahul", 101);

    sales.showEmployee();
    sales.manageSales();

    cout << "\n========================================\n";
    cout << "2. MULTILEVEL INHERITANCE\n";
    cout << "========================================\n";

    BDOManager bdo("Amit", 102);

    bdo.showEmployee();
    bdo.manageMarketing();
    bdo.handleBusinessDevelopment();

    cout << "\n========================================\n";
    cout << "3. HIERARCHICAL INHERITANCE\n";
    cout << "========================================\n";

    SalesManager sales2("Rohan", 103);
    MarketingManager marketing("Priya", 104);
    HRManager hr("Neha", 105);

    sales2.manageSales();
    marketing.manageMarketing();
    hr.manageHR();

    cout << "\n========================================\n";
    cout << "4. MULTIPLE INHERITANCE\n";
    cout << "========================================\n";

    HRDirector director(
        "Anjali",
        106,
        "Employee Management System");

    director.showEmployee();
    director.manageHR();
    director.manageTeam();
    director.directHR();

    cout << "\n========================================\n";
    cout << "5. HYBRID INHERITANCE\n";
    cout << "========================================\n";

    cout << "Hybrid inheritance combines multiple "
         << "inheritance types." << endl;

    cout << "Example hierarchy:" << endl;

    cout << R"(

                     Employee
                    /       \
                   /         \
       MarketingManager     HRManager
               |                |
          BDOManager       HRDirector
                                |
                               Lead

    )";

    cout << "\n========================================\n";
    cout << "6. DIAMOND PROBLEM + VIRTUAL INHERITANCE\n";
    cout << "========================================\n";

    VirtualBDOManager virtualBDO("Vikas", 107);

    virtualBDO.showDetails();
    virtualBDO.salesWork();
    virtualBDO.marketingWork();
    virtualBDO.bdoWork();

    cout << "\n========================================\n";
    cout << "PROGRAM FINISHED\n";
    cout << "========================================\n";

    return 0;
}