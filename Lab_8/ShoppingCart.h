#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include "ItemToPurchase.h"
#include <string>
#include <vector>
using namespace std;

class ShoppingCart
{
	public:
		ShoppingCart(string customerName = "none", string dateCreated = "January 1, 2016");
		string GetCustomerName();
		string GetDateCreated();
		bool CheckCartForItem(string);
		void AddItemToCart(ItemToPurchase);
		void RemoveItemFromCart(string);
		void UpdateItemQuantity(string, int);
		int GetNumOfItems();
		double GetTotalCost();
		void PrintItemTotalsAndCosts();
		void PrintItemDescriptions();
		void PrintCartDescription();
	private:
		string customerName;
		string dateCreated;
		vector<ItemToPurchase> items;
};
#endif