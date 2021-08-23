#pragma once
class Car {
	
private:
	int code[8];
	int safe[3];
public:
	int* GetCode();
	int* GetSafe();
	void SetCode(int arr[], int length);
	void SetSafe(int arr[], int length); 
};