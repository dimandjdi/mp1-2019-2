#include <locale.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<memory.h>
#define _CRT_SECURE_NO_WARNINGS
int main(void)
{
	setlocale(LC_ALL, "Rus");
	int i, j;
	int sh, prov = 0, a, r = 0, obsh=0, n;
	int shtr[8] = { 7564 , 1209 , 1221 , 6390 , 3210 , 5671 , 9232 , 6758  };
	char tov[8][25] = { {"Порошок для стирки"},{"Мыло"},{"Кондиционер для стирки"},{"Шампунь"}, {"Бальзам для волос"}, {"Пена для ванны"}, {"Гель для душа"}, {"Мочалка"} };
	int cena[8] = { 75 , 25 , 170 , 200 , 230 , 140 , 125 , 50 };
	int ski[8];
	int newce[8];
	int kol[8]={ 0 };
	printf("Рады приветствовать Вас в магазине 'Чистюля'!\n");
	while (r == 0)
	{
		prov = 0;
		while (prov == 0)
		{
			printf("Введите нужный штрих-код: \n");
			for (i = 0; i < 8; i++)
			{
				printf("%d ", shtr[i]);
			}
			printf("\n");
			scanf_s("%d", &sh);

			for (i = 0; i < 10; i++)
			{
				a = 0;
				a = a * 10 + shtr[i];
				if (sh == a)
				{
					prov = 1;
					break;
				}
			}
			if (prov == 0)
			{
				printf("Такого штрих-кода нет, попробуйте ввести ещё раз \n");
				scanf_s("%d", &sh);
			}
			if (prov == 1)
			{
				printf("Ваш товар:\n");
				puts(tov[i]);
				srand(time(0));
				ski[i] = 5*(1 + rand() % (9))+5;
				newce[i] = cena[i] * (100 - ski[i]) / 100;
				printf("Цена %d руб/шт.\nСкидка на товар : %d проц.\nЦена на товар с учетом скидки %d руб/шт.\n", cena[i], ski[i], newce[i]);
				printf("Введите количество покупаемого товара: \n");
				scanf_s("%d", &n);
				kol[i] = n;
				printf("Это все ваши продукты?\nЕсли да, введите 1, если нет, введите 0\n");
				scanf_s("%d", &r);
				break;
			}
		}

	}
	printf("Итоговый чек:\n");
	for (i = 0; i < 8; i++)
	{
		if (kol[i] != 0)
		{
			puts(tov[i]);
			printf("%d шт. x %d руб. Действующая скидка на товар %d проц.\n", kol[i], newce[i], ski[i]);
			obsh = obsh + (kol[i] * newce[i]);
		}
	}
	printf("Итого:\nОбщая стоимость покупки: %d руб.\n", obsh);
	printf("Спасибо за покупку, приходите ещё!\n");
	system("pause");
}