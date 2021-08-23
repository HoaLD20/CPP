#include <iostream>
#include "showmsg.h"
//show_msg.cpp
using namespace std;


/// <summary>
/// Show message when driver select P of N gear
/// </summary>
/// <param name="type">type of gear</param>
/// <param name="speed">current speed of car</param>
void ShowMsgPN(string type, int speed) {
	/*
	* When the speed is 0 km/h, the vehicle is sucessfully stopped
	  A vehicle can only shift gears to P / N when it is completely stopped.
	*/
	if (speed > 0) {	//the vehicle has not completely stopped
		cout << "HAY CHAC CHAN XE DA DUNG VA VAN TOC LA 0 KM/H" << endl;
	}
	else {
		cout << "DA VE SO " << type << "." << endl;
		cout << "CHU Y SU DUNG PHANH TAY DE DAM BAO AN TOAN" << endl;
	}
}

/// <summary>
/// Set message for safe speed
/// </summary>
/// <param name="speed">current speed of car</param>
/// <param name="arr_speed">list safe speed</param>
/// <returns>message to show in terminal</returns>
string SetMessageSafeSpeed(int speed, int arr_speed[]) {
	string msg = "";
	if (speed < arr_speed[0]) {
		msg = "BAN CHU Y GIU KHOANG CACH TOI THIEU LA 20m";
	}
	if (speed >= arr_speed[0] && speed < arr_speed[1]) {
		msg = "BAN CHU Y GIU KHOANG CACH TOI THIEU LA 55m";
	}
	if (speed >= arr_speed[1] && speed < arr_speed[2]) {
		msg = "BAN CHU Y GIU KHOANG CACH TOI THIEU LA 70m";
	}
	if (speed >= arr_speed[2]) {
		msg = "BAN CHU Y GIU KHOANG CACH TOI THIEU LA 100m";
	}
	return msg;
}
