#include <iostream>
#include <deque>

using namespace std;

int find(deque<string> d, string value) {
    for (int i = 0; i < d.size(); ++i) {
        if (d.at(i) == value) {
            return i;
        }
    }
    return -1;
}

int main()
{
    deque<string> line;
    line.push_back("David");
    line.push_back("Raymond");
    line.push_back("Cynthia");
    line.push_back("Brian");
    line.push_back("Jennifer");
    string name;
    cout << "Name to find: ";
    cin >> name;
    int pos = find(line, name);
    if (pos > -1) {
        cout << name << " found at position " << pos << endl;
    }
    else {
        cout << name << " not found." << endl;
    }
    deque<string>::iterator iter = line.begin();
    ++iter;
    line.insert(iter, "Donnie");
    for(iter = line.begin(); iter < line.end(); ++iter) {
        cout << *iter << endl;
    }
    return 0;
}
