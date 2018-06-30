#ifndef ITEMTOPURCHASE_H
#define ITEMTOPURCHASE_H

#include <string>
using namespace std;

class ItemToPurchase
{
	public:
		ItemToPurchase(string name = "none", string description = "none", double price = 0.0, int quantity = 0);
		void SetName(string);
		string GetName();
		void SetPrice(double);
		double GetPrice();
		void SetQuantity(int);
		int GetQuantity();
		void SetItemDescription(string);
		string GetItemDescription();

	private:
		string itemName;
		double itemPrice;
		int itemQuantity;
		string itemDescription;
};

#endif // ITEMTOPURCHASE_H