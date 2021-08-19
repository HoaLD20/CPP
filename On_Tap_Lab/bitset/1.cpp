#include <iostream>
#include <bitset>
using namespace std;
int main(int argc, char const *argv[])
{
    /*
    error
    */
    int n = 4;
    bitset<n> foo;
    cout << foo;
    return 0;
}
