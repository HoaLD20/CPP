#include "sort.h"
#include "manipulation.h"

/// <summary>
/// change value inmediately from address of it
/// </summary>
/// <param name="firstNumber">first number</param>
/// <param name="seccondNumber">seccond number</param>
// void swap(int *firstNumber, int *seccondNumber)
// {
// 	int temp = *firstNumber;
// 	*firstNumber = *seccondNumber;
// 	*seccondNumber = temp;
// }
void Swap(int *xp, int *yp)
{
	//thuc hien swap 2 phan tu voi nhau
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}
/// <summary>
/// Bubble sort
/// </summary>
/// <param name="arr"> array need to be sorted</param>
/// <param name="n">array lenght</param>
/// <returns>number of step</returns>
// int BubbleSort(int arr[], int n)
// {
// 	int count = 0;
// 	int i, j; // declare two variable to get two index and compare each others
// 	for (i = 0; i < n - 1; i++)
// 		// Last i elements are already in place
// 		for (j = 0; j < n - i - 1; j++)
// 			//compare to get larger value then swap them
// 			if (arr[j] > arr[j + 1]) {
// 				swap(&arr[j], &arr[j + 1]);
// 				count++;
// 			}
// 	return count;
// }

int BubbleSort(int *pointer, int size)
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
				// doi cho 2 so
				swap = *(pointer + count2);
				*(pointer + count2) = *(pointer + count2 + 1);
				*(pointer + count2 + 1) = swap;
				++complex;
			}
		}
	}
	return complex;
}
/// <summary>
/// Selection sort
/// </summary>
/// <param name="arr"> array need to be sorted</param>
/// <param name="n">array lenght</param>
/// <returns>number of step</returns>
// int SelectionSort(int arr[], int n)
// {
// 	int i, j, min_idx;
// 	int count = 0;
// 	// One by one move boundary of unsorted subarray
// 	for (i = 0; i < n - 1; i++)
// 	{
// 		// Find the minimum element in unsorted array
// 		min_idx = i;
// 		for (j = i + 1; j < n; j++)
// 			if (arr[j] < arr[min_idx]) {
// 				min_idx = j;

// 			}

// 		// Swap the found minimum element with the first element
// 		swap(&arr[min_idx], &arr[i]);
// 		count++;
// 	}
// 	return count;
// }

int SelectionSort(int *ptr, int n)
{
	int i, j, t;
	int complex = 0;

	// Sort the numbers using pointers
	for (i = 0; i < n; i++)
	{

		for (j = i + 1; j < n; j++)
		{

			if (*(ptr + j) < *(ptr + i))
			{

				t = *(ptr + i);
				*(ptr + i) = *(ptr + j);
				*(ptr + j) = t;
				complex += 1;
			}
		}
	}
	return complex;
}

/// <summary>
/// check different between two array
/// </summary>
/// <param name="pre_install">first array</param>
/// <param name="user_input">second array</param>
/// <returns>true if different, else false</returns>
bool isDiff(int pre_install[], int user_input[])
{
	int temp_pre_install[8];
	int temp_user_input[8];
	for (int i = 0; i < 8; i++)
	{
		temp_pre_install[i] = pre_install[i];
		temp_user_input[i] = user_input[i];
	}

	SelectionSort(temp_user_input, 8);
	BubbleSort(temp_pre_install, 8);
	//check different
	for (int i = 0; i < 8; i++)
	{
		if (temp_user_input[i] != temp_pre_install[i])
		{
			return true;
		}
	}
	return false;
}