#include"stdio.h"
#include"math.h"
#include"time.h"
#include"locale.h"
void main()
{
	setlocale(LC_CTYPE, "Russian");
	int a, b, c, d;//для первого режима переменные
	int n, m, v;//для второга режима переменная
	char sign;
	sign = '1';
	n = 0;
	d = 0; //количество попыток игры
	b = 0;
	v = 0;
	a = 0;
	printf("Выберите цифру режима игры,в который хотите сыграть:");
	printf("режим 1-программа загадывает случайное число,режим 2-вы загадываете случайное число");
	scanf_s("%d", &a);
	switch (a)
	{
	default:
		printf("Вы ввели цифру ,не соответствующую режиму");
		break;
	case 1:
		srand(time(NULL));
		c = (rand() % 1000) + 1;
		printf("Я - великий комьютерный мозг загадал число, и Вам, дорогой друг, придется угадать его.\n");
		while (c != b)
		{
			printf("Введите число:");
			scanf_s("%d", &b);
			if (c > b)
				printf("Моё число больше \n");
			else if (c < b)
				printf("Моё число меньше \n");
			else
				printf("Вы победили меня.Это то число которое я загадал.\n");
			d++;
		}
		printf("Количество попыток составило : %i", d);
		break;
	case 2:
		printf("Загадайте число (от 1 до 1000), и я очень быстро отгадаю его.");
		scanf_s("%d", &m);
		if ((m < 1) || (m > 1000))
		{
			printf("Вы ввели число, которое не входит в промежуток (от 1 до 1000) \n");
		}
		else
			n = 500;
		v = n / 2;
		while (m != n)
		{
			printf("Ваше число %d? \n", n);
			scanf_s(" %c", &sign);
			if (sign == '>')
			{
				n = n + v;
			}
			else
			{
				n = n - v;
			}
			v = (v + 1) / 2;
			d++;
		}
		d++;
		printf("Ваше число %d? \n", n);
		scanf_s(" %c", &sign);
		printf("Ваше число угадано \n");
		printf("Количество попыток составило: %d \n", d);
		break;
	}system("pause");
}