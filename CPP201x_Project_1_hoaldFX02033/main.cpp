#include <iostream>
#include "General.h"
#include "Display.h"
#include "Sound.h"
#include "CommonInfo.h"
#include <fstream>
#include <regex>
#include "CheckValid.h"
#include <sstream>
#include <istream>
#include <fstream>
#include <iostream>

//khai bao object cua cac class
Display *display = new Display();
Sound *sound = new Sound();
General *general = new General();
Setting *setting = new Setting();

//khai bao cac array de chua cac thong tin của xe
Setting arr_settings[100];
Sound arr_sounds[100];
General arr_generals[100];
Display arr_displays[100];

int settingCnt = 0;			 //lam index cua array chinh chua car
string languageT, timezoneT; //bien tmp chua timezone va language khi ng dung lua chon
static int countCar = 1;	 //dem so index car cua xe

vector<CommonInfo> timezoneList;
vector<CommonInfo> languageList;

void NhapThongTinCaiDat();
void XuatThongTinCaiDat();

void XuatThongTinCaiDat_Sound();
void XuatThongTinCaiDat_General();
void XuatThongTinCaiDat_Display();
void XuatThongTatCaTinCaiDat();

void NhapThongTinCaiDat_Sound();
void NhapThongTinCaiDat_General();
void NhapThongTinCaiDat_Display();

void downloadTimeZone();
void downloadLanguage();

void menu();

// Sort data advance
bool comparatorSetting(Setting &setting1, Setting &setting2);
bool comparatorDisplay(Display &display1, Display &display2);
bool comparatorSound(Sound &display1, Sound &display2);
bool comparatorGeneral(General &display1, General &display2);
bool comparatorTimezone(CommonInfo c1, CommonInfo c2);
bool comparatorLanguage(CommonInfo c1, CommonInfo c2);

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main(int argc, char **argv)
{
	menu();
	return 0;
}

//menu chinh
void menu()
{

	int selection = 0;
	printf("\033c");
	cout << "--- SELECT MENU ---"
		 << endl
		 << "1. Input setting information"
		 << endl
		 << "2. Print setting information"
		 << endl
		 << "0. Exit"
		 << endl
		 << "Your choice: ";
	do
	{
		selection = validInput("Your choice");
		switch (selection)
		{
		case 1:
			//system("cls");
			printf("\033c");
			NhapThongTinCaiDat();
			break;
		case 2:
			//system("cls");
			printf("\033c");
			XuatThongTinCaiDat();
			break;
		case 0:
			//system("cls");
			printf("\033c");
			cout << "Thanks for using this program" << endl;
			exit(0); //ket thuc chuong trinh
			break;
		default:
			cout << "Please enter your choice from 1-3. Re-enter: ";
			break;
		}
	} while (selection != 0);
}

//menu input display, sound, genaral
void NhapThongTinCaiDat()
{
	int selection;

	do
	{
		cout << "--- SELECT MENU ---"
			 << endl
			 << "1. Display setting "
			 << endl
			 << "2. Sound setting "
			 << endl
			 << "3. General setting "
			 << endl
			 << "0. Back"
			 << endl
			 << "Your choice: ";
		selection = validInput("Your choose");
		switch (selection)
		{
		case 1:
			//system("cls");
			printf("\033c");
			NhapThongTinCaiDat_Display(); //nhap thon tin cho Display
			break;
		case 2:
			//system("cls");
			printf("\033c");
			NhapThongTinCaiDat_Sound(); //nhap thon tin cho Sound
			break;
		case 3:
			NhapThongTinCaiDat_General(); //nhap thon tin cho General
										  //system("cls");
			printf("\033c");
			break;
		case 0:
			//system("cls");
			printf("\033c");
			menu(); //tro ve man hinh menu chinh
			break;
		default:
			//system("cls");
			printf("\033c");
			cout << "Please enter your choice from 1-4. " << endl;
			break;
		}
	} while (selection != 0);
}

