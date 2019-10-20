#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<locale.h>
int main()
{
	setlocale(LC_ALL, "Rus");
	int n, g = 1;
	while (g == 1)
	{
		printf("Выберите длину загадываемого числа(от 2 до 5)\n");
		scanf_s("%i", &n);
		if ((n < 2) || (n > 5))
		{
			printf("Неверная длина числа");
			return(0);
		}
		//printf("%d\n", n);
		else
		{
			srand(time(0));
			int x[5];
			for (int i = 0; i < n; i = i + 1)//генерация неповторяющихся цифр:
			{
				x[i] = rand() % 9 + 1;//генерируем рандомную цифру
				for (int j = 0; j < i; j = j + 1)//перебор цифр для сравнения
				{
					while (x[i] == x[j])//сравнение и замена повторяющихся цифр
					{
						x[i] = rand() % 10;
						j = 0;
					}
				}
				//printf("%d", x[i]);
			}

			int c[5], p, r, m, k = 0, b = 0;
			while (b != n)
			{
				printf("Попробуйте угадать число\n");
				scanf_s("%d", &m);
				for (int p = n - 1; p >= 0; p = p - 1)
				{
					k = 0;
					b = 0;
					c[p] = m % 10;
					m = m / 10;
				}
				/*for (int p = 0; p < n; p = p + 1)
				{
					printf("%i", c[p]);
				}*/
				for (int r = 0; r < n; r = r + 1)
				{
					//printf("%d", c[r]);
					if (x[r] == c[r])
					{
						b = b + 1;
					}
					else
					{
						for (p = 0; p < n; p++)
							if ((x[r] == c[p]) && (r != p))
								k = k + 1;
					}
				}
				printf("Быков %d    Коров %d\n", b, k);
				if (b == n)
					printf("Вы выиграли!!!");
				g = 0;
			}
		}
		printf("Если хотите сыграть ещё раз, нажмите 1\n");
		scanf_s("%d", &g);
	}
}