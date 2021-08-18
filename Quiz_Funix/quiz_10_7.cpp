#include <iostream>

using namespace std;
void selectionSort(int arr[], int size);
int main(int argc, char const *argv[])
{
    int arr[] = {3, 4, 5, 2, 1};
    int arr_2[] = {12, 9, 10, 7, 8, 29, 30, 14, 45, 8};
    int count = 0;
    for (int i = 0; i < sizeof(arr_2)/sizeof(arr_2[0]); i++)
    {
        if(arr_2[i] == 8){
            break;
        }
        else{
            count += 1;
        }
    }
    cout << count << endl;
    return 0;
}

void selectionSort(int arr[], int size)
{
    int first, temp;
    int count = 0;
    for (int i = size - 1; i > 0; --i)
    {
        first = 0;
        for (int j = 1; j <= i; ++j)
        {
            if (arr[j] > arr[first])
            {
                first = j;
                count += 1;
            }
            temp = arr[first];
            arr[first] = arr[i];
            arr[i] = temp;
        }
    }
    cout << count;
}