#include<stdio.h>
#include<locale.h>
#include <stdlib.h>
#include <time.h>
void main()
{
	setlocale(LC_CTYPE, "Russian");
	int a, b, c, t, r, mode, k;
	char e = '1';
	printf(" Выберите режим игры, выбрав соответствующую цифру (1 - программа загадывает; 2 - программа угадывает): ");
	scanf_s("%d", &mode);
	switch (mode)
	{
	case 1:
		srand(time(NULL));
		r = 1 + rand() % 1000;
		t = k = 0;
		while (t != r)
		{
			printf("Программа загадала число: ");
			scanf_s("%d", &t);
			if (t > r)
				printf("Загаданное число меньше \n");
			else if (t < r)
				printf("Загаданное число больше \n");
			else if (t = r)
				printf("Угадали \n");
			k++;
		}
		printf("Количество попыток: %d \n", k);
		break;

	case 2:
		c = 500;
		a = c / 2;
		k = 1;
		b = -1;
		while ((1 > b) || (b > 1000))
		{
			printf("Загадайте число: ");
			scanf_s("%d", &b);
		}
		while (c != b)
		{
			printf("Ваше число %d? \n", c);
			scanf_s(" %c", &e);
			if (e == '>')
			{
				c = c + a;
			}
			else
			{
				c = c - a;
			}
			a = (a + 1) / 2;
			k++;
		}

		printf("Ваше число %d? \n", c);
		scanf_s(" %c", &e);
		printf("Количество попыток: %d \n", k);
		break;

	default:
		printf("Введено некорректное число \n");
		break;
	}
	system("pause");
}