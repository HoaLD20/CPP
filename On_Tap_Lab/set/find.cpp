#include <iostream>
#include <set>
#include <vector>

using namespace std;
int main(int argc, char const *argv[])
{
    vector<int> my_vector = {12, 5, 8, 9, 10};
    set<int> s(my_vector.begin(), my_vector.end());
    for (auto &&i : s)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << *s.end() << endl;
    cout << *s.begin() << endl;

    set<int>::iterator it = s.find(2);
    cout << *it;
    return 0;
}
