#include "General.h"
#include "CommonInfo.h"

General::General():Setting()
{
	timeZone = "";
	language = "";
}

General::General(const General& u):Setting(u)
{
	timeZone = u.timeZone;
	language = u.language;
}

General::~General(){}

void General::nhapThongTin(){
	Setting::nhapThongTin();
}

void General::xuatThongTin(){
	Setting::xuatThongTin();
	cout << setw(15) << get_timeZone() << setw(15) << get_language() << endl;
}

string General::get_language(){
	return language;
}

string General::get_timeZone(){
	return timeZone;
}

void General::set_timeZone(string data){
	timeZone = data;
}

void General::set_language(string data){
	language = data;
}

string General::layMaSoCaNhan()
{
	return getPersonalKey();
}

string General::layTenChuXe()
{
	return getCarName();
}

string General::layEmail()
{
	return getEmail();
}

int General::layOdo()
{
	return getODO();
}

int General::layServiceRemind()
{
	return getServiceRemind();
}

void General::xuatThongTinRieng()
{
	cout << setiosflags(ios::left) << setw(23) << "TIME ZONE" << setw(2) << ":" << get_timeZone() << resetiosflags(ios::left) << endl;
	cout << setiosflags(ios::left) << setw(23) << "LANGUAGE" << setw(2) << ":" << get_language() << resetiosflags(ios::left) << endl;
}

void General::set_car_name(string data)
{
	setCarName(data);
}

void General::set_personal_key(string data)
{
	setPersonalKey(data);
}

void General::set_email(string data)
{
	setEmail(data);
}

void General::set_odo(int data)
{
	setOdo(data);
}

void General::set_service_remind(int data)
{
	setServiceRemind(data);
}

string* General::layThongTinRieng(string* array)
{
	array = new string[2];
	array[0] = get_timeZone();
	array[1] = get_language();
	return array;
}

void General::thayDoiThongTinRieng(int number)
{
	set_timeZone(to_string(number));
	set_language(to_string(number));
}
