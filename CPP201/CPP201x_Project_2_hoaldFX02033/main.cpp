#include <iostream>
#include "General.h"
#include "Display.h"
#include "Sound.h"
#include "CommonInfo.h"
#include <bits/stdc++.h>
#include <fstream>

// 3 list luu tru du lieu cho Display, Sound, General voi class Template List
List<Setting *> display;
List<Setting *> sound;
List<Setting *> general;

vector<CommonInfo> timezoneList;
vector<CommonInfo> languageList;

void NhapThongTinCaiDat();
void XuatThongTinCaiDat();

void XuatThongTinCaiDat_Sound();
void XuatThongTinCaiDat_General();
void XuatThongTinCaiDat_Display();
void XuatThongTinTatCaCaiDat();

void NhapThongTinCaiDat_Sound();
void NhapThongTinCaiDat_General();
void NhapThongTinCaiDat_Display();

void downloadTimeZone();
void downloadLanguage();

void ReadFromFile(); //Ham doc du lieu tu file
void WriteOnFile();	 //Ham ghi du lieu len file

int menu();

string WhiteSpaceDelete(string &);
string ConvertSelectionToData(vector<CommonInfo> list, int selection);
//Loai bo khoang trang trong chuoi
void CheckDigit(string &);														  //Kiem tra dau vao co phai so nguyen khong
void DuplicationOfInfo(List<Setting *>);										  //Kiem tra trung lap thong tin
int ChonTimeZoneVaLanguage(vector<CommonInfo>);									  //Liet ke ra danh sach TimeZone va Language
int isDigits(int);																  //Kiem tra so nhap vao dung khong, trong phan chon TimeZone va Language
int PositionOfTheSamePersonalKey(List<Setting *>, const string &);				  //Tim kiem vi tri phan tu co cung MSCN
bool KiemTraMSCNHoacTen(List<Setting *>, int size, string, int &, string);		  //Kiem tra MSCN hoac ten
const vector<string> explode(const string &, const char &);						  //Ham dua du lieu tu mot chuoi vao mang vector<>, ky tu c la dau phan cach giua cac phan tu
void GetInfo(List<Setting *>, int &, string &, string &, string &, int &, int &); //Ham lay thong tin chung

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main(int argc, char **argv)
{
	int length_lang;
	int length_time;
	ifstream filestr;

	filestr.open("languages.txt", std::ios::in | std::ios::out | std::ios::app); // open your file
	filestr.seekg(0, ios::end);													 // put the "cursor" at the end of the file
	length_lang = filestr.tellg();												 // find the position of the cursor
	filestr.close();

	filestr.open("timezones.txt", std::ios::in | std::ios::out | std::ios::app); // close your file
	filestr.seekg(0, ios::end);													 // put the "cursor" at the end of the file
	length_time = filestr.tellg();												 // find the position of the cursor
	filestr.close();

	if (length_lang == 0)
	{
		fstream f;
		f.open("languages.txt", std::ios::in | std::ios::out | std::ios::app);

		string data = "1 / Mandarin (entire branch)\n2 / Spanish\n3 / English\n4 / Hindi\n5 / Arabic\n6 / Portuguese\n7 / Bengali\n8 / Russian\n9 / Japanese\n10 / Punjabi\n11 / German\n12 / Javanese\n13 / Wu(inc.Shanghainese)\n14 / Malay(inc.Indonesian and Malaysian)\n15 / Telugu\n16 / Vietnamese\n17 / Korean\n18 / French\n19 / Marathi\n20 / Tamil\n21 / Urdu\n22 / Turkish\n23 / Italian\n24 / Yue(inc.Cantonese)\n25 / Thai\n26 / Gujarati\n27 / Jin\n28 / Southern Min\n29 / Persian\n30 / Polish\n";
		f
			<< data;
		f.close();
	}
	else
	{
	}
	if (length_time == 0)
	{
		fstream f;
		f.open("timezones.txt", std::ios::in | std::ios::out | std::ios::app);

		string data = "(GMT-12:00) /  International Date Line West\n(GMT-11:00) /  Midway Island, Samoa\n(GMT-10:00) /  Hawaii\n(GMT-09:00) /  Alaska\n(GMT-08:00) /  Tijuana, Baja California\n(GMT-07:00) /  Chihuahua, La Paz, Mazatlan - New\n(GMT-06:00) /  Guadalajara, Mexico City, Monterrey - New\n(GMT-05:00) /  Eastern Time (US and Canada)\n(GMT-04:00) /  Atlantic Time (Canada)\n(GMT-03:30) /  Newfoundland\n(GMT-02:00) /  Mid-Atlantic\n(GMT-01:00) /  Azores\n(GMT-00:00) /  Monrovia, Reykjavik\n(GMT+01:00) /  Belgrade, Bratislava, Budapest, Ljubljana, Prague\n(GMT+02:00) /  Minsk\n(GMT+03:00) /  Moscow, St. Petersburg, Volgograd\n(GMT+04:00) /  Abu Dhabi, Muscat\n(GMT+04:30) /  Kabul\n(GMT+05:00) /  Tashkent\n(GMT+05:30) /  Chennai, Kolkata, Mumbai, New Delhi\n(GMT+05:45) /  Kathmandu\n(GMT+06:00) /  Astana, Dhaka\n(GMT+06:30) /  Yangon (Rangoon)\n(GMT+07:00) /  Bangkok, Hanoi, Jakarta\n(GMT+08:00) /  Beijing, Chongqing, Hong Kong, Urumqi\n(GMT+08:00) /  Irkutsk, Ulaanbaatar\n(GMT+09:00) /  Seoul\n(GMT+09:30) /  Adelaide\n(GMT+10:00) /  Canberra, Melbourne, Sydney\n(GMT+11:00) /  Magadan, Solomon Islands, New Caledonia\n(GMT+12:00) /  Fiji, Kamchatka, Marshall Is.\n(GMT+13:00) /  Nuku'alofa\n";
		f << data;
		f.close();
	}
	else
	{
	}
	ReadFromFile(); //Doc du lieu tu file
	downloadLanguage();
	downloadTimeZone();

	int selection = 0;

	do
	{
		selection = menu();

		switch (selection)
		{
		case 1:
			NhapThongTinCaiDat();
			break;
		case 2:
			XuatThongTinCaiDat();
			break;
		case 0:
			printf("\033c");
			WriteOnFile(); //Ghi du lieu len file
			cout << "\n\n\t\t--- CHAO TAM BIET ---\n\n";
			cout << endl
				 << "Press Enter to continue...";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin.get();
			return 0;
		}
	} while (true);

	return 0;
}

