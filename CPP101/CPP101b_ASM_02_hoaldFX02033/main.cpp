
/**
 * Author: Le Duc Hoa - hoaldfx02033
 * 
 */
#include <iostream>
#include <string>
using namespace std;

int vanToc;			  //khoi tao bien van toc cua xe
bool isLogin = false; //khoi toa bien de kiem tra xem ng dung da dang nhap r hay chua(phan biet khi chuyen tu menu D N P R sang menu chinh de k can login lai)
string option;		  //danh dau lua chon che do nao trong 4 che do
int mucVannToc[3];	  //khai bao mang chua muc van toc
int v1, v2, v3;		  //van toc muc 1 2 3
//kiem tra input dau vao co la so hay khong
int checkChoice()
{
	int choice;
	while (!(cin >> choice))
	{
		cout << "NHAP SAI LUA CHON. VUI LONG NHAP LAI: ";
		//khi xay ra loi khi lay dau vao tu cin thi loi van con xuat hien trong vong lap while, vi vay dung clear de xoa loi do
		//khi input vao bi sai thi gia tri do duoc luu vao bo nho dem, vi vay can dung ignore de bo qua 456 ki tu dau tien nhung se dung cho den khi gap \n (xuong hang)
		//nhu vay co the xoa duoc loi vua nhap sai va bo qua duoc ki tu nhap sai trong bo nho dem, de co the nhap lai ki tu moi
		//neu khong dung thi no cu doc ki tu sai trong bo nho dem => bi lap mai mai
		cin.clear();
		cin.ignore(456, '\n');
	}
	isLogin = true; //danh dau da login roi
	return choice;
}

//kiem tra chuoi nhap vao co chua ki tu so khong
bool isNumber(string s)
{
	//chay tu ki tu dau den ki tu cuoi cua chuoi
	for (int i = 0; i < s.size(); i++)
	{
		//neu chuoi nhap vao khon co cac ki tu nam trong khoanh cha '0'-'9' trong bang ascci thi chuoi k phai toan chua ki tu so
		if ((s[i] >= '0' && s[i] <= '9') == false)
		{
			return false; //chu
		}
	}
	return true;
}

