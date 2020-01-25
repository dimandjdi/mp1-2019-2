#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
int main()
{
	setlocale(LC_CTYPE, "Russian");
	struct EDA
	{
		int barecode[4];
		char name[20];
		int price;
		int k;
		double discount;
		int sum;
	};
	int mas[4] = { 0 };
	double cost_discount, discount;
	int cost, a, i, t, j, b, n, w, x, s;
	cost = i = x = s = 0;
	cost_discount = discount = 0;
	t = 1;
	printf("                     Добро пожаловать в наш магазин! \n");
	struct EDA mass[30];
	FILE *f;
	f = fopen("food.txt", "r");
	while (!feof(f))
	{
		fscanf(f, "%d%d%s", &a, &mass[i].price, &mass[i].name);
		n = 0;
		b = a;
		mass[i].k = 0;
		mass[i].sum = 0;
		mass[i].discount = 0;
		while (b)
		{
			n++;
			b /= 10;
		}
		for (int j = 0; j < 4; j++)
			mass[i].barecode[j] = 0;
		for (int j = 3; j >= 4 - n; j--)
		{
			mass[i].barecode[j] = a % 10;
			a /= 10;
		}
		for (j = 0; j < 4; j++)
		{
			printf("%d", mass[i].barecode[j]);
		}
		printf(" %s %d руб \n", mass[i].name, mass[i].price);
		i++;
	}
	printf("        Инфорация о скидках: каждый 3й продукт идёт со скидкой 15 процентов. \n");
	while (t == 1)
	{
		w = 1;
		printf("Введите штрихкод продукта из предложенного списка: ");
		scanf("%d", &x);
		n = 0;
		b = x;
		while (b)
		{
			n++;
			b /= 10;
		}
		for (j = 3; j >= 4 - n; j--)
		{
			mas[j] = x % 10;
			x /= 10;
		}
		for (i = 0; i < 30; i++)
		{
			for (j = 0; j < 4; j++)
			{
				if (mas[j] != mass[i].barecode[j])
					break;
			}
			if (j == 4)
			{
				s++;
				printf("В чек добавлен: %s %d руб \n", mass[i].name, mass[i].price);
				mass[i].k++;
				mass[i].sum += mass[i].price;
				w = 0;
				if ((s % 3) == 0)
				{
					mass[i].discount = mass[i].price * 0.15;
				}
				break;
			}
		}
		if (w != 0)
		{
			printf("Продукта с введённым штрихкодом нет в нашем магазине((( \n");
		}
		printf("Выбери: 1 - добавить продукт; 0 - оплатить покупку: \n");
		scanf("%d", &t);
	}
	printf("                              Чек покупателя:\n");
	for (i = 0; i < 30; i++)
	{
		if (mass[i].k > 0)
		{
			discount += mass[i].discount;
			cost += mass[i].sum;
			printf("Наименование продукта: %s, стоймость: %d руб, кол-во: %d \n", mass[i].name, mass[i].price, mass[i].k);
		}
	}
	printf("Общая стоймость товаров: %d руб \n", cost);
	printf("Суммарная скидка: %.2lf руб \n", discount);
	cost_discount = cost - discount;
	printf("Итоговая сумма к оплате: %.2lf руб \n", cost_discount);
	printf("Спасибо за покупку! \n");
	system("pause");
}