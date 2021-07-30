#ifndef COMMON_H_
#define COMMON_H_

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class CommonInfo{
public:
	string getNumber() {
		return number;	
	}
	
	string getName(){
		return name;
	}
	
	void setNumber(string data) {
		number = data;	
	}
	
	void setName(string data){
		name = data;
	}
	
	
	void printData(int i){
		cout  << setw(2) << i << ": " << setw(15) << number << name << endl;
	}
	
private:
	string number;
	string name;		
};

#endif // COMMON_H_