//nhap thon tin cai dat cho Display
void NhapThongTinCaiDat_Display()
{

	do
	{
		//system("cls");
		printf("\033c");
		bool exist = false;
		int indexCar = -1;
		cout << " --- Input Display setting --- " << endl;
		cout << "Car index: " << countCar << endl;
		//neu nhap dc 100 car roi thi k cho nhap nua
		if (settingCnt >= 100)
		{
			cout << "The list can only contain 100 cars. The list is full" << endl;
		}
		else
		{
			//nhap thong tin chung cho xe
			Setting st = setting->nhapThongTin();
			//check trung car
			for (int i = 0; i < settingCnt; i++)
			{
				if (st.getPersonalKey() == arr_settings[i].getPersonalKey())
				{
					exist = true;
					indexCar = i; //lay vi tri cua xe trung de update
					break;
				}
			}

			//neu ma so ca nhan khong ton tai
			if (!exist)
			{

				cout << "	-> This is car, data will be appended to your list" << endl;

				//neu xe khong ton tai thi luu thang vao arr setting luon
				arr_settings[settingCnt] = st;

				//nhap thong tin cho Display
				arr_displays[settingCnt] = display->nhapThongTin(st);

				//khoi tao gia tri mac dinh khi k chon chuc nang nhap cho general
				General gen;
				arr_generals[settingCnt] = gen;

				//khoi tao gia tri mac dinh khi k chon chuc nang nhap cho sound
				Sound snd;
				arr_sounds[settingCnt] = snd;

				//tang index cua arr setting len 1
				settingCnt++;
				countCar++; //tang index car len 1 de dem so xe nhap vao
			}
			else
			{ //neu MSCN cua xe ton tai

				cout << "	-> This car already existed, data will be overriten" << endl;
				arr_settings[indexCar] = st;						//update Setting
				arr_displays[indexCar] = display->nhapThongTin(st); //nhap lai thong tin cho Display
			}
		}
	} while (isInputNewCar(settingCnt));
}

//nhap thong tin cho Sound
void NhapThongTinCaiDat_Sound()
{
	string personalKey; //MSCN

	do
	{
		//system("cls");
		printf("\033c");
		bool exist = false;
		int indexCar = -1;
		cout << " --- Input Display setting --- " << endl;
		cout << "Car index: " << countCar << endl;
		//neu nhap dc 100 car roi thi k cho nhap nua
		if (settingCnt >= 100)
		{
			cout << "The list can only contain 100 cars. The list is full" << endl;
		}
		else
		{
			//nhap thong tin chung cho xe
			Setting st = setting->nhapThongTin();
			for (int i = 0; i < settingCnt; i++)
			{
				if (st.getPersonalKey() == arr_settings[i].getPersonalKey())
				{
					exist = true;
					indexCar = i; //lay vi tri cua xe trung de update
					break;
				}
			}
			//neu ma so ca nhan khong ton tai
			if (!exist)
			{

				cout << "	-> This is car, data will be appended to your list" << endl;

				//neu xe khong ton tai thi luu thang vao arr setting luon
				arr_settings[settingCnt] = st;

				///add new cho arr sound, general, display de khi chon chuc nang print cho tung cai thi van hien ra duoc
				//nhap thong tin cho Sound
				arr_sounds[settingCnt] = sound->nhapThongTin(st);

				Display dis;
				arr_displays[settingCnt] = dis;

				General gen;
				arr_generals[settingCnt] = gen;

				//tang index cua arr setting len 1
				settingCnt++;
				countCar++; //tang index car len 1 de dem so xe nhap vao
			}
			else
			{ //neu MSCN cua xe ton tai
				cout << "	-> This car already existed, data will be overriten" << endl;

				arr_settings[indexCar] = st;					//update Setting
				arr_sounds[indexCar] = sound->nhapThongTin(st); //nhap lai thong tin cho Sound
			}
		}
	} while (isInputNewCar(settingCnt));
}

