#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
    int n = 5, i = 0, S = 0;
    int *p = new int[5];
    for (i = 0; i < n; i++)
        *(p + i) = (i % 2 == 0) ? 0 : i;
    for (i = 0; i < n; i++)
        S += *(p + i);
    cout << S;
    return 0;
}