#include "Sort.h"
using namespace std;
#include <iostream>

//ham swap
void swap(int *xp, int *yp)
{
	//thuc hien swap 2 phan tu voi nha
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

int bubbleSort(int *pointer, int size)
{
	int count1, count2, swap, complex = 0;
	//di tu ptu dau toi ptu cuoi
	for (count1 = 0; count1 < size - 1; count1++)
	{
		// di tu phan tu dau tien toi phan tu cuoi khi phan tu cuoi do chua dc sx
		for (count2 = 0; count2 < size - count1 - 1; count2++)
		{

			// so sanh 2 so lien ke
			if (*(pointer + count2) > *(pointer + count2 + 1))
			{
				++complex;
				// doi cho 2 so
				swap = *(pointer + count2);
				*(pointer + count2) = *(pointer + count2 + 1);
				*(pointer + count2 + 1) = swap;
			}
		}
	}
	return complex;
}

// bubble sort
// int bubbleSort(int arr[], int n)
// {
// 	int i, j, complex = 0;
// 	bool check = false;
// 	//di tu ptu dau toi ptu cuoi
// 	for (i = 0; i < n - 1; i++) {

// 		// di tu phan tu dau tien toi phan tu cuoi khi phan tu cuoi do chua dc sx
// 		for (j = 0; j < n - i - 1; j++) {
// 			++complex;//dem so lan lap cua thuat toan de tinh do phuc tap
// 			if (arr[j] > arr[j + 1]) {//neu 2 thang nam ke nhau co thang trc lon hon thang sau, thi doi cho
// 				swap(&arr[j], &arr[j + 1]);//thuc hien swap
// 				// kiem tra xem co phai truong hop bestcase cua bbsort khong (bestcase: 1234..), neu la bestcase thi chi can
// 				//lap qua 1 lan va k doi cho giua cac phtu, roi cho thoat khoi ham sort luon
// 				check = true;
// 			}
// 		}
// 		//neu k swap thi out (toi uu thuat toan, k can lap lai nhieu lan, chi can lap qua 1 lan ma k swap thi out luon)
// 		if (!check) {
// 			return complex;
// 		}
// 	}
// 	return complex;
// }

// Ham selection sort
// int selectionSort(int a[], int n)
// {
// 	int complex = 0;//tinh do phuc tap cua thuat toan
// 	for (int i = 0; i < n - 1; i++)//chay tu ptu dau toi ptu cuoi cua mang
// 	{
// 		int iMin = i;//gan i la phan tu nho nhat trong mang
// 		for (int j = i + 1; j < n; j++)//di tu phan tu i+1 de so sanh i voi nhung ptu sau
// 		{
// 			++complex;//dem so lan lap cua thuat toan de tinh do phuc tap
// 			if (a[iMin] > a[j]) {//neu min>j thi gan thang j la ptu nho nhat mang, va tiep tiep tim phan tu nho nhat trong mang cho het vong lap for cua j

// 				iMin = j;// gan j la ptu nho nhat
// 			}
// 		}
// 		if (i != iMin)//neu tim duoc ptu nho nhat kha i (luc dau gan min =i) thi thuc hien swap
// 			swap(&a[i], &a[iMin]);//doi cho i va min, dem thang min len vi tri dau tien
// 	}
// 	return complex;

// }

int selectionSort(int *const array, const int size)
{
	int smallest; // index of smallest element
	int complex = 0;
	for (int i = 0; i < size - 1; i++)
	{
		smallest = i; // first index of remaining array

		// loop to find index of smallest element
		for (int index = i + 1; index < size; index++)
		{

			if (array[index] < array[smallest])
			{

				smallest = index;
			}
		}

		swap(&array[i], &array[smallest]);
		complex++;
	}
	return complex;
}

//in mang ra khi chua sx
void printArray(int arr[], int size)
{
	int i;
	//in ra tung phan tu cua mang
	//size la do dai cua mang
	for (i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
