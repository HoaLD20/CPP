#include <iostream>
#include <fstream>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;


int main()
{
	// Get total from file
	int total = 0;
	std::fstream donFile("donation_total2.txt", ios::app);
	std::string lineIn, lastLine;
	while (std::getline(donFile, lineIn))
	{
		lastLine = lineIn;
	}
	donFile.clear();
	total = stoi(lastLine);

	// Get donation
	std::cout << "Enter donation (eg. Tom 25): ";
	std::string name, line;
	int amt;
	std::getline(std::cin, line);
	std::stringstream stream(line);
	stream >> name >> amt;

	// Update total and file
	total += amt;
	donFile << total << std::endl;

	donFile.close();
	return 0;
}