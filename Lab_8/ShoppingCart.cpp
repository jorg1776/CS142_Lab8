#include "stdafx.h"

#include "ShoppingCart.h"

string ShoppingCart::GetCustomerName() { return customerName; }

string ShoppingCart::GetDateCreated() { return dateCreated; }

void ShoppingCart::AddItemToCart(ItemToPurchase item) {	items.push_back(item); }

void ShoppingCart::RemoveItemFromCart(string itemName) { }

void ShoppingCart::UpdateItemQuantity(string, int) { }

int ShoppingCart::GetNumOfItems() { }

double ShoppingCart::GetTotalCost() { }

void ShoppingCart::PrintItemTotalsAndCosts() { }

void ShoppingCart::PrintItemDescriptions() { }