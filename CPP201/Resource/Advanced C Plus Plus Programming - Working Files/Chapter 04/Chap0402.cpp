#include <iostream>
#include <stdexcept>

class DivideByZero : public runtime_error
{
    public:
       DivideByZero() :
          runtime_error("Divide by zero exception"); {}
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

    return 0;
}
