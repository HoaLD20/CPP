#ifndef SOUND_H_
#define SOUND_H_

#include "Setting.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Sound : public Setting {
public:
	Sound();
	Sound(Setting);
	~Sound();
	void nhapThongTin(Setting);
	void updateSound(Setting, int, int, int, int);
	void updateSound(Setting);
	string formatTypeSound();

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

