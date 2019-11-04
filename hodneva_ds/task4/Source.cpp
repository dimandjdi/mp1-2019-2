#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
void main()
{
	setlocale(LC_ALL, "Rus");
	int i, j;
	float sum = 0, summ = 0, skidka = 0;
	const int z = 50;
	float cena[11] = { 100,80,60,250,25,35,30,45,50,60,350 };
	int shtr, a, p = 0;
	int shtrihkod[11][5] = {{1,2,3,4},{5,6,7,8},{9,1,0,1},{1,1,2,1},{3,1,4,1},{5,1,6,1},{7,1,8,1},{9,2,0,2},{1,2,2,2},{3,2,4,2},{5,2,6,2}};
	char tov[11][z] = {{"Пирог с ягодами"},{"Блины"},{"Молоко"},{"Конфеты"}, {"Хлеб"}, {"Макароны"}, {"Рис"}, {"Творог"}, {"Яблоки 1 кг."}, {"Печенье"}, {"Торт"}};
	bool proverka;
	float kolvo[11][2] = { 0 };
	printf("1234\n5678\n9101\n1121\n3141\n5161\n7181\n9202\n1222\n3242\n5262\n");
	while (p == 0)
	{
		proverka = false;
		while (proverka == false)
		{
			printf("Введите штрих код выбранного продукта\n");
			scanf("%d", &shtr);

			for (i = 0; i < 11; i++)
			{
				a = 0;
				for (j = 0; j < 4; j++)
				{
					a = a * 10 + shtrihkod[i][j];
				}
				if (shtr == a)
				{
					proverka = true;
					break;
				}

			}
			if (proverka == false)
			{
				printf("Такого штрих кода не существует\n");
			}
			if (proverka == true)
			{
				printf("Товар:\n");
				kolvo[i][0]++;
				kolvo[i][1] = rand() % (51);
				printf("Цена за 1 шт: %.2f руб.\n", cena[i]);
				printf("Хотите завершить покупки?\n Если да, введите 1, если нет, введите 0\n");
				scanf("%d", &p);
			}
		}

	}
	printf("Итого:\n");
	for (i = 0; i < 11; i++)
	{
		if (kolvo[i][0] != 0)
		{
			printf("%.2f шт. x %.2f руб. Скидка на товар %.0f%%\n", kolvo[i][0], cena[i], kolvo[i][1]);
			sum = sum + (kolvo[i][0] * cena[i]);
			summ = summ + (kolvo[i][0] * (cena[i] - (cena[i] * kolvo[i][1] / 100)));
			skidka = 100.0 - (summ * 100) / sum;
		}

	}
	printf("Итого:\n Цена без скидки:%.2f руб.\n Скидка:%.2f%% Цена покупки:%.2f руб.", sum, skidka, summ);
	printf("Спасибо за покупку\n");
}
