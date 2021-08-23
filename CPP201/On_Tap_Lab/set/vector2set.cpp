#include <iostream>
#include <set>
#include <vector>

using namespace std;
int main(int argc, char const *argv[])
{
    vector<int> a = {1, 5, 5, 5, 12};
    set<int> b(a.begin(), a.end());
    for (auto &&i : b)
    {
        cout << i << " ";
    }

    return 0;
}
