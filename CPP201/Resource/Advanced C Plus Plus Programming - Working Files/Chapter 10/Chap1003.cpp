#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void display(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void selectionSort(int arr[], int size)
{
    int first, temp;
    for (int i = size-1; i > 0; --i) {
        first = 0;
        for (int j = 1; j <= i; ++j) {
            if (arr[j] > arr[first]) {
                first = j;
            }
            temp = arr[first];
            arr[first] = arr[i];
            arr[i] = temp;
        }
        display(arr,size); // to display values
    }
}

void insertionSort(int arr[], int length)
{
   int i, j, tmp;
   for (i = 1; i < length; i++) {
      j = i;
      while (j > 0 && arr[j - 1] > arr[j]) {
         tmp = arr[j];
         arr[j] = arr[j - 1];
         arr[j - 1] = tmp;
         j--;
      }
   }
}

int main()
{
    const int size = 10;
    int numbers[size];
    srand(unsigned(time(0)));
    for (int i = 0; i < size; ++i) {
        numbers[i] = (rand() % 100) + 1;
        cout << numbers[i] << " ";
    }
    cout << endl;
    insertionSort(numbers, size);
    for (int i = 0; i < size; ++i) {
        cout << numbers[i] << " ";
    }
    return 0;
}
