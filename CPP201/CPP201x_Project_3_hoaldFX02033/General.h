#ifndef GENERAL_H_
#define GENERAL_H_

#include <vector>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class General
{
public:
	General();
	General(const General& u);
	~General();
	void xuatThongTin();
	string get_language();
	string get_timeZone();
	void set_timeZone(string data);
	void set_language(string data);
	void xuatThongTinRieng();	//Xuat thong tin cua lop General
	string* layThongTinRieng(string* array); //Lay thong tin rieng cua lop con ke thua
private:
	string timeZone;
	string language;
};

#endif // GENERAL_H_