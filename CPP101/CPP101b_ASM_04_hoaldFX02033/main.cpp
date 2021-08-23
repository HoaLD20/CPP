/*
	Author	: Le Duc Hoa
	Code	: FX02033
*/
#include <iostream>
#include <regex>
#include "sort.h"
#include "showmsg.h"
#include "manipulation.h"
#include "car.h"

#define P 1			  // gear of car
#define R 2			  // gear of car
#define N 3			  // gear of car
#define D 4			  // gear of car
#define POWER_OFF 5	  // turn of the engine
#define TANG_TOC 6	  // increase speed
#define GIAM_TOC 7	  // decrease speed
#define PHANH 8		  // brake the engine
#define TRO_VE_MENU 9 // back to main menu

using namespace std;

Car *car = new Car();			 // store user input
int g_user_input[8];				 // user input personal code
string g_file_name = "asm03.dat"; // file saved personal code

/// <summary>
/// Get safe speed from user
/// </summary>
/// <returns>list 3 safe speed in ordered</returns>
int *GetSafeSpeed()
{
	printf("\033c");
	int l_safe_speed[3];
	string msg = "";	   // message show in terminal
	string temp_speed = ""; // get user input to check valid data
	cout << "CAI DAT MUC VAN TOC CANH BAO KHOANG CACH AN TOAN VOI 3 MUC VAN TOC:" << endl;
	// for (int i = 0; i < 3; i++)
	// {
	// 	l_safe_speed[i] = CheckValidInput("VAN TOC MUC ", "NHAP LAI VAN TOC MUC ", i, "\\d+");

	// }

	do
	{
		for (int i = 0; i < 3; i++)
		{ //nhap 3 muc va toc
			// cout << "MUC VAN TOC " << i + 1 << " : ";
			//nhpa muc van toc la so
			l_safe_speed[i] = CheckValidInput("VAN TOC MUC ", "NHAP LAI VAN TOC MUC ", i, "\\d+");
		}
		//cac muc van toc k dc nhap bang nhau
		if ((l_safe_speed[0] == l_safe_speed[1]) || (l_safe_speed[0] == l_safe_speed[2]) || (l_safe_speed[1] == l_safe_speed[2]))
		{
			cout << "CAC MUC DO VAN TOC KHONG DUOC BANG NHAU. VUI LONG NHAP LAI!!" << endl;
		}
		//nhap lai neu cac muc van toc bang nhau
	} while ((l_safe_speed[0] == l_safe_speed[1]) || (l_safe_speed[0] == l_safe_speed[2]) || (l_safe_speed[1] == l_safe_speed[2]));

	//use selection sort to sort list safe speed
	SelectionSort(l_safe_speed, 3);
	car->SetSafe(l_safe_speed, 3);
	return car->GetSafe();
}

/// <summary>
/// Getter for preInstall array
/// </summary>
/// <returns>preInstall array</returns>
int *GetPreInstallCode()
{
	return car->GetCode();
}

/// <summary>
/// Get user input personal code
/// </summary>
/// <returns>user input array</returns>
int *UserInputPersonalCode()
{
	string msg = "";
	string temp_number = "";
	cout << "NHAP MA SO CA NHAN, MANG 08 SO:" << endl;
	for (int i = 0; i < 8; i++)
	{
		g_user_input[i] = CheckValidInput("SO THU ", "NHAP LAI SO THU ", i, "\\d");
	}
	return g_user_input;
}

/// <summary>
/// Set personal code from file to global variable
/// </summary>
/// <param name="code">data from file (personal code)</param>
void SetCodeFromFileToPreInstall(int *code)
{
	int index = 7;
	int l_pre_install[8];
	for (int i = 0; i < 8; i++)
	{
		l_pre_install[i] = *(code + i);
	}
	car->SetCode(l_pre_install, 8);
}

/// <summary>
/// Setup personal code for first time login car
/// Or reset personal code when user want to change it
/// </summary>
void SetPreInstallCode()
{
	string msg = "";
	string temp_number = "";
	int l_pre_array[8];
	cout << "CAI DAT MA SO CA NHAN CHO XE, MANG 8 S0:" << endl;
	for (int i = 0; i < 8; i++)
	{
		l_pre_array[i] = CheckValidInput("SO THU ", "NHAP LAI SO THU ", i, "\\d");
	}
	car->SetCode(l_pre_array, 8);
}

