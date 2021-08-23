#include <iostream>

using namespace std;

int main()
{
    string s1 = "a needle in a haystack";
    string word = "needle";
    int pos = s1.find(word);
    string s2 = s1.substr(pos, word.length());
    cout << s2 << endl;
    string s3 = s1.substr(pos+word.length()+1);
    cout << s3 << endl;
    s1.replace(pos, word.length(), "pin");
    cout << s1 << endl;
    return 0;
}
