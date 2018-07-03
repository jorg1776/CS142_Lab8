#include "stdafx.h"

#include <iostream>
#include <iomanip>
#include "ItemToPurchase.h"
#include "ShoppingCart.h"

ItemToPurchase CreateItem()
{
	string itemName;
	string itemDescription;
	double itemPrice;
	int itemQuantity;

	cout << "Enter the item name: ";
	getline(cin, itemName);
	cout << "Enter the item description: ";
	getline(cin, itemDescription);
	cout << "Enter the item price: ";
	cin >> itemPrice;
	cout << "Enter the item quantity: ";
	cin >> itemQuantity;

	cin.ignore(256, '\n');

	return ItemToPurchase(itemName, itemDescription, itemPrice, itemQuantity);
}

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

void HandleOptionInput(string input, ShoppingCart &cart)
{
	if (input == "add")
	{
		ItemToPurchase item = CreateItem();
		cart.AddItemToCart(item);
	}
	else if (input == "remove")
	{
		string itemToRemove;
		cout << "Enter name of the item to remove: ";
		getline(cin, itemToRemove);

		cart.RemoveItemFromCart(itemToRemove);
	}
	else if (input == "change")
	{
		string newName;
		int newQuantity;
		cout << "Enter the item name: ";
		getline(cin, newName);
		cout << "Enter the new quantity: ";
		cin >> newQuantity;
		cin.ignore(256, '\n');

		cart.UpdateItemQuantity(newName, newQuantity);
	}
	else if (input == "descriptions")
	{
		cart.PrintCartDescription();
		cart.PrintItemDescriptions();
	}
	else if (input == "cart")
	{
		cart.PrintCartDescription();
		cart.PrintItemTotalsAndCosts();
	}
	else if (input == "options")
	{
		DisplayOptions();
	}
	else
	{
		cout << "Invalid option" << endl;
	}
}

ShoppingCart CreateCart()
{
	string customerName;
	string date;

	cout << "Enter Customer's Name: ";
	getline(cin, customerName);
	cout << "Enter Today's Date: ";
	getline(cin, date);
	cout << endl;

	return ShoppingCart(customerName, date);
}

int main()
{
	ShoppingCart cart = CreateCart();

	string option;
	do
	{
		cout << "Enter option: ";
		getline(cin, option);
		HandleOptionInput(option, cart);
	} while (option != "quit");

	system("pause");
	return 0;
}

