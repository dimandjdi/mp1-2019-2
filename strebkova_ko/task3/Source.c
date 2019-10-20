#include <stdio.h> 
#include <locale.h> 
#include <stdlib.h> 
#include <time.h> 
int check(int number[], int length, int attempt, int kol_attempts)
{
	int cow = 0, bull = 0, i, j, k = length - 1;
	char c;
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
		printf("Нажмите Enter для продолжения игры или введите пробел, если хотите сдаться\n");
		getchar();
		c = getchar();
		switch (c)
		{
		case 10:
			printf("Попробуйте угадать снова:\n");
			break;
		case 32:
			bull = length;
			break;
		}
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
			for (j = 0; j < length; j++)
			{
				if ((number[j] == number[i]) && (j != i))
				{
					flag = 1;
					break;
				}
			}

		} while (flag == 1);

	}
	printf("\nПредположите, какое число загадал компьютер:\n");
	do 
	{
		kol_attempts = kol_attempts + 1;
		scanf_s("%d", &attempt);
	} while (check(number, length, attempt, kol_attempts) != length);
	printf("Нажмите Enter для начала новой игры или введите пробел для выхода из игры\n");
	getchar();
	c = getchar();
	switch (c)
	{
	case 10:
		main();
		break;
	case 32:
		exit(0);
		break;
	}
	system("pause");
}