int menu()
{
	int selection = 0;
	string str;

	do
	{
		printf("\033c");
		cout << "--- MOI BAN LUA CHON ---\n";
		cout << "1. Nhap thong tin cai dat\n";
		cout << "2. Xuat thong tin cai dat\n";
		cout << "0. Thoat\n";
		cout << "Lua chon cua ban la: ";
		cin >> str;
		if (str.length() == 1 && str[0] >= 48 && str[0] <= 50)
		{
			selection = stoi(str);
			break;
		}
	} while (true);

	return selection;
}

void NhapThongTinCaiDat()
{
	int selection;
	string str;

	do
	{
		printf("\033c");
		cout << "--- MOI BAN LUA CHON ---\n";
		cout << "1-Nhap thong tin Display\n";
		cout << "2-Nhap thong tin Sound\n";
		cout << "3-Nhap thong tin General\n";
		cout << "0-Thoat\n";
		cout << "Lua chon cua ban la: ";
		cin >> str;

		if (str.length() == 1 && str[0] >= 48 && str[0] <= 51)
		{
			selection = stoi(str);
			break;
		}
	} while (true);

	printf("\033c");
	switch (selection)
	{
	case 1:
	{
		cout << " --- Ban nhap thong tin Display --- " << endl;
		NhapThongTinCaiDat_Display();
		break;
	}
	case 2:
	{
		cout << " --- Ban nhap thong tin Sound --- " << endl;
		NhapThongTinCaiDat_Sound();
		break;
	}
	case 3:
	{
		cout << " --- Ban nhap thong tin General --- " << endl;
		NhapThongTinCaiDat_General();
		break;
	}
	case 0:
	{
		return;
	}
	}
}

//Thay doi thong tin chung cua du lieu co cung ma so ca nhan voi du lieu vua nhap
//neu du lieu chua duoc tao thi khoi tao du lieu mac dinh
//u: du lieu vua nhap
//selection: 1. Doi tuong vua nhap thuoc lop Display;  2. Lop Sound;  3. Lop General
void ThayDoiCaiDatChungVaKhoiTaoDuLieu(Setting u, int selection)
{
	Setting *p = NULL;	   //Con tro tro den vung nho cua lop General hoac lop Display hoac lop Sound
	bool found = false;	   //true: Da cai dat du lieu cho chuc nang do;  false: Chua cai dat du lieu cho chuc nang do
	int defaultNumber = 1; //Gia tri khoi tao mac dinh cho thong tin cua cac chuc nang

	if (selection != 1)
	{
		for (int i = 0; i < display.size(); ++i)
		{
			if (display.get(i)->layMaSoCaNhan().compare(u.layMaSoCaNhan()) == 0) //Bang 0 khi 2 MSCN giong nhau va tien hanh thay doi
			{																	 //thong tin chung cua list
				display.get(i)->thayDoiThongTinChung(u);						 //Neu da cai dat du lieu roi thi thay doi thong tin chung cho phu hop
				found = true;
				break;
			}
		}
		if (found == false) //Chua cai dat du lieu thi tien hanh khoi tao du lieu mac dinh
		{
			p = new Display;
			p->thayDoiThongTinChung(u);				//Nhap thong tin chung cho du lieu
			p->thayDoiThongTinRieng(defaultNumber); //Khoi tao du lieu mac dinh
			display.add(p);
		}
	}

	if (selection != 2)
	{
		for (int i = 0; i < sound.size(); ++i)
		{
			if (sound.get(i)->layMaSoCaNhan().compare(u.layMaSoCaNhan()) == 0) //Bang 0 khi 2 MSCN giong nhau va tien hanh thay doi
			{																   //thong tin chung cua list
				sound.get(i)->thayDoiThongTinChung(u);						   //Neu da cai dat du lieu roi thi thay doi thong tin chung cho phu hop
				found = true;
				break;
			}
		}
		if (found == false) //Chua cai dat du lieu thi tien hanh khoi tao du lieu mac dinh
		{
			p = new Sound;
			p->thayDoiThongTinChung(u);				//Nhap thong tin chung cho du lieu
			p->thayDoiThongTinRieng(defaultNumber); //Khoi tao du lieu mac dinh
			sound.add(p);
		}
	}

	if (selection != 3)
	{
		for (int i = 0; i < general.size(); ++i)
		{
			if (general.get(i)->layMaSoCaNhan().compare(u.layMaSoCaNhan()) == 0) //Bang 0 khi 2 MSCN giong nhau va tien hanh thay doi
			{																	 //thong tin chung cua list
				general.get(i)->thayDoiThongTinChung(u);						 //Neu da cai dat du lieu roi thi thay doi thong tin chung cho phu hop
				found = true;
				break;
			}
		}
		if (found == false) //Chua cai dat du lieu thi tien hanh khoi tao du lieu mac dinh
		{
			p = new General;
			p->thayDoiThongTinChung(u);				//Nhap thong tin chung cho du lieu
			p->thayDoiThongTinRieng(defaultNumber); //Khoi tao du lieu mac dinh
			general.add(p);
		}
	}
}

//Kiem tra so nhap vao dung khong, trong phan chon TimeZone va Language
//maxSelection: gia tri nhap lon nhat cua TimeZone hoac Language
int isDigits(int maxSelection)
{
	bool is_digit; //true: la so (0-9),  false: khong la so (0-9)
	string str_selection;
	int selection;

	do
	{
		is_digit = true;
		cout << "MOI BAN CHON: ";
		cin >> str_selection;

		for (auto n : str_selection) //Duyet tren tat ca phan tu cua chuoi "str_selection"
		{
			if (!isdigit(n))
			{
				cout << "\t(!) Nhap so (1-" << to_string(maxSelection + 1) << ")\n"; //Neu chuoi nhap co ky tu thi thong bao va nhap lai
				is_digit = false;
				break;
			}
		}

		if (is_digit == true)
		{
			selection = stoi(str_selection);					 //Chuoi nhap khong co ky tu thi ep kieu sang kieu so nguyen
			if (selection >= 1 && selection <= maxSelection + 1) //Neu lua chon khong nam trong khoang 0-maxSelection thi thong bao va nhap lai
			{
				return selection;
			}
			else
				cout << "\t(!) Nhap so (1-" << to_string(maxSelection + 1) << ")\n";
		}
	} while (true);
}

