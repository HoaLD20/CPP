#ifndef DISPLAY_H_
#define DISPLAY_H_

#include "Setting.h"
#include <iostream>
#include <string>
using namespace std;

class Display : public Setting{

public:
	Display();
	Display(const Display& u);
	~Display();
	void nhapThongTin();
	void xuatThongTin();
	int get_light_level();
	int get_screen_light_level();
	int get_taplo_light_level();
	void set_light_level(int data);
	void set_screen_light_level(int data);
	void set_taplo_light_level(int data);
	string layMaSoCaNhan();
	string layTenChuXe();
	string layEmail();
	int layOdo();
	int layServiceRemind();
	void xuatThongTinRieng();	//Xuat thong tin cua lop Display
	void set_car_name(string data);
	void set_personal_key(string data);
	void set_email(string data);
	void set_odo(int data);
	void set_service_remind(int data);
	string* layThongTinRieng(string* array); //Lay thong tin rieng cua lop con ke thua
	void thayDoiThongTinRieng(int number);	//Thay doi thong tin rieng cua lop
private:
	int light_level;
	int screen_light_level;
	int taplo_light_level;
};

#endif /* DISPLAY_H_ */