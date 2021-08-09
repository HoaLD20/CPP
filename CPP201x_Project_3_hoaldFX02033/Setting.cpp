#include "Setting.h"

Setting::Setting()
{
	car_name = "";
	personal_key = "";
	email = "";
	odo = 0;
	service_remind = 0;
	general = new General;
	sound = new Sound;
	disp = new Display;
	general->set_language("1");	//Khoi tao gia tri mac dinh
	general->set_timeZone("1");
	sound->set_call_level(1);
	sound->set_media_level(1);
	sound->set_navi_level(1);
	sound->set_notification_level(1);
	disp->set_light_level(1);
	disp->set_screen_light_level(1);
	disp->set_taplo_light_level(1);
}

Setting::Setting(const Setting& u)
{
	car_name = u.car_name;
	personal_key = u.personal_key;
	email = u.email;
	odo = u.odo;
	service_remind = u.service_remind;
}

Setting::~Setting(){}

string Setting::getCarName(){
	return car_name;
}

string Setting::getPersonalKey(){
	return personal_key;
}

string Setting::getEmail()
{
	return email;
}

int Setting::getODO (){
	return odo;
}

int Setting::getServiceRemind(){
	return service_remind;
}

void Setting::setCarName(string data)
{
	car_name = data;
}

void Setting::setPersonalKey(string data)
{
	personal_key = data;
}

void Setting::setEmail(string data)
{
	email = data;
}

void Setting::setOdo(int data)
{
	odo = data;
}

void Setting::setServiceRemind(int data)
{
	service_remind = data;
}

General* Setting::getGeneral()
{
	return general;
}

Sound* Setting::getSound()
{
	return sound;
}

Display* Setting::getDisplay()
{
	return disp;
}

void Setting::nhapThongTin(){
	string name;

	cout << "TEN CHU XE: ";
	cin.ignore();
	getline(cin, name);
	setCarName(name);
	setEmail(emailInput());
	setPersonalKey(personalKeyInput());
	setOdo(ODOInput());
	setServiceRemind(serviceRemindInput(getODO()));
}

void Setting::xuatThongTin(){
	cout << setw(20) << getCarName() << setw(25) << getEmail() << setw(10) << getPersonalKey()
		<< setw(10) << getODO() << setw(10) << getServiceRemind();
}

void Setting::xuatThongTinChung()
{
	cout << setiosflags(ios::left) << setw(23) << "TEN CHU XE" << setw(2) << ":" << getCarName() << resetiosflags(ios::left) << endl;
	cout << setiosflags(ios::left) << setw(23) << "MA SO CA NHAN" << setw(2) << ":" << getPersonalKey() << resetiosflags(ios::left) << endl;
	cout << setiosflags(ios::left) << setw(23) << "EMAIL" << setw(2) << ":" << getEmail() << resetiosflags(ios::left) << endl;
	cout << setiosflags(ios::left) << setw(23) << "THONG TIN ODO" << setw(2) << ":" << getODO() << resetiosflags(ios::left) << endl;
	cout << setiosflags(ios::left) << setw(23) << "KM BAO HANH" << setw(2) << ":" << getServiceRemind() << resetiosflags(ios::left) << endl;
}

string Setting::layMaSoCaNhan()
{
	return getPersonalKey();
}

string Setting::layTenChuXe()
{
	return getCarName();
}

string Setting::layEmail()
{
	return getEmail();
}

int Setting::layOdo()
{
	return getODO();
}

int Setting::layServiceRemind()
{
	return getServiceRemind();
}

void Setting::thayDoiThongTinChung(Setting* u)
{
	setCarName(u->getCarName());
	setEmail(u->getEmail());
	setOdo(u->getODO());
	setServiceRemind(u->getServiceRemind());
}

void Setting::nhapThongTinChung(string carName, string personalKey, string email, int odo, int serviceRemind)
{
	setCarName(carName);
	setPersonalKey(personalKey);
	setEmail(email);
	setOdo(odo);
	setServiceRemind(serviceRemind);
}

void Setting::nhapThongTinSound()
{
	sound->nhapThongTin();
}

void Setting::nhapThongTinDisplay()
{
	disp->nhapThongTin();
}

