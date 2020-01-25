#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h>
#include <conio.h>
#include <memory.h>
#include "Console.cpp"

using namespace std;

struct Product
{
	char name[25];
	int barcode = 0;
	int price = 0;
	int discount = 0;
};

struct ProductInCheck
{
	int amount = 0;
};

Product* products;
ProductInCheck* check;

int ReadDB(char* dbFilename)
{
	FILE *DB;
	errno_t err;
	err = fopen_s(&DB,"text.txt", "r");
	int n = 0;
	fscanf(DB,"%d", &n);
	products = (Product*)malloc(n * sizeof(Product));
	check = (ProductInCheck*)malloc(n * sizeof(ProductInCheck));
	gotoxy(0, 15);
	for (int i = 0; i < n; i++)
	{
		products[i] = Product();
		check[i] = ProductInCheck();
		fscanf(DB, "%d%s%d%d", &products[i].barcode, &products[i].name, &products[i].price, &products[i].discount);
	}
	return n;
}

void animated_printup(int n, char pic[20][11])
{
	int t;
	for (int i=0; i < n; i++)
	{
		t = clock();
		for (int j = 0; j < i; j++)
		{
			gotoxy(25, 30 - i+j);
			puts(pic[j]);
		}
		while (clock() - t < 150);
		clrscr();
	}
}
void CheckPreview(int n)
{
	gotoxy(40, 2);
	int total = 0;
	int ii = 2;
	for (int i = 0; i < n; i++)
	{
		if (check[i].amount > 0)
		{
			int fullprice = check[i].amount * products[i].price * (100 - products[i].discount) / 100;
			total += fullprice;
			printf("%s %dx%d$x%d%%", products[i].name, check[i].amount, products[i].price, 100 - products[i].discount);
			gotoxy(59, ii);
			printf("=%d", fullprice);
			ii++;
			gotoxy(40, ii);
		}
	}
	gotoxy(40, ii+2);
	printf("Total:");
	gotoxy(59, ii + 2);
	printf("%d", total);
}
void ProductsPreview(int n)
{
	gotoxy(0, 15);
	for (int i = 0; i < n; i++)
	{
		printf("%d %s %d\n", products[i].barcode, products[i].name, products[i].discount);
	}
}

void AddProductToCheck(int barcode, int n)
{
	for (int i=0; i < n; i++)
	{
		if (products[i].barcode == barcode)
		{
			check[i].amount+=1;
			return;
		}
	}
	gotoxy(0, 8);
	printf("Нет такого товара");
}


int main(void)
{
	setwindow(90, 20);
	setwindow(90, 20);
	clrscr();
	setlocale(LC_ALL, "Rus");
	int n = ReadDB("text.txt");
	while (true)
	{
		gotoxy(0, 0);
		printf("ESC - закончить пробивать товары");
		CheckPreview(n);
		ProductsPreview(n);
		int barcode = 0;
		while (true)
		{
			int input[5] = { 0 };
			barcode = 0;
			number_input(1, 1, 4, input);
			clrscr();
			if (input[0] == -1)
				break;
			for (int i = 0; i < 4; i++)
				barcode += pow(10, i) * input[3 - i];
			if (barcode > 1000 || barcode == 0)
				break;
		}
		if (barcode == 0)
			break; 
		else
			AddProductToCheck(barcode, n);
	}
	int ii=0;
	int total = 0;
	for (int i = 0; i < n; i++)
	{
		if (check[i].amount > 0)
		{
			int fullprice = check[i].amount * products[i].price * (100 - products[i].discount) / 100;
			total += fullprice;
			printf("%s %dx%d$x%d%%", products[i].name, check[i].amount, products[i].price, 100 - products[i].discount);
			gotoxy(19, ii);
			printf("=%d",fullprice);
			ii++;
			gotoxy(0, ii);
		}
	}
	printf("\n\nTotal:");
	gotoxy(20, ii+2);
	printf("%d", total);
	getchar();
}