/// <summary>
/// Show and compare two array
/// </summary>
/// <param name="preInstall">personal code from file</param>
/// <param name="userInput">personal code from user input</param>
void ShowAndCompareTwoSort(int preInstall[], int userInput[])
{
	// two temp array not to change value of original
	int temp_pre_install[8];
	int temp_user_input[8];

	//two temp array get the same data to compare
	int temp_compare_arr_bubble[8];
	int temp_compare_arr_select[8];
	for (int i = 0; i < 8; i++)
	{
		temp_pre_install[i] = preInstall[i];
		temp_user_input[i] = userInput[i];
		temp_compare_arr_bubble[i] = userInput[i];
		temp_compare_arr_select[i] = userInput[i];
	}

	//show two array before and after sort in terminal
	ShowArray("MANG NHAP VAO TRUOC KHI SAP XEP: ", temp_user_input, 8);
	SelectionSort(temp_user_input, 8); // sort user input by selection sort algorithm
	ShowArray("----> MANG NHAP VAO SAU KHI SAP XEP: ", temp_user_input, 8);

	ShowArray("MA SO CA NHAN TRUOC KHI SAP XEP: ", temp_pre_install, 8);
	BubbleSort(temp_pre_install, 8); // sort user input by bubble sort algorithm
	ShowArray("----> MA SO CA NHAN SAU KHI SAP XEP: ", temp_pre_install, 8);
	cout << endl;

	int count_bubble = BubbleSort(temp_compare_arr_bubble, 8);
	int count_selection = SelectionSort(temp_compare_arr_select, 8);
	//comparison between bubble sort and selection sort
	cout << "SU DUNG MANG MA NGUOI DUNG NHAP VAO DE SO SANH 2 THUAT TOAN SAP XEP" << endl;
	cout << "BUBBLE SORT USE: " << count_bubble << " STEPS" << endl;
	cout << "SELECTION SORT USE: " << count_selection << " STEPS" << endl;
	if (count_bubble > count_selection)
	{
		cout << "SELECTION SORT FASTER THAN BUBBLE SORT" << endl;
	}
	else if (count_bubble < count_selection)
	{

		cout << "BUBBLE SORT FASTER THAN SELECTION SORT" << endl;
	}
	else
	{

		cout << "BUBBLE SORT AS FAST AS SELECTION SORT" << endl;
	}
}

/// <summary>
/// Login to the car
/// </summary>
/// <returns>user is login to the car successfully or not</returns>
bool Islogin()
{
	int number[8];	   // list number user input before sort
	int l_pre_array[8]; // list number car code before sort
	Car *car_read_from_file = new Car();
	car_read_from_file = ReadFile(g_file_name); // get data from file saved personal code
	/*
		For first time login to car, then set this code as default personal code
		if already have personal code, then check is login successfully
		if login successfully, then ask user for changing password, else closing program
	*/
	if (IsArrayEmpty(car_read_from_file->GetCode(), 8))
	{
		SetPreInstallCode(); //get personal code from user
		/*string preInstall = changeArrayToString(car->GetCode(), "", 8);*/
		WriteFile(g_file_name, car);
		cout << "CAI DAT MA SO CA NHAN THANH CONG" << endl;
	}
	else
	{
		SetCodeFromFileToPreInstall(car_read_from_file->GetCode());
	}
	printf("\033c");
	//show and compare two array
	int *ptr_pre_install = GetPreInstallCode();
	int *ptr_user_input = UserInputPersonalCode();

	for (int i = 0; i < 8; i++)
	{
		number[i] = *(ptr_user_input + i);
		l_pre_array[i] = *(ptr_pre_install + i);
	}
	ShowAndCompareTwoSort(l_pre_array, number);
	return !IsDiff(l_pre_array, number);
}

