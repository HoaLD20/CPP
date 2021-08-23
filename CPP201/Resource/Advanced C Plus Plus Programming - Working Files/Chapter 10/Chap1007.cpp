#include <iostream>
#include <cstdlib>
#include <time.h>
#include <stdio.h>
using namespace std;

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
    }
}

void quickSort(int arr[], int left, int right) {
    int i = left;
    int j = right;
    int tmp;
    int pivot = arr[(left+right)/2];
    while (i <= j) {
        while (arr[i] < pivot)
           i++;
        while (arr[j] > pivot)
           j--;
        if (i <= j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    }
    if (left < j)
       quickSort(arr, left, j);
    if (i < right)
       quickSort(arr, i, right);
}

double getTime(clock_t time1, clock_t time2) {
    double ticks = time1 - time2;
    return (ticks*10)/CLOCKS_PER_SEC;
}

void genData(int arr[], int size) {
    srand(time(NULL));
    for(int i = 0; i < size; ++i) {
        arr[i] = rand() % 100 + 1;
    }
}

int main()
{
    const int size = 10000;
    int numbers[size];
    genData(numbers, size);
    clock_t begin = clock();
    insertionSort(numbers, size);
    clock_t end = clock();
    cout << "Insertion sort: " <<
       getTime(end, begin) << "ms " << endl;
    genData(numbers, size);
    begin = clock();
    quickSort(numbers, 0, size);
    end = clock();
    cout << "Quicksort: " <<
       getTime(end, begin) << "ms " << endl;
    return 0;
}