//nhap thong tin cai dat cho General
void NhapThongTinCaiDat_General()
{
	string personalKey; //MSCN

	do
	{
		//system("cls");
		printf("\033c");
		bool exist = false;
		int indexCar = -1;
		cout << " --- Input Display setting --- " << endl;
		cout << "Car index: " << countCar << endl;
		//neu nhap dc 100 car roi thi k cho nhap nua
		if (settingCnt >= 100)
		{
			cout << "The list can only contain 100 cars. The list is full" << endl;
		}
		else
		{
			//nhap thong tin chung cho xe
			Setting st = setting->nhapThongTin();
			for (int i = 0; i < settingCnt; i++)
			{
				if (st.getPersonalKey() == arr_settings[i].getPersonalKey())
				{
					exist = true;
					indexCar = i; //lay vi tri cua xe trung de update
					break;
				}
			}
			//neu ma so ca nhan khong ton tai
			if (!exist)
			{

				cout << "	-> This is car, data will be appended to your list" << endl;

				//neu xe khong ton tai thi luu thang vao arr setting luon
				arr_settings[settingCnt] = st;

				//chon language
				downloadLanguage(); //hien list language cho ng dung chon

				//chon timezone
				downloadTimeZone(); //hien list timezone cho ng dung chon

				//nhap thong tin cho General
				General gen;
				arr_generals[settingCnt] = general->nhapThongTin(st, timezoneT, languageT);

				//add new cho arr sound, general, display de khi chon chuc nang print cho tung cai thi van hien ra duoc
				Display dis;
				arr_displays[settingCnt] = dis;
				Sound snd;
				arr_sounds[settingCnt] = snd;

				settingCnt++; //tang index cua arr setting len 1
				countCar++;	  //tang index car len 1 de dem so xe nhap vao
			}
			else
			{ //neu MSCN cua xe ton tai

				cout << "	-> This car already existed, data will be overriten" << endl;

				arr_settings[indexCar] = st;					//update Setting
				downloadLanguage();								//hien list language cho ng dung chon
				arr_generals[indexCar].set_language(languageT); //update language

				//choose timezone
				downloadTimeZone();								//hien list timezone cho ng dung chon
				arr_generals[indexCar].set_timeZone(timezoneT); //update language
			}
		}
	} while (isInputNewCar(settingCnt));
}

//xuat thong tin cai dat cho xe
void XuatThongTinCaiDat()
{

	int selection; //lua chon menu

	//sort array de in ra danh sach
	sort(arr_settings, arr_settings + settingCnt, comparatorSetting);
	sort(arr_displays, arr_displays + settingCnt, comparatorDisplay);
	sort(arr_sounds, arr_sounds + settingCnt, comparatorSound);
	sort(arr_generals, arr_generals + settingCnt, comparatorGeneral);

	do
	{
		cout << "--- SELECT MENU ---"
			 << endl
			 << "1. Print display setting information "
			 << endl
			 << "2. Print sound setting information "
			 << endl
			 << "3. Print general setting information "
			 << endl
			 << "4. Print all setting information"
			 << endl
			 << "0. Back"
			 << endl
			 << "Your choice: ";
		selection = validInput("Your choose");
		switch (selection)
		{
		case 1:
			printf("\033c");
			XuatThongTinCaiDat_Display(); //xuat thong tin cai dat cho Display
			cout << endl
				 << "Press Enter to continue...";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			printf("\033c");
			break;
		case 2:
			printf("\033c");
			XuatThongTinCaiDat_Sound(); //xuat thong tin cai dat cho Sound
			cout << endl
				 << "Press Enter to continue...";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			printf("\033c");
			break;
		case 3:
			printf("\033c");
			XuatThongTinCaiDat_General(); //xuat thong tin cai dat cho General
			cout << endl
				 << "Press Enter to continue...";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			//cin.get();
			printf("\033c");
			break;
		case 4:
			printf("\033c");
			XuatThongTatCaTinCaiDat(); //xuat tat ca thong tin cai dat
			//system("pause");
			cout << endl
				 << "Press Enter to continue...";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			//cin.get();
			printf("\033c");
			break;
		case 0:
			printf("\033c");
			menu(); //tro ve man hinh menu
			break;
		default:
			printf("\033c");
			cout << "Please enter your choice from 1-4. " << endl;
			break;
		}
	} while (selection != 0);
}

//tach chuoi
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

