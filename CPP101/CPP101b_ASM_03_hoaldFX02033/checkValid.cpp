#include "checkValid.h"
using namespace std;
#include <regex>

//check valid input 
int validInput() {
	string input;
	do {
		cin >> input;
		//nhap so nguyen tu 1-9
		if (!regex_match(input, regex("\\d"))) {
			cout << "NHAP LAI SO: ";

		}
	} while (!regex_match(input, regex("\\d")));
	return stoi(input);
}

//check valid input muc van toc
int validInputVanToc() {
	string input;
	do {
		cin >> input;
		//nhap so nguyen tu 1-9
		if (!regex_match(input, regex("\\d+"))) {
			cout << "NHAP LAI SO: ";

		}
	} while (!regex_match(input, regex("\\d+")));
	return stoi(input);
}

//thay doi ma so mac dinh
bool changPassword(string message) {
	string choice;
	while (true) {
		printf("\033c");
		cout << message << endl << "  >>>>>>>>  ";

		cin >> choice;
		//khi chon yes
		if (regex_match(choice, regex("[Yy]"))) {
			return true;
		}
		//khi chon no
		else if (regex_match(choice, regex("[Nn]"))) {
			return false;
		}
	}


}