#ifndef LIST_H_
#define LIST_H_
#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>
using namespace std;

template<class T>
class List {
private:
	T elements_[100];
	int index = 0;
public:
	List();
	virtual ~List();	
	void add(T const&);	//Them phan tu vao cuoi mang
	void changeElement(T const&, int pos);	//Thay doi gia tri phan tu trong mang
	T get(int pos);
	int size();
	void Sap_Xep();
	void pop_element(int pos);	//Xoa phan tu tai vi tri pos trong mang
};

#endif /* LIST_H_ */

//List<Setting*> display