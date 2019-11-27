#include "stdio.h"
#include<locale.h>
#include <stdlib.h>

int main()

{
	setlocale(LC_ALL, "Russian");
	int a, w, k, b;
	char x;
	x = '1';
	printf("Введите число в интервале от 1 до 1000 \n");
	scanf_s("%d", &a);
	w = 500;
	k = w / 2;
	while (a != w)
	{
		printf ("Число равно %d? \n", w);
		scanf_s ("%c" &x);
		if (x == '<')
		{
			w = w + k;
		}
		if (x == '>')
		{
			w = w - k;
		}
		k = (k+1) / 2;
		b = b + 1;
	}
	printf ("Ваше число %d", k);
	scanf_s("%c", x);
	printf ("Угадали с %d попытки ", b);
	system("pause");
	return 0;
}