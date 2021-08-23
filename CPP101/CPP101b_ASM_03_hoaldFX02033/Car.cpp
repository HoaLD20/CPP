#include "Car.h"
#include "checkValid.h"
#include "Sort.h"
#include "File.h"
#include <iostream>
#include <string>
#include <regex>
using namespace std;
#include <iostream>
#include <string>

string f_mscn = "ASM3.dat";
string f_vantoc = "MUCVANTOC.dat";
int vanToc;				   //khoi tao bien van toc cua xe
string option;			   //danh dau lua chon che do nao trong 4 che do
int maSoNhap[8];		   //mang chua gia tri ma ng dung nhap vao
int maSoMacDinh[8];		   //khi chua co ma so mac dinh thi ng dung cai dat vao
int maSoMacDinhFile[8];	   //ma so mac dinh lay ra tu file
int maSoNhapBubbleSort[8]; // mang cho bubbleSort sort de thuc hien so sanh do phuc tap, neu gop lai chung thi khi selection hoac bubble sort thi thangw kia k con gi de tinhs so buoc thuc hien
int maSoSelectionSort[8];  //mang cho selectionSort sort de thuc hien so sanh do phuc tap
int mucVannToc[3];		   //khai bao mang chua mucn toc va
bool isLogin = false;	   //khoi toa bien de kiem tra xem ng dung da dang nhap r hay chua(phan biet khi chuyen tu menu D N P R sang menu chinh de k can login lai)
int v1, v2, v3;			   //van toc muc 1 2 3
string instalMSCN;		   //chuoi chua ma so ca nhan sau khi chuyen arr sang chuoi va luu chuoi vao file
string instalMVT;		   //chuoi chua muc van toc sau khi chuyen arr sang chuoi va luu chuoi vao file
int vanTocFile[3];		   //doc muc van toc tu trong file ra
int vanTocFileCompare[3];  //doc van toc tu file sau khi thay doi vna toc mac dinh de di kiem tra khoang cach an toan dua vao van toc nguoi dung nhap

//canh bao khoang cach
void CanhBaoKC(int vanToc)
{
	//kiem tra van toc va dua ra thong bao khoang cach an toan
	if (vanToc < v1)
	{
		cout << "BAN CHU Y GIU KHOANG CACH TOI THIEU LA 20m" << endl;
	}
	else if (v1 <= vanToc && vanToc < v2)
	{
		cout << "BAN CHU Y GIU KHOANG CACH TOI THIEU LA 55m" << endl;
	}
	else if (v2 <= vanToc && vanToc <= v3)
	{
		cout << "BAN CHU Y GIU KHOANG CACH TOI THIEU LA 70m" << endl;
	}
	else
	{
		cout << "BAN CHU Y GIU KHOANG CACH TOI THIEU LA 100m" << endl;
	}
}

//sao sanh do phuc tap cua bbsort va selection sort
void SoSanhDoPhucTap(int slSort, int bbSort)
{
	cout << "BUBBLE SORT SU DUNG: " << bbSort << " BUOC" << endl;
	cout << "SELECTION SORT SU DUNG: " << slSort << " BUOC" << endl;

	//lay so vong lap cua 2 thuat toan va dua ra thong bao do phuc tap thuat toan
	if (bbSort > slSort)
	{
		cout << "DO PHUC TAP CUA BUBBLE SORT LON HON SELECTION SORT" << endl;
	}
	else if (bbSort < slSort)
	{
		cout << "DO PHUC TAP CUA BUBBLE SORT NHO HON SELECTION SORT" << endl;
	}
	else if (bbSort == slSort)
	{
		cout << "DO PHUC TAP CUA BUBBLE SORT BANG SELECTION SORT" << endl;
	}
}

//cai dat ma ca nhan
void CaiDatMaSoMacDinh()
{
	cout << "CAI DAT MA SO CA NHAN, MANG 08 SO:" << endl;
	for (int i = 0; i < 8; i++)
	{
		cout << "NHAP SO THU " << i + 1 << ": ";
		maSoMacDinh[i] = validInput();
	}
	printf("\033c");
}

