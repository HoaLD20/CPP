#include "Display.h"
#include "CheckValid.h"

//contructor khong co tham so
Display::Display()
{	
	light_level = 0;
	screen_light_level = 0;
	taplo_light_level = 0;
	setPersonalKey(arr_settings[settingCnt].getPersonalKey());
}

//contructor co tham so
Display::Display(int light_lv, int screen_light_lv, int taplo_light_lv, string carName, string personalKey,
	string email_, int odo_, int serviceRemind) {

	this->car_name = carName;
	this->personal_key = personalKey;
	this->email = email_;
	this->odo = odo_;
	this->service_remind = serviceRemind;
	this->light_level = light_lv;
	this->screen_light_level = screen_light_lv;
	this->taplo_light_level = taplo_light_lv;
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
Display Display::nhapThongTin(Setting setting) {

	cout << "Light level: ";
	this->light_level = validInput("Light level");
	cout << "Screen light level: ";
	this->screen_light_level = validInput("Screen light level");
	cout << "Taplo light level: ";
	this->taplo_light_level = validInput("Taplo light level");

	return Display(this->light_level, this->screen_light_level, this->taplo_light_level,
		setting.getCarName(), setting.getPersonalKey(), setting.getEmail(), setting.getODO(), setting.getServiceRemind());
}

//xuat thong tin cau Display
void Display::xuatThongTin(Setting arr_settings[], Display arr_displays[], int settingCnt) {
	cout << setw(30) << left << "Owner name"
		<< setw(35) << left << "Email"
		<< setw(15) << left << "Key number"
		<< setw(15) << left << "ODO number"
		<< setw(25) << left << "Remind Service (km)"
		<< setw(15) << left << "Light level"
		<< setw(20) << left << "Screen light level"
		<< setw(15) << left << "Taplo level" << endl;

	//left: đặt feild điều chỉnh sang trái
	//in ra tung thong tin cua Display trog arr
	for (int i = 0; i < settingCnt; i++) {
		cout << setw(30) << left << arr_settings[i].getCarName()
			<< setw(35) << left << arr_settings[i].getEmail()
			<< setw(15) << left << arr_settings[i].getPersonalKey()
			<< setw(15) << left << arr_settings[i].getODO()
			<< setw(25) << left << arr_settings[i].getServiceRemind()
			<< setw(15) << left << arr_displays[i].get_light_level()
			<< setw(20) << left << arr_displays[i].get_screen_light_level()
			<< setw(15) << left << arr_displays[i].get_taplo_light_level() << endl;
	}
}
