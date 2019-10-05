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
	int a;
		printf("Введите число: ");
		scanf_s("%d", &a);
	while (a != num);
	{
		printf("Введите число: ");
		scanf_s("%d", &a);
		if (num < a) {
			printf("Загаданное число меньше");
		}
		else {
			if (num > a) {
				printf("Загаданное число больше");
			}
		}
	}
	printf("Угадали");
	return 0;
}