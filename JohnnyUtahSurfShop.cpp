// JohnnyUtahSurfShop.cpp : This program allows you to make purchases of small, medium, and large size surfboards.
//

// Declaring the required headings needed.

#include <iostream>
#include <iomanip>
#include <cctype>

using namespace std;

// Listing the required constants for the program.
int totalQuantitySmall, totalQuantityMedium, totalQuantityLarge, totalQuantityXXXS;

void ShowUsage();

void MakePurchase(int& iTotalSmall, int& iTotalMedium, int& iTotalLarge, int& iTotalXXXS);
void DisplayPurchase(const int iTotalSmall, const int iTotalMedium, const int iTotalLarge, const int iTotalXXXS);
void DisplayTotal(const int iTotalSmall, const int iTotalMedium, const int iTotalLarge, const int iTotalXXXS);

int main()
{
	char choice;
	//int quantity;
	totalQuantitySmall = totalQuantityMedium = totalQuantityLarge = totalQuantityXXXS = 0;

	// Display title of program.
	cout << "***********************************************************************" << endl;
	cout << "*****Welcome to my Johnny Utah's PointBreak Surf Shop*****" << endl;
	cout << "***********************************************************************" << endl << endl;

	ShowUsage();

	//Create a while loop until the selected choice does not equal q.
	while (true)
	{
		// Display prompt for user to select.
		cout << "\nPlease enter selection: ";
		cin >> choice;

		//If user selects s as the choice, call the function.
		if (tolower(choice) == 's')
		{
			ShowUsage();
		}
		else if (tolower(choice) == 'p')
		{
			MakePurchase(totalQuantitySmall, totalQuantityMedium, totalQuantityLarge, totalQuantityXXXS);
			cout << endl;
		}
		else if (tolower(choice) == 'c')
		{
			if (totalQuantitySmall == 0 && totalQuantityMedium == 0 && totalQuantityLarge == 0 && totalQuantityXXXS == 0)
			{
				cout << "No purchase has been made." << endl;
			}
			else
			{
				DisplayPurchase(totalQuantitySmall, totalQuantityMedium, totalQuantityLarge, totalQuantityXXXS);
			}
		}
		else if (tolower(choice) == 't')
		{
			//If the quantity is equal to 0, display a message.
			if (totalQuantitySmall == 0 && totalQuantityMedium == 0 && totalQuantityLarge == 0 && totalQuantityXXXS == 0)
			{
				cout << "No purchase has been made." << endl;
			}
			else
			{
				DisplayTotal(totalQuantitySmall, totalQuantityMedium, totalQuantityLarge, totalQuantityXXXS);
			}
		}
		else if (tolower(choice) == 'q')
		{
			cout << "Program exiting..." << endl;
			break;
		}
		else
		{
			cout << "The choice is invalid." << endl;
		}
	}
	return 0;
}

void ShowUsage()
{
	//Display the menu of choices for the user.

	cout << "To show program usage press 'S'" << endl;
	cout << "To purchase a surfboard press 'P'" << endl;
	cout << "To display current purchase press 'C'" << endl;
	cout << "To display total amount due press 'T'" << endl;
	cout << "To quit the program press 'Q'" << endl;

}

void MakePurchase(int& iTotalSmall, int& iTotalMedium, int& iTotalLarge, int& iTotalXXXS)
{
	//Declare the variables required.
	int quantity = 0;
	char size = '\0';

	//Require user to enter the quanity and size of the surfboard.
	cout << "What size surfboard would you like? (Small (s), Medium (m), Large (l), Extra-Extra-Extra Small (x) : ";
	cin >> size;
	cout << "How many surfboards you would like to purchase? : ";
	cin >> quantity;

	if (tolower(size) == 's')
	{
		iTotalSmall = iTotalSmall + quantity;
	}
	else if (tolower(size) == 'm')
	{
		iTotalMedium = iTotalMedium + quantity;
	}
	else if (tolower(size) == 'l')
	{
		iTotalLarge = iTotalLarge + quantity;
	}
	else if (tolower(size) == 'x')
	{
		iTotalXXXS = iTotalXXXS + quantity;
	}
}

void DisplayPurchase(const int iTotalSmall, const int iTotalMedium, const int iTotalLarge, const int iTotalXXXS)
{
	if (iTotalSmall > 0)
	{
		cout << "The total number of small surfboards is " << iTotalSmall;
		cout << endl;
	}
	if (iTotalMedium > 0)
	{
		cout << "The total number of medium surfboards is " << iTotalMedium;
		cout << endl;
	}
	if (iTotalLarge > 0)
	{
		cout << "The total number of large surfboards is " << iTotalLarge;
		cout << endl;
	}
	if (iTotalXXXS > 0)
	{
		cout << "The total number of XXXS surfboards is " << iTotalXXXS;
		cout << endl;
	}
}

void DisplayTotal(const int iTotalSmall, const int iTotalMedium, const int iTotalLarge, const int iTotalXXXS)
{
	double surfboard_amount_small, surfboard_amount_medium, surfboard_amount_large, surfboard_amount_xxxs, totalAmtDue;

	surfboard_amount_small = surfboard_amount_medium = surfboard_amount_large = surfboard_amount_xxxs = totalAmtDue = 0;

	//Set a precision for double values to two decimal places.
	cout << fixed << setprecision(2);

	//declare constant variables
	double costOfSmallSurfboard = 175.00;
	double costOfMediumSurfboard = 190.00;
	double costOfLargeSurfboard = 200.00;
	double costOfXXXSSurfboard = 25.00;

	if (iTotalSmall > 0)
	{
		surfboard_amount_small = iTotalSmall * costOfSmallSurfboard;
		cout << "The total number of small surfboards is " << iTotalSmall;
		cout << " at a total of $ ";
		cout << surfboard_amount_small << endl;

		// Calculate the total number of small surfboards to the total amount.
		totalAmtDue = totalAmtDue + surfboard_amount_small;
	}
	if (iTotalMedium > 0)
	{
		surfboard_amount_medium = iTotalMedium * costOfMediumSurfboard;
		cout << "The total number of medium surfboards is " << iTotalMedium;
		cout << " at a total of $ ";
		cout << surfboard_amount_medium << endl;

		//Calculate the total number of medium surfboards to the total amount.
		totalAmtDue = totalAmtDue + surfboard_amount_medium;
	}
	if (iTotalLarge > 0)
	{
		surfboard_amount_large = iTotalLarge * costOfLargeSurfboard;
		cout << "The total number of large surfboards is " << iTotalLarge;
		cout << " at a total of $ ";
		cout << surfboard_amount_large << endl;

		//Calculate the total number of large surfboards to the total amount.
		totalAmtDue = totalAmtDue + surfboard_amount_large;
	}
	if (iTotalXXXS > 0)
	{
		surfboard_amount_xxxs = iTotalXXXS * costOfXXXSSurfboard;
		cout << "The total number of XXXS surfboards is " << iTotalXXXS;
		cout << " at a total of $ ";
		cout << surfboard_amount_xxxs << endl;

		//Calculate the total number of xxxs surfboards to the total amount.
		totalAmtDue = totalAmtDue + surfboard_amount_xxxs;
	}

	cout << "Amount due: $ " << totalAmtDue << endl;

}