//doc Timezone trong file ra de hien thi va cho ng dung lua chon
void downloadTimeZone()
{
	ifstream f;
	int lineNumber = 0; //dem so hang trong file
	CommonInfo commonInfo;
	string str; //dung de doc tung hang trong file
	vector<string> data_vector;
	int selection; //lua chon 1 trong 30 language

	f.open("timezones.txt"); // mo va doc data tu file languages.txt

	if (!f.is_open()) //neu file k ton tai thi show thong bao loi
	{
		cout << "Fail open file timezones";
		//system("pause");
		cout << endl
			 << "Press Enter to continue...";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin.get();
	}
	else
	{

		//doc file la language cho ng dung chon
		cout << "----- SELECT TIMEZONES DATA -----" << endl;
		if (timezoneList.size() == 0)
		{
			while (f.eof() == false)
			{
				// f.seekg(1, 1);					 //nhich qua 1 byte de bo dau '('
				f.seekg(1, ios::beg); //nhich qua 1 byte de bo dau '('

				getline(f, str);				 //doc file
				data_vector = explode(str, ')'); //cat cuoi dua vao dau ')'
				if (data_vector.size() == 2)
				{
					// set data cua Language vao common info vector
					commonInfo.setNumber(data_vector[0]);
					commonInfo.setName(data_vector[1]);
					timezoneList.push_back(commonInfo);
				}
			}
		}

		//sort lisst timezone va hien ra list timezone cho ng dung chon
		sort(timezoneList.begin(), timezoneList.end(), comparatorTimezone);
		for (CommonInfo &item : timezoneList)
		{
			lineNumber++;
			cout << "  " << lineNumber << ": "
				 << "(" << item.getNumber() + ")" + item.getName() << "\n"; //in data trong file ra man hinh
		}

		//nhap lua chon cho Timezone
		cout << "YOUR SELECTION: ";
		selection = validTimezones();

		//hien lua chon ra man hình
		cout << "	Timezone: " << timezoneList[selection - 1].getNumber() << endl;
		;
		//gan Timezone vao timezoneT de hien Timezone o chuc nang General Setting
		timezoneT = timezoneList[selection - 1].getNumber();
		general->set_timeZone(timezoneList[selection - 1].getNumber()); //set Timezone cho general
	}

	f.close();
	//system("pause");
	cout << endl
		 << "Press Enter to continue...";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.get();
	//system("cls");
	printf("\033c");
}

//doc language trong file ra de hien thi va cho ng dung lua chon
void downloadLanguage()
{
	ifstream f;
	CommonInfo commonInfo;
	string str;			//dung de doc tung hang trong file
	int lineNumber = 0; //den so hang trong file
	vector<string> data_vector;
	int selection; //lua chon 1 trong 30 language

	f.open("languages.txt"); // mo va doc data tu file languages.txt

	if (!f.is_open()) //neu file k ton tai thi show thong bao loi
	{
		cout << "Fail open file languages";
		//system("pause");
		cout << endl
			 << "Press Enter to continue...";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin.get();
	}
	else
	{
		//doc file la language cho ng dung chon
		cout << "----- SELECT LANGUAGE DATA -----" << endl;
		if (timezoneList.size() == 0)
		{
			while (getline(f, str))
			{

				data_vector = explode(str, '/'); //cat chuoi dua vao dau '/'
				if (data_vector.size() == 2)
				{
					// set data cua Language vao common info vector
					commonInfo.setNumber(data_vector[0]);
					commonInfo.setName(data_vector[1]);
					languageList.push_back(commonInfo);
				}
			}
		}

		//sort language khi hien thi
		sort(languageList.begin(), languageList.end(), comparatorLanguage);
		//hien list language ra man hinh de lua chon
		for (CommonInfo &item : languageList)
		{
			lineNumber++;
			cout << "  " << lineNumber << ": " << item.getName() << "\n"; //in data trong file ra man hinh
		}

		//nhap lua chon cho language
		cout << "YOUR SELECTION: ";
		selection = validLanguage();

		//hien lua chon ra man hình
		cout << "	Language: " << languageList[selection - 1].getName() << endl;
		;
		//gan language vao languageT de hien language o chuc nang General Setting
		languageT = languageList[selection - 1].getName();
		general->set_language(languageList[selection - 1].getName()); //set language cho general
	}

	f.close();
	//system("pause");
	cout << endl
		 << "Press Enter to continue...";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.get();
	//system("cls");
	printf("\033c");
}

//xuat thong tin cho Display
void XuatThongTinCaiDat_Display()
{
	display->xuatThongTin(arr_settings, arr_displays, settingCnt);
}

//xuat thong tin cai dat cua Sound
void XuatThongTinCaiDat_Sound()
{
	sound->xuatThongTin(arr_settings, arr_sounds, settingCnt);
}

