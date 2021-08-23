#include <iostream>
#include <set>

using namespace std;

int main()
{
    set<string> words;
    string word = "";
    do {
        cout << "Enter a word (quit to quit): ";
        cin >> word;
        words.insert(word);
    } while (word != "quit");
    set<string>::iterator it = words.begin();
    while (it != words.end()) {
        cout << *it << " ";
        ++it;
    }
    return 0;
}
