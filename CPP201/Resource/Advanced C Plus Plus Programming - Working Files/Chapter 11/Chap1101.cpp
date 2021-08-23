#include <iostream>
using namespace std;

namespace firstNums {
    int num1 = 10;
    int num2 = 12;
}

namespace secondNums {
    int num1 = 1;
    int num2 = 2;
}

int main()
{
    cout << "num1 in firstNums: " << firstNums::num1 << endl;
    cout << "num1 in secondNums: " << secondNums::num1 <<
       endl;
    cout << "num2 in firstNums: " << firstNums::num2 << endl;
    cout << "num2 in secondNums: " << secondNums::num2 <<
       endl;
    {
        using namespace firstNums;
        cout << "num1 in firstNums: " << num1 << endl;
        cout << "num2 in firstNums: " << num2 << endl;
    }
    {
        using namespace secondNums;
        cout << "num1 in secondNums: " << num1 << endl;
        cout << "num2 in secondNums: " << num2 << endl;
    }
    return 0;
}
