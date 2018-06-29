#ifndef ITEMTOPURCHASE_H
#define ITEMTOPURCHASE_H

#include <string>
using namespace std;

class ItemToPurchase
{
	public:
		ItemToPurchase();
		ItemToPurchase(string, double, int);
		void SetName(string);
		string GetName();
		void SetPrice(double);
		double GetPrice();
		void SetQuantity(int);
		int GetQuantity();

	private:
		string itemName;
		double itemPrice;
		int itemQuantity;

};

#endif // ITEMTOPURCHASE_H