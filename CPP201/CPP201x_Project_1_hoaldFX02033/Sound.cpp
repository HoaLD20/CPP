#include "Sound.h"
#include "CheckValid.h"

//contructor
Sound::Sound() : Setting() {
	media_level = 0;
	call_level = 0;
	navi_level = 0;
	notification_level = 0;
	setPersonalKey(arr_settings[settingCnt].getPersonalKey());
}

//contructor co tham so
Sound::Sound(int media_lv, int call_lv, int navi_lv, int notification_lv, string carName, string personalKey,
	string email_, int odo_, int serviceRemind) : Setting() {

	this->car_name = carName;
	this->personal_key = personalKey;
	this->email = email_;
	this->odo = odo_;
	this->service_remind = serviceRemind;
	this->media_level = media_lv;
	this->call_level = call_lv;
	this->navi_level = navi_lv;
	this->notification_level = notification_lv;
}

//ham huy
Sound::~Sound() {}

//nhap thong tin cho Sound
Sound Sound::nhapThongTin(Setting setting) {
	cout << "Media volume level: ";
	this->media_level = validInput("Media volume level");
	cout << "Call volume level: ";
	this->call_level = validInput("Call volume level");
	cout << "Navigation volume level: ";
	this->navi_level = validInput("Navigation volume level");
	cout << "Notification volume level: ";
	this->notification_level = validInput("Notification volume level");
	return Sound(this->media_level, this->call_level, this->navi_level, this->notification_level,
		setting.getCarName(), setting.getPersonalKey(), setting.getEmail(), setting.getODO(), setting.getServiceRemind());
}

//xuat thong tin Sound
void Sound::xuatThongTin(Setting arr_settings[], Sound arr_sounds[], int settingCnt) {
	cout << setw(30) << left << "Owner name"
		<< setw(35) << left << "Email"
		<< setw(15) << left << "Key number"
		<< setw(15) << left << "ODO number"
		<< setw(25) << left << "Remind Service (km)"
		<< setw(10) << left << "Media"
		<< setw(10) << left << "Call"
		<< setw(10) << left << "Navi"
		<< setw(10) << left << "Notify" << endl;

	//in ra tung thong tin cua Soundtrog arr
	for (int i = 0; i < settingCnt; i++) {
		cout << setw(30) << left << arr_settings[i].getCarName()
			<< setw(35) << left << arr_settings[i].getEmail()
			<< setw(15) << left << arr_settings[i].getPersonalKey()
			<< setw(15) << left << arr_settings[i].getODO()
			<< setw(25) << left << arr_settings[i].getServiceRemind()
			<< setw(10) << left << arr_sounds[i].get_media_level()
			<< setw(10) << left << arr_sounds[i].get_call_level()
			<< setw(10) << left << arr_sounds[i].get_navi_level()
			<< setw(10) << left << arr_sounds[i].get_notification_level()
			<< endl;
	}
}

int Sound::get_media_level() {
	return this->media_level;
}

int Sound::get_call_level() {
	return this->call_level;
}

int Sound::get_navi_level() {
	return this->navi_level;
}

int Sound::get_notification_level() {
	return this->notification_level;
}

void Sound::set_media_level(int data) {
	this->media_level = data;
}

void Sound::set_call_level(int data) {
	this->call_level = data;
}

void Sound::set_navi_level(int data) {
	this->navi_level = data;
}

void Sound::set_notification_level(int data) {
	this->notification_level = data;
}

