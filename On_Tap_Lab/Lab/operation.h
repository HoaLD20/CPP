#ifndef OPERATION_H_
#define OPERATION_H_

#include <string>
#include <vector>

using namespace std;

bool getInputYN(string msg);
string getInputString(string msg, string reMsg, string reg);
int getInputNumber(string msg, string reMsg, string reg);
vector<string> explode(const string&, const char&);

#endif