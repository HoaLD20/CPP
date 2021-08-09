#include <iostream>
#include "Setting.h"
#include "CommonInfo.h"
#include <fstream>
#include <bits/stdc++.h>

using namespace std;

vector<Setting *> setting;

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

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main(int argc, char **argv)
{
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

void NhapThongTinCaiDat_Sound()
{
	char continues = 'n';
	do
	{
		cout << " NHAP THONG TIN SOUND, XE SO " << setting.size() + 1 << endl;

		bool found = false;		  //true: tai khoan ton tai,  false: tai khoan khong ton tai
		Setting *p = new Setting; //Con tro de luu thong tin nhap vao

		p->nhapThongTin();		//Nhap thong tin chung
		p->nhapThongTinSound(); //Nhap thong tin cho chuc nang Sound

		//Tim MSCN trung khop voi MSCN vua nhap
		for (int i = 0; i < setting.size(); ++i)
		{
			if (setting[i]->layMaSoCaNhan().compare(p->layMaSoCaNhan()) == 0) //Bang 0 khi 2 MSCN giong nhau va tien hanh thay doi
			{																  //thong tin chung cua list
				setting[i]->thayDoiThongTinChung(p);
				setting[i]->thayDoiThongTinSound(p);
				delete p; //Giai phong vung nho cap phat
				found = true;
				break;
			}
		}

		if (found == false)
		{
			setting.push_back(p);
		}

		cout << "TIEP TUC XE SO " << setting.size() + 1 << " ? (y/n): ";
		cin >> continues;
		cout << endl;
	} while (continues == 'y');
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
				cout << "\t(!) Nhap so (0-" << to_string(maxSelection) << ")\n"; //Neu chuoi nhap co ky tu thi thong bao va nhap lai
				is_digit = false;
				break;
			}
		}

		if (is_digit == true)
		{
			selection = stoi(str_selection);				 //Chuoi nhap khong co ky tu thi ep kieu sang kieu so nguyen
			if (selection >= 0 && selection <= maxSelection) //Neu lua chon khong nam trong khoang 0-maxSelection thi thong bao va nhap lai
			{
				return selection;
			}
			else
				cout << "\t(!) Nhap so (0-" << to_string(maxSelection) << ")\n";
		}
	} while (true);
}

//Liet ke ra danh sach TimeZone va Language
//Mang list: mang TimeZone hoac Language
int ChonTimeZoneVaLanguage(vector<CommonInfo> list)
{
	for (size_t i = 0; i < list.size(); ++i)
	{
		cout << setw(2) << i << ":" << setw(16) << list[i].getNumber()
			 << setiosflags(ios::left) << list[i].getName() << resetiosflags(ios::left) << endl; //Dinh dang thong tin xuat
	}

	return isDigits(int(list.size()) - 1); //Chay ham isDigits() de tra ve gia tri selection cua TimeZone hoac Language; tham so la gioi han lon nhat cua lua chon
}

void NhapThongTinCaiDat_General()
{
	string timezone, language;
	char continues = 'n';

	do
	{
		cout << " NHAP THONG TIN GENERAL, XE SO " << setting.size() + 1 << endl;

		Setting *p = new Setting; //Con tro de luu thong tin nhap vao
		p->nhapThongTin();		  //Nhap thong tin chung
		bool found = false;		  //true: tai khoan ton tai,  false: tai khoan khong ton tai

		cout << "\nMOI BAN CHON TIME ZONE\n";
		timezone = to_string(ChonTimeZoneVaLanguage(timezoneList)); //Lua chon timeZone

		cout << "\nMOI BAN CHON LANGUAGE\n";
		language = to_string(ChonTimeZoneVaLanguage(languageList)); //Lua chon language

		p->nhapThongTinGeneral(timezone, language); //Nhap gia tri timezone va language cho doi tuong

		//Tim MSCN trung khop voi MSCN vua nhap
		for (int i = 0; i < setting.size(); ++i)
		{
			if (setting[i]->layMaSoCaNhan().compare(p->layMaSoCaNhan()) == 0) //Bang 0 khi 2 MSCN giong nhau va tien hanh thay doi
			{																  //thong tin chung cua list
				setting[i]->thayDoiThongTinChung(p);
				setting[i]->thayDoiThongTinGeneral(p);
				delete p; //Giai phong vung nho cap phat
				found = true;
				break;
			}
		}

		if (found == false)
		{
			setting.push_back(p);
		}

		cout << "TIEP TUC XE SO " << setting.size() + 1 << " ? (y/n): ";
		cin >> continues;
		cout << endl;
	} while (continues == 'y');
}

