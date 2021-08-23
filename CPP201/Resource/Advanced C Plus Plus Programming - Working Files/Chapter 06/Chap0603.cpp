#include <iostream>
#include <list>

using namespace std;

void display(list<string> lyst) {
   list<string>::iterator iter = lyst.begin();
    while (iter != lyst.end()) {
        cout << *iter << endl;
        ++iter;
    }
}

int main()
{
    list<string> names;
    names.push_back("Mary");
    names.push_back("Zach");
    names.push_back("Elizabeth");
    list<string>::iterator iter = names.begin();
    while (iter != names.end()) {
        cout << *iter << endl;
        ++iter;
    }
    cout << "first item: " << names.front() << endl;
    cout << "last item: " << names.back() << endl;
    names.reverse();
    list<string>::iterator riter = names.begin();
    while (riter != names.end()) {
        cout << *riter << endl;
        ++riter;
    }
    names.sort();
    display(names);
    names.push_front("Barry");
    display(names);
    cout << "size of list: " << names.size() << endl;
    names.remove("Elizabeth");
    display(names);
    names.pop_front();
    names.pop_back();
    display(names);
    names.clear();
    if (names.empty()) {
        cout << "list empty" << endl;
    }
    else {
        cout << "list not empty" << endl;
    }
    return 0;
}
