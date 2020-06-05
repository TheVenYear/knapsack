#include <iostream>
#include "item/Item.h"
#include <time.h>

Item *items;

int max(int a, int b) { return (a > b) ? a : b; }

int knapsack(int w, int n)
{
	if (n == 0 || w == 0)
		return 0;

	if (items[n - 1].Weight > w)
		return knapsack(w, n - 1);

	return max(items[n - 1].Price +
				   knapsack(w - items[n - 1].Weight, n - 1),
			   knapsack(w, n - 1));
}

//Напоминалка: 10, 60; 20, 100; 30, 120;
int main()
{
	clock_t start = clock();
	printf("Enter how much elements you want to store: ");
	int length = 0;
	scanf("%i", &length);

	items = new Item[length];

	printf("Enter elements('n1 n2'):\n");
	for (int i = 0; i < length; i++)
	{
		scanf("%i %i", &items[i].Weight, &items[i].Price);
	}

	printf("Enter knapsack space: ");
	int space = 0;
	scanf("%i", &space);
	printf("Answer is %i\n", knapsack(space, length));
	clock_t end = clock();
	double seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("The time is %f seconds\n", seconds);
	system("pause");
	return 0;
}
