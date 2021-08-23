#include <iostream>
#include <fstream>

using namespace std;
int main(){
    (int arr[10] = {0,1,2,3,4,5,6,7,8,9};
    ofstream myfile('example.txt', ios::out);
    for (int i = 0; i < 10; i+=2)
    {
        myfile << arr[i] << " ";
    }
    myfile.close();
    

    return 0;
}