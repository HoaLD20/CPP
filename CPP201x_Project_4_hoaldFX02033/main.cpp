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
#include "BinaryTree.h"
#include <set>

// Declare binary tree
BinaryTree *treeDisplay = new BinaryTree;
BinaryTree *treeSound = new BinaryTree;
BinaryTree *treeGeneral = new BinaryTree;

//khai bao object cua cac class
Display *display = new Display();
Sound *sound = new Sound();
Setting *setting = new Setting();

//Type to show data, show theo display, sound hay general
//so 1 thi vo case 1: display, so 2 thi vo case 2: sound, so 3 thi vo case 3:general
int displayType = 1, soundType = 2, generalType = 3, settingType = 4;
string languageT, timezoneT; //bien tmp chua timezone va language khi ng dung lua chon
int indexCar = 0;			 //dem so xe trong tree

vector<CommonInfo> timezoneList;
vector<CommonInfo> languageList;

void NhapThongTinCaiDat();
void XuatThongTinCaiDat();
//choice to sort by name or personal key
void chonSapXep_XuatThongTinCaiDat(string str);
//hien car group theo ten or personal key o lua chon hien all
void groupByNameOrKey();
void XuatThongTatCaTinCaiDat(Node *resultDisplay, Node *resultSound, Node *resultGeneral);

void NhapThongTinCaiDat_Sound();
void NhapThongTinCaiDat_General();
void NhapThongTinCaiDat_Display();

void downloadTimeZone();
void downloadLanguage();

void menu();
void readDataFromFile();
void seperateData(string line);
void writeDataToFile();
bool isKeyExisted(Node *node);

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
	printf("\033c");
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

		string data = "1 / Mandarin (entire branch)\n2 /Spanish\n3 / English\n4 / Hindi\n5 / Arabic\n6 / Portuguese\n7 / Bengali\n8 / Russian\n9 / Japanese\n10 / Punjabi\n11 / German\n12 / Javanese\n13 / Wu(inc.Shanghainese)\n14 / Malay(inc.Indonesian and Malaysian)\n15 / Telugu\n16 / Vietnamese\n17 / Korean\n18 / French\n19 / Marathi\n20 / Tamil\n21 / Urdu\n22 / Turkish\n23 / Italian\n24 / Yue(inc.Cantonese)\n25 / Thai\n26 / Gujarati\n27 / Jin\n28 / Southern Min\n29 / Persian\n30 / Polish\n ";
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
	readDataFromFile(); //doc file setting.txt
	menu();
	return 0;
}

/*
* kiem tra key or name nguoi dung nhap vao co ton tai hay k
*/
bool isKeyExisted(Node *node)
{

	// Check node co ton tai hay khong, co ton tai
	if (node != NULL)
	{
		return true;
	}

	//neu key khong ton tai
	return false;
}

//menu chinh
void menu()
{

	int selection = 0;

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
	{ //nhap thong tin cho xe tiep theo hay khong

		printf("\033c");
		cout << " --- Input Display setting --- " << endl;
		cout << "Car index: " << indexCar << endl;

		//nhap thong tin chung cho xe
		Setting st = setting->nhapThongTin();

		// khoi tao Display, truyen vo st la thong tin chung
		Display *dpl = new Display(st);

		// tim key ng dung trong tree Display xem co ton tai chua
		Node *nodeDisplay = treeDisplay->searchByPersonalKey(st.getPersonalKey());

		// tim kim mscn tren tree Display, Sound de thuc hien update khi trung
		Node *nodeSound = treeSound->searchByPersonalKey(st.getPersonalKey());
		Node *nodeGeneral = treeGeneral->searchByPersonalKey(st.getPersonalKey());

		//neu ma so ca nhan khong ton tai, nodeDisplay la mscn dc tim thay trong tree Display
		if (!isKeyExisted(nodeDisplay))
		{

			cout << "	-> This is car, data will be appended to your list" << endl;

			//Add new Display
			dpl->nhapThongTin(st);	  //require user input data of Display
			treeDisplay->insert(dpl); //insert dpl vao cay treeDisplay

			//Add empty Sound and General
			treeSound->insert(new Sound(st));
			treeGeneral->insert(new General(st));
			indexCar++; //so luong xe
		}
		else
		{ //neu MSCN cua xe ton tai

			cout << "	-> This car already existed, data will be overriten" << endl;

			//Update setting cho sound, display, general tai mscn tim thay trong tree
			nodeSound->data->updateSetting(st);
			nodeDisplay->data->updateSetting(st);
			nodeGeneral->data->updateSetting(st);

			// Input data cho display
			dpl->nhapThongTin(st);
			//update thong tin cho nut trong cay display
			//ep kieu node qua display de update thong tin cua display
			dynamic_cast<Display *>(nodeDisplay->data)->updateDisplay(st, dpl->get_light_level(), dpl->get_screen_light_level(), dpl->get_taplo_light_level());
		}

	} while (isInputNewCar(indexCar - 1));
}

