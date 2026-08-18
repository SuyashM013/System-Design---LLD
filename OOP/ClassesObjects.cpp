#include <bits/stdc++.h>
using namespace std;

class Student
{
public:
    // Attributes
    string name;
    int age;
    int id;

    // Behaviours
    Student()
    {
        cout  << "Student Default Constructor" << endl;
    }

    Student(string name, int age, int id){
        this->name = name;
        this->age = age;
        this->id = id;
    }


    void study()
    {
        cout << this->name << " studying" << endl;
    }

    void bunk()
    {
        cout << " bunking" << endl;
    }
    void details(){
        cout << this->name << " " << this->age << " " << this->id << endl;
    }

    ~Student()
    {
        cout << " Student Destructor" << endl;
    }
};

int main()
{
    // Student s1;
    // s1.name = "Suyash";
    // s1.age = 22;
    // s1.id = 1;

    // s1.study();

    Student s2("Suyash", 22, 1);
    Student s3("Joi", 22, 2);
    Student s4("John", 29, 3);


    s2.details();
    s3.details();
    cout << endl;
    return 0;
}