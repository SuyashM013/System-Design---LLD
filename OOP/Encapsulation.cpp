#include <bits/stdc++.h>
using namespace std;

// perfect encap -> sare attributes private hote hain

class Student
{

private:
    float gpa;
    string gf;

    void gfChat()
    {
        cout << this->name << " has gf " << this->gf << " -> chatting with gf" << endl;
    }

public:
    int age;
    int id;
    string name;

    // Behaviours
    Student()
    {
        cout << "Student Default Constructor" << endl;
    }

    Student(string name, int age, int id, float gpa, string gf)
    {
        this->name = name;
        this->age = age;
        this->id = id;
        this->gpa = gpa;
        this->gf = gf;
    }

    void study()
    {
        cout << this->name << " studying " << "with gpa " << this->gpa << endl;
    }

    void bunk()
    {
        cout << " bunking" << endl;
    }
    void details()
    {
        cout << this->name << " " << this->age << " " << this->id << endl;
    }

    ~Student()
    {
        cout << this->name << " Student Destructor" << endl;
    }
};

int main()
{

    Student s1("Suyash", 22, 1, 9.5, "john");
    s1.study();
    // s1.gfChat(); // error

    cout << endl;
    return 0;
}