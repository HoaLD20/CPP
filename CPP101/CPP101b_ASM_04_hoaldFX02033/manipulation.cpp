#include <iostream>
#include <fstream>
#include <istream>
#include <ostream>
#include <regex>
#include "manipulation.h"
#include "car.h"

using namespace std;

/// <summary>
/// Change all element of array to list string
/// </summary>
/// <param name="array">array to change type</param>
/// <param name="midle">string between each elements</param>
/// <param name="length">length of array</param>
/// <returns>string after change array to string</returns>
string changeArrayToString(int *array, string midle, int length)
{
	string re = "";
	for (int i = 0; i < length - 1; i++)
	{
		re += to_string(*(array + i)) + midle;
	}
	re += to_string(*(array + (length - 1)));
	return re;
}

/// <summary>
/// Show all elements of array
/// </summary>
/// <param name="msg">message before show array</param>
/// <param name="arr">array to show in terminal</param>
/// <param name="length">length of array</param>
void showArray(string msg, int arr[], int length)
{
	cout << msg;
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

/// <summary>
/// Check valid input from user
/// </summary>
/// <param name="msg">message in first time</param>
/// <param name="reMsg">message when user input wrong format</param>
/// <param name="index">index of times input</param>
/// <param name="reg">regular expession to check user input</param>
/// <returns>user input</returns>
int CheckValidInput(string msg, string reMsg, int index, string reg)
{
	string showMsg = msg;
	string temp = "";
	/*
		Check valid data from user
	*/
	do
	{
		cout << showMsg << (index + 1) << ": ";
		getline(cin, temp);
		showMsg = reMsg;
	} while (!regex_match(temp, regex(reg)));
	return stoi(temp);
}

/// <summary>
/// Write data into file
/// </summary>
/// <param name="fileName">file name to write data</param>
/// <param name="data">data to write into file</param>
void WriteFile(string fileName, Car *data)
{
	ofstream ofile(fileName, ios::binary | ios::out);
	if (ofile.is_open())
	{
		ofile.write((char *)data, sizeof(Car));
		ofile.close();
	}
}

/// <summary>
/// Read data from file
/// </summary>
/// <param name="fileName">file name to read data</param>
/// <returns>string from file</returns>
Car *ReadFile(string fileName)
{
	Car *car = new Car();
	ifstream ifile(fileName, ios::binary | ios::in);
	if (ifile.is_open())
	{
		ifile.read((char *)car, sizeof(Car));
		ifile.close();
	}
	return car;
}

/// <summary>
/// Check user want to change something or not
/// </summary>
/// <param name="msg">message to show for user</param>
/// <returns>user input</returns>
bool CheckChange(string msg)
{
	string userInput = "";
	while (true)
	{
		printf("\033c");
		// system("cls");
		cout << msg << endl;
		getline(cin, userInput);
		if (regex_match(userInput, regex("[Yy]")))
		{
			return true;
		}
		else if (regex_match(userInput, regex("[Nn]")))
		{
			return false;
		}
	}
}

/// <summary>
///	Show main menu of car
/// </summary>
/// <returns>user selection in main menu</returns>
int GearboxTransmissionSelection()
{
	string gear = "1"; //declare default value
	int temp = 0;	   //declare default value
	cout << "XIN MOI LUA CHON" << endl;
	/*
		Only accept value from 1 to 5, except others and any characters
	*/
	do
	{
		temp = stoi(gear);
		if (temp == 0 && (temp < 1 || temp > 5))
		{
			system("cls");
			cout << "XIN MOI LUA CHON LAI" << endl;
		}
		cout << "1. P" << endl;
		cout << "2. R" << endl;
		cout << "3. N" << endl;
		cout << "4. D" << endl;
		cout << "5. POWER OFF" << endl;
		getline(cin, gear);
		//check value from 1 to 5 or not
		if (!regex_match(gear, regex("[1-5]")))
		{
			temp = 6;
			gear = "0";
		}
		else
		{
			temp = stoi(gear);
		}
	} while (temp > 5 || temp < 1);
	return temp;
}
/// <summary>
/// check array empty or not
/// </summary>
/// <param name="arr">array to check</param>
/// <param name="length">size of array</param>
/// <returns></returns>
bool IsArrayEmpty(int *arr, int length)
{
	for (int i = 0; i < length; i++)
	{
		if (*(arr + i) == 0)
		{
			return true;
		}
	}
	return false;
}
