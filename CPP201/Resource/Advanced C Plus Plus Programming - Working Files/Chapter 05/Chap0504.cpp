#include <iostream>
#include <sstream>

using namespace std;

class Person {
    private:
       string first, middle, last;
       int age;
    public:
       Person(string f, string m, string l, int ag) {
           first = f;
           middle = m;
           last = l;
           age = ag;
       }
       string ToString() {
           stringstream stm;
           stm << first << " " << middle << " " <<
              last << " " << age;
           return stm.str();
       }
};

int main()
{
    Person aPerson("George", "Fred", "Jones", 27);
    cout << aPerson.ToString() << endl;
    return 0;
}
