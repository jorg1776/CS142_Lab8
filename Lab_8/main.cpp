#include "stdafx.h"

#include <iostream>
#include <iomanip>
#include "ItemToPurchase.h"
#include "ShoppingCart.h"


void DisplayOptions()
{
	cout << "MENU" << endl;
	cout << "add - Add item to cart" << endl;
	cout << "remove - Remove item from cart" << endl;
	cout << "change - Change item quantity" << endl;
	cout << "descriptions - Output items' descriptions" << endl;
	cout << "cart - Output shopping cart" << endl;
	cout << "options - Print the options menu" << endl;
	cout << "quit - Quit" << endl;
	cout << endl;
}

bool HandleOptionInput(string input)
{
	if (input == "add")
	{
		return true;
	}
	else if (input == "remove")
	{
		return true;
	}
	else if (input == "change")
	{
		return true;
	}
	else if (input == "descriptions")
	{
		return true;
	}
	else if (input == "cart")
	{
		return true;
	}
	else if (input == "options")
	{
		DisplayOptions();
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	string customerName;
	string date;

	cout << "Enter Customer's Name: ";
	getline(cin, customerName);
	cout << "Enter Today's Date: ";
	getline(cin, date);
	cout << endl;

	bool isOptionValid = false;
	string option;
	do
	{
		cout << "Enter option:";
		getline(cin, option);
		isOptionValid = HandleOptionInput(option);
	} while (isOptionValid == false);

	system("pause");
	return 0;
}