//thay doi ma so mac dinh
void changeMSMD()
{

	printf("\033c");
	//cai dat ma so mac dinh
	CaiDatMaSoMacDinh();
	instalMSCN = covertArrayToString(maSoMacDinh, " ", 8); //chuyen arr thanh chuoi der viet vo file
	writeFile(f_mscn, instalMSCN);
	cout << "DOI MAT KHAU THANH CONG" << endl;
}

//vai dat muc van toc
void CaiDatMucVanToc()
{
	cout << "CAI DAT VAN TOC CANH BAO KHOANG CACH AN TOAN VOI 3 MUC TOC DO " << endl;
	do
	{
		for (int i = 0; i < 3; i++)
		{ //nhap 3 muc va toc
			cout << "MUC VAN TOC " << i + 1 << " : ";
			//nhpa muc van toc la so
			mucVannToc[i] = validInputVanToc();
		}
		//cac muc van toc k dc nhap bang nhau
		if ((mucVannToc[0] == mucVannToc[1]) || (mucVannToc[0] == mucVannToc[2]) || (mucVannToc[1] == mucVannToc[2]))
		{
			cout << "CAC MUC DO VAN TOC KHONG DUOC BANG NHAU. VUI LONG NHAP LAI!!" << endl;
		}
		//nhap lai neu cac muc van toc bang nhau
	} while ((mucVannToc[0] == mucVannToc[1]) || (mucVannToc[0] == mucVannToc[2]) || (mucVannToc[1] == mucVannToc[2]));
}

