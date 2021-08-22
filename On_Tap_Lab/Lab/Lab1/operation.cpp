#include <regex>
#include <iostream>
#include <string>
#include "operation.h"
#include <iomanip>

using namespace std;

/// <summary>
/// Check user input number
/// </summary>
/// <param name="msg">show message</param>
/// <param name="reMsg">show error message</param>
/// <param name="reg">regular expression</param>
/// <returns></returns>
int getInputNumber(string msg, string reMsg, string reg) {
	string showMsg = msg;
	string userInput = "";
	/*
		Check valid data from user
	*/
	do {
		cout << showMsg;
		getline(cin, userInput);
		showMsg = reMsg;
	} while (!regex_match(userInput, regex(reg)));
	return stoi(userInput);
}

/// <summary>
/// Check user input string
/// </summary>
/// <param name="msg">show message</param>
/// <param name="reMsg">show error message</param>
/// <param name="reg">regular expression</param>
/// <returns></returns>
string getInputString(string msg, string reMsg, string reg) {
	string showMsg = msg;
	string userInput = "";
	/*
		Check valid data from user
	*/
	do {
		cout << showMsg;
		getline(cin, userInput);
		showMsg = reMsg;
	} while (!regex_match(userInput, regex(reg)));
	return userInput;
}

/// <summary>
/// Check user input yes no question
/// </summary>
/// <param name="msg">show lessage</param>
/// <returns>yse no</returns>
bool getInputYN(string msg) {
	string userInput = "a";
	while (!regex_match(userInput, regex("[YNyn]"))) {
		cout << msg << endl;
		getline(cin, userInput);
	}
	return regex_match(userInput, regex("[Yy]"));
}

vector<string> explode(const string& s, const char& c) {
	string buff{ "" };
	vector<string> v;

	for (auto n : s) {
		if (n != c)
			buff += n;
		else if (n == c && buff != "") {
			v.push_back(buff);
			buff = "";
		}
	}
	if (buff != "")
		v.push_back(buff);

	return v;
}