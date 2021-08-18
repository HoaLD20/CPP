#include <iostream>
#include "General.h"
#include <iostream>
#include "General.h"
#include "Display.h"
#include "Sound.h"
#include "CommonInfo.h"
#include "CheckValid.h"
#include <fstream>
#include <regex>

//khai bao object cua cac class
Display *display = new Display();
Sound *sound = new Sound();
Setting *setting = new Setting();

//declare vector contain object
vector<Display *> listDisplay;
vector<Sound *> listSound;
vector<General *> listGeneral;
vector<Setting *> listSetting;

//tao bien temp de luu tru list display, sound, general de thuc hien sort by name or personal key
vector<Display *> v_display_tmp;
vector<Sound *> v_sound_tmp;
vector<General *> v_general_tmp;

int position = 0;			 //danh dau vi tri xe trung
string languageT, timezoneT; //bien tmp chua timezone va language khi ng dung lua chon
int indexCar = 0;			 //dem so xe trong list
bool existKey = false;		 //khi nhao MSCN do co ton tai trong list thi in ra xe co mscn do ra o chuc nang print all
int existName = 0;			 //khi nhap name co ton tai trong list thi in nhung xe co ten do o chuc nang print all
vector<int> positionName;	 //giu vi tri cua nhung xe cung ten dc tim thay trong list o print all

vector<CommonInfo> timezoneList;
vector<CommonInfo> languageList;

void NhapThongTinCaiDat();
void XuatThongTinCaiDat();
//choice to sort by name or personal key
void chonSapXep();
//hien car group theo ten or personal key o lua chon hien all
void groupByNameOrKey();

void XuatThongTinCaiDat_Sound(vector<Sound *> v_sound_tmp);
void XuatThongTinCaiDat_General(vector<General *> v_general_tmp);
void XuatThongTinCaiDat_Display(vector<Display *> v_display_tmp);
void XuatThongTatCaTinCaiDat();

void NhapThongTinCaiDat_Sound();
void NhapThongTinCaiDat_General();
void NhapThongTinCaiDat_Display();

void downloadTimeZone();
void downloadLanguage();

void menu();
void readDataFromFile();
void seperateData(string line);
void writeDataToFile();

// Sort data by personnal key
bool comparatorDisplay(Display *display1, Display *display2);
bool comparatorSound(Sound *display1, Sound *display2);
bool comparatorGeneral(General *display1, General *display2);

// Sort data by car name
bool comparatorDisplayName(Display *display1, Display *display2);
bool comparatorSoundName(Sound *display1, Sound *display2);
bool comparatorGeneralName(General *display1, General *display2);

//sort timezone, language
bool comparatorTimezone(CommonInfo c1, CommonInfo c2);
bool comparatorLanguage(CommonInfo c1, CommonInfo c2);

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

		string data = "1 / Vietnamese";
		f << data;
		f.close();
	}
	else
	{
	}
	if (length_time == 0)
	{
		fstream f;
		f.open("timezones.txt", std::ios::in | std::ios::out | std::ios::app);

		string data = "(GMT+07:00) /  Bangkok, Hanoi, Jakarta";
		f << data;
		f.close();
	}
	else
	{
	}
	readDataFromFile(); //doc file setting.txt
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
		 << "3. Exit"
		 << endl
		 << "Your choice: ";
	do
	{
		selection = validInput("Your choice");
		switch (selection)
		{
		case 1:

			printf("\033c");
			NhapThongTinCaiDat();
			break;
		case 2:
			printf("\033c");
			XuatThongTinCaiDat();
			break;
		case 3:
			writeDataToFile();
			printf("\033c");
			cout << "Thanks for using this program" << endl;
			exit(0); //ket thuc chuong trinh
			break;
		default:
			cout << "Please enter your choice from 1-3. Re-enter: ";
			break;
		}
	} while (selection != 3);
}

