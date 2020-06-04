#ifndef ITEM_H
#define ITEM_H

struct Item
{
	Item(int weight, int price);
	Item();
	int Weight;
	int Price;
};

#include "Item.cpp"
#endif