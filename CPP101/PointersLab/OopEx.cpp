#include <iostream>
using namespace std;
class Student
{
public:
    string name;
    int age;

    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    };
};

int main()
{

    Student s;
    s.display();
    return 0;
}