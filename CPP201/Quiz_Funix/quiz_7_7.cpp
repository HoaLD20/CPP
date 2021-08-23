#include <iostream>
#include <set>
using namespace std;
int main(int argc, char const *argv[])
{
    set<int> my_set;
    my_set.insert(20);
    my_set.insert(30);
    my_set.insert(10);

    cout << *my_set.begin() << endl;

    while (!my_set.empty())
    {
        cout << ' ' << *my_set.begin();
       my_set.erase(my_set.begin());
    }
    cout << '\n';

    return 0;
}