//nhap thong tin cho Sound
void NhapThongTinCaiDat_Sound()
{
	do
	{ //nhap thong tin cho xe tiep theo hay khong

		printf("\033c");
		cout << " --- Input Sound setting --- " << endl;
		cout << "Car index: " << indexCar << endl;

		//nhap thong tin chung cho xe
		Setting st = setting->nhapThongTin();

		// khoi tao Sound, truyen vo st la thong tin chung
		Sound *s = new Sound(st);

		// tim key ng dung trong tree Sound
		Node *nodeSound = treeSound->searchByPersonalKey(st.getPersonalKey());

		// tim kim mscn tren tree Display, General de thuc hien update khi trung
		Node *nodeDisplay = treeDisplay->searchByPersonalKey(st.getPersonalKey());
		Node *nodeGeneral = treeGeneral->searchByPersonalKey(st.getPersonalKey());

		//neu ma so ca nhan khong ton tai, nodeDisplay la mscn dc tim thay trong tree Display
		if (!isKeyExisted(nodeSound))
		{

			cout << "	-> This is car, data will be appended to your list" << endl;

			//Add new Display
			s->nhapThongTin(st);  //require user input data of Display
			treeSound->insert(s); //insert dpl vao cay treeDisplay

			//Add empty Sound and General
			treeDisplay->insert(new Display(st));
			treeGeneral->insert(new General(st));
			indexCar++; //so luong xe
		}
		else
		{ //neu MSCN cua xe ton tai

			cout << "	-> This car already existed, data will be overriten" << endl;

			//Update setting cho sound, display, general tai mscn tim thay trong tree
			nodeSound->data->updateSetting(st);
			nodeDisplay->data->updateSetting(st);
			nodeGeneral->data->updateSetting(st);

			// Input data cho display
			s->nhapThongTin(st);
			//update thong tin cho display
			dynamic_cast<Sound *>(nodeSound->data)->updateSound(st, s->get_media_level(), s->get_call_level(), s->get_navi_level(), s->get_notification_level());
		}

	} while (isInputNewCar(indexCar - 1));
}