//man hinh dang nhap
void InputLogin()
{

	isLogin = true;			  // kiem tra chuong trinh da login chưa khi chuyen tu menu phu sang menu chinh(menu so)		string input;//truyen vao trong ham check co phai la so khong hay la chu, neu la so thi gan gi tri phan tu cua mang cho gia tri input do (check is Number)
	int checkEqualArr = 0;	  //kiem tra chuoi ng dung nhap vao va chuoi gan cung trong chuong trinh co bang nhau khong
	int checkNotEqualArr = 0; //danh dau 2 chuoi khong bang
	bool checkMSCN = false;	  //check ma so ca nhan
	bool checkMVT = false;	  //check ma van toc
	string strMSCN = "";	  // doc ma so ca nhan tu file
	string strMVT = "";		  //doc muc van toc tu file

	/// file mscn chua co data thi phai cai dat ma so ca nhan mac dinh
	strMSCN = readFile(f_mscn);
	if (strMSCN.empty())
	{
		//neu chua co mscn mac dinh thi bat dau cai dat mscn
		CaiDatMaSoMacDinh();
		//chuyen mang so ca nhan nhap vao thanh chuoi de luu vao file
		instalMSCN = covertArrayToString(maSoMacDinh, " ", 8);
		writeFile(f_mscn, instalMSCN);
	}

	/// nguoi dung nhap ma so ca nhan cua minh
	cout << "NHAP MA SO CA NHAN, MANG 08 SO" << endl;
	//nhap 8 so cho mang
	for (int i = 0; i < 8; i++)
	{
		int input = 0;
		cout << "SO THU " << i + 1 << " : ";
		//chi duoc nhap so tu nhien 0-9
		input = validInput();
		//mscn nhap do nguoi dung nhap vao
		maSoNhap[i] = input;
		//de thuc hien selection sort bat dau so sanh do phuc tap
		maSoSelectionSort[i] = input;
		//de thuc hien bubble sort bat dau so sanh do phuc tap
		maSoNhapBubbleSort[i] = input;
	}
	printf("\033c"); //xoa mang hinh

	///hin ra man hinh MSCN, ma so mac dinh truoc va sau khi sx
	//mang ng dung nhap vao va su dung selection sort
	cout << "MANG NHAP VAO TRUOC KHI SAP XEP:  ";
	printArray(maSoNhap, 8);							//in ra chuoi moi nhap xong ( chua sort)
	selectionSort(maSoNhap, 8);							//thuc hien selection sort
	cout << "-------> MANG NHAP VAO SAU KHI SAP XEP: "; //in ra mang vua sx
	printArray(maSoNhap, 8);

	//lay ma mac dinh tu trong file ra va hien thi
	getMaSoMDFormFile(f_mscn, maSoMacDinhFile, ' ');

	//mang mac dinh la dung bubble sort
	//SORT ma mat dinh
	cout << "MA SO CA NHAN TRUOC TRUOC KHI SAP XEP: ";
	printArray(maSoMacDinhFile, 8);
	bubbleSort(maSoMacDinhFile, 8); //sort mac so mac dinh
	cout << "-------> MA SO CA NHAN SAU KHI SAP XEP: ";
	printArray(maSoMacDinhFile, 8); //in ra ma so mac dinh vua sx

	//so sanh do phuc tap cua 2 thuat toan
	int complexSelection = selectionSort(maSoSelectionSort, 8);
	int complexBubble = bubbleSort(maSoNhapBubbleSort, 8);
	SoSanhDoPhucTap(complexSelection, complexBubble);

	/// kiem tra 2 mang co bang nhau khong
	// system("pause");
	cout << "\n\tPress any key to continue ....";
	cin.ignore().get();
	for (int i = 0; i < 8; i++)
	{
		if (maSoNhap[i] == maSoMacDinhFile[i])
		{					 //neu cac phan tu cua mang bang nhau
			++checkEqualArr; //bien kiem tra bang nhau tang
		}
		else
		{
			++checkNotEqualArr; //neu co ptu k bang nhau thi bien check tang
		}
	}
	if (checkNotEqualArr == 0)
	{ //neu chuoi MSCN va MSMD bang nhau chuyen qua man hinh change password
		if (changPassword("BAN CO MUON THAY DOI MA SO MAC DINH HAY KHONG (Y/N)?"))
		{ //neu chon Y thi thuc hien cay dat pass
			printf("\033c");
			//thay doi password
			changeMSMD();
			// system("pause");
			cout << "\n\tPress any key to continue ....";
			cin.ignore().get();
		}
		//cai muc do van toc
		printf("\033c");
		CaiDatMucVanToc(); //ng dung cai dat muc van toc nhung chua luu vao file, khi chon yes thi ms luu vao file

		//neu trong file k co data thi luu vao file luon
		strMVT = readFile(f_vantoc);
		if (strMVT.empty())
		{
			//neu file rong thi luu thang vao file luon
			instalMVT = covertArrayToString(mucVannToc, ",", 3);
			writeFile(f_vantoc, instalMVT);
			// system("pause");
			cout << "\n\tPress any key to continue ....";
			cin.ignore().get();
		}
		else
		{ //neu file da co data roi thi hoi ngta co muon thay doi ma van toc khong, neu chon yes thi thuc hien luu MVT moi voa file van toc
			//neu van toc mac dinh luu trong file khac voi van toc nhap vao thi hoi co muon thay doi MVT hay k
			//neu giong nhau giua trong file va nhap vao thi k can hoi
			int checkSameMVT = 0; //kiem tra xem trong MVT lay ra tu file co ptu nao khac voi MVT trong mang do nguoi dung nhap voa khong
			int checkDiffMVT = 0;
			//la ma van toc tu file ra de bat dau ss xem van toc nhap vao co giong van toc trong file khong
			getMaSoMDFormFile(f_vantoc, vanTocFile, ',');
			bubbleSort(vanTocFile, 3); //sort MVT lay ra tu file de ss MVT trong file va nhap vao co giong nhau khong
			bubbleSort(mucVannToc, 3); //sort muc van toc nhap vao de ss MVT trong file va nhap vao co giong nhau khong
			for (int i = 0; i < 3; i++)
			{
				//neu MVT khac nhau
				if (vanTocFile[i] != mucVannToc[i])
				{
					checkDiffMVT = 1;
				}
				else
				{
					checkSameMVT = 1;
				}
			}
			//MVT nhap khac MVT trong file
			if (checkDiffMVT != 0)
			{
				//chon yes thi bat dau luu MVT vao file
				if (changPassword("MUC VAN TOC NHAP VAO KHAC MUC VAN TOC MAC DINH \nBAN CO MUON THAY DOI MUC VAN TOC HAY KHONG (Y/N)?"))
				{
					instalMVT = covertArrayToString(mucVannToc, ",", 3);
					writeFile(f_vantoc, instalMVT);
					cout << "THAY DOI MUC DO VAN TOC THANH CONG" << endl;
					// system("pause");
					cout << "\n\tPress any key to continue ....";
					cin.ignore().get();
				}
			}
		}

		//lay MVT trong file bo vao trong arr vanTocCompare de thuc hien hien thi khoang cach an toan
		getMaSoMDFormFile(f_vantoc, vanTocFileCompare, ',');
		//sort van toc khi lay ra tu file de thuc hien dua ra thong bao khoang cach an toan
		bubbleSort(vanTocFileCompare, 3);
		v1 = vanTocFileCompare[0];
		v2 = vanTocFileCompare[1];
		v3 = vanTocFileCompare[2];
	}
	else
	{
		//neu chuoi k bang nhau thi out
		cout << "XIN CHAO VA HEN GAP LAI" << endl;
		exit(0);
	}
}

