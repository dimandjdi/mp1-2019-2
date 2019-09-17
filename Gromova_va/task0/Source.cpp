//#include "pch.h"
//#include<iostream>
#include <locale>
#include <stdio.h>
#include <math.h>
int main()
{
	setlocale(LC_CTYPE, "Russian");
	double x1, x2, y1, y2, r1, r2, z;
	printf_s("Введите координаты первой окружности x1 и y1:");
	scanf_s("%lf %lf", &x1, &y1);
	printf("Введите координаты первой окружности x2 и y2:");
	scanf_s("%lf %lf", &x2, &y2);
	printf("Введите радиусы r1 и r2:");
	scanf_s("%lf %lf", &r1, &r2);
	z = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	if (z == r1 + r2)
		printf_s("окружности касаются внешне");
	else
	{
		if ((z == 0) && (r1 == r2))
			printf("окружности совпадают ");
		else
		{
			if ((z > fabs(r1 - r2)) && (z < r1 + r2))
				printf("Окружности пересекаются ");
			else
			{
				if (z == fabs(r2 - r1))
					printf("Окружности касаются внутри");
				else
				{
					if (z < fabs(r1 - r2))
						printf("Одна окружность расположена внутри другой окрюжности");
					else
						printf("Окружности не пересекаются");
				}
			}
		}
	}
	return 0;
}