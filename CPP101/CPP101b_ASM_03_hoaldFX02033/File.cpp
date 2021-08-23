#include "File.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <istream>
#include <ostream>
using namespace std;

//chuyen arr sang chuoi
// space la khoang cach hay dau ma minh truyen cao ngan cach giua cac ki tu trong chuoi
string covertArrayToString(int arr[], string space, int length) {

	string str = "";
	for (int i = 0; i < length - 1; i++) {//di toi phan tu ke cuoi, de k them dau " " vao cuoi chuoi
		str += to_string(arr[i]) + space;
	}
	str += to_string(arr[length - 1]);//them phan tu cuoi vao chuoi maf k them " "
	return str;
}

//doc ma so mac dinh trong file ra array
//space la khoang trong hay ki tu phan cach giua cac so
void getMaSoMDFormFile(string fileName, int maSoMacDinhFile[], char space) {
	string str = "";
	string temp = "";
	int index = 0;
	str = readFile(fileName);
	for (int i = 0; i < str.size(); i++) {
		if (str[i] != space) {
			temp += str[i];//lay so truoc space
		}
		else {//neu gap ki tu phan cach cac so thi lay so trong bien temp gan vao arr, va cho bien temp la rong de lay so tiep theo
			maSoMacDinhFile[index] = stoi(temp);//lay cac so truoc so cuoi cung
			index++;//de lay vi tri cho viec gan so cuoi vao arr
			temp = "";
		}
	}
	//lay so cuoi cung, do so cuoi khong con space ở phia sau nen k the vao else de bo vao trong arr duoc nen phai dat bien index gan so cuoi cung vao
	maSoMacDinhFile[index] = stoi(temp);

}

//bo khoang trong trong chuoi khi read file
string split(string str) {
	string temp = "";
	string strMa = "";
	int index = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] != ' ') {
			temp += str[i];//lay so truoc space
		}
		else {
			index++;//de lay vi tri cho viec gan so cuoi vao arr
			strMa += temp;
			temp = "";
		}
	}
	strMa += temp;
	return strMa;
}

//viet vao file
void writeFile(string fileName, string data) {
	//khai bao 1 file, ofstram la class de ghi du lieu voa file
	//ios::binary dung de mo file nhi phan hoac ios::in dung de mo file cho cac hoat dong dau ra
	ofstream ofile(fileName, ios::out | ios::binary);
	if (ofile.is_open())
	{
		//data.c_str() mang byte
		//sizeof la so luong byte cua data ma muon ghi vao file
		ofile.write(data.c_str(), sizeof(data));
	}
	else
	{
		cerr << "Couldn't open " << fileName << " for writing." << endl;
	}
	ofile.close();
}
//doc file
string readFile(string fileName) {
	string str = "";
	//ifstream doc du lieu dau vao tu file
	//ios::binary dung de mo file nhi phan hoac ios::in dung de mo file cho cac hoat dong dau vao
	ifstream ifile(fileName, ios::binary | ios::in);
	if (ifile.is_open())
	{
		//lay chuoi trog file den khi gặp null
		getline(ifile, str, '\0');
	}
	ifile.close();
	return str;
}