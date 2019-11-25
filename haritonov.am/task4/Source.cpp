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
	struct list viev[12];
	FILE *spisok = fopen("list.txt", "r");

	int percent, k, i, j = 0, sum = 0, x, chance, in, input[100], count[100];
	for (i = 0; i < 100; i++)
		count[i] = 1;
	
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
		scanf_s("%i", &in);
		for (i = 0; i < j; i++)
		{
			if (in == input[i])
			{
				count[i]++;
				in = 1;
			}
		}
		input[j] = in;
		j++;
	} while (input[j - 1] != 0);
	printf("\nCHECK\n");
	for(k = 0; k<j; k++)
	{
		for (i = 0; i < 12; i++)
		{
			if (viev[i].bar == input[k])
			{
				if (count[i] != 0)
					printf("%2i*", count[i]);
				printf("%4i   ", viev[i].price);
				printf("%s \n", viev[i].name);
				sum = sum + count[i]* viev[i].price;
			}
		}
	}
	printf("TOTAL\n");
	printf("%4i", sum);
	getchar();
	getchar();

}