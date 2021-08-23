#include <iostream>
#include <set>

using namespace std;

void PrimeGen(int n) {
    set<int> primes;
    int count;
    for(int nums = 2; nums <= n; ++nums) {
        primes.insert(nums);
    }
    set<int>::iterator it;
    for(int mults = 2; mults*mults <= n; ++mults) {
        it = primes.find(mults);
        if (it != primes.end()) {
            for(int k=2*mults; k <= n; k += mults) {
                it = primes.find(k);
                if (it != primes.end()) {
                    primes.erase(*it);
                }
            }
        }
    }
    count = 1;
    for(set<int>::iterator it1 = primes.begin();
        it1 != primes.end(); ++it1) {
            cout << *it1 << " ";
            if (count++ % 10 == 0) {
                cout << endl;
            }
        }
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;
    PrimeGen(n);
    return 0;
}
