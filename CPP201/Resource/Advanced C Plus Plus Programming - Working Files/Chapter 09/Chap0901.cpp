#include <iostream>
#incluce <string>
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
};

int main()
{

    return 0;
}