void Setting::nhapThongTinGeneral(string timezone, string language)
{
	getGeneral()->set_timeZone(timezone);
	getGeneral()->set_language(language);
}

void Setting::thayDoiThongTinSound(Setting* p)
{
	getSound()->set_call_level(p->getSound()->get_call_level());
	getSound()->set_media_level(p->getSound()->get_media_level());
	getSound()->set_navi_level(p->getSound()->get_navi_level());
	getSound()->set_notification_level(p->getSound()->get_notification_level());
}

void Setting::thayDoiThongTinDisplay(Setting* p)
{
	getDisplay()->set_light_level(p->getDisplay()->get_light_level());
	getDisplay()->set_screen_light_level(p->getDisplay()->get_screen_light_level());
	getDisplay()->set_taplo_light_level(p->getDisplay()->get_taplo_light_level());
}

void Setting::thayDoiThongTinGeneral(Setting* p)
{
	getGeneral()->set_language(p->getGeneral()->get_language());
	getGeneral()->set_timeZone(p->getGeneral()->get_timeZone());
}

void Setting::xuatThongTinRieng()
{
	cout << " --- Thong tin Display ---\n";
	getDisplay()->xuatThongTinRieng();
	cout << " --- Thong tin Sound ---\n";
	getSound()->xuatThongTinRieng();
	cout << " --- Thong tin General ---\n";
	getGeneral()->xuatThongTinRieng();
}

void Setting::xuatThongTinGeneral()
{
	getGeneral()->xuatThongTin();
}

void Setting::xuatThongTinSound()
{
	getSound()->xuatThongTin();
}

void Setting::xuatThongTinDisplay()
{
	getDisplay()->xuatThongTin();
}

void Setting::nhapThongTinSound(int mediaLevel, int callLevel, int naviLevel, int notiLevel)
{
	getSound()->set_media_level(mediaLevel);
	getSound()->set_call_level(callLevel);
	getSound()->set_navi_level(naviLevel);
	getSound()->set_notification_level(notiLevel);
}

void Setting::nhapThongTinDisplay(int lightLevel, int screenLightLevel, int taploLightLevel)
{
	getDisplay()->set_light_level(lightLevel);
	getDisplay()->set_screen_light_level(screenLightLevel);
	getDisplay()->set_taplo_light_level(taploLightLevel);
}

string Setting::getTimezone()
{
	return getGeneral()->get_timeZone();
}

string Setting::getLanguage()
{
	return getGeneral()->get_language();
}

int Setting::getMediaLevel()
{
	return getSound()->get_media_level();
}

int Setting::getCallLevel()
{
	return getSound()->get_call_level();
}

int Setting::getNaviLevel()
{
	return getSound()->get_navi_level();
}

int Setting::getNotiLevel()
{
	return getSound()->get_notification_level();
}

int Setting::getLightLevel()
{
	return getDisplay()->get_light_level();
}

int Setting::getScreenLightLevel()
{
	return getDisplay()->get_screen_light_level();
}

int Setting::getTaploLightLevel()
{
	return getDisplay()->get_taplo_light_level();
}

