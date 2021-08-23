//
// Created by hoald on 09/08/2021.
//

#include "iostream"
using namespace std;
template<typename T, typename U>
T min(T arg1, U arg2){
    return (arg1 < arg2) ? arg1 : arg2;
}

int main(){
    double num1 = 50.5;
    int num2 = 80;
    cout << "min value is: " << min(num1, num2) << endl;
}