#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
    vector<int> numbers;
    for (int i = 1; i <= 10; ++i) {
        numbers.push_back(i);
    }
    int sum = 0;
    for (int i = 0; i < numbers.size(); ++i) {
        sum += numbers[i];
    }
    cout << "The sum is " << sum << endl;
    int sum1 = accumulate(numbers.begin(), numbers.end(), 0);
    cout << "The sum is " << sum1 << endl;
    vector<string> words;
    words.push_back("a");
    words.push_back("man");
    words.push_back("a");
    words.push_back("plan");
    words.push_back("a");
    words.push_back("canal");
    words.push_back("panama");
    string palindrome =
       accumulate(words.begin(), words.end(), string(""));
    cout << palindrome << endl;
    return 0;
}
