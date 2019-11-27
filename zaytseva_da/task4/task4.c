#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>
#define l 5
int main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	int code[l] = { 1111, 2222, 3333, 4444, 5555 };
	int cena[l] = { 54, 60, 42, 20, 35 };
	int itog[l] = { 0 };
	int skidka[l] = { 0 };
	char fruct[5][20] = { {"Персики"}, {"Абрикосы"}, {"Бананы"}, {"Яблоки"}, {"Груши"} };
	int i, n, cash, number, end, skidos;
	int itogg = 0;
	int summ = 0;
	int summa[l] = { 0 };

	printf("Приветствуем Вас в фруктовой лавке!\nВведите штрихкод из представленных ниже:\n1111\n2222\n3333\n4444\n5555\nЕсли Вы закончили с покупкой, введите 0 вместо штрихкода.\n");
	scanf_s("%i", &n);
	for (i = 0; i < l; i++)
	{
		skidka[i] = (rand() % 49 + 1);
	}
	while (n != 0)
	{
		while ((n != 0) && (n != code[1]) && (n != code[2]) && (n != code[3]) && (n != code[4]) && (n != code[0]))
		{
			printf("Фруктов с таким штрихкодом нет в наличии! Видимо не сезон для них. Попробуйте зайти через пару недель или выбрать другой фрукт :)\n");
			scanf_s("%i", &n);
		}
		for (i = 0; i < l; i++)
		{
			if (n == 0)
				break;
			else
				if (n == code[i])
				{
					printf("Фрукт: ");
					puts(fruct[i]);
					itog[i] = cena[i] * (100 - skidka[i]) / 100;
					printf("Цена за 100г фрукта %i руб.\nСкидка %i проц.\nЦена с учетом скидки %i руб.\n", cena[i], skidka[i], itog[i]);
					printf("Введите в целых сотнях граммов вес покупаемого фрукта: ");
					scanf_s("%i", &number);
					summa[i] += number;
					printf("Введите штрихкод следующего фрукта или 0.\n");
					scanf_s("%i", &n);
					break;
				}
		}
	}
	for (i = 0; i < l; i++)
	{
		itog[i] = summa[i] * (cena[i] * (100 - skidka[i]) / 100);
		summ += itog[i];
		itogg += summa[i] * cena[i];
	}
	skidos = itogg - summ;
	printf("*КАССОВЫЙ ЧЕК*\n");
	for (i = 0; i < l; i++)
	{
		if (summa[i] > 0)
		{
			puts(fruct[i]);
			printf("ВЕС (В СОТНЯХ ГРАММОВ) %i,  СУММА %i РУБ.\n", summa[i], itog[i]);
		}
	}
	printf("СТОИМОСТЬ ТОВАРОВ В ПОКУПКЕ %i РУБ.\nСУММАРНАЯ СКИДКА %i РУБ.\nИТОГ %i РУБ.\n Спасибо за посещение нашей фруктовой лавки!\n Да, мы знаем, что кофе-это фрукт, но тут он не продается, а Вы можете его получить бесплатно при следующей покупке! \n(только при условии сохранения данного чека) ", itogg, skidos, summ);
	scanf_s("%i", &end);
}