#include <iostream>
#include <deque>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    deque<string> names;
    ifstream nameList;
    nameList.open("c:\\data\\names.txt");
    string line;
    while (!nameList.eof()) {
        getline(nameList, line);
        string::iterator it = line.end();
        --it;
        size_t pos = line.find(" ");
        string name = line.substr(0,pos);
        if (*it == 'p')
           names.push_front(name);
        else
           names.push_back(name);
    }
    deque<string>::iterator it = names.begin();
    while (it != names.end()) {
        cout << *it << endl;
        ++it;
    }
    return 0;
}
