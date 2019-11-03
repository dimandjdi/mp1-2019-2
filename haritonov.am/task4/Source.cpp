#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>
#pragma warning(disable:4996)

struct list
{
	int bar;
	int price;
	char name[25];
};

void main()
{
	srand(time(NULL));
	int percent, k, i, j = 0, sum = 0, x, chance, input[100];
	struct list viev[12];
	FILE *spisok = fopen("list.txt", "r");
	printf("Bar      Price       Name\n\n");
	for(i = 0; i<12; i++)
	{
		chance = rand() % 4;
		fscanf(spisok, "%i", &viev[i].bar);
		printf("%i   ", viev[i].bar);
		if (chance == 0)
		{
			percent = (5 * ((rand() % 4)+1));
			fscanf(spisok, "%i", &viev[i].price);
			printf("%20 %4i - %2i%%   ", viev[i].price, percent);
			x = (viev[i].price*percent) / 100;
			viev[i].price -= x;
		}
		else
		{
			fscanf(spisok, "%i", &viev[i].price);
			printf("   %4i       ", viev[i].price);

		}
		fscanf(spisok, "%s", &viev[i].name);
		printf("%s \n", viev[i].name);
	}
	printf("Enter product codes, 0 - end of list\n\n");
	do
	{
		scanf_s("%i", &input[j]);
		j++;
	} while (input[j - 1] != 0);
	printf("\nCHECK\n");
	for(k = 0; k<j; k++)
	{
		for (i = 0; i < 12; i++)
		{
			if (viev[i].bar == input[k])
			{
				printf("%4i   ", viev[i].price);
				printf("%s \n", viev[i].name);
				sum += viev[i].price;
			}
		}
	}
	printf("TOTAL\n");
	printf("%4i", sum);
	getchar();
	getchar();

}