#ifndef GENERAL_H_
#define GENERAL_H_
#include "Setting.h"
#include <vector>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class General : public Setting {
public:
	General(string language, string timeZone);
	General(Setting);
	General(string personalKey, string timeZone, string language);
	General(string carName, string personalKey, string email, int odo, int remind, string language, string timeZone);
	General();
	~General();
	void nhapThongTin(Setting, string, string);
	void updateGeneral(Setting, string timeZone, string language);
	void updateGeneral(Setting);
	string formatTypeGeneral();
	string get_language();
	string get_timeZone();
	void set_timeZone(string data);
	void set_language(string data);

protected:
	string timeZone;
	string language;
};

#endif // GENERAL_H_