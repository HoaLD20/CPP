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

       void setNext(Node *aNext) {
           next = aNext;
       }
};

class LList {
    public:
       Node *head;
       LList() {
           head = NULL;
       }
       void Append(string data) {
           Node *newNode = new Node(data, NULL);
           Node *tmp = head;
           if (tmp != NULL) {
               while (tmp->Next() != NULL) {
                   tmp = tmp->Next();
               }
               tmp->setNext(newNode);
           }
           else {
               head = newNode;
           }
       }
       void Delete(string data) {
           Node *tmp = head;
           if (tmp == NULL) {
               return;
           }
           if (tmp->Next() == NULL) {
               delete tmp;
               head = NULL;
           }
           else {
               Node *prev;
               do {
                   if (tmp->getData() == data)
                      break;
                    prev = tmp;
                    tmp = tmp->Next();
               } while(tmp != NULL);
               prev->setNext(tmp->Next());
               delete tmp;
           }
       }
};

int main()
{

    return 0;
}
