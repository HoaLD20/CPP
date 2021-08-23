#pragma once

/// <summary>
/// change value inmediately from address of it
/// </summary>
/// <param name="first_number">first number</param>
/// <param name="seccond_number">seccond number</param>
void Swap(int *first_number, int *seccond_number);

/// <summary>
/// Bubble sort
/// </summary>
/// <param name="arr"> array need to be sorted</param>
/// <param name="n">array lenght</param>
/// <returns>number of step</returns>
int BubbleSort(int arr[], int lenght);

/// <summary>
/// Selection sort
/// </summary>
/// <param name="arr"> array need to be sorted</param>
/// <param name="n">array lenght</param>
/// <returns>number of step</returns>
int SelectionSort(int arr[], int lenght);

/// <summary>
/// check different between two array
/// </summary>
/// <param name="preInstall">first array</param>
/// <param name="userInput">second array</param>
/// <returns>true if different, else false</returns>
bool IsDiff(int pre_install[], int user_input[]);