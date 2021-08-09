#include "Sound.h"

int checkLevel(const char* ch);

Sound::Sound()
{
	media_level = 0;
	call_level = 0;
	navi_level = 0;
	notification_level = 0;
}

Sound::Sound(const Sound& u)
{
	media_level = u.media_level;
	call_level = u.call_level;
	navi_level = u.navi_level;
	notification_level = u.notification_level;
}

Sound::~Sound(){}

void Sound::nhapThongTin(){
	set_media_level(checkLevel("MEDIA LEVEL: "));
	set_call_level(checkLevel("CALL LEVEL: "));
	set_navi_level(checkLevel("NAVIGATION LEVEL: "));
	set_notification_level(checkLevel("NOTIFICATION LEVEL: "));
}

void Sound::xuatThongTin(){
	cout << setw(10) << get_media_level() << setw(10) << get_call_level() << setw(10) << get_navi_level() << setw(10) << get_notification_level() << endl;
}

int Sound::get_media_level(){
	return media_level;
}

int Sound::get_call_level(){
	return call_level;
}

int Sound::get_navi_level(){
	return navi_level;
}

int Sound::get_notification_level(){
	return notification_level;
}

void Sound::set_media_level(int data){
	media_level = data;
}

void Sound::set_call_level(int data){
	call_level = data;
}

void Sound::set_navi_level(int data){
	navi_level = data;
}

void Sound::set_notification_level(int data){
	notification_level = data;
}

void Sound::xuatThongTinRieng()
{
	cout << setiosflags(ios::left) << setw(23) << "MEDIA LEVEL" << setw(2) << ":" << get_media_level() << resetiosflags(ios::left) << endl;
	cout << setiosflags(ios::left) << setw(23) << "CALL LEVEL" << setw(2) << ":" << get_call_level() << resetiosflags(ios::left) << endl;
	cout << setiosflags(ios::left) << setw(23) << "NAVIGATION LEVEL" << setw(2) << ":" << get_navi_level() << resetiosflags(ios::left) << endl;
	cout << setiosflags(ios::left) << setw(23) << "NOTIFICATION LEVEL" << setw(2) << ":" << get_notification_level() << resetiosflags(ios::left) << endl;
}

string* Sound::layThongTinRieng(string* array)
{
	array = new string[4];
	array[0] = to_string(get_media_level());
	array[1] = to_string(get_call_level());
	array[2] = to_string(get_navi_level());
	array[3] = to_string(get_notification_level());
	return array;
}