string emailInput()
{
	string email;
	string local_part;	//Ten hop thu
	string domain;		//Ten mien
	size_t pos;			//Vi tri @ trong email, dung de tach ten hop thu va ten mien

	//Mau de kiem tra email nhap co dung dinh dang
	const regex patternMain
	("^[a-zA-Z0-9][a-zA-Z0-9.]{1,28}[a-zA-Z0-9]@[a-zA-Z0-9][a-zA-Z0-9-]*[a-zA-Z0-9](\\.[a-z0-9]{2,4}){1,2}$");
	//Mau de kiem tra phan ten mien
	const regex patternDomain
	("^[a-zA-Z0-9][a-zA-Z0-9-]*[a-zA-Z0-9](\\.[a-z0-9]{2,4}){1,2}$");
	//Mau de kiem tra nhap dung ky tu o phan ten hop thu
	const regex patternRightCharLocal
	("[^a-zA-Z0-9.]");
	//Mau de kiem tra ten hop thu khong duoc bat dau bang dau '.'
	const regex patternFirstDot
	("^\\.");
	//Mau de kiem tra ten hop thu khong duoc ket thuc bang dau '.'
	const regex patternLastDot
	("\\.$");
	//Mau de kiem tra co ky tu @ trong chuoi email nhap vao khong
	const regex patternA
	("@");

	do
	{
		try
		{
			cout << "EMAIL: ";
			getline(cin, email);

			if (email == "" || !regex_search(email, patternA))
			{
				cout << "\t(!) Nhap email theo dinh dang abc@xyz.def\n";
				continue;
			}

			pos = email.find_last_of('@'); //Tim '@' bat dau tu cuoi chuoi email
			domain = email.substr(pos + 1);	//Phan ten mien cua email
			local_part = email.substr(0, pos);//Phan ten hop thu cua email

			if (regex_match(email, patternMain))
				return email;
			else if (!regex_match(domain, patternDomain))
				throw "\t(!) Ten mien khong hop le\n";
			else if (regex_search(local_part, patternRightCharLocal))
				throw "\t(!) Ten hop thu gom cac ky tu (a-z), so (0-9) va dau '.'\n";
			else if (local_part.length() < 3 || local_part.length() > 30)
				throw "\t(!) Ten hop thu gom 3 den 30 ky tu\n";
			else if (regex_search(local_part, patternFirstDot) || regex_search(local_part, patternLastDot))
				throw "\t(!) Ky tu bat dau va ket thuc ten hop thu phai khac '.'\n";
		}
		catch (const char* errorName)
		{
			cout << errorName;
		}
	} while (true);
}

string personalKeyInput() {
	string id;

	//Mau gom 8 ky tu so (0-9) lien tiep nhau
	const regex patternd("\\d{8}");
	//Mau 1 ky tu khong phai la so (0-9)
	const regex patternD("\\D");

	do
	{
		try
		{
			cout << "MA SO CA NHAN: ";
			getline(cin, id);

			if (regex_match(id, patternd))
			{
				return id;
			}
			else if (regex_search(id, patternD))
			{
				throw "\t(!) Chi nhap so (0-9)\n";
			}
			else
			{
				throw "\t(!) Ma so phai la 8 ky tu so\n";
			}
		}
		catch (const char* errorName)
		{
			cout << errorName;
		}

	} while (true);
}

int ODOInput()
{
	char c[21];
	int odo;
	do
	{
		try
		{
			cout << "THONG TIN ODO: ";
			cin.getline(c, 20);
			if (strlen(c) == 0)
			{
				throw "\t(!) Nhap ky tu so (0-9)\n";

			}
			if (strlen(c) > 7)
			{
				throw "\t(!) Vong doi cua xe di duoc nhieu nhat khoang 5.000.000 (km)\n";
			}
			for (size_t i = 0; i < strlen(c); ++i)
			{
				if (!isdigit(c[i]))
				{
					throw "\t(!) Nhap ky tu so (0-9)\n";
				}
			}

			odo = stoi(c);
			if (odo > 5000000)
			{
				throw "\t(!) Vong doi cua xe di duoc nhieu nhat khoang 5.000.000 (km)\n";
			}
			return odo;
		}
		catch (const char* errorName)
		{
			cout << errorName;
		}
	} while (true);
}

int serviceRemindInput(const int& odo) //Truyen thong tin ODO de so sanh voi km bao hanh
{
	char c[21];
	int km;

	do
	{
		try
		{
			cout << "KM BAO HANH: ";
			cin.getline(c, 20);
			if (strlen(c) == 0)
			{
				throw "\t(!) Vui long nhap ky tu so (0-9)\n";
			}
			for (size_t i = 0; i < strlen(c); ++i)
			{
				if (!isdigit(c[i]))
				{
					throw "\t(!) Vui long nhap ky tu so (0-9)\n";
				}
			}

			km = stoi(c);
			if (km < odo)
			{
				throw "\t(!) KM BAO HANH phai lon hon hoac bang ODO\n";
			}
			else if (km - odo > 5000) //So km den lan bao hanh tiep theo la 5.000 km
			{
				throw "\t(!) KM BAO HANH khong lon hon ODO qua 5.000 (km)\n";
			}
			return km;
		}
		catch (const char* errorName)
		{
			cout << errorName;
		}
	} while (true);
}