#include <iostream>

using namespace std;

int main()
{

    char c;
    c = cin.get();
    do {
        cout.put(c);
        c = cin.get();
    } while(!cin.eof());
    return 0;

}
