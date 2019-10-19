#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	int mode, ugadal, k = 1, razbros, predpoloj, c, k2 = 0;
	char znak = 0;
	printf("Выбор ржима: \n 1 - компьютер загадывает число \n 2 - вы загадываете число \n");
	scanf_s("%d", &mode);

	if (mode == 1)
	{
		c = 1 + (rand() % 1000);
		printf("Компьютрер загадал, пробуйте \n");
		scanf_s("%d", &predpoloj);
		while (predpoloj != c)
		{
			if (predpoloj > c)
			{
				printf("Нужно число поменьше \n");
			}
			if (predpoloj < c)
			{
				printf("Нужно число побольше \n");
			}
			scanf_s("%d", &predpoloj);
			k++;
		}
		printf("Неплохо, количество попыток = ");
		printf("%d", k);
		printf("\n");
		system("pause");
	}

	if (mode == 2)
	{

		ugadal = 500;
		razbros = ugadal / 2;
		while (znak != '=')
		{
			printf("Ваше число %d? \n", ugadal);
			scanf_s(" %c", &znak);
			if (znak == '>')
			{

				ugadal = ugadal + razbros;

			}
			if (znak == '<')
			{
				ugadal = ugadal - razbros;
			}
			razbros = (razbros + 1) / 2;
			k2++;


		}
		printf("Ваше число - %d \n", ugadal);
		printf("Компьютер угадал за %d попыток \n", k2);
		system("pause");

	}
}