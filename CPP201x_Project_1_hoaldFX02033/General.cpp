#include "General.h"


// Constructor
General::General(string language, string timeZone)
{
	set_timeZone(timeZone);
	set_language(language);
}

// Constructor
General::General(string personalKey, string timeZone, string language)
{
	personal_key = personalKey;
	set_timeZone(timeZone);
	set_language(language);
}

// Constructor with parameter
General::General(string carName, string personalKey, string e_mail, int myodo, int remind, string timezone, string language) {
	this->car_name = carName;
	this->personal_key = personalKey;
	this->email = e_mail;
	this->odo = myodo;
	this->service_remind = remind;
	this->timeZone = timezone;
	this->language = language;
}

General::General()
{
	timeZone = "GMT+07:00";
	language = " Vietnamese";
	setPersonalKey(arr_settings[settingCnt].getPersonalKey());
}

General::~General() {}

//nhap thong tin cho General
General General::nhapThongTin(Setting setting, string timeZone, string language) {

	return General(setting.getCarName(), setting.getPersonalKey(), setting.getEmail(), setting.getODO(),
		setting.getServiceRemind(), timeZone, language);
}

//xuat thong tin cho General
void General::xuatThongTin(Setting arr_settings[], General arr_generals[], int settingCnt) {
	cout << setw(30) << left << "Owner name"
		<< setw(35) << left << "Email"
		<< setw(15) << left << "Key number"
		<< setw(15) << left << "ODO number"
		<< setw(25) << left << "Remind Service (km)"
		<< setw(20) << left << "TimeZone"
		<< setw(50) << left << "Language" << endl;

	//in ra tung thong tin cua General trog arr
	for (int i = 0; i < settingCnt; i++) {

		cout << setw(30) << left << arr_settings[i].getCarName()
			<< setw(35) << left << arr_settings[i].getEmail()
			<< setw(15) << left << arr_settings[i].getPersonalKey()
			<< setw(15) << left << arr_settings[i].getODO()
			<< setw(25) << left << arr_settings[i].getServiceRemind()
			<< setw(20) << left << arr_generals[i].get_timeZone()
			<< setw(50) << left << arr_generals[i].get_language() << endl;
	}
}


string General::get_language() {
	return this->language;
}

string General::get_timeZone() {
	return this->timeZone;
}

void General::set_timeZone(string data) {
	this->timeZone = data;
}

void General::set_language(string data) {
	this->language = data;
}