void NhapThongTinCaiDat_Display()
{
	char continues = 'n';
	do
	{
		cout << " NHAP THONG TIN DISPLAY, XE SO " << setting.size() + 1 << endl;

		Setting *p = NULL; //Con tro de luu thong tin nhap vao
		p = new Setting;

		bool found = false; //true: tai khoan ton tai,  false: tai khoan khong ton tai

		p->nhapThongTin();		  //Nhap thong tin chung
		p->nhapThongTinDisplay(); //Nhap thong tin Display

		//Tim MSCN trung khop voi MSCN vua nhap
		for (int i = 0; i < setting.size(); ++i)
		{
			if (setting[i]->layMaSoCaNhan().compare(p->layMaSoCaNhan()) == 0) //Bang 0 khi 2 MSCN giong nhau va tien hanh thay doi
			{																  //thong tin chung cua list
				setting[i]->thayDoiThongTinChung(p);
				setting[i]->thayDoiThongTinDisplay(p);
				delete p; //Giai phong vung nho cap phat
				found = true;
				break;
			}
		}

		if (found == false)
		{
			setting.push_back(p);
		}

		cout << "TIEP TUC XE SO " << setting.size() + 1 << " ? (y/n): ";
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
	CommonInfo time; //Luu gia tri tam thoi khi doc thong tin tu file

	f.open("timezones.txt");

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

	f.open("languages.txt");

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

	for (int i = 0; i < setting.size(); ++i)
	{
		setting[i]->xuatThongTin();
		setting[i]->xuatThongTinSound();
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

	for (int i = 0; i < setting.size(); ++i)
	{
		setting[i]->xuatThongTin();
		setting[i]->xuatThongTinGeneral();
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

	for (int i = 0; i < setting.size(); ++i)
	{
		setting[i]->xuatThongTin();
		setting[i]->xuatThongTinDisplay();
	}
	cout << endl;
	cout << endl
		 << "Press Enter to continue...";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.get();
}

void XuatThongTinTatCaCaiDat()
{
	string selection; //Luu lua chon cua nguoi dung
	string keyOrName; //Luu ma so ca nhan hoac ten do nguoi dung nhap vao
	char continues = 'n';
	bool found;		  //true: tim thay;  false: khong tim thay
	int position = 0; //Vi tri tim thay ten hoac ma so ca nhan trung khop trong mang setting[]

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
		found = false;
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

		for (int i = 0; i < setting.size(); i++)
		{
			if (selection == "1") //Nguoi dung chon xuat thong tin theo ten
			{
				if (setting[i]->layTenChuXe() == keyOrName)
				{
					found = true;
					position = i;
					break;
				}
			}
			else //Nguoi dung chon xuat thong tin theo ma so ca nhan
			{
				if (setting[i]->layMaSoCaNhan() == keyOrName)
				{
					found = true;
					position = i;
					break;
				}
			}
		}

		if (found == false) //Khong tim thay ma so ca nhan hoac ten
		{
			if (selection == "1")
			{
				cout << " (!) TEN CHU XE KHONG TON TAI!\n";
				cout << " TIEP TUC NHAP TEN CHU XE? (y/n): ";
			}
			else
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
	setting[position]->xuatThongTinChung();
	setting[position]->xuatThongTinRieng();

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
void DuplicationOfInfo()
{
	if (setting.size() > 1) //Neu mang gom 2 phan tu tro len thi tien hanh kiem tra co trung khop MSCN khong
	{
		for (int i = 0; i < setting.size(); ++i)
		{
			for (int j = 0; j < setting.size(); ++j)
			{
				if (i == j) //Bo qua doi tuong dang xet
					continue;
				if (setting[i]->layMaSoCaNhan() == setting[j]->layMaSoCaNhan()) //So sanh MSCN
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

	Setting *p = NULL;

	regex patternMain //Regex pattern kiem tra email
		("^[a-zA-Z0-9][a-zA-Z0-9.]{1,28}[a-zA-Z0-9]@[a-zA-Z0-9][a-zA-Z0-9-]*[a-zA-Z0-9](\\.[a-z0-9]{2,4}){1,2}$");
	regex patternd("\\d{8}"); //Regex pattern kiem tra ma so ca nhan

	try
	{
		inFile.open("Setting.txt");
		if (!inFile)
		{
			throw "\n\tKhong mo duoc file \"Setting.txt\" de doc du lieu\n";
		}
		while (getline(inFile, s))
		{
			p = new Setting; //Cap phat vung nho moi

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

			//Nhap thong tin chung doc tu file cho con tro p
			p->nhapThongTinChung(generalInfoArray[0], personalKey, email, stoi(odo), stoi(serviceRemind));

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

					//Nhap thong tin rieng cho chuc nang Display
					p->nhapThongTinDisplay(stoi(privateInfoArray[0]), stoi(privateInfoArray[1]), stoi(privateInfoArray[2]));
				}
				else if (functionName == "Sound")
				{
					if (privateInfoArray.size() != 4) //Chuc nang sound co 4 lua chon, it hon hay nhieu hon se bi loai
					{
						throw "\n\t(!) LOI (Du lieu dau vao cua thong tin rieng khong hop le)\n";
					}

					//Nhap thong tin rieng cho chuc nang Sound
					p->nhapThongTinSound(stoi(privateInfoArray[0]), stoi(privateInfoArray[1]), stoi(privateInfoArray[2]), stoi(privateInfoArray[3]));
				}
				else
				{
					if (privateInfoArray.size() != 2) //Chuc nang general co 2 lua chon, it hon hay nhieu hon se bi loai
					{
						throw "\n\t(!) LOI (Du lieu dau vao cua thong tin rieng khong hop le)\n";
					}

					//Nhap thong tin cho bien 'gen'
					p->nhapThongTinGeneral(privateInfoArray[0], privateInfoArray[1]);
				}
			}
			setting.push_back(p); //Them du lieu vao mang setting
		}
		inFile.close();

		DuplicationOfInfo(); //Kiem tra trung lap thong tin (cung MSCN)
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

//Ham ghi du lieu len tap tin "Setting.txt"
void WriteOnFile()
{
	ofstream outFile;

	try
	{
		outFile.open("Setting.txt");
		if (!outFile)
		{
			throw "\n\tKhong mo duoc file \"Setting.txt\" de ghi du lieu\n";
		}

		for (int i = 0; i < setting.size(); i++)
		{
			outFile << setting[i]->layTenChuXe() << "," << setting[i]->layEmail() << "," << setting[i]->layMaSoCaNhan()
					<< "," << setting[i]->layOdo() << "," << setting[i]->layServiceRemind() << "; "; //Ghi thong tin chung vao file

			outFile << "General:" << setting[i]->getTimezone() << "," << setting[i]->getLanguage(); //Ghi thong tin General vao file

			outFile << ";Sound:" << setting[i]->getMediaLevel() << "," << setting[i]->getCallLevel() << ","
					<< setting[i]->getNaviLevel() << "," << setting[i]->getNotiLevel(); //Ghi thong tin Sound vao file

			outFile << ";Display:" << setting[i]->getLightLevel() << "," << setting[i]->getScreenLightLevel() << ","
					<< setting[i]->getTaploLightLevel() << "\n"; //Ghi thong tin Display vao file
		}

		//Giai phong bo nho cap phat cho mang setting
		for (int i = 0; i < setting.size(); i++)
		{
			delete setting[i];
		}

		outFile.close();
	}
	catch (const char *ch)
	{
		cout << ch << endl;
	}
	cout << "\n\tDa ghi du lieu thanh cong vao file \"Setting.txt\"\n";
}