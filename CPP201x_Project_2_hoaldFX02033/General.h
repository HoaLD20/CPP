#ifndef GENERAL_H_
#define GENERAL_H_

#include "Setting.h"
#include <vector>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class General : public Setting {
public:
	General();
	General(const General& u);
	~General();
	void nhapThongTin();
	void xuatThongTin();
	string get_language();
	string get_timeZone();
	void set_timeZone(string data);
	void set_language(string data);
	string layMaSoCaNhan();
	string layTenChuXe();
	string layEmail();
	int layOdo();
	int layServiceRemind();
	void xuatThongTinRieng();	//Xuat thong tin cua lop General
	void set_car_name(string data);
	void set_personal_key(string data);
	void set_email(string data);
	void set_odo(int data);
	void set_service_remind(int data);
	string* layThongTinRieng(string* array); //Lay thong tin rieng cua lop con ke thua
	void thayDoiThongTinRieng(int number);	//Thay doi thong tin rieng cua lop
private:
	string timeZone;
	string language;
};

#endif // GENERAL_H_