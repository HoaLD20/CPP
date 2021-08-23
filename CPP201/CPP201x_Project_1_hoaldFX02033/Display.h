#ifndef DISPLAY_H_
#define DISPLAY_H_

#include "Setting.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

extern Setting arr_settings[100];//tao mang setting su dung cho toan bai
extern int settingCnt;//tao index cua mang setting su dung cho toan bai

class Display : public Setting {

public:
	
	Display();
	Display(int, int, int, string, string, string, int, int);
	~Display();
	Display nhapThongTin(Setting);	
	int get_light_level();
	int get_screen_light_level();
	int get_taplo_light_level();
	void set_light_level(int data);
	void set_screen_light_level(int data);
	void set_taplo_light_level(int data);
	void xuatThongTin(Setting arr_settings[], Display dis[], int settingCnt);
protected:
	int light_level;
	int screen_light_level;
	int taplo_light_level;
};

#endif /* DISPLAY_H_ */

