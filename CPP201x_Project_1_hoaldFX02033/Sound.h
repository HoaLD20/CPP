#ifndef SOUND_H_
#define SOUND_H_

#include "Setting.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

extern Setting arr_settings[100];//tao mang setting su dung cho toan bai
extern int settingCnt;//tao index cua mang setting su dung cho toan bai

class Sound : public Setting {
public:
	Sound();
	Sound(int, int, int, int, string, string, string, int, int);
	~Sound();
	Sound nhapThongTin(Setting);
	void xuatThongTin(Setting arr_settings[], Sound arr_sounds[], int settingCnt);
	int get_media_level();
	int get_call_level();
	int get_navi_level();
	int get_notification_level();
	void set_media_level(int data);
	void set_call_level(int data);
	void set_navi_level(int data);
	void set_notification_level(int data);
protected:
	int media_level;
	int call_level;
	int navi_level;
	int notification_level;
};
#endif // SOUND_H_

