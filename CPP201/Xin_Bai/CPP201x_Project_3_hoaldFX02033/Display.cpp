#include "Display.h"
#include "CheckValid.h"

//contructor khong co tham so
Display::Display()
{	
	this->light_level = 0;
	this->screen_light_level = 0;
	this->taplo_light_level = 0;
}

// Constructor with parameter
Display::Display(Setting setting) {
	this->car_name = setting.getCarName();
	this->personal_key = setting.getPersonalKey();
	this->email = setting.getEmail();
	this->odo = setting.getODO();
	this->service_remind = setting.getServiceRemind();
	this->light_level = 0;
	this->screen_light_level = 0;
	this->taplo_light_level = 0;
}

//ham huy
Display::~Display() {}

int Display::get_light_level() {
	return this->light_level;
}

int Display::get_screen_light_level() {
	return this->screen_light_level;
}

int Display::get_taplo_light_level() {
	return this->taplo_light_level;
}

void Display::set_light_level(int data) {
	this->light_level = data;
}

void Display::set_screen_light_level(int data) {
	this->screen_light_level = data;
}

void Display::set_taplo_light_level(int data) {
	this->taplo_light_level = data;
}


/// nhap thong tin cho Display, va tra ve cac gia tri cua light, screen light, taplo da nhan la lay
///  tu lop ke thua Setting qua nhung property cua lop cha
void Display::nhapThongTin(Setting setting) {

	cout << "Light level: ";
	this->light_level = validInput("Light level");
	cout << "Screen light level: ";
	this->screen_light_level = validInput("Screen light level");
	cout << "Taplo light level: ";
	this->taplo_light_level = validInput("Taplo light level");

	//update data Setting in Display
	updateDisplay(setting);
}

/*
* The function to update full data of Display
*/
void Display::updateDisplay(Setting setting, int light_lv, int screen_light_lv, int taplo_light_lv) {

	setCarName(setting.getCarName());
	setEmail(setting.getEmail());
	setPersonalKey(setting.getPersonalKey());
	setODO(setting.getODO());
	setServiceRemind(setting.getServiceRemind());
	this->light_level = light_lv;
	this->screen_light_level = screen_light_lv;
	this->taplo_light_level = taplo_light_lv;
}

/*
* The function to update setting data of Display
*/
void Display::updateDisplay(Setting setting) {

	setCarName(setting.getCarName());
	setEmail(setting.getEmail());
	setPersonalKey(setting.getPersonalKey());
	setODO(setting.getODO());
	setServiceRemind(setting.getServiceRemind());
}


/*
* Format display de ghi vao file setting
*/
string Display::formatTypeDisplay() {
	return to_string(get_light_level()) + "," + to_string(get_screen_light_level()) + "," + to_string(get_taplo_light_level());
}
