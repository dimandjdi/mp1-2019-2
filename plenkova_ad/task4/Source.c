#include <stdio.h> 
#include <time.h> 
#include <stdlib.h> 
#include <locale.h> 
int main(void)
{
	setlocale(LC_ALL, "Rus");
	srand(time(0));

	int n, i, stoimost_bez_skidki = 0, obshaya_skidka, stoimost_so_skidkoy = 0, kol_vo;
	int shtrihkod[21] = {      1000,            1001,         1002,             1003,              1004,                 1005,             1006,               1007,                     1008,             1009,           1010,              1011,                1012,                1013,                  1014,                      1015,                    1016,                 1017,         1018,            1019,         1020 };
	char tovar[21][50] = { {"Томаты(кг)"}, {"Огурцы(кг)"}, {"Творог(180г)"}, {"Молоко(1л)"}, {"Яблоки красные(кг)"}, {"Апельсины(кг)"}, {"Бананы(кг)"}, {"Сыр Российский(100г)"}, {"Сыр Гауда(100)"}, {"Хлеб белый"}, {"Хлеб Чёрный"}, {"Масло сливочное"}, {"Яйца куриные(10)"}, {"Сосиски(400г)"}, {"Колбаса копченая(100г)"}, {"Колбаса вареная(100г)"}, {"Арахис солёный(100г)"}, {"Йогурт"}, {"Кофе молотый"}, {"Шоколад"}, {"Конфеты(100г)"} };
	int tsena[21] = {           185,            250,            60,               45,               100,                  75,               130,               65,                        75,                 39,            26,               140,                  60,                 160,                   50,                       45,                      30,                    55,          120,              100,          90 };
	int kolichestvo[21] = { 0 };
	int tsena_so_skidkoy[21] = { 0 };
	int skidka[21] = { 0 };

	printf("~Добро пожаловать в магазин~ \nМеня зовут AnasteishA <3\nВведите штрихкод от 1000 до 1020 или введите 0, чтобы закончить и получить чек\n");
	scanf_s("%d", &n);

	for (i = 0; i < 21; i++)
	{
		skidka[i] = 5 + (rand() % 11) * 5;
	}
	while (n != 0)
	{
		for (i = 0; i < 21; i++)
		{
			if (n == 0)
				break;
			else if (n == shtrihkod[i])
			{
				printf("Ваш товар: %s\n", tovar[i]);
				tsena_so_skidkoy[i] = tsena[i] * (100 - skidka[i]) / 100;
				printf("Цена: %d рублей\nСкидка на товар: %d процентов\nЦена на товар с учетом скидки: %d рублей\n", tsena[i], skidka[i], tsena_so_skidkoy[i]);
				kolichestvo[i] = kolichestvo[i] + 1;
				printf("Введите следующий штрихкод\n");
				printf("~~~~~~~~~\n");
				scanf_s("%d", &n);
				break;
			}
		}
	}
	for (i = 0; i < 21; i++)
	{
		tsena_so_skidkoy[i] = kolichestvo[i] * (tsena[i] * (100 - skidka[i]) / 100);
		stoimost_bez_skidki = stoimost_bez_skidki + (kolichestvo[i] * tsena[i]);
		stoimost_so_skidkoy = stoimost_so_skidkoy + tsena_so_skidkoy[i];
	}
	obshaya_skidka = stoimost_bez_skidki - stoimost_so_skidkoy;


	printf("\n\n\~ЧЕК~\n");
	for (i = 0; i < 21; i++)
	{
		if (kolichestvo[i] != 0)
		{
			printf_s("%s\nКоличество: %d, цена со скидкой: %d\n", tovar[i], kolichestvo[i], tsena_so_skidkoy[i]);
			printf("~~~~~~~~~\n");
		}
	}
	printf("~Итого без скидки: %d рублей~\n~Ваша скидочка: %d рублей~\n~Итого к оплате: %d рублей~\nСпасибо за покупку)\nПриходите ещё <3", stoimost_bez_skidki, obshaya_skidka, stoimost_so_skidkoy);
}