#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{

    fstream f;
    f.open("donate_total.txt", ios::app);
    // f << "0";
    string input;
    getline(cin, input);
    string get_num;
    for (int i = 0; i < input.size(); i++)
    {
        /* code */
        if (input[i] == ' ')
        {
            for (int j = i + 1; j < input.size(); j++)
            {
                /* code */
                get_num += input[j];
            }
            break;
        }
    }
    // cout << get_num;
    f << get_num + '\n';

    // f << input;

    return 0;
}