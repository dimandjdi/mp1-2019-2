#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(0));
	int r;
	printf("Нажмите 1, чтобы отгадывать число\nНажмите 2, чтобы программа отгадывала число\n");
	scanf_s("%d", &r);
	if (r == 1)
	{
		int n = rand() % 1000;
		int t, k = 1;
		printf("Программа загадала число, угадайте его. Число равно = ...\n");
		scanf_s("%d", &t);
		while (t != n)
		{
			k = k + 1;
			if (t < n)
			{
				printf("А вот и неееет, загаданное число больше\n");
				printf("Число равно = ...\n");
				scanf_s("%d", &t);
			}
			if (t > n)
			{
				printf("Неа, загаданное число меньше\n");
				printf("Число равно = ...\n");
				scanf_s("%d", &t);
			}
			if (t == n)
			{
				printf("Угадали\n");
			}

		}
		printf("Число попыток = %d", k);
	}
	if (r == 2)
	{
		int n0 = 0, n1 = 1000;
		int t = (n0 + n1) / 2, q = 0;
		char j = ' ';
		{
			printf("Загадайте число от 0 до 1000, а я попробую его угадать\nВаше число = %d?\n", t);
			printf("Если загаданное число больше, нажмите '>'\nЕсли загаданное число меньше, нажмите '<'\nЕсли программа угадала число, нажмите '='\n");
		}
		do
		{
			j = getchar();
			q = q + 1;
			if (j == '>')
			{
				n0 = t;
				t = (n0 + n1) / 2;
				printf("%d\n", t);
			}
			else if (j == '<')
			{
				n1 = t;
				t = (n0 + n1) / 2;
				printf("%d\n", t);
			}
			else if (j == '=')
			{
				q = q / 2;
				printf("Еххууу, я смог отгадать\n");
				printf("Моё количество попыток равно %d", q);
			}
		} while (j != '=');

	}
}