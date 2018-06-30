#include "stdafx.h"

#include "ItemToPurchase.h"

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