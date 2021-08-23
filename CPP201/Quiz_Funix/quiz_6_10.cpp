#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char const *argv[])
{
    vector<int> my_vector(3);
    for (unsigned i = 0; i < 3; i++)
    {
        my_vector.push_back(i);
    }
    cout << my_vector.size() <<endl;
    for (unsigned i = 0; i < my_vector.size(); i++)
    {
        cout << my_vector[i];
    }

    return 0;
}
