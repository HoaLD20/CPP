//
// Created by hoald on 09/08/2021.
//

#include "iostream"

using namespace std;

int main(){
    try{
        throw 'a';
    } catch (int param) {
        cout << "int exception\n";
    }catch (...){
        cout << "default execption\n";
    }cout << "After exception";
    return 0;
}