//Liet ke ra danh sach TimeZone va Language
//Mang list: mang TimeZone hoac Language
int ChonTimeZoneVaLanguage(vector<CommonInfo> list)
{
	for (size_t i = 0; i < list.size(); ++i)
	{
		cout << setw(2) << i + 1 << ":" << setw(16) << list[i].getNumber()
			 << setiosflags(ios::left) << list[i].getName() << resetiosflags(ios::left) << endl; //Dinh dang thong tin xuat
	}

	return isDigits(list.size() - 1); //Chay ham isDigits() de tra ve gia tri selection cua TimeZone hoac Language; tham so la gioi han lon nhat cua lua chon
}

string ConvertSelectionToData(vector<CommonInfo> list, int selection)
{
	string value = "";
	for (size_t i = 0; i < list.size(); ++i)
	{
		if (selection == i + 1)
		{
			value = list[i + 1].getNumber() + " " + list[i + 1].getName();
		}

		// cout << setw(2) << i + 1 << ":" << setw(16) << list[i].getNumber()
		// 	 << setiosflags(ios::left) << list[i].getName() << resetiosflags(ios::left) << endl; //Dinh dang thong tin xuat
	}
	return value;
}

void NhapThongTinCaiDat_Display()
{
	char continues = 'n';
	do
	{
		cout << " NHAP THONG TIN DISPLAY, XE SO " << display.size() + 1 << endl;
		//new sound and gen here for default
		Display disp;		//Bien de luu thong tin doi tuong Display dang nhap
		Setting *p;			//Con tro tro den vung nho co gia tri giong voi bien 'disp'
		bool found = false; //true: tai khoan ton tai,  false: tai khoan khong ton tai

		disp.nhapThongTin();
		/**
		 ** Show notification when personal key found or not found 
		*/
		//Tim MSCN trung khop voi MSCN vua nhap
		for (int i = 0; i < display.size(); ++i)
		{
			if (display.get(i)->layMaSoCaNhan().compare(disp.layMaSoCaNhan()) == 0)
			{
				cout << "\n\tThis car already exist, data will be overriten !" << endl;
				break;
			}
		}
		if (found == false)
		{
			cout << "\n\tNew car will be appended to your list!" << endl;
		}
		//Nhap thong tin chung
		ThayDoiCaiDatChungVaKhoiTaoDuLieu(disp, 1); //1: Doi tuong thuoc lop Display
		//Tim MSCN trung khop voi MSCN vua nhap
		for (int i = 0; i < display.size(); ++i)
		{
			if (display.get(i)->layMaSoCaNhan().compare(disp.layMaSoCaNhan()) == 0)
			{
				p = new Display(disp);		 //Cap phat vung nho co gia tri bang voi 'disp'
				display.changeElement(p, i); //Thay doi gia tri cua bien con tro trong list display tai vi tri i
				found = true;
				break;
			}
		}
		if (found == false)
		{
			p = new Display(disp); //Cap phat vung nho co gia tri bang voi 'disp'
			display.add(p);		   //Them p vao mang elements_ cua list display
		}

		display.Sap_Xep();

		cout << "TIEP TUC XE SO " << display.size() + 1 << " ? (y/n): ";
		cin >> continues;
		cout << endl;
	} while (continues == 'y');
}
void NhapThongTinCaiDat_Sound()
{
	char continues = 'n';
	do
	{
		cout << " NHAP THONG TIN SOUND, XE SO " << sound.size() + 1 << endl;

		bool found = false; //true: tai khoan ton tai,  false: tai khoan khong ton tai
		Sound snd;
		Setting *p; //Con tro tro den vung nho co gia tri giong voi bien 'snd'

		snd.nhapThongTin();
		/**
		 ** Show notification when personal key found or not found 
		*/
		//Tim MSCN trung khop voi MSCN vua nhap
		for (int i = 0; i < sound.size(); ++i)
		{
			if (sound.get(i)->layMaSoCaNhan().compare(snd.layMaSoCaNhan()) == 0)
			{
				cout << "\n\tThis car already exist, data will be overriten !" << endl;
				break;
			}
		}
		if (found == false)
		{
			cout << "\n\tNew car will be appended to your list!" << endl;
		}										   //Nhap thong tin cho bien snd
		ThayDoiCaiDatChungVaKhoiTaoDuLieu(snd, 2); //2: Doi tuong thuoc lop Sound

		//Tim MSCN trung khop voi MSCN vua nhap
		for (int i = 0; i < sound.size(); ++i)
		{
			if (sound.get(i)->layMaSoCaNhan().compare(snd.layMaSoCaNhan()) == 0) //So sanh 2 ma so ca nhan
			{
				p = new Sound(snd);		   //Cap phat vung nho co gia tri bang voi 'snd'
				sound.changeElement(p, i); //Thay doi gia tri phan tu thu 'i' trong mang elements_ cua list 'sound' bang 'snd'
				found = true;
				break;
			}
		}

		if (found == false)
		{
			p = new Sound(snd); //Cap phat vung nho co gia tri bang voi 'snd'
			sound.add(p);		//Gan gia tri cho con tro trong mang "elements"_ list "sound"
		}

		sound.Sap_Xep(); //Sap xep mang elements_ cua list "sound" theo thu tu tang dan MSCN

		cout << "TIEP TUC XE SO " << sound.size() + 1 << " ? (y/n): ";
		cin >> continues;
		cout << endl;
	} while (continues == 'y');
}
void NhapThongTinCaiDat_General()
{
	int selection;
	char continues = 'n';
	/*Check size of list when data overloading*/
	do
	{
		cout << " NHAP THONG TIN GENERAL, XE SO " << general.size() + 1 << endl;

		General gen;		//Bien de luu thong tin doi tuong General dang nhap
		Setting *p;			//Con tro tro den vung nho co gia tri giong voi bien 'gen'
		gen.nhapThongTin(); //Nhap thong tin chung
		bool found = false; //true: tai khoan ton tai,  false: tai khoan khong ton tai

		/**
		 	** Show notification when personal key found or not found 
			*/
		//Tim MSCN trung khop voi MSCN vua nhap
		for (int i = 0; i < general.size(); ++i)
		{
			if (general.get(i)->layMaSoCaNhan().compare(gen.layMaSoCaNhan()) == 0)
			{
				cout << "\n\tThis car already exist, data will be overriten !" << endl;
				break;
			}
		}
		if (found == false)
		{
			cout << "\n\tNew car will be appended to your list!" << endl;
		}

		ThayDoiCaiDatChungVaKhoiTaoDuLieu(gen, 3); //3: Doi tuong thuoc lop General

		cout << "\nMOI BAN CHON TIME ZONE\n";
		selection = ChonTimeZoneVaLanguage(timezoneList); //Lua chon timeZone
		gen.set_timeZone(to_string(selection));			  //Nhap gia tri timeZone cho doi tuong
		cout << "Your time zone is: " << ConvertSelectionToData(timezoneList, selection - 1) << endl;
		cout << "\nMOI BAN CHON LANGUAGE\n";
		selection = ChonTimeZoneVaLanguage(languageList); //Lua chon language
		gen.set_language(to_string(selection));			  //Nhap gia tri language cho doi tuong
		cout << "Your language is: " << ConvertSelectionToData(languageList, selection - 1) << endl;

		//Tim MSCN trung khop voi MSCN vua nhap
		for (int i = 0; i < general.size(); ++i)
		{
			if (general.get(i)->layMaSoCaNhan().compare(gen.layMaSoCaNhan()) == 0)
			{
				p = new General(gen);		 //Cap phat vung nho co gia tri bang voi 'gen'
				general.changeElement(p, i); //Thay doi gia tri cua bien con tro trong list general tai vi tri i
				found = true;
				break;
			}
		}
		if (found == false)
		{
			p = new General(gen); //Cap phat vung nho co gia tri bang voi 'gen'
			general.add(p);		  //Them p vao mang elements_ cua list general
		}

		general.Sap_Xep(); //Sap xep mang elements_ cua list "general" theo thu tu tang dan MSCN

		cout << "TIEP TUC XE SO " << general.size() + 1 << " ? (y/n): ";
		cin >> continues;
		cout << endl;
	} while (continues == 'y');
}

