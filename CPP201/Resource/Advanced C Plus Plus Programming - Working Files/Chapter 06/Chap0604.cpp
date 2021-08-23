#include <iostream>
#include <deque>

using namespace std;

int main()
{
    deque<string> line;
    line.push_back("Customer 1");
    line.push_front("Customer 2");
    line.push_back("Customer 3");
    for (int i = 0; i < line.size(); ++i) {
        cout << line[i] << endl;
    }
    line.pop_back();
    line.pop_front();
    for (int i = 0; i < line.size(); ++i) {
        cout << line[i] << endl;
    }
    cout << "size of line: " << line.size() << endl;
    return 0;
}