//nhap thong tin cai dat cho General
void NhapThongTinCaiDat_General()
{

	do
	{
		printf("\033c");
		cout << " --- Input General setting --- " << endl;
		cout << "Car index: " << indexCar << endl;

		//nhap thong tin chung cho xe
		Setting st = setting->nhapThongTin();

		//khoi tao General
		General *g = new General(st);

		// tim key ng dung trong tree General
		Node *nodeGeneral = treeGeneral->searchByPersonalKey(st.getPersonalKey());

		// tim kim mscn tren tree Display, Sound de thuc hien update khi trung
		Node *nodeSound = treeSound->searchByPersonalKey(st.getPersonalKey());
		Node *nodeDisplay = treeDisplay->searchByPersonalKey(st.getPersonalKey());

		//neu ma so ca nhan khong ton tai
		if (!isKeyExisted(nodeGeneral))
		{

			cout << "	-> This is car, data will be appended to your list" << endl;

			//chon language
			downloadLanguage(); //hien list language cho ng dung chon

			//chon timezone
			downloadTimeZone(); //hien list timezone cho ng dung chon

			g->set_language(languageT); //set language de luc print ra thi dung get language
			g->set_timeZone(timezoneT);
			g->nhapThongTin(st, timezoneT, languageT); //require user input data of General
			treeGeneral->insert(g);

			//Add empty Display and Sound
			treeDisplay->insert(new Display(st));
			treeSound->insert(new Sound(st));
			indexCar++;
		}
		else
		{ //neu MSCN cua xe ton tai

			cout << "	-> This car already existed, data will be overriten" << endl;

			//Update setting
			nodeSound->data->updateSetting(st);
			nodeDisplay->data->updateSetting(st);
			nodeGeneral->data->updateSetting(st);

			downloadLanguage(); //hien list language cho ng dung chon
			//choose timezone
			downloadTimeZone(); //hien list timezone cho ng dung chon

			g->nhapThongTin(st, timezoneT, languageT);
			dynamic_cast<General *>(nodeGeneral->data)->updateGeneral(st, g->get_timeZone(), g->get_language());
		}

	} while (isInputNewCar(indexCar - 1));
}

//xuat thong tin cai dat cho xe
void XuatThongTinCaiDat()
{

	int selection; //lua chon menu

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
			 << "5. Back"
			 << endl
			 << "Your choice: ";
		selection = validInput("Your choose");
		switch (selection)
		{
		case 1:
			printf("\033c");
			chonSapXep_XuatThongTinCaiDat("display"); //chon sx theo ten hay mscn
			//system("pause");
			cout << endl
				 << "Press Enter to continue...";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			printf("\033c");
			break;
		case 2:
			printf("\033c");
			chonSapXep_XuatThongTinCaiDat("sound"); //chon sx theo ten hay mscn
			//system("pause");
			cout << endl
				 << "Press Enter to continue...";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			printf("\033c");
			break;
		case 3:
			printf("\033c");
			chonSapXep_XuatThongTinCaiDat("general"); //chon sx theo ten hay mscn
			//system("pause");
			cout << endl
				 << "Press Enter to continue...";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			printf("\033c");
			break;
		case 4:
			printf("\033c");
			groupByNameOrKey(); //chon in all theo ten hay mscn va in ra all thong tin
			//system("pause");
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
void chonSapXep_XuatThongTinCaiDat(string str)
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
	case 1: //sort de in ra danh sach theo MSCN
		printf("\033c");

		if (str == "display")
		{ //neu chon case la display thi in ra display
			cout << setw(30) << left << "Owner name"
				 << setw(35) << left << "Email"
				 << setw(15) << left << "Key number"
				 << setw(15) << left << "ODO number"
				 << setw(25) << left << "Remind Service (km)"
				 << setw(15) << left << "Light level"
				 << setw(20) << left << "Screen light level"
				 << setw(15) << left << "Taplo level" << endl;
			treeDisplay->printTree(displayType); //in ra display theo in order tree
		}
		else if (str == "sound")
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
			treeSound->printTree(soundType);
		}
		else if (str == "general")
		{
			cout << setw(30) << left << "Owner name"
				 << setw(35) << left << "Email"
				 << setw(15) << left << "Key number"
				 << setw(15) << left << "ODO number"
				 << setw(25) << left << "Remind Service (km)"
				 << setw(20) << left << "TimeZone"
				 << setw(50) << left << "Language" << endl;
			treeGeneral->printTree(generalType);
		}
		cout << endl;
		break;
	case 2: //sap xep theo ower name
		printf("\033c");
		if (str == "display")
		{ //neu chon case la display thi in ra display
			cout << setw(30) << left << "Owner name"
				 << setw(35) << left << "Email"
				 << setw(15) << left << "Key number"
				 << setw(15) << left << "ODO number"
				 << setw(25) << left << "Remind Service (km)"
				 << setw(15) << left << "Light level"
				 << setw(20) << left << "Screen light level"
				 << setw(15) << left << "Taplo level" << endl;

			//get all data cua Display va push_back data vao trong vector listDisplay
			vector<Display *> *listDisplay = new vector<Display *>;
			treeDisplay->getAllDisplay(listDisplay);

			//thuc hien sort by name
			sort(listDisplay->begin(), listDisplay->end(), comparatorDisplayName);
			//tao vector luu tru display sau khi sort
			vector<Display *> setDisplay(listDisplay->begin(), listDisplay->end());

			// Print Display data out
			for (Display *item : setDisplay)
			{
				item->xuatThongTin();
			}
		}
		else if (str == "sound")
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

			// get all data cua Sound va push_back data vao trong vector listSound
			vector<Sound *> *listSound = new vector<Sound *>;
			treeSound->getAllSound(listSound);

			// thuc hien sort by name
			sort(listSound->begin(), listSound->end(), comparatorSoundName);
			// tao vector luu tru Sound sau khi sort
			vector<Sound *> setSound(listSound->begin(), listSound->end());

			// Print Display data out
			for (Sound *item : setSound)
			{
				item->xuatThongTin();
			}
		}
		else if (str == "general")
		{
			cout << setw(30) << left << "Owner name"
				 << setw(35) << left << "Email"
				 << setw(15) << left << "Key number"
				 << setw(15) << left << "ODO number"
				 << setw(25) << left << "Remind Service (km)"
				 << setw(20) << left << "TimeZone"
				 << setw(50) << left << "Language" << endl;

			// get all data cua General va push_back data vao trong vector listGeneral
			vector<General *> *listGeneral = new vector<General *>;
			treeGeneral->getAllGeneral(listGeneral);

			// thuc hien sort by name
			sort(listGeneral->begin(), listGeneral->end(), comparatorGeneralName);
			// tao vector luu tru general sau khi sort
			vector<General *> setGeneral(listGeneral->begin(), listGeneral->end());

			// Print General data out
			for (General *item : setGeneral)
			{
				item->xuatThongTin();
			}
		}
		cout << endl;
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

