#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    int Array[10] = {0, 1, 1, 2, 3, 4, 8, 13, 21, 34};
    copy(Array + 7, Array + 10, Array + 2);
    for (int i = 0; i < 10; i++)
    {
        cout << " " << Array[i];
    }

    return 0;
}
