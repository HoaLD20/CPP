#include <iostream>

using namespace std;

template <typename T>
class Stack {
    private:
       T datastore[100];
       int top;
    public:
       Stack() {
           top = -1;
       }

       void push(int num) {
           ++top;
           datastore[top] = num;
       }

       T pop() {
           int val = datastore[top];
           datastore[top] = 0;
           --top;
           return val;
       }

       T peek() {
           return datastore[top];
       }
};

int main()
{
    Stack<double> numbers;
    numbers.push(12);
    numbers.push(22);
    cout << numbers.peek() << endl;
    double value = numbers.pop();
    cout << numbers.peek() << endl;
    return 0;
}
