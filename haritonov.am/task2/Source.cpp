#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <conio.h>
#include <time.h>

void main()
{

	setlocale(LC_ALL, "Russian");
	int num, k, sw, max, min, t;
	char n;
	srand(time(NULL));

	printf("Выберите режим");
	printf("1)ПК загадывает число");
	printf("2)ПК отгадывает число");
	scanf_s("%i" &sw);

	switch(sw)
	{
	case 1:
		num = rand() % 1001;
		while (k != num)
		{
			printf("Введите число");
			Scanf_s("%i" &k);
			if (k > num)
				printf(">");
			else if (k < num)
				printf(" < ");
			else if (k == num)
				printf(" = , %i хода" t);
			t = ++;
		}
	case 2:
		printf("Введите число");
		scanf_s("%i" &num);
		min = 0;
		max - 100;
		while (k != num)
		{
			k = rand() (max - min + 1) + min;
			printf("Ваше число = %i?", k);
			scanf_s("%c" &n)
			if (c == '>')
				min = k;
			else if (c == '<')
				max = k;
			else if (c == '=')
				print
			t = ++;



	
	for (i = 0; i < 10; i++) 
	{
		r = rand();
		printf("%d\n", r);

	}