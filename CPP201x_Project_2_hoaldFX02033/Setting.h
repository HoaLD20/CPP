#ifndef SETTING_H_
#define SETTING_H_

#include <iostream>
#include <iomanip>
#include <string>
#include <regex>
#include "list.h"
#include "list.cpp"

using namespace std;

class Setting {
public:
	Setting();
	Setting(const Setting& u);
	virtual ~Setting();
	virtual void nhapThongTin();
	virtual void xuatThongTin();
	void xuatThongTinChung();	//Xuat thong tin cua lop Setting - lop co so
	string layMaSoCaNhan();
	string layTenChuXe();
	string layEmail();
	int layOdo();
	int layServiceRemind();
	void thayDoiThongTinChung(Setting& u);	//Thay doi thong tin cua lop Setting thong qua doi tuong u
	virtual void xuatThongTinRieng();	//Su dung tinh chat da hinh cuar OOP, truy cap den phuong thuc lop con
	virtual string* layThongTinRieng(string *array); //Lay thong tin rieng cua lop con ke thua
	virtual void thayDoiThongTinRieng(int number);	//Thay doi thong tin rieng cua lop con (General, Display, Sound)
	
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
private:
	string car_name;
	string personal_key; 	// Chuoi 8 ky tu so
	string email;			// email format abc@xyz.com
	int odo;
	int service_remind;
};

string emailInput();					//Validate email
string personalKeyInput();				//Validate ma so ca nhan
int ODOInput();							//Kiem tra odo nhap vao
int serviceRemindInput(const int& odo);	//Kiem tra km bao hanh
int checkLevel(const char* ch);			//Kiem tra dau vao cho level


#endif /* SETTING_H_ */


