#include "header.h"

using namespace std;

int main()
{
start:
    system("cls");
    string dir;
    char dLetter;
    cout << "Enter drive letter (eg: \'C\' or \'c\'): ";
    cin >> dLetter;
    dir.push_back(dLetter);
    dir += ":/";

    char choice;
    unsigned int passNo;

    error_code ec;
    filesystem::space_info spaceInfo;

    if(space_inquiry(dir,ec, spaceInfo))
    {
        if(ec.value() == 0)
        {
            cout << "Total space:\t" << spaceInfo.capacity << " bytes" << endl;
            cout << "Free space:\t" << spaceInfo.free << " bytes" << endl;
            cout << "Available space:\t" << spaceInfo.available << " bytes" << endl;

            cout << "Proceed to wipe free space (Y/N)? ";
choices:
            cin >> choice;

            if (choice == 'n' || choice == 'N')
            {
                goto start;
            }
            else if (choice == 'y' || choice == 'Y')
            {
                cout << "Enter number of passes (0 to return/cancel): ";
                cin >> passNo;

                if (passNo == 0)
                {
                    goto start;
                }
                else
                {
                    wiper(dir, spaceInfo.available, passNo);
                }
            }
            else
            {
                cout << "Invalid input. (Y/N)? ";
                goto choices;
            }
        }

        else
        {
            cout << "An error occured. Error code: " << ec.value() << ", Error msg: " << ec.message() <<endl;
        }
    }
    else
    {
        cout << "Directory not found." << endl;
    }

    cout << "Wipe another directory (Y/N)? ";
    cin >> choice;
    if (choice == 'y' || choice == 'Y')
    {
        goto start;
    }
    else
    {
        return 1;
    }
}
