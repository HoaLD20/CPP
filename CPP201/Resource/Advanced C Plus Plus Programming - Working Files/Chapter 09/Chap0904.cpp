#include <iostream>

using namespace std;

class Queue {
    private:
       string datastore[100];
       int back;
       const static int front = 0;
       void shift() {
           for(int i = front; i <= back; ++i) {
               datastore[i] = datastore[i+1];
           }
           --back;
       }
    public:
       Queue() {
           back = -1;
       }
       void in(string value) {
           ++back;
           datastore[back] = value;
       }
       string out() {
           string retVal = datastore[front];
           shift();
           return retVal;
       }
       void show() {
           for(int i = front; i <= back; ++i) {
               cout << datastore[i] << " ";
           }
           cout << endl;
       }
       int count() {
           int cnt = 0;
           for (int i = 0; i <= back; ++i) {
               ++cnt;
           }
           return cnt;
       }

       string qFront() {
           return datastore[front];
       }
       string qBack() {
           return datastore[back];
       }
       bool isEmpty() {
           if (back == -1) {
               return true;
           } else {
               return false;
           }
       }
       void clear() {
           for (int i = front; i <= back; ++i) {
               datastore[i] = "";
           }
       }
};


int main()
{
    Queue letters;
    letters.in("A");
    letters.in("B");
    letters.in("C");
    cout << "front: " << letters.qFront() << endl;
    cout << "back: " << letters.qBack() << endl;
    cout << "count: " << letters.count() << endl;
    letters.out();
    cout << "front: " << letters.qFront() << endl;
    cout << "back: " << letters.qBack() << endl;
    cout << "count: " << letters.count() << endl;
    letters.in("D");
    cout << "front: " << letters.qFront() << endl;
    cout << "back: " << letters.qBack() << endl;
    cout << "count: " << letters.count() << endl;
    letters.out();
    cout << "front: " << letters.qFront() << endl;
    cout << "back: " << letters.qBack() << endl;
    cout << "count: " << letters.count() << endl;
    return 0;
}
