/*
Jordan Gruenewald, Test-Out, jorgruenewald@gmail.com

Test 1: Testing object removed from cart and
Input: "Jordan", "January 1, 2016",
		"add", "BYU hat", "A hat with a Y", 5.00, 1
		"descriptions", "remove", "BYU hat", "descriptions"
Expected output:
	Descriptions before removal:
		BYU hat: A hat with a Y
	Descriptions after removal:
		Shopping cart is empty

Test 2: Testing changing quantities of items in cart
Input: "Jordan", "January 1, 2016",
		"add", "BYU hat", "A hat with a Y", 5.00, 2, "cart",
		"change", "BYU hat", 5, "cart"
Expected output:
	Cart after first add:
		Number of items: 2
		BYU hat 2 @ $5.00 = $10.00
	Cart affter second add:
		Number of items: 5
		BYU hat 5 @ $5.00 = $25.00

Test 3: Testing adding of totals
Input: "Jordan", "January 1, 2016",
		"add", "BYU hat", "A hat with a Y", 5.00, 2,
		"add", "U shirt", "Shirt with a red U", 35.00, 2, "cart"
Expected output:
	Number of items: 4
	Total: $80.00
*/

#include "stdafx.h"
#include "ItemToPurchase.h"
#include "ShoppingCart.h"
#include <iostream>
#include <iomanip>

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
		cout << endl;
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
	else if (input == "quit")
	{
		cout << "Goodbye." << endl;
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

