#include <map>
#include <string>
#include <iostream>

int main()
{
    std::map<int, std::string> m = {
        std::make_pair(0, "zero"), std::make_pair(1, "two"), std::make_pair(2, "two")};

    int key = 0;
    for (auto i : m)
    {
        if (i.second == "two")
        {
            key = i.first;
            std::cout << key << std::endl;
        }
    }

    
}