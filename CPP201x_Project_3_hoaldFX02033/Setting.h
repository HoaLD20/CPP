#ifndef SETTING_H_
#define SETTING_H_

#include <iostream>
#include <iomanip>
#include <string>
#include <regex>
#include "Display.h"
#include "General.h"
#include "Sound.h"
using namespace std;

class Setting {
public:
	Setting();
	Setting(const Setting& u);
	~Setting();
	void nhapThongTin();
	void xuatThongTin();
	void xuatThongTinChung();	//Xuat thong tin cua lop Setting - lop co so
	string layMaSoCaNhan();
	string layTenChuXe();
	string layEmail();
	int layOdo();
	int layServiceRemind();
	void thayDoiThongTinChung(Setting* u);	//Thay doi thong tin cua lop Setting thong qua doi tuong u
	void nhapThongTinChung(string carName, string personalKey, string email, int odo, int serviceRemind);//Nhap thong tin chung
	
	void nhapThongTinSound();	//Nhap thong tin cho chuc nang Sound
	void nhapThongTinDisplay();	//Nhap thong tin cho chuc nang Display
	void nhapThongTinGeneral(string timezone, string language); //Nhap thong tin cho chuc nang General
	void thayDoiThongTinSound(Setting* p);//Thay doi thong tin cho chuc nang Sound
	void thayDoiThongTinDisplay(Setting* p);	//Thay doi thong tin cho chuc nang Display
	void thayDoiThongTinGeneral(Setting* p);	//Thay doi thong tin cho chuc nang General
	void xuatThongTinRieng();	//Xuat thong tin rieng
	void xuatThongTinGeneral();	//Xuat thong tin General
	void xuatThongTinSound();	//Xuat thong tin Sound
	void xuatThongTinDisplay();	//Xuat thong tin Display
	void nhapThongTinSound(int mediaLevel, int callLevel, int naviLevel, int notiLevel);//Nhap thong tin cho chuc nang Sound
	void nhapThongTinDisplay(int lightLevel, int screenLightLevel, int taploLightLevel);//Nhap thong tin cho chuc nang Display

	string getTimezone();
	string getLanguage();
	int getMediaLevel();
	int getCallLevel();
	int getNaviLevel();
	int getNotiLevel();
	int getLightLevel();
	int getScreenLightLevel();
	int getTaploLightLevel();

protected:	
	string getCarName();
	string getPersonalKey();
	string getEmail();
	int getODO ();
	int getServiceRemind();

	void setCarName(string data);
	void setPersonalKey(string data);
	void setEmail(string data);
	void setOdo(int data);
	void setServiceRemind(int data);

	General* getGeneral();
	Sound* getSound();
	Display* getDisplay();
private:
	string car_name;
	string personal_key; 	// Chuoi 8 ky tu so
	string email;			// email format abc@xyz.com
	int odo;
	int service_remind;

	General* general;
	Sound* sound;
	Display* disp;
};

string emailInput();					//Validate email
string personalKeyInput();				//Validate ma so ca nhan
int ODOInput();							//Kiem tra odo nhap vao
int serviceRemindInput(const int& odo);	//Kiem tra km bao hanh


#endif /* SETTING_H_ */


