#include <iostream>

using namespace std;

template <typename T>
bool equals(T value1, T value2) {
    if (value1 == value2) {
        return true;
    }
    else {
        return false;
    }
}

int main()
{
    int a, b;
    a = 1, b = 2;
    if (equals(a,b)) {
        cout << a << " and " << b << " are equal." << endl;
    }
    else {
        cout << a << " and " << b << " are not equal."
           << endl;
    }
    string word1, word2;
    word1 = word2 = "hello";
    if (equals(word1, word2)) {
        cout << word1 << " and " << word2 << " are equal."
           << endl;
    }
    else {
        cout << word1 << " and " << word2 << " are not equal."
           << endl;
    }
    return 0;
}
