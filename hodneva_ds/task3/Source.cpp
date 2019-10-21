#include <stdio.h> 
#include <time.h> 
#include <stdlib.h> 
#include <locale.h> 
int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	int n;
	bool r;
	int comp[5] = { 0 }; // массив с числом, которые загадал компьютер
	int my[5] = { 0 }; // массив с числом, которое вводит пользователь
	int cow = 0; //коровы
	int bull = 0; //быки
	int i,j,z;
	int p = 1;
	bool alreadyThere; //если в массиве число повторяется, то alreadyThere принимает значение true
		printf_s("Введите количество цифр в числе\n");
		scanf_s("%d", &n);
		while (n < 2 || n > 5) 
	{
		printf_s("Неправильный ввод. Введите количество цифр в числе\n");
		scanf_s("%d", &n);
	}
	alreadyThere = true;
	while (alreadyThere == true)
	{
		alreadyThere = false;
		for (i = 0; i < n; i++)
		{
				comp[i] = 1 + rand() % 9;
		}
		for (i = 0; i < n; i++)
		{
			for (j = i + 1; j < n; j++)
			{
				if (comp[i] == comp[j])
				{
					alreadyThere = true;
					break;
				}
			}
		}
	}

	for (i = 0; i < n; i++)
	{
		p = p * 10;
	}
	while (bull != n)
	{
		do
		{
			r = true;
			printf_s("Введите число с неповторяющимися цифрами\n");
			scanf_s("%d", &z);
			if (z >= p)
			{
				printf_s("Ваше число длинее, чем нужно\n");
				r = false;
			}
			else
				if (z < p / 10)
				{
					printf_s("Введенное число короче, чем нужно\n");
					r = false;
				}
				else
				{
					for (i = 0; i < n; i++)
					{
						my[i] = z % 10;
						z = z / 10;
					}
					for (i = 0; i < n; i++)
						for (j = i + 1; j < n; j++)
							if (my[i] == my[j])
							{
								r = false;
								break;
							}
				}
		} 
		while (r != true);

		cow = 0;
		bull = 0;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				if (my[i] == comp[j] && i == j)
					bull++;
				if (my[i] == comp[j] && i != j)
					cow++;
			}
		}
		printf_s("cow-%d, bull-%d\n", cow, bull);
	}
	printf_s("Вы выиграли");
	scanf_s("%d", &cow);
}
