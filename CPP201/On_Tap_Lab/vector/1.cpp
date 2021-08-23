#include <iostream>
#include <vector>

using namespace std;
void PrintVector(vector<int> a);

int main(int argc, char const *argv[])
{
    vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> b;
    //
    PrintVector(a);
    a.push_back(200);
    PrintVector(a);
    //
    cout << "Last element: " << a.back() << endl;
    cout << "Front element: " << a.front() << endl;
    b.insert(b.begin(), 5, 10);
    b.push_back(2001);
    b.insert(b.begin(), 90);
    PrintVector(b);
    cout << "First element: " << a[0] << " or " << a.at(0) << endl;

    vector<int> c = {999, 5, 6};

    if (c.empty())
    {
        cout << "c is empty" << endl;
    }
    else
    {
        cout << "c is not empty" << endl;
        cout << c.size() << endl;
    }
    PrintVector(c);
    c.resize(2);
    PrintVector(c);
    c.erase(c.begin());
    // c.push_back(50);
    PrintVector(c);

    return 0;
}

void PrintVector(vector<int> a)
{
    for (auto &&i : a)
    {
        cout << i << " ";
    }
    cout << endl;
}
