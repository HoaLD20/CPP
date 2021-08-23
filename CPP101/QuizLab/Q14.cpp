#include <iostream>
#include <fstream>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

string GetLastLine(string file_name)
{

    string lastLine;
    // string filename = "test.txt";
    ifstream fin;
    fin.open(file_name);
    if (fin.is_open())
    {
        fin.seekg(-1, ios_base::end); // go to one spot before the EOF

        bool keepLooping = true;
        while (keepLooping)
        {
            char ch;
            fin.get(ch); // Get current byte's data

            if ((int)fin.tellg() <= 1)
            {                        // If the data was at or before the 0th byte
                fin.seekg(0);        // The first line is the last line
                keepLooping = false; // So stop there
            }
            else if (ch == '\n')
            {                        // If the data was a newline
                keepLooping = false; // Stop at the current position.
            }
            else
            {                                 // If the data was neither a newline nor at the 0 byte
                fin.seekg(-2, ios_base::cur); // Move to the front of that data, then to the front of the data before it
            }
        }

        getline(fin, lastLine); // Read the current line
        // cout << "Result: " << lastLine << '\n'; // Display it

        fin.close();
    }
    return lastLine;
}

int main(int argc, char const *argv[])
{

    fstream f;

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

    string data = GetLastLine("donate_total.txt");
    f.open("donate_total.txt", ios::app);
    int num = stoi(data);
    num = num + stoi(get_num);
    f << '\n' + get_num + '\n';
    f << num;
    f.close();

    return 0;
}
