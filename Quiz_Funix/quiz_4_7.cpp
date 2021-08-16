//
// Created by hoald on 09/08/2021.
//

#include "iostream"

using namespace std;
class Test1{

};

class Test2:public Test1{

};


void Funct();
int main(){
    try {
        Funct();
    } catch (const Test1&) {
        cerr << "Caught an exception" << endl;

    }
    return 0;
}
void Funct(){
    throw Test2();
}