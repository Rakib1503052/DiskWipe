#include "header.h"

using namespace std;

int main()
{
start:
	system("cls");
	string dir;
	cout << "Enter directory: ";
	cin >> dir;

	map<string, size_t> spaceInfo = space_inquiry(dir);
	
	cout << "Total space:\t" << spaceInfo["capacity"] << "bytes" << endl;
	cout << "Free space:\t" << spaceInfo["free"] << "bytes" << endl;
	cout << "Available space:\t" << spaceInfo["available"] << "bytes" << endl;

	cout << "Proceed to wipe free space (Y/N)? ";
	char choice;
	int passNo;
choices:
	cin >> choice;

	if (choice == 'n' || choice == 'N') { goto start; }
	else if (choice == 'y' || choice == 'Y')
	{
	passIn:
		cout << "Enter number of passes (0 to return): ";
		cin >> passNo;
		if (passNo < 0) { cout << "Invalid input." << endl; goto passIn; }
		else if (passNo == 0) { goto start; }
		else { wiper(dir, spaceInfo["free"], passNo); }
	}
	else { cout << "Invalid input. (Y/N)? "; goto choices; }

	cout << "Wipe another directory (Y/N)? ";
	cin >> choice;
	if (choice == 'n' || choice == 'N') { goto start; }
	else { return 1; }
}