//menu input display, sound, genaral
void NhapThongTinCaiDat()
{
	int selection;

	do
	{
		printf("\033c");
		cout << "--- SELECT MENU ---"
			 << endl
			 << "1. Display setting "
			 << endl
			 << "2. Sound setting "
			 << endl
			 << "3. General setting "
			 << endl
			 << "4. Back"
			 << endl
			 << "Your choice: ";
		selection = validInput("Your choose");
		switch (selection)
		{
		case 1:
			printf("\033c");
			NhapThongTinCaiDat_Display(); //nhap thon tin cho Display
			break;
		case 2:
			printf("\033c");
			NhapThongTinCaiDat_Sound(); //nhap thon tin cho Sound
			break;
		case 3:
			NhapThongTinCaiDat_General(); //nhap thon tin cho General

			printf("\033c");
			break;
		case 4:
			printf("\033c");
			menu(); //tro ve man hinh menu chinh
			break;
		default:
			printf("\033c");
			cout << "Please enter your choice from 1-4. " << endl;
			break;
		}
	} while (selection != 4);
}

//nhap thon tin cai dat cho Display
void NhapThongTinCaiDat_Display()
{

	do
	{
		printf("\033c");
		bool exist = false;

		cout << " --- Input Display setting --- " << endl;
		cout << "Car index: " << indexCar << endl;
		//neu nhap dc 100 car roi thi k cho nhap nua

		//nhap thong tin chung cho xe
		Setting st = setting->nhapThongTin();
		//check trung car
		for (int i = 0; i < listSetting.size(); i++)
		{
			if (st.getPersonalKey() == listSetting.at(i)->getPersonalKey())
			{
				exist = true;
				position = i; //lay vi tri cua xe trung de update
				break;
			}
		}

		//neu ma so ca nhan khong ton tai
		if (!exist)
		{

			cout << "	-> This is car, data will be appended to your list" << endl;

			//Add new Setting
			Setting *set = new Setting();
			set->updateSetting(st);
			listSetting.push_back(set);

			//Add new Display
			Display *dpl = new Display(st);
			dpl->nhapThongTin(st); //require user input data of Display
			listDisplay.push_back(dpl);

			//Add empty Sound and General
			listSound.push_back(new Sound(st));
			listGeneral.push_back(new General(st));
			indexCar++;
		}
		else
		{ //neu MSCN cua xe ton tai

			cout << "	-> This car already existed, data will be overriten" << endl;

			//Update data cua Setting list tai position trung
			listSetting.at(position)->updateSetting(st);

			//nhap thong tin cho Display va update data cua Display list
			listDisplay.at(position)->nhapThongTin(st);
			listSound.at(position)->updateSound(st);
			listGeneral.at(position)->updateGeneral(st);
		}

	} while (isInputNewCar(listGeneral.size()));
}

//nhap thong tin cho Sound
void NhapThongTinCaiDat_Sound()
{
	string personalKey; //MSCN

	do
	{
		printf("\033c");
		bool exist = false;
		cout << " --- Input Sound setting --- " << endl;
		cout << "Car index: " << indexCar << endl;

		//nhap thong tin chung cho xe
		Setting st = setting->nhapThongTin();
		for (int i = 0; i < listSetting.size(); i++)
		{
			if (st.getPersonalKey() == listSetting.at(i)->getPersonalKey())
			{
				exist = true;
				position = i; //lay vi tri cua xe trung de update
				break;
			}
		}
		//neu ma so ca nhan khong ton tai
		if (!exist)
		{

			cout << "	-> This is car, data will be appended to you list\n";
			//Add new Setting
			Setting *set = new Setting();
			set->updateSetting(st);
			listSetting.push_back(set);

			//Add new Sound
			Sound *s = new Sound(st);
			s->nhapThongTin(st); //require user input data of Sound
			listSound.push_back(s);

			//Add empty Display and General
			listDisplay.push_back(new Display(st));
			listGeneral.push_back(new General(st));
			indexCar++;
		}
		else
		{ //neu MSCN cua xe ton tai
			cout << "	-> This car already existed, data will be overriten" << endl;

			//Update data of Setting list tai vi tri trung
			listSetting.at(position)->updateSetting(st);

			//nhao thong tin cho Sound and update data of Sound list tai vi tri trung position
			//Require user input data for Sound and update data of Sound list
			listSound.at(position)->nhapThongTin(st);
			listDisplay.at(position)->updateDisplay(st);
			listGeneral.at(position)->updateGeneral(st);
		}
	} while (isInputNewCar(listGeneral.size()));
}

