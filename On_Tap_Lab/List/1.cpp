#include <iostream>
#include <list>

using namespace std;

int main(int argc, char const *argv[])
{
    list<int> a = {5, 10, 15};
    for (auto &&i : a)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << a.front() << endl;
    cout << a.back() << endl;
    a.remove(15);
    list<int>::iterator position = a.begin();
    position; 
    cout << *position;
    // a.erase(position);

    // a.push_back(11);
    // a.push_front(12);
    // a.pop_back();
    // a.pop_front();

    for (auto &&i : a)
    {
        cout << i << " ";
    }
    cout << endl;
    a.reverse();
    for (list<int>::iterator i = a.begin(); i != a.end(); i++)
    {
        // a.erase(i);
        cout << *i << " ";
    }
    cout << endl;
    cout << a.size() << endl;

    cout << endl;

    return 0;
}
