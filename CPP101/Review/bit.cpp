#include<iostream>

using namespace std;

int main() {
	int a = 6;
	if (a & 1) {
		cout << a << " is odd number";
	} else {
		cout << a << " is even number";
	}

	return 0;
}