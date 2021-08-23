#include <iostream>
#include "car.h"
using namespace std;
/*
 <summary>
 Get personal code
 </summary>
 <returns>personal code array</returns>
 */
int *Car::GetCode()
{
	return Car::code;
}
/*
 <summary>
 Get safe distance
 </summary>
 <returns>safe distance array</returns>
*/
int *Car::GetSafe()
{
	return Car::safe;
}
/*
 <summary>
 Set safe distance array
 </summary>
 <param name="s">array to set safe distance</param>
*/
void Car::SetSafe(int s[], int length)
{
	for (int i = 0; i < length; i++)
	{
		Car::safe[i] = s[i];
	}
}
/*
 <summary>
 Set personal code array
 </summary>
 <param name="code">array to set personal code array</param>
*/
void Car::SetCode(int code[], int length)
{
	for (int i = 0; i < length; i++)
	{
		Car::code[i] = code[i];
	}
}