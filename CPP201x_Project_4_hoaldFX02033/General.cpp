#include "General.h"


// Constructor
General::General(string language, string timeZone)
{
	set_timeZone(timeZone);
	set_language(language);
}

// Constructor
General::General(string personalKey, string timeZone, string language)
{
	personal_key = personalKey;
	set_timeZone(timeZone);
	set_language(language);
}

General::General(string carName, string personalKey, string e_mail, int myodo, int remind, string timezone, string language) {
	this->car_name = carName;
	this->personal_key = personalKey;
	this->email = e_mail;
	this->odo = myodo;
	this->service_remind = remind;
	this->timeZone = timezone;
	this->language = language;
}

// Constructor with parameter
General::General(Setting setting)
{
	this->car_name = setting.getCarName();
	this->personal_key = setting.getPersonalKey();
	this->email = setting.getEmail();
	this->odo = setting.getODO();
	this->service_remind = setting.getServiceRemind();
	this->timeZone = "+07:00";	// (GMT+07:00) /  Bangkok, Hanoi, Jakarta
	this->language = " Vietnamese";	// Vietnamese
}

General::General()
{
	this->timeZone = "+07:00";	// (GMT+07:00) /  Bangkok, Hanoi, Jakarta 23 15
	this->language = " Vietnamese";	// Vietnamese
}

General::~General() {}

//nhap thong tin cho General
void General::nhapThongTin(Setting setting, string timeZone, string language) {

	//update data Setting in General
	updateGeneral(setting, timeZone, language);
}

void General::xuatThongTin() {	
	cout << setw(30) << left << getCarName()
		<< setw(35) << left << getEmail()
		<< setw(15) << left << getPersonalKey()
		<< setw(15) << left << getODO()
		<< setw(25) << left << getServiceRemind()
		<< setw(20) << left << "GMT" + this->timeZone
		<< setw(50) << left << this->language << endl;
}



/*
* The function to update full data of General
*/
void General::updateGeneral(Setting setting, string timeZone, string language) {

	setCarName(setting.getCarName());
	setEmail(setting.getEmail());
	setPersonalKey(setting.getPersonalKey());
	setODO(setting.getODO());
	setServiceRemind(setting.getServiceRemind());
	this->timeZone = timeZone;
	this->language = language;
}

/*
* The function to update setting data of General
*/
void General::updateGeneral(Setting setting) {

	setCarName(setting.getCarName());
	setEmail(setting.getEmail());
	setPersonalKey(setting.getPersonalKey());
	setODO(setting.getODO());
	setServiceRemind(setting.getServiceRemind());
}

/*
* The function to format type of General data to write to file
*/
string General::formatTypeGeneral() {
	return  get_timeZone() + "," + get_language();
}


string General::get_language() {
	return this->language;
}

string General::get_timeZone() {
	return this->timeZone;
}

void General::set_timeZone(string data) {
	this->timeZone = data;
}

void General::set_language(string data) {
	this->language = data;
}
