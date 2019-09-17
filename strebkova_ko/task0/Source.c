#include <stdio.h> 
#include <math.h> 
#include <locale.h>
#include <conio.h>
void main ()
{
	setlocale(LC_ALL, "Rus");
	double x1, y1, x2, y2, R1, R2, s;
	printf("Введите координаты центра и радиус для первой окружности");
	scanf_s("%lf %lf %lf", &x1, &y1,&R1);
	printf("Введите координаты центра и радиус для второй окружности");
	scanf_s("%lf %lf %lf", &x2, &y2, &R2);
	s = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
	if (s == fabs(R1 - R2))
	{
		if (s == 0)
			printf("Окружности совпадают");
		else
			printf("Внутреннее касание окружностей");
	}
	if (s < fabs(R1 - R2))
		printf("Одна окружность внутри другой");
	if (s == R1 + R2)
		printf("Внешнее касание окружностей");
	if (s > R1 + R2)
		printf("Окружности не касаются друг друга");
	if ((s > fabs(R1 - R2)) && (s < R1 + R2))
		printf("Окружности пересекаются");
	_getch();
}