#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str0;
    string str1 = "";
    string str2(str1);
    string str3("a string");
    string str4(10,'*');
    string str5 = "hello";
    string str6 = "world";
    string str7 = str5 + " " + str6 + "!";
    cout << str7 << endl;
    string str8 = str5 + ", ";
    cout << str8 << endl;
    string str9 = "hello" + ", " + str6;
    return 0;
}
