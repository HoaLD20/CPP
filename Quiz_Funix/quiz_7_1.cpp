#include <iostream>
#include <map>
#include <utility>

using namespace std;

int main(int argc, char const *argv[])
{
    multimap<string, string> vars;
    vars.insert(pair<string, string>("An", "50"));
    vars.insert(pair<string, string>("Hai", "60"));
    vars.insert(pair<string, string>("Binh", "70"));

    string search_name = "Hai";
    multimap<string, string>::iterator iter = vars.find(search_name);
    multimap<string, string>::iterator last = vars.upper_bound(search_name);
    
    vars.erase("Hoa");
    cout << vars.size();
    return 0;
}
