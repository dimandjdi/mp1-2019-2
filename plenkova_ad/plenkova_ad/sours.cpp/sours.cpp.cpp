#include <stdio.h>
#include <math.h>
#include <locale.h>
int main()
{
	setlocale(LC_ALL, "Rus");

	double x1, y1, x2, y2, r1, r2, d;
	printf("\n Введите координаты центра первой окружности х1=");
	scanf_s("%lf", &x1);
	printf("\n y1=");
	scanf_s("%lf", &y1);

	printf("\n Введите координаты центра второй окружности х2=");
	scanf_s("%lf", &x2);
	printf("\n y2=");
	scanf_s("%lf", &y2);

	printf("\n Введите радиус первой окружности r1=");
	scanf_s("%lf", &r1);
	printf("\n Введите радиус первой окружности r2=");
	scanf_s("%lf", &r2);

	d = (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));

	if (d > (fabs(r1 + r2)))
		printf("\n Окружности не пересекаются");

	else if (r1 == r2 && x1 == x2 && y1 == y2)
		printf("\n Координаты центров совпадают, радиусы равны");

	else if (d == fabs(r1 + r2))
		printf("\n Окружности касаются наружно");

	else if (((fabs(r1 - r2)) < d) && (d < (fabs(r1 + r2))))
		printf("\n Окружности пересекаются");
		
	else if (d == fabs(r1 - r2))
		printf("\n Окружности касаются внутренне");

	else if (d < (fabs(r1 - r2)))
		printf("\n Одна окружность внутри другой");
}