#include <bits/stdc++.h>
using namespace std;

// |---------------------|
// |    Base Class       |
// |---------------------|
// |     vehicle         |
// |---------------------|
// |    Derived Class    |
// |---------------------|
// |     car             |
// |     Truck           |
// |     Motorcycle      |
// |---------------------|

// |---------------------|
// |    Vehicles         |
// |---------------------|
// |    +name            |
// |    +model           |
// |    +color           |
// |    +speed           |
// |    +acceleration    |
// |    +brake           |
// |    +noOfTyres       |
// |---------------------|
// |+start_engine()      |
// |+stop_engine()       |
// |+accelerate()        |
// |+brake()             |
// |---------------------|

class Vehicle
{

protected:
    string name;
    string model;
    string color;
    int noOfTyres;

    Vehicle(string _name, string _model, string _color, int _noOfTyres)
    {
        cout << "Vehicle Default Constructor" << endl;
        this->name = _name;
        this->model = _model;
        this->color = _color;
        this->noOfTyres = _noOfTyres;
    }

public:
    void start_engine()
    {
        cout << "Engine is starting " << name << " " << model << endl;
    }

    void stop_engine()
    {
        cout << "Engine is stopping " << name << " " << model << endl;
    }

    ~Vehicle()
    {
        cout << "Vehicle Destructor" << endl;
    }
};

class Car : public Vehicle
{

protected:
    int noofDoors;
    string transmissionType;

public:
    Car(string _name, string _model, string _color, int _noOfTyres, int _noofDoors, string _transmissionType) : Vehicle(_name, _model, _color, _noOfTyres)
    {
        cout << "Car Default Constructor" << endl;
        this->noofDoors = _noofDoors;
        this->transmissionType = _transmissionType;
    }

    void accelerate()
    {
        cout << "Car is accelerating " << name << " " << model << endl;
    }

    void brake()
    {
        cout << "Car is braking " << name << " " << model << endl;
    }

    void startAC()
    {
        cout << "AC is starting " << name << " " << model << endl;
    }
    ~Car()
    {
        cout << "Car Destructor" << endl;
    }
};

class MotorCycle : public Vehicle
{
protected:
    string type;
    int mileage;
    string handleType;

public:
    MotorCycle(string _name, string _model, string _color, int _noOfTyres, string _type, int _mileage, string _handleType) : Vehicle(_name, _model, _color, _noOfTyres){
        cout << "MotorCycle Default Constructor" << endl;
        this->type = _type;
        this->mileage = _mileage;
        this->handleType = _handleType;
    }

    void accelerate()
    {
        cout << "MotorCycle is accelerating " << name << " " << model << endl;
    }
    void brake()
    {
        cout << "MotorCycle is braking " << name << " " << model << endl;
    }
    void horn(){
        cout << "Horn is sounding " << name << " " << model << endl;
    }

    ~MotorCycle()
    {
        cout << "MotorCycle Destructor" << endl;
    }

};

main()
{
    Car A("BMW", "X5", "Black", 4, 5, "Automatic");
    A.start_engine();
    A.accelerate();
    A.brake();
    A.stop_engine();
    A.startAC();

    cout << endl << "-----------------------------------------------------" << endl << endl;


    MotorCycle B("Honda", "CBR", "Red", 2, "Sport", 25, "Leather");
    B.start_engine();
    B.accelerate();
    B.brake();
    B.horn();
    B.stop_engine();

    cout << endl;
    return 0;
}