void XuatThongTinCaiDat()
{
	int selection;
	string str;

	do
	{
		printf("\033c");
		cout << "--- MOI BAN LUA CHON ---\n";
		cout << "1-Xuat thong tin Display\n";
		cout << "2-Xuat thong tin Sound\n";
		cout << "3-Xuat thong tin General\n";
		cout << "4-Xuat tat ca thong tin\n";
		cout << "0-Thoat\n";
		cout << "Lua chon cua ban la: ";
		cin >> str;

		if (str.length() == 1 && str[0] >= 48 && str[0] <= 52)
		{
			selection = stoi(str);
			break;
		}
	} while (true);

	printf("\033c");
	switch (selection)
	{
	case 1:
		cout << " --- Thong tin Display ---\n";
		XuatThongTinCaiDat_Display();
		break;
	case 2:
		cout << " --- Thong tin Sound ---\n";
		XuatThongTinCaiDat_Sound();
		break;
	case 3:
		cout << " --- Thong tin General ---\n";
		XuatThongTinCaiDat_General();
		break;
	case 4:
		XuatThongTinTatCaCaiDat();
		break;
	case 0:
		return;
	}
}
//Ham dua du lieu tu mot chuoi vao mang vector<>, ky tu c la dau phan cach giua cac phan tu
const vector<string> explode(const string &s, const char &c)
{
	string buff{""};
	vector<string> v;

	for (auto n : s)
	{
		if (n != c)
			buff += n;
		else if (n == c && buff != "")
		{
			v.push_back(buff);
			buff = "";
		}
	}
	if (buff != "")
		v.push_back(buff);

	return v;
}

void downloadTimeZone()
{
	ifstream f;
	char c[256];
	CommonInfo time; //* Store temp value after read file timezones.txt

	f.open("timezones.txt", std::ios::in | std::ios::out | std::ios::app);

	while (!f.eof())
	{
		f.getline(c, 255);
		time.setNumber(explode(c, '/')[0]); //Phan tu dau cua mang vector sau khi explode() la number cua timeZone
		time.setName(explode(c, '/')[1]);	//Phan tu thu 2 cua mang vector sau khi explode() la name cua timeZone
		timezoneList.push_back(time);		//Them phan tu time vao vector<> timezoneList
	}

	f.close();

	CommonInfo tmp;
	int timeAfter;	//Thoi gian cua chuoi nam sau trong mang
	int timeBefore; //Thoi gian cua chuoi nam truoc trong mang

	//Sap xep mang TimeZone theo utc/index
	//Gop gio va phut thanh 1 chuoi, co dau cong hoac tru truoc chuoi
	//Chuyen sang so nguyen va sap xep theo thu tu tang dan
	for (size_t i = 0; i < timezoneList.size() - 1; ++i)
	{
		for (size_t j = timezoneList.size() - 1; j > i; --j)
		{
			timeAfter = stoi(timezoneList[j].getNumber().substr(4, 3) + timezoneList[j].getNumber().substr(8, 2));			//Trich ra gio va phut roi gop thanh 1 chuoi, ep sang kieu so nguyen
			timeBefore = stoi(timezoneList[j - 1].getNumber().substr(4, 3) + timezoneList[j - 1].getNumber().substr(8, 2)); //Trich ra gio va phut roi gop thanh 1 chuoi, ep sang kieu so nguyen
			if (timeAfter < timeBefore)																						//Neu thoi gian nam sau nho hon thoi nam truoc thi doi cho cho nhau
			{
				tmp = timezoneList[j];
				timezoneList[j] = timezoneList[j - 1];
				timezoneList[j - 1] = tmp;
			}
		}
	}
}

