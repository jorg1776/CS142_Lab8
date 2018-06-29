#include "stdafx.h"

#include <iostream>
#include <iomanip>
#include "ItemToPurchase.h"

int main()
{
	ItemToPurchase item1;
	ItemToPurchase item2;

	for (int i = 1; i <= 2; i++)
	{
		string name;
		double price;
		int quantity;

		cout << "Item " << i << endl;
		cout << "Enter the item name : ";
		getline(cin, name);
		cout << "Enter the item price : ";
		cin >> price;
		cout << "Enter the item quantity : ";
		cin >> quantity;

		cout << endl;
		cin.ignore();

		if (i == 1)
			item1 = ItemToPurchase(name, price, quantity);
		else
			item2 = ItemToPurchase(name, price, quantity);
	}
	
	cout << "TOTAL COST" << endl;

	cout << setprecision(2) << fixed;
	cout << item1.GetName() << " " << item1.GetQuantity() << " @ $" << item1.GetPrice() << " = $" << item1.GetPrice() * item1.GetQuantity() << endl;
	cout << item2.GetName() << " " << item2.GetQuantity() << " @ $" << item2.GetPrice() << " = $" << item2.GetPrice() * item2.GetQuantity() << endl;
	cout << endl;

	double totalPrice = item1.GetPrice() * item1.GetQuantity() + item2.GetPrice() * item2.GetQuantity();
	cout << "Total: $" << totalPrice << endl;

	system("pause");
	return 0;
}