//man hinh sau khi dang nhap thanh cong
void Screen2(int vanToc, string option)
{ //truyen v, option de biet khi ng chay da chay bao nhieu km va dang chon che do nao (PRND)
	int choice;
	if (!isLogin)
	{ //neu chua dang nhap (isLogin = false) thi thuc hien login, login roi thi bo qua buoc nay
		InputLogin();
	}
	printf("\033c"); //xoa man hinh de menu duoc gon gan sau moi lan hien lai
	do
	{

		if (option == "P" || option == "N")
		{ //khi chon che do P hoac N thi thong bao
			cout << "DA VE SO " << option << ". CHU Y SU DUNG PHANH TAY DE DAM BAO AN TOAN" << endl;
		}
		if (option != " ")
			cout << "BAN DANG TRONG CHE DO " << option << endl
				 << endl; //hien thong bao cho nguoi dung biet dang trong che do nao
		cout << "XIN CHAO " << split(readFile(f_mscn)) << endl
			 << "XIN MOI LUA CHON " << endl;
		cout << "1. P" << endl
			 << "2. R" << endl
			 << "3. N" << endl
			 << "4. D" << endl
			 << "5. POWER OFF" << endl
			 << "  >>>>>>>  "; //menu
		choice = validInput(); //nhap lua chon
		switch (choice)
		{
		case 1:
		{
			printf("\033c");
			if (vanToc == 0)
			{ //khi moi khoi dong, hoac khi phanh xe
				option = "P";
			}
			else
			{ //khi xe co v>0 ma chon dau xe P thi thong bao k thuc hien duoc
				cout << "HAY CHAC CHAN XE DA DUNG VA VAN TOC LA 0 KM/H" << endl;
			}
			break;
		}
		case 2:
		{
			printf("\033c");
			if (vanToc == 0)
			{						   //khi moi khoi dong, hoac khi phanh xe
				Drive_Reverse(7, "R"); //khi moi chay thi v truyen vao tu ham main la 0, nen co the chon dc che do lui xe va khoi tao v=7
			}
			else if (vanToc != 0 && option == "R")
			{								// chon lai chinh no khi thoat khoi menu hop so (co v > 0, khong the chuyen sang cac so khac duoc)
				Drive_Reverse(vanToc, "R"); //khi v>0, sao khi chon che do D hoac R roi, thi v truyen vao luc nay la v hien tai cua xe di chuyen
			}
			else
			{
				cout << "HAY CHAC CHAN XE DA DUNG VA VAN TOC LA 0 KM/H" << endl; //khi v>0 thi k chuyen duoc qua lui xe
			}
			break;
		}
		case 3:
		{
			printf("\033c");
			if (vanToc == 0)
			{ //khi moi khoi dong, hoac khi phanh xe
				option = "N";
			}
			else
			{
				cout << "HAY CHAC CHAN XE DA DUNG VA VAN TOC LA 0 KM/H" << endl; //khi v>0 thi k chuyen duoc qua so N
			}
			break;
		}
		case 4:
		{
			printf("\033c");
			if (vanToc == 0)
			{						   //khi moi khoi dong, hoac khi phanh xe
				Drive_Reverse(7, "D"); //khi moi chay thi v truyen vao tu ham main la 0, nen co the chon dc che do lui xe va khoi tao v=7, chon che do D
			}
			else if (vanToc != 0 && option == "D")
			{								// chon lai chinh no khi thoat khoi menu hop so (co v > 0, khong the chuyen sang cac so khac duoc)
				Drive_Reverse(vanToc, "D"); //khi v>0, sao khi chon che do D hoac R roi, thi v truyen vao luc nay la v hien tai cua xe di chuyen
			}
			else
			{
				cout << "HAY CHAC CHAN XE DA DUNG VA VAN TOC LA 0 KM/H" << endl; //khi xe dang lui R, ma chon sang D thi thong bao khong chuyen duoc
			}
			break;
		}
		case 5:
		{
			printf("\033c");
			cout << "XIN CHAO VA HEN GAP LAI" << endl;
			exit(0); //ket thuc chuong trinh
			break;
		}
		default: //loi khi k nhap 1 trong 5 lua chon
		{
			printf("\033c");
			cout << "VUI LONG NHAP LUA CHON 1-5 !! " << endl;
			break;
		}
		}
	} while (choice != 5); //chon 5 thi ket thuc chuong trinh
}

