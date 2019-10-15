#include<stdio.h>
#include<locale.h>
#include<time.h>
#include<math.h>
#include <stdlib.h>
int main()
{
	setlocale(LC_CTYPE, "Russian");
	int n, k, t, x, f, w, bull, cow;
	bull = cow = n = x = t = f = k = w = 0;
	int a[5], b[5];
	printf("\n");
	printf("Если ты захочешь сдаться, то введи: -1 \n");
	printf("\n");
	while ((n < 2) || (n > 5))
	{
		printf("Выбери количество цифр в загаданом числе (от 2 до 5 цифр): ");
		scanf_s("%d", &n);
	}
	srand(time(NULL));
	a[0] = rand() % 9 + 1;
	for (int i = 1; i < n; i++)
	{
		f = 1;
		while (f != 0)
		{
			f = 0;
			a[i] = rand() % 10;
			for (int j = 0; j < i; j++)
				if (a[i] == a[j])
				{
					f = 1;
					break;
				}
		}
	}
	while (bull != n)
	{
		do
		{
			do
			{
				printf("Введи число: ");
				scanf_s("%d", &t);
				k = 0;
				x = t;
				if (t == -1)
				{
					printf("Игра проиграна, в следующий раз тебе повезёт больше. \n");
					break;
				}
				while (x != 0)
				{
					k++;
					x /= 10;
				}
			} while (k != n);
			if (t == -1)
			{
				break;
			}
			for (int i = n - 1; i >= 0; i--)
			{
				b[i] = t % 10;
				t /= 10;
			}
			w = 0;
			for (int i = 0; i < n - 1; i++)
			{
				for (int j = i + 1; j < n; j++)
				{
					if (b[i] == b[j])
					{
						w = 1;
						break;
					}
				}
			}
		} while (w != 0);
		if (t == -1)
		{
			break;
		}
		bull = cow = 0;
		for (int i = 0; i < n; i++)
		{
			if (a[i] == b[i])
			{
				bull++;
			}
			else
			{
				for (int j = 0; j < n; j++)
				{
					if ((a[i] == b[j]) && (i != j))
					{
						cow++;
					}
				}
			}
		}
		printf("Быков: %d, коров: %d \n", bull, cow);
		if (bull == n)
		{
			break;
		}
	}
	if (bull == n)
	{
		printf("Ты выйграл игру, ура!!! \n");
	}
	system("pause");
}
