#include "stdafx.h"

#include "ItemToPurchase.h"
#include <iostream>
#include <iomanip>

ItemToPurchase::ItemToPurchase(string name, string description, double price, int quantity)
{
	itemName = name;
	itemPrice = price;
	itemQuantity = quantity;
}

void ItemToPurchase::SetName(string name){ itemName = name; }

string ItemToPurchase::GetName() { return itemName; }

void ItemToPurchase::SetPrice(double price) { itemPrice = price; }

double ItemToPurchase::GetPrice() { return itemPrice; }

void ItemToPurchase::SetQuantity(int quantity) { itemQuantity = quantity; }

int ItemToPurchase::GetQuantity() { return itemQuantity; }

void ItemToPurchase::SetItemDescription(string description) { itemDescription = description; }

string ItemToPurchase::GetItemDescription() { return itemDescription; }

void ItemToPurchase::PrintCost()
{
	cout << setprecision(2) << fixed;
	cout << itemName << " " << itemQuantity << " @ $" << itemPrice << " = $" << itemPrice * itemQuantity << endl;
}

void ItemToPurchase::PrintDescription()
{
	cout << itemName << ": " << itemDescription << endl;
}