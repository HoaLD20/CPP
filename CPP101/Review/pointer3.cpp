#include <iostream>
using namespace std;

void change(int *a)
{
    // ra 4
    //*a++;
    *a += 1;
    cout << &a << endl;
}

int main(int argc, char const *argv[])
{
    int a = 4;
    cout << &a << endl;

    change(&a);
    cout << a << endl;
    cout << &a << endl;
    return 0;
}
