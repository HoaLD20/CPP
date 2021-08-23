#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// base class
class Employee {
    protected:
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

        string toString() {
            stringstream stm;
            stm << name << ": " << pay;
            return stm.str();
        }

        double grossPay(int hours) {
            return pay * hours;
        }
};

// derived class

class Manager : public Employee {
    private:
       bool salaried;

    public:

        Manager(string name, double pay, bool isSalaried)
         : Employee(name, pay)
         {
             salaried = isSalaried;
         }

        bool getSalaried() {
            return salaried;
        }

        double grossPay(int hours) {
            if (salaried) {
                return pay;
            } else {
                return pay * hours;
            }
        }

        string toString() {
            stringstream stm;
            string salary;
            if (salaried) {
                salary = "Salaried";
            } else {
                salary = "Hourly";
            }
            stm << name << ": " << pay
                << ": " << salary << endl;
            return stm.str();
        }
};

int main()
{
    vector<Employee> emps;
    Employee emp1("Jones", 25.00);
    Manager mgr1("Smith", 1200, true);
    emps.push_back(emp1);
    emps.push_back(mgr1);
    for (int i = 0; i < emps.size(); ++i) {
        cout << emps[i].grossPay(40) << endl;
    }
    return 0;
}
