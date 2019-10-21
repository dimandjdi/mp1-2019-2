#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>

void main()
{
	setlocale(LC_ALL, "Ru");
	int x, n, flag, chislo, bik, korova;
	bik = 0; korova = 0;
    int j, i;
	unsigned int mas[5];
    int igrok[5];
	srand(time(0));
	printf("Выберите длину загадываемого числа от (2 до 5)\n");
	scanf_s("%i", &n);
	for (i = 0; i < (n); i++)
	{
		flag = 1;
	    while (flag != 0)
	    {
		    flag = 0;
		    mas[i] = rand() % 9 + 1;
		    for (int j = 0; j < i; j++)
			if (mas[i] == mas[j])
			{
				flag= 1;
				break;
			}

	    }
	}
	printf("Компьютер загадал число,попробуй угадать, если хочешь закончить игру напиши '1'\n");
	while (bik != n)
	{
		scanf_s("%i", &chislo);
		if (chislo == 1)
		{
			bik = n;
			printf("К сожалению, у тебя не вышло победить,попробуй в другой раз\n");
			system("pause");
			return 0;
		}
		else
		{
			bik = 0;
			korova = 0;
			for (i = n-1; i >= 0; i--)
			{
				igrok[i] = chislo % 10;
				chislo = chislo / 10;
			}
			for (i = 0; i < n; i++)
			{
				if (mas[i] == igrok[i])
					bik++;
				else 
				{
					for (j = 0; j < n; j++)
					{
						if (igrok[j] == mas[i])
							korova++;
						else
							korova = korova;
					}
				}
			}
			printf("Быков:%i   Коров:%i\n", bik, korova);
		}
	}
	printf("Ура,ты победил\n");
		system("pause");
}
