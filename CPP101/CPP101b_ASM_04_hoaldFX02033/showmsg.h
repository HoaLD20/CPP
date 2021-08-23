#pragma once
#include <iostream>
using namespace std;

/// <summary>
/// Set message for safe speed
/// </summary>
/// <param name="speed">current speed of car</param>
/// <param name="arr_speed">list safe speed</param>
/// <returns>message to show in terminal</returns>
string SetMessageSafeSpeed(int speed, int arr_speed[]);

/// <summary>
/// Show message when driver select P of N gear
/// </summary>
/// <param name="type">type of gear</param>
/// <param name="speed">current speed of car</param>
void ShowMsgPN(string type, int speed);