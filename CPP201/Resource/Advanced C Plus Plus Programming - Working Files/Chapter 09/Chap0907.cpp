#include <iostream>

using namespace std;

class Node {
    public:
       string data;
       Node *next;
       Node(string aData, Node *aNext) {
           data = aData;
           next = aNext;
       }
       string getData() {
           return data;
       };
       Node *Next() {
           return next;
       }
};

int main()
{

    return 0;
}
