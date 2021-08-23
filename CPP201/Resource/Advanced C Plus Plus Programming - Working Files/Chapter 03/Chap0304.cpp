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

template<>
class Stack<string> {
    private:
       string datastore[100];
       int top;
    public:
       Stack() {
           top = -1;
       }

       void push(string val) {
           ++top;
           datastore[top] = val;
       }

       string pop() {
           string val = datastore[top];
           datastore[top] = "";
           --top;
           return val;
       }

       string peek() {
           return datastore[top];
       }
};

int main()
{
    /*Stack<double> numbers;
    numbers.push(12);
    numbers.push(22);
    cout << numbers.peek() << endl;
    double value = numbers.pop();
    cout << numbers.peek() << endl;*/
    Stack<string> names;
    names.push("Mary");
    names.push("Joe");
    cout << names.peek() << endl;
    string name = names.pop();
    cout << names.peek() << endl;
    return 0;
}
