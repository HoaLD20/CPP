#include <iostream>
#include <string>
using namespace std;

class Stack {
    private:
       string datastore[100];
       int top;
    public:
       Stack() {
           top = -1;
       }

       void push(string value) {
           ++top;
           datastore[top] = value;
       }

       string pop() {
           string retVal = datastore[top];
           --top;
           return retVal;
       }

       string peek() {
           return datastore[top];
       }

       int count() {
           return top + 1;
       }

       void clear() {
           for (int i = 0; i <= top-1; ++i) {
               datastore[i] = "";
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

int main()
{
    Stack names;
    names.push("Mary");
    names.push("Joe");
    cout << "number of items: " << names.count() << endl;
    if (!names.isEmpty()) {
        names.pop();
    }
    cout << "number of items: " << names.count() << endl;
    names.clear();
    cout << "number of items: " << names.count() << endl;
    return 0;
}
