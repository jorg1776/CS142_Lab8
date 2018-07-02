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

void ShoppingCart::AddItemToCart(ItemToPurchase item) {	items.push_back(item); }

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
	cout << "Number of items: " << GetNumOfItems() << endl;
	cout << endl;
	
	for (int i = 0; i < items.size(); i++)
	{
		items.at(i).PrintCost();
	}
}

void ShoppingCart::PrintItemDescriptions() 
{ 
	cout << "Item Descriptions"<< endl;
	cout << endl;

	for (int i = 0; i < items.size(); i++)
	{
		items.at(i).PrintDescription();
	}
} 