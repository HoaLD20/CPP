#include <iostream>
#include <set>
using namespace std;

struct cmp
{
    bool operator()(int a, int b) { return a > b; }
};

int main()
{

    set<int> s;

    s.insert(1); // s={1}

    s.insert(4); // s={4,1}

    s.insert(2); // s={4,2,1}

    s.insert(9); // s={9,4,2,1}

    for (set<int>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }

    return 0;
}
