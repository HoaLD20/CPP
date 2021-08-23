#include <iostream>
#include <map>
using namespace std;
int main(int argc, char const *argv[])
{
    map<char, int> my_map;
    map<char, int>::iterator it;
    my_map['b'] = 100;
    my_map['a'] = 200;
    my_map['c'] = 300;
    for (map<char, int>::iterator it = my_map.begin(); it != my_map.end(); it++)
    {
        cout << it->first << " => " << it->second << '\n';
    }

    return 0;
}
