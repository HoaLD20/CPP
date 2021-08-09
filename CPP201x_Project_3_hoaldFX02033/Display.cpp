#include "Display.h"
#include <string.h>
#include <stdio.h>
int checkLevel(const char *ch)
{
	char c[21];
	int ret;

	do
	{
		try
		{
			cout << ch;
			cin.getline(c, 20);
			if (strlen(c) == 0 || strlen(c) > 1)
			{
				throw "\t(!) Nhap so nguyen tu 1 den 5\n";
			}
			else
			{
				if (c[0] >= 49 && c[0] <= 53)
				{
					ret = stoi(c);
					break;
				}
				else
					throw "\t(!) Nhap so nguyen tu 1 den 5\n";
			}
		}
		catch (const char *errorName)
		{
			cout << errorName;
		}
	} while (true);
	return ret;
}

Display::Display()
{
	light_level = 0;
	screen_light_level = 0;
	taplo_light_level = 0;
}

Display::Display(const Display &u)
{
	light_level = u.light_level;
	screen_light_level = u.screen_light_level;
	taplo_light_level = u.taplo_light_level;
}

Display::~Display() {}

void Display::nhapThongTin()
{
	set_light_level(checkLevel("LIGHT LEVEL: "));
	set_screen_light_level(checkLevel("SCREEN LIGHT LEVEL: "));
	set_taplo_light_level(checkLevel("TAPLO LIGHT LEVEL: "));
}

void Display::xuatThongTin()
{
	cout << setw(10) << get_light_level() << setw(10) << get_screen_light_level() << setw(10) << get_taplo_light_level() << endl;
}

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

void Display::xuatThongTinRieng()
{
	cout << setiosflags(ios::left) << setw(23) << "LIGHT LEVEL" << setw(2) << ":" << get_light_level() << resetiosflags(ios::left) << endl;
	cout << setiosflags(ios::left) << setw(23) << "SCREEN LIGHT LEVEL" << setw(2) << ":" << get_screen_light_level() << resetiosflags(ios::left) << endl;
	cout << setiosflags(ios::left) << setw(23) << "TAPLO LIGHT LEVEL" << setw(2) << ":" << get_taplo_light_level() << resetiosflags(ios::left) << endl;
}

string *Display::layThongTinRieng(string *array)
{
	array = new string[3];
	array[0] = to_string(get_light_level());
	array[1] = to_string(get_screen_light_level());
	array[2] = to_string(get_taplo_light_level());
	return array;
}