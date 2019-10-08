#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <time.h>

void main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");

	int x, y, num, q, t, i, j, z, m, n;

	printf("Введите число от 2 до 5");
	scanf_s("%int", &n);
	switch (n)
	{
	case 2:
		y = 99; x = 10;
		break;
	case 3:
		y = 999; x = 100;
		break;
	case 4:
		y = 9999; x = 1000;
		break;
	case 5:
		y = 99999; x = 10000;
		break;
	}
	num = rand() % (y - x + 1) + x;
	while (q != num)
	{
		scanf_s("%int", &q);
		for (i = 0; i < n; ++i)
		{
			z = num % 10;
			num = num / 10;
			for (j = 0; j < n; ++j)
			{
				m = q % 10;
				q = q / 10;
				if (z == m)
					if ((z == m) && (i == j))
						printf("Цифра %int угадана вплоть до позиции", m);
					else printf("Цифра %int угадана, но не на верной позиции", m);
			}
		}
	}
}


/* там все дичь, смотри сюда
	do
	num = rand() % (y - x + 1) + x;
	while(!((num % 10) != (num % 100)/10))
	________
	do
	num = rand() % (y - x + 1) + x;
	while(!((num % 10) != ((num % 100)/10) != ((num % 1000)/100)))
	________
	do
	num = rand() % (y - x + 1) + x;
	while(!((num % 10) != ((num % 100)/10) != ((num % 1000)/100) != ((num % 10000)/1000)))
	________
	do
	num = rand() % (y - x + 1) + x;
	while(!((num % 10) != ((num % 100)/10) != ((num % 1000)/100) != ((num % 10000)/1000) != ((num % 100000)/10000))) 
*/