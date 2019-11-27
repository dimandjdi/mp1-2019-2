#include<math.h>
#include<time.h>
#include<stdio.h>
#include<locale.h>
struct magazin
{
	char mas[15];
	int code;
	int price;
};
struct chek
{
	char name[15];
	int  oneprice;
	int kolvo;
	int fullprice;
	double skidka;
};
struct itogchek
{
	int overfullprice;
	double fullskidka;
	double itog;
};
struct magazin magazin[10];
void abrakadabra(void)
{
	magazin[0].code = 1111;
	magazin[1].code = 2222;
	magazin[2].code = 3333;
	magazin[3].code = 4444;
	magazin[4].code = 5555;
	magazin[5].code = 6666;
	strcpy(magazin[0].mas, "SCHAST'E");
	strcpy(magazin[1].mas, "MECHTA");
	strcpy(magazin[2].mas, "RADOST'");
	strcpy(magazin[3].mas, "YDACHA");
	strcpy(magazin[4].mas, "VESEL'E");
	strcpy(magazin[5].mas, "YVERENNOST'");
	magazin[0].price = 45;
	magazin[1].price = 250;
	magazin[2].price = 32;
	magazin[3].price = 128;
	magazin[4].price = 76;
	magazin[5].price = 322;
}
void main()

{
	int code, i, j, k = 0, flag = 0;
	double b;
	setlocale(LC_ALL, "ru");
	printf("А вот и Галина пришла,что же она сегодня нам принесла?\n");
	abrakadabra();
	for (i = 0; i < 6; i++)
		printf("%i %s %iр \n", magazin[i].code, magazin[i].mas, magazin[i].price);
	srand(time(0));
	struct chek chek[6];
	for (i = 0; i < 6; i++)
	{
		chek[i].name[0] = '0';
		chek[i].kolvo = 0;
	}
	printf("Магазин у Галины открыт\n");
	printf("Выбирайте покупочки\n");
	printf("Если хотите закончить сканровать товары,нажмите 0\n");
	scanf_s("%i", &code);
	while (code != 0)
	{
		for (i = 0; i < 6; i++)
		{
			if (code == magazin[i].code)
				for (j = 0; j < 6; j++)
				{
					if (strcmp(magazin[i].mas, chek[j].name) == 0)
						chek[j].kolvo++;
					else
						k++;
				}
			if (k == 6)
				for (int count = 0; count < 6; count++)
					if (chek[count].name[0] == '0')
					{
						strcpy(chek[count].name, magazin[i].mas);
						chek[count].oneprice = magazin[i].price;
						chek[count].kolvo++;
						flag++;
						break;
					}
			k = 0;
		}
		printf("Хотите выбрать ещё?\n");
		scanf_s("%i", &code);
	}
	struct itogchek itogcheck;

	for (i = 0; i < flag; i++)
	{
		chek[i].fullprice = chek[i].oneprice*chek[i].kolvo;
		b = (0.01 * (rand() % 11 * 5));
		chek[i].skidka = chek[i].fullprice*b;
		printf("Скидка :%.1lf\n", chek[i].skidka);
	}
	itogcheck.overfullprice = 0;
	itogcheck.fullskidka = 0;
	for (i = 0; i < flag; i++)
	{
		itogcheck.overfullprice += chek[i].fullprice;
		itogcheck.fullskidka += chek[i].skidka;
	}
	itogcheck.itog = itogcheck.overfullprice - itogcheck.fullskidka;
	printf("ЧЕК СФОРМИРОВАН\n");
	for (i = 0; i < flag; i++)
		printf("%s   %iрХ%i    %iр\n", chek[i].name, chek[i].oneprice, chek[i].kolvo, chek[i].fullprice);
	printf("Стоимость товаров: %i\n", itogcheck.overfullprice);
	printf("Общая скидка: %.1lf\n", itogcheck.fullskidka);
	printf("Сумма к оплате: %.1lf\n", itogcheck.itog);
	printf("СПАСИБО ЗА ПОКУПКУ\n");
	system("pause");
}