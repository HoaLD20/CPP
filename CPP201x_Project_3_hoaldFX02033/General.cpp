#include "General.h"
#include "CommonInfo.h"

General::General()
{
	timeZone = "";
	language = "";
}

General::General(const General& u)
{
	timeZone = u.timeZone;
	language = u.language;
}

General::~General(){}

void General::xuatThongTin(){
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

void General::xuatThongTinRieng()
{
	cout << setiosflags(ios::left) << setw(23) << "TIME ZONE" << setw(2) << ":" << get_timeZone() << resetiosflags(ios::left) << endl;
	cout << setiosflags(ios::left) << setw(23) << "LANGUAGE" << setw(2) << ":" << get_language() << resetiosflags(ios::left) << endl;
}

string* General::layThongTinRieng(string* array)
{
	array = new string[2];
	array[0] = get_timeZone();
	array[1] = get_language();
	return array;
}
