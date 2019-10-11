#include <math.h> 
#include <stdio.h> 
#include <locale.h> 
int main()
{
	setlocale(LC_CTYPE, "Russian");
	double x1, y1, r1, x2, y2, r2;
	double a, h;
	printf("Введите x1, y1, r1 и x2, y2, r2: ");
	scanf_s("%lf %lf %lf %lf %lf %lf", &x1, &y1, &r1, &x2, &y2, &r2);
	a = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	if ((a == 0) && (r1 == r2))
		printf("Окружности совпадают");
	else if (a < fabs(r1 - r2))
		printf("Одна окружность расположена внутри другой окружности");
	else if ((a > fabs(r1 - r2)) && (a < r1 + r2))
		printf("Окружности пересекаются");
	else if (a == r1 + r2)
		printf("Окружности касаются внешним образом");
	else if (a == fabs(r1 - r2))
		printf("Окружности касаются внутренним образом");
	else if (a > r1 + r2)
		printf("Одна окружность находится вне другой окружности");
	printf("\n");
	system("pause");
}



#include<stdio.h>
#include<locale.h>
void main()
{
	setlocale(LC_CTYPE, "Russian");

	int word, numder;
	char c;
	char n;
	word = numder = c = 0;
	printf("Введите строку: ");

	do
	{
		c = getchar();

		if ((c >= '0') && (c <= '9'))
		{
			while ((c != ' ') && (c != '\t') && (c != '\n'))
			{
				c = getchar();
			}
			numder++;
		}

		else
		{
			if ((c != ' ') && (c != '\n'))
			{
				do
				{
					c = getchar();
				} while ((c != ' ') && (c != '\t') && (c != '\n'));
				word++;
			}
		}
	} while (c != '\n');

	printf("Количество чисел: %d \n", numder);
	printf("Количество слов: %d \n", word);
	system("pause");
}