void downloadLanguage()
{
	ifstream f;
	char c[256];
	CommonInfo lang;

	f.open("languages.txt", std::ios::in | std::ios::out | std::ios::app);

	while (!f.eof())
	{
		f.getline(c, 255);
		// lang.setNumber(explode(c, '/')[0]); //Phan tu dau cua mang vector sau khi explode() la number cua language
		lang.setNumber("");				  //Phan tu dau cua mang vector sau khi explode() la number cua language
		lang.setName(explode(c, '/')[1]); //Phan tu thu 2 cua mang vector sau khi explode() la number cua language
		languageList.push_back(lang);
	}

	f.close();

	CommonInfo tmp;

	//Sap xep Language theo Alphabet
	for (size_t i = 0; i < languageList.size() - 1; ++i)
	{
		for (size_t j = languageList.size() - 1; j > i; --j)
		{
			if (languageList[j].getName().compare(languageList[j - 1].getName()) == -1) //So sanh theo ten cua language, neu bang -1 thi language[j]<language[j-1]
			{
				tmp = languageList[j];
				languageList[j] = languageList[j - 1];
				languageList[j - 1] = tmp;
			}
		}
	}
}

void XuatThongTinCaiDat_Sound()
{
	cout << setw(20) << "TEN CHU XE" << setw(25) << "Email" << setw(10) << "MSC" << setw(10) << "ODO" << setw(10) << "SEVICES" << setw(10) << "Media" << setw(10) << "Call" << setw(10) << "Navi" << setw(10) << "Notify" << endl;

	for (int i = 0; i < sound.size(); ++i)
	{
		sound.get(i)->xuatThongTin();
	}
	cout << endl;
	cout << endl
		 << "Press Enter to continue...";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.get();
}

void XuatThongTinCaiDat_General()
{
	cout << setw(20) << "TEN CHU XE" << setw(25) << "Email" << setw(10) << "MSC" << setw(10) << "ODO" << setw(10) << "SEVICES" << setw(15) << "TimeZone" << setw(15) << "Language" << endl;

	for (int i = 0; i < general.size(); ++i)
	{
		general.get(i)->xuatThongTin();
	}
	cout << endl;
	cout << endl
		 << "Press Enter to continue...";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.get();
}

void XuatThongTinCaiDat_Display()
{
	cout << setw(20) << "TEN CHU XE" << setw(25) << "Email" << setw(10) << "MSC" << setw(10) << "ODO" << setw(10) << "SEVICES" << setw(10) << "Light" << setw(10) << "Screen" << setw(10) << "Taplo" << endl;

	for (int i = 0; i < display.size(); ++i)
	{
		display.get(i)->xuatThongTin();
	}
	cout << endl;
	cout << endl
		 << "Press Enter to continue...";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.get();
}

//true: ton tai ma so ca nhan,  false: khong ton tai ma so ca nhan
//location: vi tri co MSCN trung voi personalKey
//selection: 1.ten chu xe,   2.ma so ca nhan
bool KiemTraMSCNHoacTen(List<Setting *> setting, int size, string keyOrName, int &location, string selection)
{
	if (selection == "1")
	{
		for (int i = 0; i < size; ++i)
		{
			if (setting.get(i)->layTenChuXe().compare(keyOrName) == 0) //Neu 2 MSCN trung khop thi luu vi tri hien tai, tra ve true
			{
				location = i;
				return true;
			}
		}
	}
	else
	{
		for (int i = 0; i < size; ++i)
		{
			if (setting.get(i)->layMaSoCaNhan().compare(keyOrName) == 0) //Neu 2 MSCN trung khop thi luu vi tri hien tai, tra ve true
			{
				location = i;
				return true;
			}
		}
	}

	location = -1;
	return false;
}

