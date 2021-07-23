#include <iostream>
using namespace std;

class DaHinh
{
public:
    void Print_Int(int i)
    {
        cout << "Print Int " << i;
    }

    void Print_Int(string name)
    {
        cout << "Print Int " << name;
    }

    void Print_Int(string gioi_tinh)
    {
        cout << "Print Int " << gioi_tinh;
    }
};

int main(int argc, char const *argv[])
{
    DaHinh dahinh;
    cout << dahinh.Print_Int(100);

    return 0;
}
