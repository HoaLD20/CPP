#include <iostream>
#include <fstream>

using namespace std;
int main()
{
    streampos begin, end;
    ifstream myfile("./example.txt", ios::in);
    begin = myfile.tellg();
    myfile.seekg(0, ios::end);
    end = myfile.tellg();
    myfile.close();
    cout << "size: " << (end - begin) << "byte";

    return 0;
}