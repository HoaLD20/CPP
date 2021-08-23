#include <iostream>

using namespace std;
class Student{
    public:
        void disp(){
            cout << "Lop co so \n";
        }
};
class Topper: public Student{
    public: 
        void disp(){
            cout << "Lop dan xuat\n";
        }
};

int main(int argc, char const *argv[])
{
    Student s;
    Topper t;
    s.disp();
    t.disp();
    return 0;
}