void XuatThongTinTatCaCaiDat()
{
	string selection;
	string keyOrName;
	bool foundDis, foundSou, foundGen; //true: co ton tai ma so ca nhan hoac ten chu xe,  false: khong ton tai ma so ca nhan hoac ten chu xe
	char continues = 'n';
	int locationDis, locationSou, locationGen; //Vi tri du lieu trong mang trung voi MSCN hoac ten chu xe dang tim kiem
	string noInfo = "chua cai dat thong tin";

	do
	{
		cout << "\n\tXUAT THONG TIN THEO:\n";
		cout << " 1. Ten chu xe\n";
		cout << " 2. Ma so ca nhan\n";
		cout << " 0. Thoat\n";
		cout << " Lua chon cua ban la: ";
		cin >> selection;
		if (selection.length() == 1 && selection[0] >= 48 && selection[0] <= 50)
		{
			break;
		}
		printf("\033c");
	} while (true);

	printf("\033c");
	do
	{
		if (selection == "1")
		{
			cout << "\n\t NHAP TEN CHU XE: ";
		}
		else if (selection == "2")
		{
			cout << "\n\t NHAP MA SO CA NHAN: ";
		}
		else if (selection == "0")
		{
			return;
		}
		cin.ignore();
		getline(cin, keyOrName);

		//Kiem tra su ton tai cua du lieu co cung MSCN hoac ten chu xe
		foundDis = KiemTraMSCNHoacTen(display, display.size(), keyOrName, locationDis, selection);
		foundSou = KiemTraMSCNHoacTen(sound, sound.size(), keyOrName, locationSou, selection);
		foundGen = KiemTraMSCNHoacTen(general, general.size(), keyOrName, locationGen, selection);
		/*Check exist and show notification*/
		if (foundDis == false && foundSou == false && foundGen == false) //Khong ton tai MSCN o 3 list display, sound, general
		{
			if (selection == "1")
			{
				cout << " (!) TEN CHU XE KHONG TON TAI!\n";
				cout << " TIEP TUC NHAP TEN CHU XE? (y/n): ";
			}
			else if (selection == "2")
			{
				cout << " (!) MA SO CA NHAN KHONG TON TAI!\n";
				cout << " TIEP TUC NHAP MA SO CA NHAN? (y/n): ";
			}
			do
			{
				cin >> continues;
			} while (continues != 'y' && continues != 'n');

			if (continues == 'n')
				return;
		}
		else
		{
			break;
		}

	} while (continues == 'y');

	//Xuat thong tin chung: Ten chu xe, mscn, email, odo, km bao hanh
	//Neu MSCN co ton tai thi in ra thong tin chung va chi in 1 lan

	//Xuat thong tin theo tung chuc nang
	//Neu du lieu chua cai dat thi thong bao "chua cai dat thong tin"

	//in ra toan bo thong tin cua tung xe

	if (selection == "1")
	{
		/*show theo ho ten*/
		if (foundDis == true)
		{
			for (int i = 0; i < display.size(); i++)
			{

				if (display.get(i)->layTenChuXe().compare(keyOrName) == 0) //Neu 2 MSCN trung khop thi luu vi tri hien tai, tra ve true
				{
					display.get(i)->xuatThongTinChung();

					display.get(i)->xuatThongTinRieng();
					sound.get(i)->xuatThongTinRieng();
					general.get(i)->xuatThongTinRieng();
					cout << "\n\t" << string(20, '*') << endl;
				}
			}
		}
		else
		{
			cout << setiosflags(ios::left) << setw(23) << "LIGHT LEVEL" << setw(2) << ":" << resetiosflags(ios::left) << noInfo << endl;
			cout << setiosflags(ios::left) << setw(23) << "SCREEN LIGHT LEVEL" << setw(2) << ":" << resetiosflags(ios::left) << noInfo << endl;
			cout << setiosflags(ios::left) << setw(23) << "TAPLO LIGHT LEVEL" << setw(2) << ":" << resetiosflags(ios::left) << noInfo << endl;
		}
	}
	else
	{
		/*Display data follow personal key*/
		if (foundDis == true)
		{
			display.get(locationDis)->xuatThongTinChung();

			display.get(locationDis)->xuatThongTinRieng(); //In thong tin rieng cua list display
			sound.get(locationSou)->xuatThongTinRieng();   //In thong tin rieng cua list sound
			general.get(locationGen)->xuatThongTinRieng(); //In thong tin rieng cua list general
		}
		else
		{
			cout << setiosflags(ios::left) << setw(23) << "LIGHT LEVEL" << setw(2) << ":" << resetiosflags(ios::left) << noInfo << endl;
			cout << setiosflags(ios::left) << setw(23) << "SCREEN LIGHT LEVEL" << setw(2) << ":" << resetiosflags(ios::left) << noInfo << endl;
			cout << setiosflags(ios::left) << setw(23) << "TAPLO LIGHT LEVEL" << setw(2) << ":" << resetiosflags(ios::left) << noInfo << endl;
		}
	}
	cout << endl;
	cout << endl
		 << "Press Enter to continue...";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

//Loai bo khoang trang trong chuoi
string WhiteSpaceDelete(string &s)
{
	string ret;
	for (size_t i = 0; i < s.length(); i++)
	{
		if (s[i] != ' ')
		{
			ret += s[i];
		}
	}
	return ret;
}

void CheckDigit(string &s) //Kiem tra dau vao co phai so nguyen khong
{
	for (size_t i = 0; i < s.length(); i++)
	{
		if (!isdigit(s[i]))
			throw "\n\t(!) LOI (Du lieu dau vao cua thong tin chung khong hop le)\n";
	}
}

//Kiem tra trung lap thong tin
//Tien hanh kiem tra khi doc xong du lieu tu file vao cac mang
//Neu mang gom 2 phan tu tro len thi tien hanh kiem tra co trung khop MSCN khong
void DuplicationOfInfo(List<Setting *> list)
{
	if (list.size() > 1) //Neu mang gom 2 phan tu tro len thi tien hanh kiem tra co trung khop MSCN khong
	{
		for (int i = 0; i < list.size(); ++i)
		{
			for (int j = 0; j < list.size(); ++j)
			{
				if (i == j) //Bo qua doi tuong dang xet
					continue;
				if (list.get(i)->layMaSoCaNhan() == list.get(j)->layMaSoCaNhan()) //So sanh MSCN
				{
					throw "\n\t(!) LOI (Du lieu dau vao bi trung lap thong tin)\n";
				}
			}
		}
	}
}

void ReadFromFile()
{
	string s;						 //Luu du lieu doc tu file
	string generalInfo, privateInfo; //Luu thong tin chung va thong tin rieng de xu ly
	string Info;					 //Luu thong tin rieng cua tung chuc nang
	size_t pos;						 //Vi tri cua dau ";"
	size_t colonPos;				 //Vi tri cua dau ':'
	ifstream inFile;
	vector<string> generalInfoArray; //Mang luu thong tin cai dat chung
	vector<string> privateInfoArray; //Mang luu thong tin cai dat rieng
	string email, personalKey, odo, serviceRemind;
	string functionName; //Ten chuc nang
	string selection;	 //Trich ra lua chon cua tung chuc nang
	bool endOfSequence;	 //true: ket thuc chuoi;  false: chua ket thuc chuoi

	Display disp;
	Setting *dispPointer; //Tro den vung nho lop Display
	Sound snd;
	Setting *sndPointer; //Tro den vung nho lop Sound
	General gen;
	Setting *genPointer; //Tro den vung nho lop General

	regex patternMain //Regex pattern kiem tra email
		("^[a-zA-Z0-9][a-zA-Z0-9.]{1,28}[a-zA-Z0-9]@[a-zA-Z0-9][a-zA-Z0-9-]*[a-zA-Z0-9](\\.[a-z0-9]{2,4}){1,2}$");
	regex patternd("\\d{8}"); //Regex pattern kiem tra ma so ca nhan

	try
	{
		inFile.open("Setting.txt", std::ios::in | std::ios::out | std::ios::app);
		if (!inFile)
		{
			throw "\n\tKhong mo duoc file \"Setting.txt\" de doc du lieu\n";
		}
		while (getline(inFile, s))
		{
			if (s.find_first_of(";") == -1)
			{
				throw "\n\t(!) LOI (Du lieu dau vao phai co thong tin chung va thong tin rieng)\n";
			}
			pos = s.find_first_of(";");		//Tim vi tri cua dau ';'
			generalInfo = s.substr(0, pos); //Trich chuoi ky tu tu vi tri 0 la pos phan tu

			//KIem tra phan thong tin chung co phai la thong tin rieng
			//neu la thong tin rieng thi co dau ':'
			//ham tra ve gia tri '-1' khi khong co dau ':'
			if (generalInfo.find_first_of(":") != -1)
			{
				throw "\n\t(!) LOI (Du lieu dau vao thieu thong tin chung)\n";
			}
			generalInfoArray = explode(generalInfo, ','); //Dua thong tin vao mang

			if (generalInfoArray.size() != 5) //Thua hoac thieu thong tin chung
			{
				throw "\n\t(!) LOI (Du lieu dau vao cua thong tin chung khong hop le)\n";
			}

			//Kiem tra email dau vao co dung khong
			email = WhiteSpaceDelete(generalInfoArray[1]);
			if (!regex_match(email, patternMain))
			{
				throw "\n\t(!) LOI (Du lieu dau vao cua thong tin chung khong hop le)\n";
			}

			//Kiem tra ma so ca nhan dau vao
			personalKey = WhiteSpaceDelete(generalInfoArray[2]);
			if (!regex_match(personalKey, patternd))
			{
				throw "\n\t(!) LOI (Du lieu dau vao cua thong tin chung khong hop le)\n";
			}

			//Kiem tra gia tri odo dau vao
			odo = WhiteSpaceDelete(generalInfoArray[3]);
			CheckDigit(odo);

			//Kiem tra gia tri service remind
			serviceRemind = WhiteSpaceDelete(generalInfoArray[4]);
			CheckDigit(serviceRemind);

			s = s.substr(pos + 1);			   //Trich chuoi ky tu thong tin rieng
			privateInfo = WhiteSpaceDelete(s); //Xoa khoang trang trong chuoi s
			if (privateInfo.length() == 0)	   //Kiem tra chuoi thong tin rieng co rong hay khong
			{
				throw "\n\t(!) LOI (Du lieu dau vao thieu thong tin rieng)\n";
			}

			endOfSequence = false;
			while (!endOfSequence)
			{
				privateInfoArray.resize(0);
				if (privateInfo.find_first_of(';') == -1)  //Kiem tra con chuc nang khac o phia sau nua khong
				{										   //ham tra ve gia tri '-1' khi khong co dau ';' trong chuoi
					Info = privateInfo.substr(0, INT_MAX); //Trich ra chuoi thong tin rieng cua mot chuc nang
					endOfSequence = true;
				}
				else
				{
					pos = privateInfo.find_first_of(';'); //Tim vi tri cua dau ';'
					Info = privateInfo.substr(0, pos);	  //Trich ra chuoi thong tin rieng cua mot chuc nang
					privateInfo = privateInfo.substr(pos + 1, INT_MAX);
				}

				colonPos = Info.find_first_of(':');				//Vi tri cua dau ':'
				functionName = Info.substr(0, colonPos);		//Trich ra ten chuc nang
				selection = Info.substr(colonPos + 1, INT_MAX); //Trich ra lua chon cua tung chuc nang
				privateInfoArray = explode(selection, ',');		//Dua cac thong tin cai dat cua chuc nang vao mang

				//Kiem tra cac lua chon cai dat thong tin rieng co phai la so hay khong
				for (size_t i = 0; i < privateInfoArray.size(); i++)
				{
					CheckDigit(privateInfoArray[i]);
				}

				if (functionName == "Display")
				{
					if (privateInfoArray.size() != 3) //Chuc nang display co 3 lua chon, it hon hay nhieu hon se bi loai
					{
						throw "\n\t(!) LOI (Du lieu dau vao cua thong tin rieng khong hop le)\n";
					}

					//Nhap thong tin cho bien 'disp'
					disp.set_car_name(generalInfoArray[0]);
					disp.set_email(email);
					disp.set_personal_key(personalKey);
					disp.set_odo(stoi(odo));
					disp.set_service_remind(stoi(serviceRemind));
					disp.set_light_level(stoi(privateInfoArray[0]));
					disp.set_screen_light_level(stoi(privateInfoArray[1]));
					disp.set_taplo_light_level(stoi(privateInfoArray[2]));

					dispPointer = new Display(disp);
					display.add(dispPointer); //Them thong tin vao mang display
				}
				else if (functionName == "Sound")
				{
					if (privateInfoArray.size() != 4) //Chuc nang sound co 4 lua chon, it hon hay nhieu hon se bi loai
					{
						throw "\n\t(!) LOI (Du lieu dau vao cua thong tin rieng khong hop le)\n";
					}

					//Nhap thong tin cho bien 'snd'
					snd.set_car_name(generalInfoArray[0]);
					snd.set_email(email);
					snd.set_personal_key(personalKey);
					snd.set_odo(stoi(odo));
					snd.set_service_remind(stoi(serviceRemind));
					snd.set_media_level(stoi(privateInfoArray[0]));
					snd.set_call_level(stoi(privateInfoArray[1]));
					snd.set_navi_level(stoi(privateInfoArray[2]));
					snd.set_notification_level(stoi(privateInfoArray[3]));

					sndPointer = new Sound(snd);
					sound.add(sndPointer); //Them thong tin vao mang sound
				}
				else
				{
					if (privateInfoArray.size() != 2) //Chuc nang general co 2 lua chon, it hon hay nhieu hon se bi loai
					{
						throw "\n\t(!) LOI (Du lieu dau vao cua thong tin rieng khong hop le)\n";
					}

					//Nhap thong tin cho bien 'gen'
					gen.set_car_name(generalInfoArray[0]);
					gen.set_email(email);
					gen.set_personal_key(personalKey);
					gen.set_odo(stoi(odo));
					gen.set_service_remind(stoi(serviceRemind));
					gen.set_timeZone(privateInfoArray[0]);
					gen.set_language(privateInfoArray[1]);

					genPointer = new General(gen);
					general.add(genPointer); //Them thong tin vao mang general
				}
			}
		}
		inFile.close();

		//Kiem tra trung lap thong tin
		DuplicationOfInfo(display);
		DuplicationOfInfo(sound);
		DuplicationOfInfo(general);

		display.Sap_Xep();
		sound.Sap_Xep();
		general.Sap_Xep();
	}
	catch (const char *ch)
	{
		cout << ch << endl;
		cout << "\t\t\t\t--- CHAO TAM BIET ---\n\n";
		cout << endl
			 << "Press Enter to continue...";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin.get();
		exit(0);
	}
}

//Tim kiem vi tri phan tu co cung MSCN
int PositionOfTheSamePersonalKey(List<Setting *> list, const string &personalKey)
{
	for (int i = 0; i < list.size(); ++i)
	{
		if (list.get(i)->layMaSoCaNhan() == personalKey)
		{
			return i;
		}
	}
	return -1; //Tra ve -1 khi khong co phan tu nao co MSCN trung voi MSCN duoc dua vao
}

//Ham lay thong tin chung
void GetInfo(List<Setting *> list, int &position, string &carName, string &email, string &personalKey, int &odo, int &serviceRemind)
{
	carName = list.get(position)->layTenChuXe();
	email = list.get(position)->layEmail();
	personalKey = list.get(position)->layMaSoCaNhan();
	odo = list.get(position)->layOdo();
	serviceRemind = list.get(position)->layServiceRemind();
}

//Ham ghi du lieu len tap tin "Setting.txt"
void WriteOnFile()
{
	ofstream outFile;
	string carName, personalKey, email, lightLevel, screenLevel, taploLevel;
	string mediaLevel, callLevel, naviLevel, notiLevel, timeZone, language;
	int odo, serviceRemind;
	string *generalArray = NULL; //Con tro tro den mang thong tin rieng cua doi tuong "general"
	string *soundArray = NULL;	 //Con tro tro den mang thong tin rieng cua doi tuong "sound"
	string *displayArray = NULL; //Con tro tro den mang thong tin rieng cua doi tuong "display"
	int sndPos = -1;			 //Vi tri phan tu trong mang "sound" co MSCN trung khop
	int dispPos = -1;			 //Vi tri phan tu trong mang "display" co MSCN trung khop

	try
	{
		outFile.open("Setting.txt");
		if (!outFile)
		{
			throw "\n\tKhong mo duoc file \"Setting.txt\" de ghi du lieu\n";
		}

		//Ghi thong tin trong list "general"
		for (int i = 0; i < general.size(); ++i)
		{
			GetInfo(general, i, carName, email, personalKey, odo, serviceRemind);									//Lay thong tin chung
			outFile << carName << "," << email << "," << personalKey << "," << odo << "," << serviceRemind << "; "; //Ghi thong tin chung vao file

			generalArray = general.get(i)->layThongTinRieng(generalArray); //Tro den dia chi cua mang chua thong tin rieng
			timeZone = generalArray[0];
			language = generalArray[1];
			outFile << "General:" << timeZone << "," << language; //Ghi thong tin rieng vao file

			//Kiem tra MSCN cua phan tu trong list "sound" trung khop voi MSCN phan tu trong list "general"
			sndPos = PositionOfTheSamePersonalKey(sound, personalKey);
			if (sndPos != -1) //Bang -1: khong co phan tu nao trong list "sound" co MSCN trung voi MSCN dang xet
			{
				soundArray = sound.get(sndPos)->layThongTinRieng(soundArray); //Tro den dia chi cua mang chua thong tin rieng
				mediaLevel = soundArray[0];
				callLevel = soundArray[1];
				naviLevel = soundArray[2];
				notiLevel = soundArray[3];
				outFile << ";Sound:" << mediaLevel << "," << callLevel << "," << naviLevel << "," << notiLevel; //Ghi thong tin rieng vao file
				sound.pop_element(sndPos);																		//Xoa phan tu tai vi tri sndPos trong mang "sound"
			}

			//Kiem tra MSCN cua phan tu trong list "display" trung khop voi MSCN phan tu trong list "general"
			dispPos = PositionOfTheSamePersonalKey(display, personalKey);
			if (dispPos != -1)
			{
				displayArray = display.get(dispPos)->layThongTinRieng(displayArray);
				lightLevel = displayArray[0];
				screenLevel = displayArray[1];
				taploLevel = displayArray[2];
				outFile << ";Display:" << lightLevel << "," << screenLevel << "," << taploLevel << "\n"; //Ghi thong tin rieng vao file
				display.pop_element(dispPos);															 //Xoa phan tu tai vi tri dispPos trong list "display"
			}
			else
			{
				outFile << "\n";
			}
		}

		//Ghi thong tin trong list "sound"
		for (int i = 0; i < sound.size(); ++i)
		{
			GetInfo(sound, i, carName, email, personalKey, odo, serviceRemind);										//Lay thong tin chung
			outFile << carName << "," << email << "," << personalKey << "," << odo << "," << serviceRemind << "; "; //Ghi thong tin chung vao file

			soundArray = sound.get(i)->layThongTinRieng(soundArray); //Tro den dia chi cua mang chua thong tin rieng
			mediaLevel = soundArray[0];
			callLevel = soundArray[1];
			naviLevel = soundArray[2];
			notiLevel = soundArray[3];
			outFile << "Sound:" << mediaLevel << "," << callLevel << "," << naviLevel << "," << notiLevel; //Ghi thong tin rieng vao file

			//Kiem tra MSCN cua phan tu trong list "display" trung khop voi MSCN phan tu trong list "sound"
			dispPos = PositionOfTheSamePersonalKey(display, personalKey);
			if (dispPos != -1)
			{
				displayArray = display.get(dispPos)->layThongTinRieng(displayArray);
				lightLevel = displayArray[0];
				screenLevel = displayArray[1];
				taploLevel = displayArray[2];
				outFile << ";Display:" << lightLevel << "," << screenLevel << "," << taploLevel << "\n"; //Ghi thong tin rieng vao file
				display.pop_element(dispPos);															 //Xoa phan tu tai vi tri dispPos trong list "display"
			}
			else
			{
				outFile << "\n";
			}
		}

		//Ghi thong tin trong list "display"
		for (int i = 0; i < display.size(); ++i)
		{
			GetInfo(display, i, carName, email, personalKey, odo, serviceRemind);									//Lay thong tin chung
			outFile << carName << "," << email << "," << personalKey << "," << odo << "," << serviceRemind << "; "; //Ghi thong tin chung vao file

			displayArray = display.get(i)->layThongTinRieng(displayArray);
			lightLevel = displayArray[0];
			screenLevel = displayArray[1];
			taploLevel = displayArray[2];
			outFile << "Display:" << lightLevel << "," << screenLevel << "," << taploLevel << "\n"; //Ghi thong tin rieng vao file
		}

		outFile.close();
	}
	catch (const char *ch)
	{
		cout << ch << endl;
	}
	cout << "\n\tDa ghi du lieu thanh cong vao file \"Setting.txt\"\n";
}