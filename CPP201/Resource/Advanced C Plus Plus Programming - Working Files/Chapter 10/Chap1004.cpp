#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void display(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertionSort(int arr[], int size)
{
    int j, temp;
    for (int i = 1; i < size; ++i) {
        j = i;
        while (j > 0 && arr[j-1]>arr[j]) {
            temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j--;
        }
        display(arr, size);
    }
}

int main()
{
    const int size = 10;
    int numbers[size];
    srand(unsigned(time(0)));
    for (int i = 0; i < size; ++i) {
        numbers[i] = (rand() % 100)+1;
        cout << numbers[i] << " ";
    }
    cout << endl;
    insertionSort(numbers, size);
    display(numbers, size);
    return 0;
}
