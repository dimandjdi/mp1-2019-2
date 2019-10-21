#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
int main(void)
{
	int mass1[5],
		mass2[5],
		i, z, n, x, bull = 0, cow = 0;
	int l = 1;
	setlocale(LC_ALL, "Rus");
	printf("Выберите и введите длину числа от 2 до 5 символов\n");
	scanf_s("%d", &n);
	while ((n < 2) || (n > 5))
	{
		printf("Вы неправльно ввели длину числа, попробуйте еще раз\n");
		scanf_s("%d", &n);
	}
	while (l == 1)
	{
		srand(time(NULL));
		mass1[0] = 1 + rand() % 9;
		l = 0;
		i = 1;
		while (i < n)
		{
			mass1[i] = rand() % 10;
			i++;
		}
		for (i = 0; i < n; i++)
			for (z = i + 1; z < n; z++)
			{
				if (mass1[i] == mass1[z])
				{
					l = 1;
					break;
				}
			}
	}
	while (bull != n)
	{
		printf("Попробуйте угадать число\n");
		scanf_s("%d", &x);
		bull = 0;
		cow = 0;
		for (i = n - 1; i >= 0; i--)
		{
			mass2[i] = x % 10;
			x = x / 10;
		}
		for (i = 0; i < n; i++)
		{
			if (mass2[i] == mass1[i])
				bull++;
			else for (z = 0; z < n; z++)
			{
				if (mass2[i] == mass1[z])
					cow++;
			}
		}
		printf("%d быков %d коров\n", bull, cow);
	}
	if (bull == n)
		printf("число отгадано!\n");
	system("pause");
}