//nhap thong tin cai dat cho General
void NhapThongTinCaiDat_General()
{
	string personalKey; //MSCN

	do
	{
		printf("\033c");
		bool exist = false;
		cout << " --- Input General setting --- " << endl;
		cout << "Car index: " << indexCar << endl;

		//nhap thong tin chung cho xe
		Setting st = setting->nhapThongTin();
		for (int i = 0; i < listSetting.size(); i++)
		{
			if (st.getPersonalKey() == listSetting.at(i)->getPersonalKey())
			{
				exist = true;
				position = i; //lay vi tri cua xe trung de update
				break;
			}
		}
		//neu ma so ca nhan khong ton tai
		if (!exist)
		{

			cout << "	-> This is car, data will be appended to your list" << endl;

			//Add new Setting
			Setting *set = new Setting();
			set->updateSetting(st);
			listSetting.push_back(set);

			//chon language
			downloadLanguage(); //hien list language cho ng dung chon

			//chon timezone
			downloadTimeZone(); //hien list timezone cho ng dung chon

			General *general = new General();
			general->set_language(languageT); //set language de luc print ra thi dung get language
			general->set_timeZone(timezoneT);
			general->nhapThongTin(st, timezoneT, languageT); //require user input data of General
			listGeneral.push_back(general);

			//Add empty Display and Sound
			listDisplay.push_back(new Display(st));
			listSound.push_back(new Sound(st));
			indexCar++;
		}
		else
		{ //neu MSCN cua xe ton tai

			cout << "	-> This car already existed, data will be overriten" << endl;

			//Update data of Setting list
			listSetting.at(position)->updateSetting(st);

			downloadLanguage(); //hien list language cho ng dung chon
			//choose timezone
			downloadTimeZone(); //hien list timezone cho ng dung chon

			listGeneral.at(position)->nhapThongTin(st, timezoneT, languageT);
			listDisplay.at(position)->updateDisplay(st);
			listSound.at(position)->updateSound(st);
		}

	} while (isInputNewCar(listGeneral.size()));
}

//xuat thong tin cai dat cho xe
void XuatThongTinCaiDat()
{

	int selection; //lua chon menu

	do
	{

		//tao bien tam luu truc list cua sound, display general de thuc hien sort theo ten hoac MSCN
		v_display_tmp = listDisplay;
		v_sound_tmp = listSound;
		v_general_tmp = listGeneral;

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
			 << "5. Back"
			 << endl
			 << "Your choice: ";
		selection = validInput("Your choose");
		switch (selection)
		{
		case 1:
			printf("\033c");
			chonSapXep();							   //chon sx theo ten hay mscn
			XuatThongTinCaiDat_Display(v_display_tmp); //xuat thong tin cai dat cho Display
			cout << endl
				 << "Press Enter to continue...";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			printf("\033c");
			break;
		case 2:
			printf("\033c");
			chonSapXep();						   //chon sx theo ten hay mscn
			XuatThongTinCaiDat_Sound(v_sound_tmp); //xuat thong tin cai dat cho Sound
			cout << endl
				 << "Press Enter to continue...";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			printf("\033c");
			break;
		case 3:
			printf("\033c");
			chonSapXep();							   //chon sx theo ten hay mscn
			XuatThongTinCaiDat_General(v_general_tmp); //xuat thong tin cai dat cho General
			cout << endl
				 << "Press Enter to continue...";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			printf("\033c");
			break;
		case 4:
			printf("\033c");
			groupByNameOrKey();		   //chon in all theo ten hay mscn
			XuatThongTatCaTinCaiDat(); //xuat tat ca thong tin cai dat
			cout << endl
				 << "Press Enter to continue...";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			printf("\033c");
			break;
		case 5:
			printf("\033c");
			menu(); //tro ve man hinh menu
			break;
		default:
			printf("\033c");
			cout << "Please enter your choice from 1-4. " << endl;
			break;
		}
	} while (selection != 5);
}

