#include <stdio.h> 
#include <locale.h> 
#include <stdlib.h> 
#include <conio.h> 
#include <time.h> 
int check(int number[], int length, int attempt, int kol_attempts)
{
	int cow = 0, bull = 0, i, j, k = length - 1;
	for (j = 0; j < length; j++)
	{
		for (i = length - 1; i >= 0; i--)
		{
			if ((attempt % 10 == number[i]) && (i == k))
			{
				bull++;
				break;
			}
			else if ((attempt % 10 == number[i]) && (i != k))
			{
				cow++;
				break;
			}
		}
		k = k - 1;
		attempt = attempt / 10;
	}
	printf("Количество быков: %d\n", bull);
	printf("Количество коров: %d\n", cow);
	if (bull != length)
	{
		printf("Попробуйте снова или нажмите Esc, если хотите сдаться\n");
		if (_getch() == 27)
			bull = length;
	}
	else
		printf("Количество попыток: %d\n", kol_attempts);
	return bull;
}

void main()
{
	setlocale(LC_ALL, "Rus");
	int number[5] = {10, 10, 10, 10, 10};
	int length, i, j, attempt, flag, kol_attempts = 0;
	char c;
	srand(time(0));
	printf("Введите длину загадаемого числа (от 2 до 5)\n");
	scanf_s("%d", &length);
	for (i = 0; i < length; i++)
	{
		do
		{
			flag = 0;
			number[i] = rand() % 10;
			for (j = 0; j < i; j++)
			{
				if (number[j] == number[i])
				{
					flag = 1;
					break;
				}
			}
		} while (flag == 1);
	}
	printf("Предположите, какое число загадал компьютер:\n");
	do 
	{
		kol_attempts = kol_attempts + 1;
		scanf_s("%d", &attempt);
	} while (check(number, length, attempt, kol_attempts) != length);
	printf("Нажмите Enter для начала новой игры или Esc для выхода из игры\n");
	c = _getch();
	switch (c)
	{
	    case 27:
			exit(0);
			break; 
	    default:
			main();
			break;
	}
	system("pause");
}