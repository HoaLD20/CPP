#include <iostream>
#include <map>
#include <vector>

using namespace std;
int main(int argc, char const *argv[])
{
    // iterator cho vector
    vector<int>::iterator it_1;
    // vector thuong
    vector<int> vector;

    // add element to vector
    for (int i = 0; i < 10; i++)
    {
        vector.push_back(i);
    }
    cout << vector.front() << endl;
    it_1 = vector.end();
    // cout << vector.cend() << endl;
    cout << *it_1 << endl;

    return 0;
}