//lua chon sx theo name or MSCN
void chonSapXep()
{
	int selection;

	cout << "--- SELECT MENU ---"
		 << endl
		 << "1. Sort by personal identification number "
		 << endl
		 << "2. Sort by car owner "
		 << endl
		 << "3. Exit "
		 << endl
		 << "Your choice: ";
	selection = validInput();
	switch (selection)
	{
	case 1:

		printf("\033c");
		//sort array de in ra danh sach theo MSCN
		sort(v_display_tmp.begin(), v_display_tmp.end(), comparatorDisplay);
		sort(v_sound_tmp.begin(), v_sound_tmp.end(), comparatorSound);
		sort(v_general_tmp.begin(), v_general_tmp.end(), comparatorGeneral);

		printf("\033c");
		break;
	case 2:

		printf("\033c");
		//sort array de in ra danh sach theo name
		sort(v_display_tmp.begin(), v_display_tmp.end(), comparatorDisplayName);
		sort(v_sound_tmp.begin(), v_sound_tmp.end(), comparatorSoundName);
		sort(v_general_tmp.begin(), v_general_tmp.end(), comparatorGeneralName);

		printf("\033c");
		break;
	case 3:

		printf("\033c");
		XuatThongTinCaiDat(); //tro ve man hinh menu
		break;
	default:

		printf("\033c");
		cout << "Please enter your choice from 1-3. " << endl;
		break;
	}
}

