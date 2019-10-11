#include<stdio.h>
#include<locale.h>
#include<time.h>
#include <stdlib.h>
#include<math.h>
int main()
{
	setlocale(LC_CTYPE, "Russian"); 
	int n, k, t, x, f, w, bull, cow, choice;
	bull = cow = choice = n = x = t = f = k = w = 0;
	int a[5], b[5];
    while ((n < 2) || (n > 5))
	{
		printf("Выберите количество цифр в загаданом числе (от 2 до 5 цифр): ");
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
				printf("Введите число: "); 
				scanf_s("%d", &t);
				k = 0;
				x = t;
				while (x != 0)
				{
					k++;
					x /= 10;
				}
			} while (k != n);
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
		bull = cow = 0;
		for (int i = 0; i < n; i++)
		{
			if (a[i] == b[i])
			{
				bull++;
			}
			else
			{
				for (int j = 0 ; j < n; j++)
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
		printf("Выберите соответствующую цифру: 1 - попытаться угатать ещё раз; 2 - сдаться: \n");
		scanf_s("%d", &choice);
		if (choice == 2)
		{
			printf("Игра проиграна, в следующий раз тебе повезёт больше. \n");
			break;
		}
    }
	if (bull == n)
	{
		printf("Ты выйграл игру, ура!!! \n");
	}
	system("pause");
}
