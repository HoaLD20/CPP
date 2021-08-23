#ifndef SETTING_H_
#define SETTING_H_

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Setting {
public:
	Setting();
	Setting(string, string, string, int, int);
	virtual ~Setting();
	Setting nhapThongTin();
	string getCarName();
	void setCarName(string);
	string getPersonalKey();
	void setPersonalKey(string);
	string getEmail();
	void setEmail(string);
	int getODO();
	void setODO(int);
	int getServiceRemind();
	void setServiceRemind(int);
protected:
	string car_name;
	string personal_key; 	// Chuoi 8 ky tu so
	string email;			// email format abc@xyz.com
	int odo;
	int service_remind;
};
#endif /* SETTING_H_ */

