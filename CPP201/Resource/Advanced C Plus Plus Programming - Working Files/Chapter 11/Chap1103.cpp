#include <iostream>

using namespace std;

namespace Currency {
    const int one = 1;
    const int two = 2;
    const int five = 5;
    const int ten = 10;
    const int twenty = 20;
    const int fifty = 50;
    const int hundred = 100;
}

int main()
{
    using namespace Currency;
    cout << one << endl
       << two << endl
       << five << endl
       << ten << endl
       << twenty << endl
       << fifty << endl
       << hundred << endl;
    cout << Currency::hundred << endl;
    cout << Currency::fifty << endl;
    return 0;
}
