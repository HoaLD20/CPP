#include <iostream>
#include <stdexcept>

using namespace std;

class DivideByZero : public runtime_error
{
    public:
       DivideByZero() :
          runtime_error("Divide by zero exception") {}
};

double quotient(double numer, double denom) {
    if (denom == 0) {
        throw DivideByZero();
    }
    else {
        return numer / denom;
    }
}

int main()
{
    double number1, number2, ratio;
    cout << "Enter a numerator: ";
    cin >> number1;
    cout << "Enter a denominator: ";
    cin >> number2;
    try {
        ratio = quotient(number1, number2);
        cout << "Result is: " << ratio << endl;
    }
    /*catch (DivideByZero &except) {
        cout << except.what() << endl;
    }*/
    catch (...) {
        cout << "Exception thrown and caught" << endl;
    }
    return 0;
}
