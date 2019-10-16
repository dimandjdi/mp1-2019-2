#include <stdio.h> 
#include <locale.h> 
#include <time.h> 
#include <stdlib.h> 
int main(void)
{
	setlocale(LC_ALL, "Rus");
	int ar[5], arr[5];
	int bull = 0, cow = 0, a, j, n, i, l = 1;
	printf("Сыграем в игру 'Быки и коровы'. Если вам надоест играть введите: 0.\nВведите длину загадываемого числа (от 2 до 5)\n");
	scanf_s("%d", &n);
	while ((n > 5) || (n < 2))
	{
		printf("Неверно введена длина загадываемого числа. Попробуйте ещё раз\n");
		scanf_s("%d", &n);
	}
	while (l == 1)
	{
		srand(time(NULL));
		ar[0] = 1 + rand() % 9;
		l = 0;
		i = 1;
		while (i < n)
		{
			ar[i] = rand() % 10;
			i++;
		}
		for (i = 0; i < n; i++)
			for (j = i + 1; j < n; j++)
			{
				if (ar[i] == ar[j])
				{
					l = 1;
					break;
				}
			}
	}
	while (bull != n)
	{
		printf("Введите предполагаемое число :\n");
		scanf_s("%d", &a);
		if (a == 0)
		{
			printf("Игра завершена. Загаданное число : ");
			for (i = 0; i < n; i++)
			{
				printf("%d", ar[i]);
			}
			printf("\n");
			break;
		}
		else
		{
			bull = 0;
			cow = 0;
			for (i = n - 1; i >= 0; i--)
			{
				arr[i] = a % 10;
				a = a / 10;
			}
			for (i = 0; i < n; i++)
			{
				if (arr[i] == ar[i])
					bull++;
				else
				{
					for (j = 0; j < n; j++)
					{
						if (arr[i] == ar[j])
							cow++;
					}
				}
			}
			printf("Быков  %d, коров %d \n", bull, cow);
		}
	}
	if (bull==n)
		printf("Ура!Вы вы отгадали число!\n");
		system("pause");
}