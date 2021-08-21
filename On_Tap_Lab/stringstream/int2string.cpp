#include <sstream>
#include <iostream>
#include <typeinfo>
using namespace std;
int main(int argc, char const *argv[])
{
    stringstream ss;

    int nValue = 12345;
    double dValue = 67.89;
    ss << nValue << " " << dValue;

    string strValue1, strValue2;
    ss >> strValue1 >> strValue2;

    cout << strValue1 << " " << strValue2 << std::endl;
    cout << typeid(strValue1).name() << " " << typeid(strValue2).name() << endl;

    return 0;
}