/// <summary>
/// Control car when driver choose R or D gear
/// </summary>
/// <param name="speed">current speed of car</param>
/// <param name="type_drive">type of gear</param>
/// <param name="arr_speed">list safe speed</param>
void GearboxTransmissionSelectionRD(int &speed, string type_drive, int arr_speed[])
{
	//set default value when car starts to drive
	if (speed == 0)
	{
		speed = 7;
	}
	int gear = 0;				  // gear that driver selected
	string temp_gear = "";		  // temperature value to get gear input
	bool check_back_to_menu = false; // check if driver want to back to main menu
	do
	{
		do
		{
			printf("\033c"); // re-display terminal
			cout << "---- TOC DO HIEN TAI: " << speed << endl;
			//set message for safe speed
			cout << SetMessageSafeSpeed(speed, arr_speed) << endl;
			/*
				If speed is over 60 km / h in Drive gear (or over 20km/ h in Reverse gear)
				issue a high-speed warning to the driver
			*/
			if ((type_drive.compare("R") == 0 && speed >= 20) || (type_drive.compare("D") == 0 && speed >= 60))
			{
				cout << "TOC DO NGUY HIEM, BAN NEN GIAM TOC DO" << endl;
			}

			cout << "MOI LUA CHON" << endl;
			cout << "1. TANG TOC" << endl;
			cout << "2. GIAM TOC" << endl;
			cout << "3. PHANH" << endl;
			cout << "4. TRO VE MENU" << endl;
			getline(cin, temp_gear);
			//check selected value from 1 to 4
			if (!regex_match(temp_gear, regex("[1-4]")))
			{
				gear = 5;
			}
			else
			{
				gear = stoi(temp_gear);
			}
		} while (gear > 4 || gear < 1);
		/*
			Equivalent to inceasing speed when choosing the accelerative
			Equivalent to slowing down speed when choosing the decelerative
			And for applying brake, stop the car (decelarate to 0 km/ h)
		*/
		switch (gear + 5)
		{ //plus 5 to suitable for defination
		case TANG_TOC:
			speed += 5;
			break;
		case GIAM_TOC:
			//speed can be negative number
			if (speed < 5)
			{
				speed = 0;
			}
			else
			{
				speed -= 5;
			}
			break;
		case PHANH:
			speed = 0;
			break;
		case TRO_VE_MENU:
			check_back_to_menu = true;
			break;
		}
	} while ((gear >= 1 && gear <= 4) && check_back_to_menu == false);
	printf("\033c"); // re-display terminal
}

/// <summary>
/// Set speed of car from reverse speed or drive speed
/// </summary>
/// <param name="reverse_speed"> reverse speed</param>
/// <param name="drive_speed">drive speed</param>
/// <param name="speed">speed of car</param>
void SetMoveSpeed(int &reverse_speed, int &drive_speed, int &speed)
{
	if (reverse_speed == 0 && drive_speed == 0)
	{
		speed = 0;
	}
	else
	{
		speed = (reverse_speed > drive_speed) ? reverse_speed : drive_speed;
	}
}

/// <summary>
/// Change Password Management
/// </summary>
void ChangePasswordManager()
{
	// ask user for change password
	if (CheckChange("BAN CO MUON DOI MAT KHAU KHONG (Y/N)?"))
	{
		printf("\033c");
		SetPreInstallCode();
		WriteFile(g_file_name, car);
		cout << "DOI MAT KHAU THANH CONG" << endl;
	}
}

/// <summary>
/// Set Safe Speed From File To Global
/// </summary>
/// <param name="str">data read from file</param>
void SetSafeSpeedFromFileToGlobal(int *ptr_speed)
{
	int l_safe_speed[3];
	for (int i = 0; i < 3; i++)
	{
		l_safe_speed[i] = *(ptr_speed + i);
	}
	car->SetSafe(l_safe_speed, 3);
}

