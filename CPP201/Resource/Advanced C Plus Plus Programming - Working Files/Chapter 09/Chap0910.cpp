#include <iostream>

using namespace std;

class Stack {
    private:
       int datastore[100];
       int top;
    public:
       Stack() {
           top = -1;
       }

       void push(int value) {
           ++top;
           datastore[top] = value;
       }

       int pop() {
           int retVal = datastore[top];
           --top;
           return retVal;
       }

       int peek() {
           return datastore[top];
       }

       int count() {
           return top + 1;
       }

       void clear() {
           for (int i = 0; i <= top-1; ++i) {
               datastore[i] = 0;
           }
           top = -1;
       }

       bool isEmpty() {
           if (top == -1) {
               return true;
           }
           else {
               return false;
           }
       }
};

void Convert(int number) {
    const int base = 2;
    Stack digits;
    do {
        digits.push(number % base);
        number = number / base;
    } while(number != 0);
    while(digits.count() > 0) {
        cout << digits.pop();
    }
}

int main()
{
    int number;
    cout << "Enter a base 10 number: ";
    cin >> number;
    cout << number << " base 10 equals ";
    Convert(number);
    cout << " base 2." << endl;
    return 0;
}
