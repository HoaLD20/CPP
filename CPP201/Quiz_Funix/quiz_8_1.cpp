#include <iostream>
#include <numeric>
using namespace std;
int main(int argc, char const *argv[])
{

    int arr[5] = {10, 10, 20, 30, 40};
    int sum = accumulate(arr, arr+1, 1);
    cout << "sum is " << sum << endl;
    return 0;   
}