//in mang ra khi chua sx
void printArray(int arr[], int size)
{
	int i;
	//in ra tung phan tu cua mang
	//size la do dai cua mang
	for (i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

//ham swap
void swap(int *xp, int *yp)
{
	//thuc hien swap 2 phan tu voi nha
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

int bubbleSort(int *pointer, int size)
{
	int count1, count2, swap, complex = 0;
	//di tu ptu dau toi ptu cuoi
	for (count1 = 0; count1 < size - 1; count1++)
	{
		// di tu phan tu dau tien toi phan tu cuoi khi phan tu cuoi do chua dc sx
		for (count2 = 0; count2 < size - count1 - 1; count2++)
		{
			++complex;
			// so sanh 2 so lien ke
			if (*(pointer + count2) > *(pointer + count2 + 1))
			{
				// doi cho 2 so
				swap = *(pointer + count2);
				*(pointer + count2) = *(pointer + count2 + 1);
				*(pointer + count2 + 1) = swap;
			}
		}
	}
	return complex;
}

// bubble sort
// int bubbleSort(int arr[], int n)
// {
// 	int i, j, complex = 0;
// 	bool check = false;
// 	//di tu ptu dau toi ptu cuoi
// 	for (i = 0; i < n - 1; i++)
// 	{

// 		// di tu phan tu dau tien toi phan tu cuoi khi phan tu cuoi do chua dc sx
// 		for (j = 0; j < n - i - 1; j++)
// 		{
// 			++complex; //dem so lan lap cua thuat toan de tinh do phuc tap
// 			if (arr[j] > arr[j + 1])
// 			{								//neu 2 thang nam ke nhau co thang trc lon hon thang sau, thi doi cho
// 				swap(&arr[j], &arr[j + 1]); //thuc hien swap
// 				// kiem tra xem co phai truong hop bestcase cua bbsort khong (bestcase: 1234..), neu la bestcase thi chi can
// 				//lap qua 1 lan va k doi cho giua cac phtu, roi cho thoat khoi ham sort luon
// 				check = true;
// 			}
// 		}
// 		//neu k swap thi out (toi uu thuat toan, k can lap lai nhieu lan, chi can lap qua 1 lan ma k swap thi out luon)
// 		if (!check)
// 		{
// 			return complex;
// 		}
// 	}
// 	return complex;
// }

// Ham selection sort
// int selectionSort(int a[], int n)
// {
// 	int complex = 0;				//tinh do phuc tap cua thuat toan
// 	for (int i = 0; i < n - 1; i++) //chay tu ptu dau toi ptu cuoi cua mang
// 	{
// 		int iMin = i;					//gan i la phan tu nho nhat trong mang
// 		for (int j = i + 1; j < n; j++) //di tu phan tu i+1 de so sanh i voi nhung ptu sau
// 		{
// 			++complex;			//dem so lan lap cua thuat toan de tinh do phuc tap
// 			if (a[iMin] > a[j]) //neu min>j thi gan thang j la ptu nho nhat mang, va tiep tiep tim phan tu nho nhat trong mang cho het vong lap for cua j
// 				iMin = j;		// gan j la ptu nho nhat
// 		}
// 		if (i != iMin)			   //neu tim duoc ptu nho nhat kha i (luc dau gan min =i) thi thuc hien swap
// 			swap(&a[i], &a[iMin]); //doi cho i va min, dem thang min len vi tri dau tien
// 	}
// 	return complex;
// }

// function to sort an array
int selectionSort_Pointer(int *const array, const int size)
{
	int smallest; // index of smallest element
	int complex = 0;
	for (int i = 0; i < size - 1; i++)
	{
		smallest = i; // first index of remaining array

		// loop to find index of smallest element
		for (int index = i + 1; index < size; index++)
		{
			++complex;
			if (array[index] < array[smallest])
				smallest = index;
		}

		swap(&array[i], &array[smallest]);
	}
	return complex;
}

// swap values at memory locations to which
// x and y point
// void swap_pointer(int *const x, int *const y)
// {
// 	int temp = *x;
// 	*x = *y;
// 	*y = temp;
// }

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

//man hinh dang nhap
void InputLogin()
{
	//mang ma chuong trinh cay dat san
	int maSoMacDinh[8] = {8, 5, 2, 1, 3, 6, 4, 7};
	isLogin = true;			  // kiem tra chuong trinh da login chưa khi chuyen tu menu phu sang menu chinh(menu so)
	int maSoNhap[8];		  //mang chua gia tri ma ng dung nhap vao
	string input;			  //truyen vao trong ham check co phai la so khong hay la chu, neu la so thi gan gi tri phan tu cua mang cho gia tri input do (check is Number)
	int checkEqualArr = 0;	  //kiem tra chuoi ng dung nhap vao va chuoi gan cung trong chuong trinh co bang nhau khong
	int checkNotEqualArr = 0; //danh dau 2 chuoi khong bang
	bool checkMSCN = false;	  //check ma so ca nhan
	bool checkMVT = false;	  //check ma van toc

	cout << "NHAP MA SO CA NHAN, MANG 08 SO" << endl;
	//nhap 8 so cho mang
	for (int i = 0; i < 8; i++)
	{
		cout << "SO THU " << i + 1 << " : ";
		do
		{
			cin >> input;
			if (!isNumber(input))
			{ //kiem tra chuoi nhap vao co chua ki tu so khong (neu la so thi nhap lai chuoi)
				cout << "MA SO CA NHAN LA SO. VUI LONG NHAP LAI!! " << endl
					 << "SO THU " << i + 1 << " :";
				cin.clear();
				cin.ignore(456, '\n');
				checkMSCN = false; //check ma so ca nhan, neu MSCN nhap sai (false) thi nhap lai cho den khi dung
			}
			else
			{
				maSoNhap[i] = stoi(input); //neu chuoi nhap vao chua ki tu so thi chuyen chuoi sang int
				checkMSCN = true;		   //danh dau da nhap dung, k can nhap lai
			}
		} while (checkMSCN == false); //nhap sai nhap lai
	}
	printf("\033c"); //xoa mang hinh
	//mang ng dung nhap vao va su dung selection sort
	cout << "MANG NHAP VAO TRUOC KHI SAP XEP:  ";
	printArray(maSoNhap, 8);								   //in ra chuoi moi nhap xong ( chua sort)
	int complexSelection = selectionSort_Pointer(maSoNhap, 8); //thuc hien selection sort la gan gia trij tra ve cua ham sort la do phuc tam cua thuat toan nay
	cout << "-------> MANG NHAP VAO SAU KHI SAP XEP: ";		   //in r mang vua sx
	printArray(maSoNhap, 8);

	//mang mac dinh la dung bubble sort
	//SORT ma mat dinh
	cout << "MA SO CA NHAN TRUOC TRUOC KHI SAP XEP: ";
	printArray(maSoMacDinh, 8);
	int complexBubble = bubbleSort(maSoMacDinh, 8);
	cout << "-------> MA SO CA NHAN SAU KHI SAP XEP: ";
	printArray(maSoMacDinh, 8);
	//so sanh
	SoSanhDoPhucTap(complexSelection, complexBubble);
	// kiem tra 2 mang co bang nhau khong
	// string a;
	// getline(cin, a);
	// cin.get();
	for (int i = 0; i < 8; i++)
	{
		if (maSoNhap[i] == maSoMacDinh[i])
		{					 //neu cac phan tu cua mang bang nhau
			++checkEqualArr; //bien kiem tra bang nhau tang
		}
		else
		{
			++checkNotEqualArr; //neu co ptu k bang nhau thi bien check tang
		}
	}
	cout << "\n\tPress any key to continue ....";
	cin.ignore().get();

	if (checkNotEqualArr == 0)
	{ //neu chuoi bang nhau
		printf("\033c");
		cout << "CAI DAT VAN TOC CANH BAO KHOANG CACH AN TOAN VOI 3 MUC TOC DO " << endl;
		do
		{
			for (int i = 0; i < 3; i++)
			{ //nhap 3 muc va toc
				cout << "MUC VAN TOC " << i + 1 << " : ";
				do
				{
					cin >> input; //nhap chuoi muc van toc dau vao
					if (!isNumber(input))
					{ //kiem tra chuoi co chua toan ki tu so khong
						cout << "MUC VAN TOC LA SO. VUI LONG NHAP LAI!! " << endl
							 << "MUC VAN TOC " << i + 1 << " :";
						cin.clear();
						cin.ignore(456, '\n');
						checkMVT = false; //danh dau muc van toc k la so
					}
					else
					{
						mucVannToc[i] = stoi(input); //neu chuoi nhap vao chua toan ki tu so thi ep chuoi sang int bo vao man van toc
						checkMVT = true;			 //danh dau muc van toc la so
					}
				} while (checkMVT == false); //nue k chua ki tu so thi nhap lai
			}
			//cac muc van toc k dc nhap bang nhau
			if ((mucVannToc[0] == mucVannToc[1]) || (mucVannToc[0] == mucVannToc[2]) || (mucVannToc[1] == mucVannToc[2]))
			{
				cout << "CAC MUC DO VAN TOC KHONG DUOC BANG NHAU. VUI LONG NHAP LAI!!" << endl;
			}
			//nhap lai neu cac muc van toc bang nhau
		} while ((mucVannToc[0] == mucVannToc[1]) || (mucVannToc[0] == mucVannToc[2]) || (mucVannToc[1] == mucVannToc[2]));
		bubbleSort(mucVannToc, 3); //sort muc van toc nhap vao
		//gna cac muc van toc 1, 2, 3
		v1 = mucVannToc[0];
		v2 = mucVannToc[1];
		v3 = mucVannToc[2];
	}
	else
	{
		//neu chuoi k bang nhau thi out
		cout << "XIN CHAO VA HEN GAP LAI" << endl;
		exit(0);
	}
}

//dat ten cua function Drive truoc khi su dung no, neu khong thi se k xac dinh duoc drive vi drive khai bao o duoi Screen 2, nen can phai khai bao trên Screen 2
void Drive_Reverse(int vanToc, string option);

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
		cout << "XIN CHAO 12345678" << endl
			 << "XIN MOI LUA CHON " << endl;
		cout << "1. P" << endl
			 << "2. R" << endl
			 << "3. N" << endl
			 << "4. D" << endl
			 << "5. POWER OFF" << endl
			 << "  >>>>>>>  ";	//menu
		choice = checkChoice(); //nhap lua chon
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
			cout << "CAM ON BAN DA SU DUNG UNG DUNG" << endl;
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
		choice = checkChoice(); //nhap lua chon
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

int main()
{
	Screen2(0, " "); //goi man hinh menu hop so, truyen vo van toc ban dau la 0 va k lua chon che do so (" ")
	return 0;
}
