#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
    vector<int> my_vector(4);

    fill(my_vector.begin(), my_vector.begin() + 2, 3);
    cout << *my_vector.begin() << endl;

    fill(my_vector.begin() + 1, my_vector.end() - 1, 4);
    for (vector<int>::iterator it = my_vector.begin(); it != my_vector.end();
         it++)
    {
        cout << ' ' << *it;
    }
    return 0;
}
