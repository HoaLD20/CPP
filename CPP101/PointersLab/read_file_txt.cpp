#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void ReadFile()
{
    fstream f;
    f.open("read_file.txt", ios::in);
    string data;
    string line;
    while (!f.eof())
    {
        getline(f, line);
        data += line;
    }

    f.close();
    cout << data;
}

void WriteFile()
{
    fstream f;
    f.open("read_file.txt", ios::out);
    string data = "aaaaaaaaaabbbbbbbbbbbbbbbbb\nbbbbbbbbbbbbbbbbbbb";
    f << data;
    f.close();
}

int main()

{

    return 0;
}