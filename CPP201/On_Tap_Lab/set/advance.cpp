#include <iostream>
#include <iterator>
#include <list>

using namespace std;
int main(int argc, char const *argv[])
{
    list<int> my_list = {1, 5, 5, 5, 10, 52};
    list<int>::iterator it = my_list.begin();
    advance(it, my_list.size()-1);
    cout << *it;
    return 0;
}