//che do chay xe, lui xe
void Drive_Reverse(int vanToc, string option)
{ //truyen vao v, option de biet dang trong che do nao va co v la bao nhieu
	int choice;
	printf("\033c");
	do
	{
		cout << "--------- TOC DO HIEN TAI LA: " << vanToc << "km/h" << endl; //luc dau truyen vo thi v=7 (khi khoi dong hoac phanh xe)
		CanhBaoKC(vanToc);
		if (vanToc > 60 && option == "D" || vanToc > 20 && option == "R")
		{ //in thong bao cho D kh v>60, va thong bao cho R khi v>20
			cout << "TOC DO NGUY HIEM, BAN NEN GIAM TOC DO" << endl
				 << endl;
		}
		cout << "MOI LUA CHON" << endl
			 << "1: TANG TOC" << endl
			 << "2: GIAM TOC" << endl
			 << "3: PHANH" << endl
			 << "4: TRO VE MENU" << endl
			 << "  >>  ";
		choice = validInput(); //nhap lua chon
		switch (choice)
		{
		case 1: //tang toc
		{
			printf("\033c");
			vanToc += 5; //tang 5

			break;
		}
		case 2: //giam toc
		{
			printf("\033c");
			vanToc -= 5; //giam 5
			if (vanToc < 0)
			{ //neu v giam xuong nho hon 0 thi gan cho v=0, vi v khong the <0
				vanToc = 0;
			}

			break;
		}
		case 3: //khi dap phanh thi gan v=0
		{
			printf("\033c");
			vanToc = 0;

			break;
		}
		case 4:
		{ //quay mai man hinh menu chinh
			printf("\033c");
			Screen2(vanToc, option); //truyen ra cho menu biet sau khi thuc hien che do D hoac R thi xe co van toc la bao nhieu va dang trong che do D hay R
			break;
		}
		default:
		{
			printf("\033c");
			cout << "VUI LONG NHAP LUA CHON 1-4 !! " << endl;
			break;
		}
		}
	} while (choice != 4);
}