/// <summary>
/// Safe Speed Manager
/// </summary>
void SafeSpeedManager()
{
	Car *car_read_from_file = new Car();
	car_read_from_file = ReadFile(g_file_name); // get data from file saved personal code

	int *l_safe_speed = GetSafeSpeed(); // get 3 safe speed from user input then set it in global variable
	bool check_diff = false;

	// check if file dont have data, then set data for it from user input by using global variable
	if (IsArrayEmpty(car_read_from_file->GetSafe(), 3))
	{
		car_read_from_file->SetSafe(car->GetSafe(), 3);
		WriteFile(g_file_name, car_read_from_file);
		cout << "CAI DAT TOC DO AN TOAN THANH CONG" << endl;
	}

	// file have data, then check user input is the same or not
	// if data and user input are the same then do nothing
	else
	{
		int *safe_speed_file = car_read_from_file->GetSafe();
		for (int i = 0; i < 3; i++)
		{
			if (*(l_safe_speed + i) != *(safe_speed_file + i))
			{
				check_diff = true;
				break;
			}
		}
		if (check_diff == true)
		{
			if (CheckChange("TOC DO AN TOAN KHAC GIA TRI MAC DINH\nBAN CO MUON CAI DAT LAI TOC DO AN TOAN KHONG (Y/N)?"))
			{
				car_read_from_file->SetSafe(car->GetSafe(), 3);
				WriteFile(g_file_name, car_read_from_file);
				cout << "THAY DOI TOC DO AN TOAN THANH CONG" << endl;
			}
			else
			{
				SetSafeSpeedFromFileToGlobal(car_read_from_file->GetSafe());
			}
		}
	}
}
/// <summary>
/// Main execution
/// </summary>
int main()
{
	if (!Islogin())
	{
		cout << "GOODBYE AND SEE YOU AGAIN..." << endl;
		return 0;
	}
	// system("pause");
	cout << "\n\tPress any key to continue ....";
	cin.ignore().get();
	ChangePasswordManager();
	// system("pause");
	cout << "\n\tPress any key to continue ....";
	cin.ignore().get();
	SafeSpeedManager();
	// system("pause");
	cout << "\n\tPress any key to continue ....";
	cin.ignore().get();

	bool check_power_off = false; // check if driver want to turn of the car
	int gear = 0;				// declare gear
	int speed = 0;				// current speed of car
	int reverse_speed = 0;		// reverse speed
	int drive_speed = 0;			// drive speed
	string code = "";			// code of driver
	string gear_before = "";		// check gear before to check changing between Reverse and Drive

	code = ChangeArrayToString(car->GetCode(), "", 8);
	printf("\033c");
	cout << "Xin chao " << code << endl;
	/*
		Turn on car until driver turn off the car
	*/
	do
	{
		gear = GearboxTransmissionSelection(); // get gear
		printf("\033c");

		// printf("\033c");

		/*
			1. P (Park): Used to shift gears to Park gear, park and stop the car
			2. R (Reverse): Used to shift gears to Reverse gear, reverse the car
			3. N (Neutral): Used to shift gears to Neutral gear, stop the car
			4. D (Drive): Used to shift gears to Drive gear, move forward
			5. POWER OFF to turn off the engine.
		*/
		switch (gear)
		{
		case P:
			SetMoveSpeed(reverse_speed, drive_speed, speed); //set move speed
			ShowMsgPN("P", speed);
			gear_before = "P";
			break;
		case N:
			SetMoveSpeed(reverse_speed, drive_speed, speed); //set move speed
			ShowMsgPN("N", speed);
			gear_before = "N";
			break;
		case R:
			/*
				check car is go ahead or not
			*/
			if (drive_speed != 0)
			{
				cout << "HAY CHAC CHAN VAN TOC XE LA 0 KM/H TRUOC KHI LUI XE" << endl;
			}
			else
			{
				GearboxTransmissionSelectionRD(reverse_speed, "R", car->GetSafe());
				gear_before = "R";
			}
			break;
		case D:
			/*
				check car is go back or not
			*/
			if (reverse_speed != 0)
			{
				cout << "HAY CHAC CHAN VAN TOC XE LA 0 KM/H TRUOC KHI CHUYEN TU LUI XE SANG CHAY XE" << endl;
			}
			else
			{
				GearboxTransmissionSelectionRD(drive_speed, "D", car->GetSafe());
				gear_before = "D";
			}
			break;
		case POWER_OFF:
			check_power_off = true;
			cout << "SEE YOU AGAIN..." << endl;
			break;
		}
	} while (gear >= 1 && gear <= 5 && check_power_off == false);
}