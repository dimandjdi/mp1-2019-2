#include <locale.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
int main(void)
{
	setlocale(LC_ALL, "Rus");
	int i, j;
	int sh, prov = 0, a, r = 0, obsh = 0, n, sum = 0, obski;
	int shtr[8] = { 7564 , 1209 , 1221 , 6390 , 3210 , 5671 , 9232 , 6749 };
	char tov[8][25] = { {"Порошок для стирки"},{"Мыло"},{"Кондиционер для стирки"},{"Шампунь"}, {"Бальзам для волос"}, {"Пена для ванны"}, {"Гель для душа"}, {"Мочалка"} };
	int cena[8] = { 75 , 25 , 170 , 200 , 230 , 140 , 125 , 50 };
	int ski[8];
	int newce[8];
<<<<<<< HEAD
	int kol[8] = { 0 };
=======
	int kol[8]={ 0 };
>>>>>>> 6f348077736c1b252e7006dd61d1a83072341ae2
	for (i = 0; i < 8; i++)
	{
		ski[i] = 5 * (1 + rand() % (9)) + 5;
	}
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
				puts(tov[i]);
			}
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
				newce[i] = cena[i] * (100 - ski[i]) / 100;
				printf("Цена %d руб/шт.\nСкидка на товар : %d проц.\nЦена на товар с учетом скидки %d руб/шт.\n", cena[i], ski[i], newce[i]);
				printf("Введите количество покупаемого товара: \n");
				scanf_s("%d", &n);
				kol[i] = kol[i] + n;
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
			printf("%d шт. x %d руб. + скидка %d проц.\n", kol[i], cena[i], ski[i]);
			sum = sum + (kol[i] * cena[i]);
			obsh = obsh + (kol[i] * newce[i]);
		}
		obski = sum - obsh;
	}
	printf("Итого: \nОбщая стоимость покупки без скидки: %d руб.\nСуммарная скидка: %d руб.\nИтоговая сумма к оплате : %d руб.\n", sum, obski, obsh);
	printf("Спасибо за покупку, приходите ещё!\n");
	system("pause");
}
