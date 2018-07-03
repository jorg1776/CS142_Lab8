#include "stdafx.h"
#include "ShoppingCart.h"
#include <iostream>
using namespace std;

ShoppingCart::ShoppingCart(string customerName, string dateCreated)
{
	this->customerName = customerName;
	this->dateCreated = dateCreated;
}

string ShoppingCart::GetCustomerName() { return customerName; }

string ShoppingCart::GetDateCreated() { return dateCreated; }

bool ShoppingCart::CheckCartForItem(string itemName)
{
	if (items.size() == 0) //if cart is empty
		return false;

	for (int i = 0; i < items.size(); i++)
	{
		if (items.at(i).GetName() == itemName)
			return true;
		else
			return false;
	}
}

void ShoppingCart::AddItemToCart(ItemToPurchase item) 
{	
	if (CheckCartForItem(item.GetName()) == false) //if item not in cart
		items.push_back(item);
	else
		cout << "Item is already in cart. Nothing added." << endl << endl;
}

void ShoppingCart::RemoveItemFromCart(string itemName) 
{
	for (int i = 0; i < items.size(); i++)
	{
		if (items.at(i).GetName() == itemName)
		{
			items.erase(items.begin() + i);
		}
	}
}

void ShoppingCart::UpdateItemQuantity(string itemName, int newQuantity) 
{
	for (int i = 0; i < items.size(); i++)
	{
		if (items.at(i).GetName() == itemName)
		{
			items.at(i).SetQuantity(newQuantity);
		}
	}
}

int ShoppingCart::GetNumOfItems() 
{
	int numOfItems = 0;

	for (int i = 0; i < items.size(); i++)
	{
		numOfItems += items.at(i).GetQuantity();
	}

	return numOfItems;
}

double ShoppingCart::GetTotalCost() 
{ 
	double totalCost = 0.0;

	for (int i = 0; i < items.size(); i++)
	{
		totalCost += items.at(i).GetPrice();
	}

	return totalCost;
}

void ShoppingCart::PrintItemTotalsAndCosts() 
{
	if (GetNumOfItems() > 0)
	{
		cout << "Number of items: " << GetNumOfItems() << endl;
		cout << endl;
	
		for (int i = 0; i < items.size(); i++)
		{
			items.at(i).PrintCost();
		}
	}
	else
		cout << "Shopping cart is empty" << endl << endl;
}

void ShoppingCart::PrintItemDescriptions() 
{ 
	if (GetNumOfItems() > 0)
	{
		cout << "Item Descriptions" << endl;
		cout << endl;

		for (int i = 0; i < items.size(); i++)
		{
			items.at(i).PrintDescription();
		}
	}
	else
		cout << "Shopping cart is empty" << endl << endl;
} 

void ShoppingCart::PrintCartDescription()
{
	cout << customerName << "'s Shopping Cart - " << dateCreated << endl;
}