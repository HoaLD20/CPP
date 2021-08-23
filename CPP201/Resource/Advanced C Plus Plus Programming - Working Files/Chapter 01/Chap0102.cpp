#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Employee {
    private:
        string name;
        double pay;
    public:
        Employee() {
            name = "";
            pay = 0;
        }

        Employee(string empName, double payRate) {
            name = empName;
            pay = payRate;
        }

        string getName() const {
            return name;
        }

        void setName(string empName) {
            name = empName;
        }

        int getPay() {
            return pay;
        }

        void setPay(int payRate) {
            pay = payRate;
        }

        // string toString() {
        //     stringstream stm;
        //     stm << name << ": " << pay;
        //     return stm.str();
        // }
       
};
int main()
{
    Employee emp1;
    emp1.setName("Jane Doe");
    cout << emp1.getName();
    return 0;
}
