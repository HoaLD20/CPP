//
// Created by hoald on 10/08/2021.
//

#include "iostream"
#include "string"
using namespace std;
int main(){
    int x = -1;
    try {
        cout << "Inside try\n";
        if (x < 0){
            throw x;
            cout << "After throw\n";
        }
    } catch (int x) {
        cout << "Exception Caught \n";
    }
    cout << "After catch\n";
    return 0;
}