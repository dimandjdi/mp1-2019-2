#define _CRT_SECURE_NO_WARNINGS
#define N 100;
#include <stdio.h>
#include <locale.h>
#include <conio.h>
struct storecheck
{
	int barcode;
	float price;
	int discount;
	char name[30];
	int count;
};

struct storecheck search_product (int code)
{
	FILE *products;
	struct storecheck product;
	products = fopen("products.txt", "r");
	product.count = 1;
	while (!feof(products))
	{
		fscanf_s(products, "%d %f %d", &product.barcode, &product.price, &product.discount);
		fgets (product.name, 30, products);
		product.price = product.price * (100 -  product.discount) / 100;
		if (code == product.barcode)
		{
			printf("\n%d %s%.2f р\n", product.barcode, product.name, product.price);
			break;
		}
	}
	fclose(products);
	return product;
}

void main()
{
	setlocale(LC_ALL, "Rus");
	int code, n = 1, i = 0, j = 0;
	char c;
	float fullsum = 0, discount_sum = 0;
	struct storecheck product[100];
	printf("Введите штрихкод\n");
	scanf_s("%d", &code);
	while (code != 0)
	{
		product[i] = search_product(code);
		for (j = 0; j < i; j++)
			if (product[j].barcode == product[i].barcode)
			{
				product[j].count = product[j].count + 1;
				i--;
				break;
			}
		i++;
		printf("Введите штрихкод или 0 для завершения покупок\n");
		scanf_s("%d", &code);
	} 
	printf("Check:\n");
	for (j = 0; j < i; j++)
	{
		printf("%d %s\n%.2f\t *%d\t =%.2f\n", product[j].barcode, product[j].name, product[j].price, product[j].count, product[j].price*product[j].count);
		fullsum = fullsum + product[j].price / (100 - product[j].discount) *100 * product[j].count;
		discount_sum = discount_sum + product[j].price * product[j].count;
	}
	printf("Итог: %.2f\t скидка: %.2f\n", discount_sum, fullsum - discount_sum);
	printf("Нажмите Enter для создания нового чека или Esc для выключения кассы\n");
	c = _getch();
	switch (c)
	{
	case 27:
		exit(0);
		break;
	default:
		main();
		break;
	}
	system("pause");
}