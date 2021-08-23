#include <iostream>
#include <iomanip>
#include <fstream>
#include <regex>
#include <algorithm>
#include "operation.h"
#include "ccc_time.h"

using namespace std;

//doc du lieu tu file roi in ra man hinh
//user input thong tin roi ghi de vao file
//file gom: ccc_time
#pragma region Lab_1
void writeFile(string data)
{
	ofstream oFile;
	try
	{
		oFile.open("textdata.txt", std::ios::in | std::ios::out | std::ios::app);
		if (!oFile)
		{
			cout << "Can not open textdata.txt" << endl;
		}
		else
		{
			oFile << data;
		}
		oFile.close();
	}
	catch (const char *ex)
	{
		cout << ex << endl;
	}
}

void readFile()
{
	ifstream iFile;
	string data = ""; // each line read from file
	int seconds = 0;
	Time now, later;
	try
	{
		iFile.open("textdata.txt", std::ios::in | std::ios::out | std::ios::app); //open file
		if (iFile)
		{
			while (!iFile.eof())
			{
				try
				{
					data = "";
					getline(iFile, data); //get line from file
					if (!data.empty())
					{
						seconds = stoi(data);
						cout << "Second: " << seconds << endl;
						cout << setfill('0');
						cout << "It is now " << now.get_hours() << ":" << setw(2)
							 << now.get_minutes() << ":" << setw(2)
							 << now.get_seconds() << ". ";

						later = now;
						later.add_seconds(seconds);
						cout << "In " << seconds << " seconds, it will be ";
						cout << later.get_hours() << ":" << setw(2)
							 << later.get_minutes() << ":" << setw(2)
							 << later.get_seconds() << "."
							 << endl;
					}
				}
				catch (const std::exception &)
				{
					cout << "Error: Can not convert \"" << data << "\"" << endl;
				}
			}
		}
		else
		{
			cout << "Can not find textdata.txt" << endl;
		}
	}
	catch (const char *er)
	{
		cout << er << endl;
	}
	iFile.close();
}
#pragma endregion

// liet ke cac thuat toan tim kiem
#pragma region Lab_6
int LinearExhaustive(int a[], int n, int x)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] == x)
		{
			return i;
		}
	}
	return -1;
}

int LinearSentinel(int a[], int n, int x)
{

	int last = a[n - 1];

	a[n - 1] = x;
	int i = 0;

	while (a[i] != x)
		i++;

	a[n - 1] = last;

	if ((i < n - 1) || (a[n - 1] == x))
		return i;
	else
		return -1;
}
int BinarySearch(int arr[], int l, int r, int x)
{
	if (r >= l)
	{
		int mid = l + (r - l) / 2;

		if (arr[mid] == x)
			return mid;

		if (arr[mid] > x)
			return BinarySearch(arr, l, mid - 1, x);
		return BinarySearch(arr, mid + 1, r, x);
	}
	return -1;
}
int BinarySearch(int a[], int n, int x)
{
	return BinarySearch(a, 0, n - 1, x);
}
#pragma endregion

int main()
{

	//lab1

#pragma region Lab_1
	const int SECONDS_IN_A_DAY = 60 * 60 * 24;
	long int seconds;
	string data = "";
	string regex = "";
	Time now, later;
	string title = "";
	readFile();
	cout << endl;
	do
	{
		title = "Enter a number of seconds between 1 and " + to_string(SECONDS_IN_A_DAY - 1) + ": ";
		regex = "[1-" + to_string(SECONDS_IN_A_DAY - 1) + "]";
		seconds = getInputNumber(title, title, regex);
		cout << setfill('0');
		cout << "It is now " << now.get_hours() << ":" << setw(2) << now.get_minutes() << ":" << setw(2) << now.get_seconds() << ". ";

		later = now;
		later.add_seconds(seconds);
		cout << "In " << seconds << " seconds, it will be ";
		cout << later.get_hours() << ":" << setw(2) << later.get_minutes() << ":" << setw(2) << later.get_seconds() << "." << endl;
		data += to_string(seconds) + "\n";
	} while (getInputYN("Do you want to continue? (y/n)"));

	writeFile(data);
#pragma endregion

	//lab4

#pragma region Lab_4
	int myints[] = {12, 23, 56, 76, 43, 56, 21, 78, 80, 56};
	vector<int> v_myints(myints, myints + (sizeof(myints) / sizeof(myints[0])));
	std::vector<int>::iterator it;

	int pattern[] = {56, 21};

	for (int i = 0; i < 10; i++)
	{

		cout << myints[i] << " ";
	}
	cout << endl
		 << endl;
	cout << "So lan xuat hien so 56: " << count(myints, myints + 10, 56) << endl
		 << endl;
	it = search(v_myints.begin(), v_myints.end(), pattern, pattern + 2);
	cout << pattern;
	if (it != v_myints.end())
		std::cout << "pattern[] = { 56, 21 } found at position " << (it - v_myints.begin()) << '\n';
	else
		std::cout << "pattern[] = { 56, 21 } not found\n";

#pragma endregion

		//lab6

#pragma region Lab_6
	int a[] = {12, 23, 56, 76, 43, 56, 21, 78, 80, 56};
	int x;

	cout << "Enter the value to find: ";
	cin >> x;

	//int i = LinearExhaustive(a, 10, x);
	int i = LinearSentinel(a, 10, x);
	// int i = BinarySearch(a, 10, x);

	if (i == -1)
	{
		cout << "Not found " << x << " in array A\n";
	}
	else
	{
		cout << "Position " << x << " in array is: " << i + 1 << "\n";
	}
#pragma endregion

	return 0;
}