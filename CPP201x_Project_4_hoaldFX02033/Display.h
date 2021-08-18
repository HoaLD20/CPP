#ifndef DISPLAY_H_
#define DISPLAY_H_

#include "Setting.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Display : public Setting {

public:
	
	Display();
	Display(Setting);
	~Display();
	void nhapThongTin(Setting);
	void xuatThongTin();
	void updateDisplay(Setting,int, int, int);
	void updateDisplay(Setting);
	string formatTypeDisplay();
	int get_light_level();
	int get_screen_light_level();
	int get_taplo_light_level();
	void set_light_level(int data);
	void set_screen_light_level(int data);
	void set_taplo_light_level(int data);
protected:
	int light_level;
	int screen_light_level;
	int taplo_light_level;
};

#endif /* DISPLAY_H_ */

