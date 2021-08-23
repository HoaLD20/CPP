#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <numeric>
using namespace std;

void display(vector<int> vec) {
    for(int i = 0; i < vec.size(); ++i) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

int genRandom() {
    return rand() % 100 + 1;
}

int main()
{
    vector<int> numbers(10);
    srand(time(NULL));
    /*for(int i = 0; i < numbers.size(); ++i) {
        numbers[i] = rand() % 100 + 1;
    }*/
    generate(numbers.begin(), numbers.end(),
             genRandom);
    display(numbers);
    /*int sum = 0;
    for(int i = 0; i < numbers.size(); ++i) {
        sum += numbers[i];
    }*/
    int sum = accumulate(numbers.begin(),
                         numbers.end(), 0);
    cout << "the sum is " << sum << endl;
    return 0;
}
