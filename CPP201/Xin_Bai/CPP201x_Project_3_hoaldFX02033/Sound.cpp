#include "Sound.h"
#include "CheckValid.h"

//contructor
Sound::Sound() : Setting() {
	this->media_level = 0;
	this->call_level = 0;
	this->navi_level = 0;
	this->notification_level = 0;
}

// Constructor with parameter
Sound::Sound(Setting setting) : Setting() {

	this->car_name = setting.getCarName();
	this->personal_key = setting.getPersonalKey();
	this->email = setting.getEmail();
	this->odo = setting.getODO();
	this->service_remind = setting.getServiceRemind();
	this->media_level = 0;
	this->call_level = 0;
	this->navi_level = 0;
	this->notification_level = 0;
}

//ham huy
Sound::~Sound() {}

//nhap thong tin cho Sound
void Sound::nhapThongTin(Setting setting) {
	cout << "Media volume level: ";
	this->media_level = validInput("Media volume level");
	cout << "Call volume level: ";
	this->call_level = validInput("Call volume level");
	cout << "Navigation volume level: ";
	this->navi_level = validInput("Navigation volume level");
	cout << "Notification volume level: ";
	this->notification_level = validInput("Notification volume level");

	//update data Setting in Sound
	updateSound(setting);
}

/*
* The function to update full data of Sound
*/
void Sound::updateSound(Setting setting,int media_lv, int call_lv, int navi_lv, int notification_lv) {

	setCarName(setting.getCarName());
	setEmail(setting.getEmail());
	setPersonalKey(setting.getPersonalKey());
	setODO(setting.getODO());
	setServiceRemind(setting.getServiceRemind());
	this->media_level = media_lv;
	this->call_level = call_lv;
	this->navi_level = navi_lv;
	this->notification_level = notification_lv;
}

/*
* The function to update setting data of Sound
*/
void Sound::updateSound(Setting setting) {

	setCarName(setting.getCarName());
	setEmail(setting.getEmail());
	setPersonalKey(setting.getPersonalKey());
	setODO(setting.getODO());
	setServiceRemind(setting.getServiceRemind());
}

/*
* The function to format type of Sound data to write to file
*/
string Sound::formatTypeSound() {
	return to_string(get_media_level()) + "," + to_string(get_call_level()) + "," + to_string(get_navi_level()) + "," + to_string(get_notification_level());
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