//lua chon group by name or MSCN
void groupByNameOrKey()
{
	int selection;
	string name;
	string key;
	existKey = false;
	existName = 0;
	cout << "--- SELECT MENU ---"
		 << endl
		 << "1. Group by personal identification number "
		 << endl
		 << "2. Group by car owner "
		 << endl
		 << "3. Exit "
		 << endl
		 << "Your choice: ";
	selection = validInput();
	switch (selection)
	{
	case 1: //tim mscn

		printf("\033c");

		//nhap cho toi khi tim co mscn trong list thi dung de im ra thong tin
		do
		{
			//khoi tao gia tri cho mscn k dc tim thay trong list
			existKey = false;
			cout << "Key number: "; //nhap personal key cho xe
			key = validKey();

			for (int i = 0; i < listSetting.size(); i++)
			{
				if (key == listSetting.at(i)->getPersonalKey())
				{
					existKey = true; //dc tim thay trong list
					position = i;	 //lay vi tri cua xe trung de print all
					break;
				}
			}
			if (!existKey)
			{
				cout << "Personal key is not exist" << endl;
			}
		} while (!existKey);

		printf("\033c");
		break;
	case 2: //tim ten xe

		printf("\033c");

		//nhap cho toi khi tim co name trong list thi dung de im ra thong tin
		do
		{
			existName = 0;
			positionName.clear(); //xoa du lieu trong vector khi thuc hien goi lai ham
			//nhap car name
			cout << "Owner name: ";
			name = validCarName();

			for (int i = 0; i < listSetting.size(); i++)
			{
				if (name == listSetting.at(i)->getCarName())
				{
					existName++; //dc tim thay trong list
					//gan vi tri cua nhung xe trung ten vao trong vector positionName, de thuc hien in all nhung xe cung ten
					positionName.push_back(i);
				}
			}
			if (existName == 0)
			{
				cout << "Owner name is not exist" << endl;
			}
		} while (existName == 0);

		printf("\033c");
		break;
	case 3:

		printf("\033c");
		XuatThongTinCaiDat(); //tro ve man hinh menu
		break;
	default:

		printf("\033c");
		cout << "Please enter your choice from 1-3. " << endl;
		break;
	}
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
	try
	{
		f.open("timezones.txt"); // mo va doc data tu file languages.txt

		if (!f.is_open()) //neu file k ton tai thi show thong bao loi
		{
			cout << "Fail open file timezones";
			//system("pause");
			cout << endl
				 << "Press Enter to continue...";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else
		{

			//doc file la language cho ng dung chon
			cout << "----- SELECT TIMEZONES DATA -----" << endl;
			if (timezoneList.size() == 0)
			{
				while (!f.eof())
				{
					getline(f, str);				 //doc file
					data_vector = explode(str, '/'); //cat cuoi dua vao dau ')'
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
					 << item.getNumber() + item.getName() << "\n"; //in data trong file ra man hinh
			}

			//nhap lua chon cho Timezone
			cout << "YOUR SELECTION: ";
			selection = validTimezones();

			//hien lua chon ra man hình
			cout << "	Timezone: " << timezoneList[selection - 1].getNumber() << endl;
			//gan Timezone vao timezoneT de hien Timezone o chuc nang General Setting
			timezoneT = timezoneList[selection - 1].getNumber();

			
		}
	}
	catch (const std::exception &e)
	{
		cerr << e.what() << '\n';
		cerr << "Exception occur when open file!" << endl;
	}
	f.close();
	//system("pause");
	cout << endl
		 << "Press Enter to continue...";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

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
	try
	{
		f.open("languages.txt"); // mo va doc data tu file languages.txt

		if (!f.is_open()) //neu file k ton tai thi show thong bao loi
		{
			cout << "Fail open file languages";
			//system("pause");
			cout << endl
				 << "Press Enter to continue...";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
			//gan language vao languageT de hien language o chuc nang General Setting
			languageT = languageList[selection - 1].getName();
		}
	}
	catch (const std::exception &e)
	{
		cerr << e.what() << '\n';
		cerr << "Exception occur when open file!" << endl;
	}

	f.close();
	//system("pause");
	cout << endl
		 << "Press Enter to continue...";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	printf("\033c");
}

//xuat thong tin cho Display
void XuatThongTinCaiDat_Display(vector<Display *> v_display_tmp)
{

	cout << setw(30) << left << "Owner name"
		 << setw(35) << left << "Email"
		 << setw(15) << left << "Key number"
		 << setw(15) << left << "ODO number"
		 << setw(25) << left << "Remind Service (km)"
		 << setw(15) << left << "Light level"
		 << setw(20) << left << "Screen light level"
		 << setw(15) << left << "Taplo level" << endl;

	//left: đặt feild điều chỉnh sang trái
	//in ra tung thong tin cua Display trog arr
	for (int i = 0; i < listSetting.size(); i++)
	{
		cout << setw(30) << left << v_display_tmp.at(i)->getCarName()
			 << setw(35) << left << v_display_tmp.at(i)->getEmail()
			 << setw(15) << left << v_display_tmp.at(i)->getPersonalKey()
			 << setw(15) << left << v_display_tmp.at(i)->getODO()
			 << setw(25) << left << v_display_tmp.at(i)->getServiceRemind()
			 << setw(15) << left << v_display_tmp.at(i)->get_light_level()
			 << setw(20) << left << v_display_tmp.at(i)->get_screen_light_level()
			 << setw(15) << left << v_display_tmp.at(i)->get_taplo_light_level() << endl;
	}
}

//xuat thong tin cai dat cua Sound
void XuatThongTinCaiDat_Sound(vector<Sound *> v_sound_tmp)
{
	cout << setw(30) << left << "Owner name"
		 << setw(35) << left << "Email"
		 << setw(15) << left << "Key number"
		 << setw(15) << left << "ODO number"
		 << setw(25) << left << "Remind Service (km)"
		 << setw(10) << left << "Media"
		 << setw(10) << left << "Call"
		 << setw(10) << left << "Navi"
		 << setw(10) << left << "Notify" << endl;

	//in ra tung thong tin cua Soundtrog arr
	for (int i = 0; i < listSetting.size(); i++)
	{
		cout << setw(30) << left << v_sound_tmp.at(i)->getCarName()
			 << setw(35) << left << v_sound_tmp.at(i)->getEmail()
			 << setw(15) << left << v_sound_tmp.at(i)->getPersonalKey()
			 << setw(15) << left << v_sound_tmp.at(i)->getODO()
			 << setw(25) << left << v_sound_tmp.at(i)->getServiceRemind()
			 << setw(10) << left << v_sound_tmp.at(i)->get_media_level()
			 << setw(10) << left << v_sound_tmp.at(i)->get_call_level()
			 << setw(10) << left << v_sound_tmp.at(i)->get_navi_level()
			 << setw(10) << left << v_sound_tmp.at(i)->get_notification_level()
			 << endl;
	}
}

//xuat thong tin cai dat cua General
void XuatThongTinCaiDat_General(vector<General *> v_general_tmp)
{
	cout << setw(30) << left << "Owner name"
		 << setw(35) << left << "Email"
		 << setw(15) << left << "Key number"
		 << setw(15) << left << "ODO number"
		 << setw(25) << left << "Remind Service (km)"
		 << setw(20) << left << "TimeZone"
		 << setw(50) << left << "Language" << endl;

	//in ra tung thong tin cua General trog arr
	for (int i = 0; i < listSetting.size(); i++)
	{

		cout << setw(30) << left << v_general_tmp.at(i)->getCarName()
			 << setw(35) << left << v_general_tmp.at(i)->getEmail()
			 << setw(15) << left << v_general_tmp.at(i)->getPersonalKey()
			 << setw(15) << left << v_general_tmp.at(i)->getODO()
			 << setw(25) << left << v_general_tmp.at(i)->getServiceRemind()
			 << setw(20) << left << "GMT" + v_general_tmp.at(i)->get_timeZone()
			 << setw(50) << left << v_general_tmp.at(i)->get_language() << endl;
	}
}

//xuat tat ca thogn tin cai dat cau xe
void XuatThongTatCaTinCaiDat()
{
	int dem = 0; // so thu tu cho xe hien ra
	cout << "--- All setting ---" << endl;
	//neu tim dc xe co mscn trung voi mscn nhap vao thi in xe do ra
	if (existKey)
	{
		//in ra toan bo thong tin cua xe
		//in data cua Setting
		cout << setw(10) << left << "1" << setw(30) << left << "Owner name" << setw(35) << left << "Email" << setw(20) << left << "Key number" << setw(20) << left << "ODO number" << setw(25) << left << "Remind Service (km)" << endl;
		cout << setw(10) << left << ""
			 << setw(30) << left << listDisplay.at(position)->getCarName()
			 << setw(35) << left << listDisplay.at(position)->getEmail()
			 << setw(20) << left << listDisplay.at(position)->getPersonalKey()
			 << setw(20) << left << listDisplay.at(position)->getODO()
			 << setw(25) << left << listDisplay.at(position)->getServiceRemind() << endl;

		//in data cua Display
		cout << setw(20) << left << "Display:" << setw(15) << "Light level" << setw(20) << "Screen Light level" << setw(15) << "Taplo Light" << endl;
		cout << setw(20) << left << ""
			 << setw(15) << listDisplay.at(position)->get_light_level()
			 << setw(20) << listDisplay.at(position)->get_screen_light_level()
			 << setw(15) << listDisplay.at(position)->get_taplo_light_level() << endl;

		//in data cua Sound
		cout << setw(20) << left << "Sound:" << setw(10) << left << "Media" << setw(10) << left << "Call" << setw(15) << left << "Navigation" << setw(10) << left << "Notify" << endl;
		cout << setw(20) << left << ""
			 << setw(10) << listSound.at(position)->get_media_level()
			 << setw(10) << listSound.at(position)->get_call_level()
			 << setw(15) << listSound.at(position)->get_navi_level()
			 << setw(10) << listSound.at(position)->get_notification_level() << endl;

		//in data cua General
		cout << setw(20) << "General:" << setw(20) << "Timezone" << setw(50) << "Language" << endl;
		cout << setw(20) << left << ""
			 << setw(20) << "GMT" + listGeneral.at(position)->get_timeZone()
			 << setw(50) << listGeneral.at(position)->get_language() << endl;

		cout << endl
			 << endl;
	}

	//neu tim dc xe co ten trung voi ten nhap vao thi in toan bo nhung xe do ra
	if (existName != 0)
	{
		//in ra toan bo thong tin cua tung xe
		vector<int>::iterator it = positionName.begin();
		for (; it != positionName.end(); it++)
		{

			//in data cua Setting
			cout << setw(10) << left << ++dem << setw(30) << left << "Owner name" << setw(35) << left << "Email" << setw(20) << left << "Key number" << setw(20) << left << "ODO number" << setw(25) << left << "Remind Service (km)" << endl;
			cout << setw(10) << left << ""
				 << setw(30) << left << listDisplay.at(*it)->getCarName()
				 << setw(35) << left << listDisplay.at(*it)->getEmail()
				 << setw(20) << left << listDisplay.at(*it)->getPersonalKey()
				 << setw(20) << left << listDisplay.at(*it)->getODO()
				 << setw(25) << left << listDisplay.at(*it)->getServiceRemind() << endl;

			//in data cua Display
			cout << setw(20) << left << "Display:" << setw(15) << "Light level" << setw(20) << "Screen Light level" << setw(15) << "Taplo Light" << endl;
			cout << setw(20) << left << ""
				 << setw(15) << listDisplay.at(*it)->get_light_level()
				 << setw(20) << listDisplay.at(*it)->get_screen_light_level()
				 << setw(15) << listDisplay.at(*it)->get_taplo_light_level() << endl;

			//in data cua Sound
			cout << setw(20) << left << "Sound:" << setw(10) << left << "Media" << setw(10) << left << "Call" << setw(15) << left << "Navigation" << setw(10) << left << "Notify" << endl;
			cout << setw(20) << left << ""
				 << setw(10) << listSound.at(*it)->get_media_level()
				 << setw(10) << listSound.at(*it)->get_call_level()
				 << setw(15) << listSound.at(*it)->get_navi_level()
				 << setw(10) << listSound.at(*it)->get_notification_level() << endl;

			//in data cua General
			cout << setw(20) << "General:" << setw(20) << "Timezone" << setw(50) << "Language" << endl;
			cout << setw(20) << left << ""
				 << setw(20) << "GMT" + listGeneral.at(*it)->get_timeZone()
				 << setw(50) << listGeneral.at(*it)->get_language() << endl;

			cout << endl
				 << endl;
		}
	}
}

//doc file setting.txt
void readDataFromFile()
{
	//declare file stream  de doc file
	ifstream file_in;
	string line; //chua noi dung khi doc tu file
	bool haveData = false;

	// tach chuoi tu hang moi doc va add vao list
	try
	{
		// Open file setting.txt
		file_in.open("Setting.txt");

		// ktra xem file co mo hay khong
		if (file_in.is_open())
		{
			// doc moi hang trong file
			while (!file_in.eof())
			{
				// lay hang data trong file
				getline(file_in, line);
				indexCar++;
				haveData = true;
				// tach chuoi tu hang moi doc va add vao list
				seperateData(line);
			}
		}
		//neu k co data trong file thi indexcar bat dau la 2, dem len tren -1 la 1
		//if (!haveData) indexCar=2;
	}
	catch (...) // Throw message when occur error during read file
	{
		cerr << "Exception occur when open file!" << endl;
	}
}

//tach chuoi sau khi doc data tu trong file, de lay du lieu cho Display, General, Sound va bo vao list
void seperateData(string line)
{

	int count = 0;
	string car_name, email, personal_key, odo, service_remind;

	// tach thanh tung chuoi trong hang moi doc duoc tu trong file bang dau '/' va luu tru rong vector
	vector<string> dataLine = explode(line, '/');
	for (int i = 0; i < dataLine.size(); i++)
	{
		//tach chuoi dua vao dau ':' de phan loai display, general,setting, sound
		vector<string> subData = explode(dataLine[i], '_');

		// The case is Setting
		if (subData[0] == "Setting")
		{
			//tach chuoi de lay dc data cho tung loai Display, sound, general, setting
			vector<string> dataDetail = explode(subData[1], ',');

			//khai bao variable of Setting

			// gan data vao bien de luu vao list
			car_name = dataDetail[0];
			email = dataDetail[1];
			personal_key = dataDetail[2];
			odo = dataDetail[3];
			service_remind = dataDetail[4];

			// Add data vao list Setting
			Setting *st = new Setting(car_name, personal_key, email, stoi(odo), stoi(service_remind));
			listSetting.push_back(st);

			//lay index sau khi add data vao list setting
			count = listSetting.size() - 1;

			// Add new empty Sound, Display, General vao List
			listSound.push_back(new Sound());
			listDisplay.push_back(new Display());
			listGeneral.push_back(new General());
		}
		else if (subData[0] == "Display") // The case is Display
		{
			vector<string> dataDetail = explode(subData[1], ',');
			Setting st = Setting(car_name, personal_key, email, stoi(odo), stoi(service_remind));
			// Update data to Display list tai vi tri vua add setting (count)
			// thu tu data cua Display: light level-[0], screen level-[1], taplo level-[2]
			listDisplay.at(count)->updateDisplay(st, stoi(dataDetail[0]), stoi(dataDetail[1]), stoi(dataDetail[2]));
			//displayCount++;
		}
		else if (subData[0] == "Sound") // The case is Sound
		{
			vector<string> dataDetail = explode(subData[1], ',');
			// Get Setting
			Setting st = Setting(car_name, personal_key, email, stoi(odo), stoi(service_remind));

			// Update data to Sound list tai vi tri vua add setting (count)
			// thu tu data cua Sound: media level-[0], call level-[1], navi level-[2], notification level-[3]
			listSound.at(count)->updateSound(st, stoi(dataDetail[0]), stoi(dataDetail[1]), stoi(dataDetail[2]), stoi(dataDetail[3]));
			//soundCount++;
		}
		else if (subData[0] == "General") // The case is General
		{
			vector<string> dataDetail = explode(subData[1], ',');
			// Get Setting
			Setting st = Setting(car_name, personal_key, email, stoi(odo), stoi(service_remind));

			// Update data to General list
			// thu tu data cua general: timeZone-[0], language-[1]
			listGeneral.at(count)->updateGeneral(st, dataDetail[0], dataDetail[1]);
			//generalCount++;
		}
	}
}

/*
* The function to write data to file
*/
void writeDataToFile()
{

	//khai bao bien cua file
	ofstream f;

	//chuoi chua fotmat de luu vao file
	string format;

	//write file
	try
	{
		// open txt file
		f.open("Setting.txt");

		// write data cua Display, setting, sound, general voa file Setting.txt
		for (int i = 0; i < listSetting.size(); i++)
		{
			// lay du lieu cua Setting de noi thanh 1 chuoi luu vao file
			format = "Setting_" + listSetting.at(i)->formatTypeSetting() + "/";

			// lay du lieu cua Display de noi thanh 1 chuoi luu vao file
			format += "Display_" + listDisplay.at(i)->formatTypeDisplay() + "/";

			// lay du lieu cua Sound de noi thanh 1 chuoi luu vao file
			format += "Sound_" + listSound.at(i)->formatTypeSound() + "/";

			// lay du lieu cua General de noi thanh 1 chuoi luu vao file
			format += "General_" + listGeneral.at(i)->formatTypeGeneral() + "/";

			// Write data vao file
			f << format + "\n";
		}

		// close file
		f.close();
	}
	catch (...) // Throw message when occur error during write file
	{
		cout << "Exception occur when save file!";
	}
}

/*
* The function to sort list Display by personalKey
*/
bool comparatorDisplay(Display *display1, Display *display2)
{
	return ((*display1).getPersonalKey() < (*display2).getPersonalKey());
}

/*
* The function to sort list Sound by personalKey
*/
bool comparatorSound(Sound *sound1, Sound *sound2)
{
	return ((*sound1).getPersonalKey() < (*sound2).getPersonalKey());
}

/*
* The function to sort list General by personalKey
*/
bool comparatorGeneral(General *general1, General *general2)
{
	return ((*general1).getPersonalKey() < (*general2).getPersonalKey());
}

/*
* The function to sort list Display by name
*/
bool comparatorDisplayName(Display *display1, Display *display2)
{
	return ((*display1).getCarName() < (*display2).getCarName());
}

/*
* The function to sort list Sound by name
*/
bool comparatorSoundName(Sound *sound1, Sound *sound2)
{
	return ((*sound1).getCarName() < (*sound2).getCarName());
}

/*
* The function to sort list General by name
*/
bool comparatorGeneralName(General *general1, General *general2)
{
	return ((*general1).getCarName() < (*general2).getCarName());
}

/*
* Function sort danh sach Timezone bang UTC
*/
// bool comparatorTimezone(CommonInfo c1, CommonInfo c2)
// {
// 	c1.getNumber().replace(3, 1, ",");					  //replace vị tri thu 3 trong chuoi +13:00 de thay dau : thanh dau ,
// 	c2.getNumber().replace(3, 1, ",");					  //replace vị tri thu 3 trong chuoi +13:00 de thay dau : thanh dau ,
// 	return (stoi(c1.getNumber()) < stoi(c2.getNumber())); //so sanh theo so
// }
bool comparatorTimezone(CommonInfo c1, CommonInfo c2)
{
	return (c1.getNumber() > c2.getNumber());
}

/*
* Function sort danh sach Language bang alphabet
*/
bool comparatorLanguage(CommonInfo c1, CommonInfo c2)
{
	return (c1.getName() < c2.getName());
}
