#include <iostream>
#include <set>
using namespace std;
int main(int argc, char const *argv[])
{
    set<int> numbers = {1, 2, 3, 2, 4, 5};
    auto search = numbers.find(2);
    if (search != numbers.end())
    {
        cout << "Found " << (*search) << endl;
    }
    else
    {
        cout << "Not found" << endl;
    }

    return 0;
}
