#include <iostream>
#include "General.h"
#include "Display.h"
#include "Sound.h"
#include "CommonInfo.h"
#include <fstream>

Setting** display 	= new Setting*[100];
Setting** sound 	= new Setting*[100];
Setting** general 	= new Setting*[100];

int dispCnt, soundCnt, generalCnt = 0;

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

int menu();

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main(int argc, char** argv) {
	downloadLanguage();
	downloadTimeZone();
	
	int selection = 0;
	
	// Your code
	return 0;
}

int menu(){
	int selection;

	// Your code
	return selection;
}

void NhapThongTinCaiDat(){
	int selection;
	
	// Your code
	
	system("cls");
	switch(selection){
		case 1:{
			cout << " --- Ban nhap thong tin Display --- " << endl;
	// Your code
			break;
		}
		case 2:{
			cout << " --- Ban nhap thong tin Sound --- " << endl;
	// Your code
			break;
		}
		case 3:{
			cout << " --- Ban nhap thong tin General --- " << endl;
	// Your code
			break;
		}
		case 0: 
		default:
		{
			break;
		}
	}
}

void NhapThongTinCaiDat_Sound()
{
	char continues = 'n';
	do{
		cout << " NHAP THONG TIN SOUND, XE SO " << soundCnt+1 << endl;
		// Your code
		cout << "TIEP TUC XE SO " << soundCnt+1 << " ? (y/n): ";
		cin >> continues;
		cout << endl;
	}while(continues == 'y');
}

void NhapThongTinCaiDat_General()
{
	char continues = 'n';
	do{
		cout << " NHAP THONG TIN GENERAL, XE SO " << generalCnt+1 << endl;
		// Your code
		cin >> continues;
		cout << endl;
	}while(continues == 'y');
}

void NhapThongTinCaiDat_Display()
{
	char continues = 'n';
	do{
		cout << " NHAP THONG TIN DISPLAY, XE SO " << dispCnt+1 << endl;
		
		// Your code
		cout << "TIEP TUC XE SO " << dispCnt+1 << " ? (y/n): ";
		cin >> continues;
		cout << endl;
	}while(continues == 'y');
}

void XuatThongTinCaiDat(){
	int selection;
	
	// Your code
	
	system("cls");
	switch(selection){
		// Your code
	}
}

const vector<string> explode(const string& s, const char& c) 
{
	string buff{ "" };
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

void downloadTimeZone(){
	ifstream f;
	f.open("timezones.txt");
	// Your code
	f.close();
}

void downloadLanguage(){
	ifstream f;
	f.open("languages.txt");
	// Your code
	f.close();	
}

void XuatThongTinCaiDat_Sound(){
	cout << setw(20) << "TEN CHU XE" << setw(25) << "Email" << setw(10) << "MSC" << setw(10) << "ODO" << setw(10) << "SEVICES" << setw(10) << "Media" << setw(10) << "Call" << setw(10) << "Navi" << setw(10) << "Notify"<< endl;
	// Your code
}

void XuatThongTinCaiDat_General(){
	cout << setw(20) << "TEN CHU XE" << setw(25) << "Email" << setw(10) << "MSC" << setw(10) << "ODO" << setw(10) << "SEVICES" << setw(30) << "TimeZone" << setw(20) << "Language" << endl;
	// Your code
}

void XuatThongTinCaiDat_Display(){
	cout << setw(20) << "TEN CHU XE" << setw(25) << "Email" << setw(10) << "MSC" << setw(10) << "ODO" << setw(10) << "SEVICES" << setw(10) << "Light" << setw(10) << "Taplo" << setw(10) << "Screen" << endl;
	// Your code
}

void XuatThongTatCaTinCaiDat(){
	// Your code
}

