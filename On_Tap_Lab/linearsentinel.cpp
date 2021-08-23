#include <iostream>
using namespace std;

int LinearSentinel(int a[], int n, int x)
{

    int last = a[n - 1]; // gan last bang fia tri cuoi

    a[n - 1] = x; // gan gia tri cuoi bang phan tu tim kiem
    int i = 0; // khoi tao index

    while (a[i] != x) // chay toi khi a[i] gap phan tu giong x
        i++;

    a[n - 1] = last; // gan phan tu cuoi cung bang last
    // tim dc vi tri phan tu trong mang 
    if ((i < n - 1) || (a[n - 1] == x))
        return i;
    else
        return -1;
}
int main(int argc, char const *argv[])
{
    int a[] = {12, 23, 56, 76, 43, 56, 21, 78, 80, 56};
    int x = 10;

    // cout << "Enter the value to find: ";
    // cin >> x;

    //int i = LinearExhaustive(a, 10, x);
    int i = LinearSentinel(a, 10, x);
    // int i = BinarySearch(a, 10, x);

    if (i == -1)
    {
        cout << "Not found " << x << " in array A\n";
    }
    else
    {
        cout << "Position " << x << " in array is: " << i + 1 << "\n";
    }
    return 0;
}
