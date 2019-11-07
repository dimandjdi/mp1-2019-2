#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
int main(void)
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	int n, i, m, t = 0, obshsale = 0, sum = 0;
	int sh[5] = { 2468, 1357, 5629, 4798, 7398 }; // штрихкоды
	char tov[5][19] = { {"Краски акварельные"}, {"Кисть большая"}, {"Холст"}, {"Набор кистей"}, {"Тушь"} };
	int price[5] = { 1200, 400, 550, 2000, 200 }; // цена за единицу продукта
	int cake[5] = { 0 };
	int new_price[5] = { 0 };//цена со скидкой
	int sale[5] = { 0 }; //скидка для товара
	for (i = 0; i < 5; i++)
	{
		printf("%d ", sh[i]);
		puts(tov[i]);
	}
	printf("\nВведите нужный штрих-код: ");
	scanf_s("%d", &n);
	for (i = 0; i < 5; i++)
		sale[i] = 5 * (rand() % 9 + 1) + 5;
	while (n != 0)
	{
		for (i = 0; i < 5; i++)
		{
			if (n == 0)
				break;
			else
				if (n == sh[i])
				{
					printf("Ваш товар: ");
					puts(tov[i]);
					new_price[i] = price[i] * (100 - sale[i]) / 100;
					printf("Цена %d руб.\nСкидка на товар %d проц.\nЦена на товар с учетом скидки %d руб.\n", price[i], sale[i], new_price[i]);
					printf("Введите количество покупаемого товара: ");
					scanf_s("%d", &m);
					cake[i] += m;
					printf("\nВведите штрихкод следующего товара или если вы хотите завершить ,то введите 0: ");
					scanf_s("%d", &n);
					break;
				}
		}
	}
	for (i = 0; i < 5; i++)
	{
		new_price[i] = cake[i] * (price[i] * (100 - sale[i]) / 100);
		t = t + (cake[i] * price[i]);//суммарная стоимость товаров без скидки
		sum = sum + new_price[i];//стоимость товаров со скидкой
	}
	obshsale = t - sum;
	//Формируем чек
	printf("\n\n");
	printf("КАССОВЫЙ ЧЕК\n");
	for (i = 0; i < 5; i++)
	{
		if (cake[i] != 0)
		{
			puts(tov[i]);
			printf_s("Количество %d шт , цена с учетом количества и скидки %d \n", cake[i], new_price[i]);
		}
	}
	printf("ВАША СКИДКА СОСТАВИЛА : %d  РУБЛЕЙ \n", obshsale);
	printf("ИТОГО : %d РУБЛЕЙ\n", sum);
	printf("СПАСИБО ЗА ПОКУПКУ!\n");
	system("pause");
}
