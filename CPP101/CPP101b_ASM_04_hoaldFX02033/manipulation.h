#pragma once
#include <iostream> 
#include "car.h"
using namespace std;

/// <summary>
/// Change all element of array to list string
/// </summary>
/// <param name="array">array to change type</param>
/// <param name="midle">string between each elements</param>
/// <param name="length">length of array</param>
/// <returns>string after change array to string</returns>
string ChangeArrayToString(int array[], string midle, int length);

/// <summary>
/// Show all elements of array
/// </summary>
/// <param name="msg">message before show array</param>
/// <param name="arr">array to show in terminal</param>
/// <param name="length">length of array</param>
void ShowArray(string msg, int arr[], int length);

/// <summary>
/// Check valid input from user
/// </summary>
/// <param name="msg">message in first time</param>
/// <param name="reMsg">message when user input wrong format</param>
/// <param name="index">index of times input</param>
/// <param name="reg">regular expession to check user input</param>
/// <returns>user input</returns>
int CheckValidInput(string msg, string re_msg, int index, string reg);

/// <summary>
/// Write data into file
/// </summary>
/// <param name="fileName">file name to write data</param>
/// <param name="data">data to write into file</param>
void WriteFile(string file_name, Car* data);

/// <summary>
/// Read data from file
/// </summary>
/// <param name="fileName">file name to read data</param>
/// <returns>string from file</returns>
Car* ReadFile(string file_name);

/// <summary>
/// Check user want to change something or not
/// </summary>
/// <param name="msg">message to show for user</param>
/// <returns>user input</returns>
bool CheckChange(string msg);

/// <summary>
///	Show main menu of car
/// </summary>
/// <returns>user selection in main menu</returns>
int GearboxTransmissionSelection();
/// <summary>
/// check array empty or not
/// </summary>
/// <param name="arr">array to check</param>
/// <param name="length">size of array</param>
/// <returns></returns>
bool IsArrayEmpty(int* arr, int length);
