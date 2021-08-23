#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(int argc, char const *argv[])
{
    int my_ints[] = {10, 20, 30, 30, 20, 10, 10, 20};

    int my_count = count(my_ints, my_ints + 8, 10);
    cout << "10 appears " << my_count << " times" << endl;


    vector<int> my_vectr(my_ints, my_ints + 8);
    my_count = count(my_vectr.begin(), my_vectr.end(), 20);
    
    cout << "20 appears " << my_count << " times" << endl;

    return 0;
}
