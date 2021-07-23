#ifndef SOUND_H_
#define SOUND_H_

#include "Setting.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Sound : public Setting {
public:
	Sound();
	Sound(const Sound& u);
	~Sound();
	void nhapThongTin();
	void xuatThongTin();
	int get_media_level();
	int get_call_level();
	int get_navi_level();
	int get_notification_level();
	void set_media_level(int data);
	void set_call_level(int data);
	void set_navi_level(int data);
	void set_notification_level(int data);
	string layMaSoCaNhan();
	string layTenChuXe();
	string layEmail();
	int layOdo();
	int layServiceRemind();
	void xuatThongTinRieng();	//Xuat thong tin cua lop Sound
	void set_car_name(string data);
	void set_personal_key(string data);
	void set_email(string data);
	void set_odo(int data);
	void set_service_remind(int data);
	string* layThongTinRieng(string* array); //Lay thong tin rieng cua lop con ke thua
	void thayDoiThongTinRieng(int number);	//Thay doi thong tin rieng cua lop
private:
	int media_level;
	int call_level;
	int navi_level;
	int notification_level;
};

#endif // SOUND_H_