//xuat thong tin cai dat cua General
void XuatThongTinCaiDat_General()
{
	general->xuatThongTin(arr_settings, arr_generals, settingCnt);
}

//xuat tat ca thogn tin cai dat cau xe
void XuatThongTatCaTinCaiDat()
{
	cout << "--- All setting ---" << endl;

	//in ra toan bo thong tin cua tung xe
	for (int i = 0; i < settingCnt; i++)
	{

		cout << setw(10) << left << i + 1 << setw(30) << left << "Owner name" << setw(35) << left << "Email" << setw(20) << left << "Key number" << setw(20) << left << "ODO number" << setw(25) << left << "Remind Service (km)" << endl;

		//in data cua Setting
		cout << setw(10) << left << ""
			 << setw(30) << left << arr_settings[i].getCarName()
			 << setw(35) << left << arr_settings[i].getEmail()
			 << setw(20) << left << arr_settings[i].getPersonalKey()
			 << setw(20) << left << arr_settings[i].getODO()
			 << setw(25) << left << arr_settings[i].getServiceRemind() << endl;

		//in data cua Display
		for (int count = 0; count < settingCnt; count++)
		{
			if (arr_settings[i].getPersonalKey() == arr_displays[count].getPersonalKey())
			{
				cout << setw(20) << left << "Display:" << setw(15) << "Light level" << setw(20) << "Screen Light level" << setw(15) << "Taplo Light" << endl;

				cout << setw(20) << left << ""
					 << setw(15) << arr_displays[count].get_light_level()
					 << setw(20) << arr_displays[count].get_screen_light_level()
					 << setw(15) << arr_displays[count].get_taplo_light_level() << endl;
				break;
			}
		}

		//in data cua Sound
		for (int count = 0; count < settingCnt; count++)
		{
			if (arr_settings[i].getPersonalKey() == arr_sounds[count].getPersonalKey())
			{
				cout << setw(20) << left << "Sound:" << setw(10) << left << "Media" << setw(10) << left << "Call" << setw(15) << left << "Navigation" << setw(10) << left << "Notify" << endl;

				cout << setw(20) << left << ""
					 << setw(10) << arr_sounds[count].get_media_level()
					 << setw(10) << arr_sounds[count].get_call_level()
					 << setw(15) << arr_sounds[count].get_navi_level()
					 << setw(10) << arr_sounds[count].get_notification_level() << endl;
				break;
			}
		}

		//in data cua General
		for (int count = 0; count < settingCnt; count++)
		{
			if (arr_settings[i].getPersonalKey() == arr_generals[count].getPersonalKey())
			{
				cout << setw(20) << "General:" << setw(20) << "Timezone" << setw(50) << "Language" << endl;
				cout << setw(20) << left << ""
					 << setw(20) << arr_generals[count].get_timeZone()
					 << setw(50) << arr_generals[count].get_language() << endl;
				break;
			}
		}
		cout << endl
			 << endl;
	}
}

/*
* Function sort danh sach Setting bang personalKey
*/
bool comparatorSetting(Setting &setting1, Setting &setting2)
{
	return (setting1.getPersonalKey() < setting2.getPersonalKey());
}

/*
* Function sort danh sach Display bang personalKey
*/
bool comparatorDisplay(Display &display1, Display &display2)
{
	return ((display1).getPersonalKey() < (display2).getPersonalKey());
}

/*
* Function sort danh sach Sound bang personalKey
*/
bool comparatorSound(Sound &sound1, Sound &sound2)
{
	return ((sound1).getPersonalKey() < (sound2).getPersonalKey());
}

/*
* Function sort danh sach General bang personalKey
*/
bool comparatorGeneral(General &general1, General &general2)
{
	return ((general1).getPersonalKey() < (general2).getPersonalKey());
}

/*
* Function sort danh sach Timezone bang UTC
*/
bool comparatorTimezone(CommonInfo c1, CommonInfo c2)
{
	return (c1.getNumber() < c2.getNumber());
}

/*
* Function sort danh sach Language bang alphabet
*/
bool comparatorLanguage(CommonInfo c1, CommonInfo c2)
{
	return (c1.getName() < c2.getName());
}
