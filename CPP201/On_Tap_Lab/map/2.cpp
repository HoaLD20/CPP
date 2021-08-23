#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
int main(int argc, char const *argv[])
{

    map<int, vector<string>> meow;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            string s = to_string(j);
            meow[i].push_back(s);
        }
    }
    for (auto itr = meow.begin(); itr != meow.end(); itr++)
    {
        std::cout << itr->first << ":";
        for (auto vitr = itr->second.begin(); vitr != itr->second.end(); vitr++)
        {
            std::cout << *vitr << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
