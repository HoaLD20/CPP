#include <iostream>

using namespace std;

int find(string word, char lookedFor) {
    for(int i = 0; i < word.length(); ++i) {
        if (word[i] == lookedFor) {
            return i;
        }
    }
    return -1;
}

string replace(string word, char oldChar, char newChar) {
    int pos = find(word, oldChar);
    word = word.substr(0,pos) + newChar + word.substr(pos+1);
    return word;
}

int main()
{
    /*string word = "hello";
    cout << find(word, 'e');*/
    string word = "word";
    string newword = replace(word,'d','k');
    cout << "Old word: " << word << endl <<
       "New word: " << newword << endl;
    return 0;
}
