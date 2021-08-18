#include "CheckValid.h"
using namespace std;
#include <regex>
#include <string>

//check valid car name
string validCarName() {
	string input;
	bool check;
	do {
		check = true;
		getline(cin, input);
		if (input.length() == 0 ) {			
			cout << "Car name must be a string. Re-enter: ";
			check = false;
		}

	} while (!check);
	return input;
}

//check valid input 
int validInput(string name) {
	string input;
	do {
		getline(cin, input);//lay chuoi de dem regex với \\d+
		//nhap so nguyen tu 1-9
		if (!regex_match(input, regex("\\d+"))) {
			cout << name << " must be a interger. Re-enter: ";

		}
	} while (!regex_match(input, regex("\\d+")));
	return stoi(input);
}

//check valid input chon sap xep
int validInput() {
	string input;
	do {
		getline(cin, input);//lay chuoi de dem regex với \\d+
		//nhap so nguyen tu 1-9
		if (!regex_match(input, regex("[1-3]{1}"))) {
			cout <<"Please enter your choice from 1-3. Re-enter: ";

		}
	} while (!regex_match(input, regex("[1-3]{1}")));
	return stoi(input);
}
//check valid email 
string validEmail() {
	string input;
	bool check;
	do {
		check = true;
		getline(cin, input);
		if (!regex_match(input, regex("[a-zA-Z0-9]+([.-_][a-zA-Z0-9]+)*@[a-zA-Z0-9][a-zA-Z0-9-]*[a-zA-Z0-9](\\.[a-z0-9]{2,}){1,}"))) {
			cout << "Re-enter the email with the format abc@gmail.com: ";
			check = false;
		}
	} while (!check);
	return input;
}

//check valid personal key 
string validKey() {
	string input;
	do {
		getline(cin, input);
		if (!regex_match(input, regex("\\d{8}"))) {
			cout << "Personal key must be a digit and 8 digits. Re-enter personal key: ";
		}
	} while (!regex_match(input, regex("\\d{8}")));
	return input;
}

//nhap thong tin cho xe tiep theo hay khong
bool isInputNewCar(int count) {
	string choice;
	while (true) {
		cout << "Will you input for Car " << count + 1 << " ? (y/n): ";

		getline(cin, choice);
		//khi chon yes
		if (regex_match(choice, regex("[Yy]"))) {
			return true;
		}
		//khi chon no
		else if (regex_match(choice, regex("[Nn]"))) {
			system("cls");
			return false;
		}
		else {
			cout << "\nPlease just enter \'Y\' or \'y\' or \'N\' or \'n\' \n" << endl;
		}
	}
}

//check valid khi lua chon timezone
int validTimezones() {
	string input;
	bool check;
	do {
		check = true;
		getline(cin, input);
		if (!regex_match(input, regex("\\d+")) || stoi(input) <= 0 || stoi(input) > 32) {
			cout << "Select must be a integer number from 1 to 32. Re-enter: ";
			check = false;
		}
	} while (!check);
	return stoi(input);
}

//check valid khi lua chon language
int validLanguage() {
	string input;
	bool check;
	do {
		check = true;
		getline(cin, input);
		if (!regex_match(input, regex("\\d+")) || stoi(input) <= 0 || stoi(input) > 30) {
			cout << "Select must be a integer number from 1 to 30. Re-enter: ";
			check = false;
		}
	} while (!check);
	return stoi(input);
}
