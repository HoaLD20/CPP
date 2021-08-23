#include <iostream>

using namespace std;

int main()
{
    int *a;
    a = new int[10];
    for (int i = 0; i < 10; i++)
    {
        /* code */
        a[i] = i;
    }

    for (int i = 0; i < 10; i++)
    {
        /* code */
        cout << *a << " ";
        a+=1;
    }
    
    a -= 10;
    delete a;
    

    return 0;
}
