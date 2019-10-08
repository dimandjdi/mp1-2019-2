#include "stdio.h"

#include "math.h"

#include<locale.h>

#include <stdlib.h>

#include <time.h>

int main()

{
	setlocale(LC_ALL, "Russian");
	int num = rand() % 1000;
	printf("%d", num);
	int a,b;
	b = 1;
	printf("Введите число: ");
	scanf_s("%d", &a);
	while (a != num)
	{
		if (num < a) {
			printf("Загаданное число меньше \n");
		}
		if (num > a) {
			printf("Загаданное число больше \n");
		}
		if (num != a)
		{
			printf("Введите число: \n");
			scanf_s("%d", &a);
		}
		b = b + 1;
	}
	printf("Угадали с %d попытки ", b);
	system("pause");
	return 0;
}
