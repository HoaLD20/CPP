#include <iostream>

using namespace std;

// duyet mang bang pointer

int main() {
    int arr[] = { 1, 2, 3, 4, 5 };
  
    int* p = &arr[0]; // cho gia tri cua p bang o nho cua phan tu dau 
    
    // tien
    cout << "&arr[0]: " << &arr[0] << endl;
    cout << "arr[0]: " << arr[0] << endl;
    cout << "arr: " << arr << endl;
    cout << "*p: " << *p << endl;
    cout << "p: " << p << endl;
    cout << "&p: " << &p << endl;


    for (int i = 0; i < 5; i++) {
        cout << p[i] << " "; 
    }

    // for (int i = 0; i < 5; i++)
    // {
    //     /* code */
    //     cout << *p << " ";
    //     p ++ ;
    // }
    // p -= 5;
    // delete p;
    
    return 0;
}