//lua chon group by name or MSCN va in ra tat ca thong tin cua xe
void groupByNameOrKey()
{
	int selection; //lua chon group theo name or mscn
	string name;   //nhap name
	string key;	   //nhap mscn

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
	{
		printf("\033c");
		cout << "Please enter the personal key: "; //nhap personal key cho xe
		key = validKey();

		// Find the node in the trees (Display, Sound and General) by personal key that user-entered
		//search su dung binary search tree ( nho hon thi qua nhanh trai, lon hon thi tim qua nhanh phai)
		//do khi insert vao cay thi insert dua vao personal key nen khi tim thi mscn dc tim theo BST con owner name thi k dc tim theo BST
		Node *resultDisplay = treeDisplay->searchByPersonalKey(key);
		Node *resultSound = treeSound->searchByPersonalKey(key);
		Node *resultGeneral = treeGeneral->searchByPersonalKey(key);

		// print all thong tin cua xe sau khi tim dc mscn tuong ung
		XuatThongTatCaTinCaiDat(resultDisplay, resultSound, resultGeneral);
		break;
	}
	case 2: //tim ten xe
	{
		printf("\033c");
		cout << "Please enter the owner name: ";
		name = validCarName();
		//in ra all thong tin dua vao name dang tim kim
		treeDisplay->searchByName(name);
		break;
	}
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
			cout << "Fail open file timezones ";
			timezoneT = "+07:00";
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
				while (f.eof() == false)
				{
					//f.seekg(4, 1);//nhich qua 4 byte de bo 'GMT' chi lay phan so '-12:00'
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
			cout << "	Timezone: "
				 << "GMT" << timezoneList[selection - 1].getNumber() << endl;
			//gan Timezone vao timezoneT de hien Timezone o chuc nang General Setting
			timezoneT = timezoneList[selection - 1].getNumber();
		}
	}
	catch (...) // Throw message when occur error during read file
	{
		cerr << "Exception occur when open file! " << endl;
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
			languageT = " Vietnamese";
			//system("pause");
			cout << endl
				 << "Press Enter to continue...";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else
		{
			//doc file la language cho ng dung chon
			cout << "----- SELECT LANGUAGE DATA -----" << endl;
			if (languageList.size() == 0)
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
	catch (...) // Throw message when occur error during read file
	{
		cerr << "Exception occur when open file!" << endl;
	}

	f.close();
	//system("pause");
	cout << endl
		 << "Press Enter to continue...";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	printf("\033c");
}

//xuat tat ca thogn tin cai dat cau xe
void XuatThongTatCaTinCaiDat(Node *resultDisplay, Node *resultSound, Node *resultGeneral)
{

	// If one of result is Null, print out "NOT FOUND"
	if (resultDisplay == NULL || resultSound == NULL || resultGeneral == NULL)
	{
		cout << "NOT FOUND!!! \n"
			 << endl;
	}
	else
	{ //neu tim thay xe dang tim thi in ra

		cout << "--- All setting ---" << endl;

		//Truyền kết quả tìm kiếm đến đúng loại để in ra
		//dynamic_cast chuyen doi kieu du lieu tu Node* sang Display, Sound, General de in thong tin ra cho xe
		Display *dpl_result = dynamic_cast<Display *>(resultDisplay->data);
		Sound *s_result = dynamic_cast<Sound *>(resultSound->data);
		General *g_result = dynamic_cast<General *>(resultGeneral->data);

		//in ra toan bo thong tin cua xe
		//in data cua Setting
		cout << setw(10) << left << "1" << setw(30) << left << "Owner name" << setw(35) << left << "Email" << setw(20) << left << "Key number" << setw(20) << left << "ODO number" << setw(25) << left << "Remind Service (km)" << endl;
		cout << setw(10) << left << ""
			 << setw(30) << left << resultDisplay->data->getCarName()
			 << setw(35) << left << resultDisplay->data->getEmail()
			 << setw(20) << left << resultDisplay->data->getPersonalKey()
			 << setw(20) << left << resultDisplay->data->getODO()
			 << setw(25) << left << resultDisplay->data->getServiceRemind() << endl;

		//in data cua Display
		cout << setw(20) << left << "Display:" << setw(15) << "Light level" << setw(20) << "Screen Light level" << setw(15) << "Taplo Light" << endl;
		cout << setw(20) << left << ""
			 << setw(15) << dpl_result->get_light_level()
			 << setw(20) << dpl_result->get_screen_light_level()
			 << setw(15) << dpl_result->get_taplo_light_level() << endl;

		//in data cua Sound
		cout << setw(20) << left << "Sound:" << setw(10) << left << "Media" << setw(10) << left << "Call" << setw(15) << left << "Navigation" << setw(10) << left << "Notify" << endl;
		cout << setw(20) << left << ""
			 << setw(10) << s_result->get_media_level()
			 << setw(10) << s_result->get_call_level()
			 << setw(15) << s_result->get_navi_level()
			 << setw(10) << s_result->get_notification_level() << endl;

		//in data cua General
		cout << setw(20) << "General:" << setw(20) << "Timezone" << setw(50) << "Language" << endl;
		cout << setw(20) << left << ""
			 << setw(20) << "GMT" + g_result->get_timeZone()
			 << setw(50) << g_result->get_language() << endl;

		cout << endl
			 << endl;
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
		}
		else if (subData[0] == "Display") // The case is Display
		{
			vector<string> dataDetail = explode(subData[1], ',');
			Setting st = Setting(car_name, personal_key, email, stoi(odo), stoi(service_remind));
			// Update data to Display list tai vi tri vua add setting (count)
			// thu tu data cua Display: light level-[0], screen level-[1], taplo level-[2]
			Display *dpl = new Display(st);
			dpl->updateDisplay(st, stoi(dataDetail[0]), stoi(dataDetail[1]), stoi(dataDetail[2]));
			treeDisplay->insert(dpl); //insert vao cay display
		}
		else if (subData[0] == "Sound") // The case is Sound
		{
			vector<string> dataDetail = explode(subData[1], ',');
			// Get Setting
			Setting st = Setting(car_name, personal_key, email, stoi(odo), stoi(service_remind));

			// Update data to Sound list tai vi tri vua add setting (count)
			// thu tu data cua Sound: media level-[0], call level-[1], navi level-[2], notification level-[3]
			Sound *s = new Sound(st);
			s->updateSound(st, stoi(dataDetail[0]), stoi(dataDetail[1]), stoi(dataDetail[2]), stoi(dataDetail[3]));
			treeSound->insert(s);
		}
		else if (subData[0] == "General") // The case is General
		{
			vector<string> dataDetail = explode(subData[1], ',');
			// Get Setting
			Setting st = Setting(car_name, personal_key, email, stoi(odo), stoi(service_remind));

			// Update data to General list
			// thu tu data cua general: timeZone-[0], language-[1]
			General *g = new General(st);
			g->updateGeneral(st, dataDetail[0], dataDetail[1]);
			treeGeneral->insert(g);
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

		// khoi tao vector de luu tru data
		vector<Display *> *listDisplay = new vector<Display *>;
		vector<Sound *> *listSound = new vector<Sound *>;
		vector<General *> *listGeneral = new vector<General *>;

		// lay data cua Display, Sound and General trong tree
		listDisplay = treeDisplay->getAllDisplay(listDisplay);
		listSound = treeSound->getAllSound(listSound);
		listGeneral = treeGeneral->getAllGeneral(listGeneral);

		// write data cua Display, setting, sound, general voa file Setting.txt
		for (int i = 0; i < listDisplay->size(); i++)
		{
			// lay du lieu cua Setting de noi thanh 1 chuoi luu vao file
			format = "Setting_" + listDisplay->at(i)->formatTypeSetting() + "/";

			// lay du lieu cua Display de noi thanh 1 chuoi luu vao file
			format += "Display_" + listDisplay->at(i)->formatTypeDisplay() + "/";

			// lay du lieu cua Sound de noi thanh 1 chuoi luu vao file
			format += "Sound_" + listSound->at(i)->formatTypeSound() + "/";

			// lay du lieu cua General de noi thanh 1 chuoi luu vao file
			format += "General_" + listGeneral->at(i)->formatTypeGeneral() + "/";

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
bool comparatorTimezone(CommonInfo c1, CommonInfo c2)
{
	//c1.getNumber().replace(3, 1, ","); //replace vị tri thu 3 trong chuoi +13:00 de thay dau : thanh dau ,
	//c2.getNumber().replace(3, 1, ","); //replace vị tri thu 3 trong chuoi +13:00 de thay dau : thanh dau ,

	c1.setNumber(c1.getNumber().erase(0, 4));
	c1.setNumber(c1.getNumber().erase(c1.getNumber().length() - 1, c1.getNumber().length()));
	c1.setNumber(c1.getNumber().replace(3, 1, ","));

	c2.setNumber(c2.getNumber().erase(0, 4));
	c2.setNumber(c2.getNumber().erase(c1.getNumber().length() - 1, c1.getNumber().length()));
	c2.setNumber(c2.getNumber().replace(3, 1, ","));

	//cout << c1.getNumber() << endl;
	return (stoi(c1.getNumber()) < stoi(c2.getNumber())); //so sanh theo so
}

/*
* Function sort danh sach Language bang alphabet
*/
bool comparatorLanguage(CommonInfo c1, CommonInfo c2)
{
	return (c1.getName() < c2.getName());
}
