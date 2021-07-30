#include "Setting.h"
#include "CheckValid.h"
#include <sstream>

//contructor
Setting::Setting(string carName, string personalKey, string email, int odo, int remind)
{
	setCarName(carName);
	setPersonalKey(personalKey);
	setEmail(email);
	setODO(odo);
	setServiceRemind(remind);
}

//contructor khong co tham so
Setting::Setting()
{
}

//destructor
Setting::~Setting() {}

string Setting::getCarName() {
	string name = car_name;
	return name;
}

void Setting::setCarName(string name) {
	this->car_name = name;
}
string Setting::getPersonalKey() {
	string key = personal_key;
	return key;
}
void Setting::setPersonalKey(string key) {
	this->personal_key = key;
}

string Setting::getEmail()
{
	return email;
}

// Set email function
void Setting::setEmail(string email) {
	this->email = email;
}

int Setting::getODO() {
	return odo;
}
void Setting::setODO(int ODO) {
	this->odo = ODO;
}
int Setting::getServiceRemind() {
	return service_remind;
}
void Setting::setServiceRemind(int serviceRemind) {
	this->service_remind = serviceRemind;
}

//nhap thong tin chung cho xe
Setting Setting::nhapThongTin() { //bool keyExist truyen vo de biet MSCN nay co trung khong
	cout << "Owner name: ";
	this->car_name = validCarName(); //nhap car name
	cout << "Email: ";
	this->email = validEmail();//nhap email
	cout << "Key number: "; //hien personal key cho xe
	this->personal_key = validKey();
	cout << "ODO number: ";
	this->odo = validInput("ODO number"); //nhap odd
	cout << "Remind service (km): ";
	this->service_remind = validInput("Remind service");//nhap service remind

	return Setting(car_name, personal_key, email, odo, service_remind);
}


