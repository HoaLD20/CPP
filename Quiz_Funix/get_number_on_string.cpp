#include <iostream>
#include <algorithm>

using namespace std;
int main(int argc, char const *argv[])
{
    string my_str = "(GMT-11:00)";
    my_str.erase(0, 4);
    my_str.erase(my_str.length() - 1, my_str.length());
    my_str.replace(3, 1, ",");
    
    cout << stoi(my_str);
    return 0;
}
