#include "Display.h"

Display::Display() : Setting()
{
	light_level = 0;
	screen_light_level = 0;
	taplo_light_level = 0;
}

Display::Display(const Display &u) : Setting(u)
{
	light_level = u.light_level;
	screen_light_level = u.screen_light_level;
	taplo_light_level = u.taplo_light_level;
}

Display::~Display() {}

int Display::get_light_level()
{
	return light_level;
}

int Display::get_screen_light_level()
{
	return screen_light_level;
}

int Display::get_taplo_light_level()
{
	return taplo_light_level;
}

void Display::set_light_level(int data)
{
	light_level = data;
}

void Display::set_screen_light_level(int data)
{
	screen_light_level = data;
}

void Display::set_taplo_light_level(int data)
{
	taplo_light_level = data;
}

string Display::layMaSoCaNhan()
{
	return getPersonalKey();
}

string Display::layTenChuXe()
{
	return getCarName();
}

string Display::layEmail()
{
	return getEmail();
}

int Display::layOdo()
{
	return getODO();
}

int Display::layServiceRemind()
{
	return getServiceRemind();
}

void Display::xuatThongTinRieng()
{
	cout << setiosflags(ios::left) << setw(23) << "LIGHT LEVEL" << setw(2) << ":" << get_light_level() << resetiosflags(ios::left) << endl;
	cout << setiosflags(ios::left) << setw(23) << "SCREEN LIGHT LEVEL" << setw(2) << ":" << get_screen_light_level() << resetiosflags(ios::left) << endl;
	cout << setiosflags(ios::left) << setw(23) << "TAPLO LIGHT LEVEL" << setw(2) << ":" << get_taplo_light_level() << resetiosflags(ios::left) << endl;
}

void Display::set_car_name(string data)
{
	setCarName(data);
}

void Display::set_personal_key(string data)
{
	setPersonalKey(data);
}

void Display::set_email(string data)
{
	setEmail(data);
}

void Display::set_odo(int data)
{
	setOdo(data);
}

void Display::set_service_remind(int data)
{
	setServiceRemind(data);
}

string *Display::layThongTinRieng(string *array)
{
	array = new string[3];
	array[0] = to_string(get_light_level());
	array[1] = to_string(get_screen_light_level());
	array[2] = to_string(get_taplo_light_level());
	return array;
}

void Display::thayDoiThongTinRieng(int number)
{
	set_light_level(number);
	set_screen_light_level(number);
	set_taplo_light_level(number);
}

void Display::nhapThongTin()
{
	Setting::nhapThongTin();
	set_light_level(checkLevel("LIGHT LEVEL: "));
	set_screen_light_level(checkLevel("SCREEN LIGHT LEVEL: "));
	set_taplo_light_level(checkLevel("TAPLO LIGHT LEVEL: "));
}

void Display::xuatThongTin()
{
	Setting::xuatThongTin();
	// set space when out put
	cout << setw(10) << get_light_level() << setw(10) << get_screen_light_level() << setw(10) << get_taplo_light_level() << endl;
}
