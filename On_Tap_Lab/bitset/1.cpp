#include <iostream>
#include <bitset>
using namespace std;
int main(int argc, char const *argv[])
{
    /*
    error
    */
    int n = 4;
    bitset<4> foo(n); // bit set nhan gia tri co dinh da biet truoc
                        // ma khong qua bat ki bien nao 
    cout << foo;
    return 0;
}
