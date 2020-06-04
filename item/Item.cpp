#include "Item.h"

Item::Item(int weight, int price)
{
	Weight = weight;
	Price = price;
}

Item::Item()
{
	Weight = 0;
	Price = 0;
}