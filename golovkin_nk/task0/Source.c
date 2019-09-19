#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <locale.h>
void main()
{
	setlocale(LC_ALL, "RU");


	double z, x1, y1, R1, x2, y2, R2, d;
	printf("Введите значения первой окружности (x, y), R: ");
	scanf_s("%lf %lf %lf", &x1, &y1, &R1);

	printf("Введите значения второй окружности (x, y), R: ");
	scanf_s("%lf %lf %lf", &x2, &y2, &R2);

	d = sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));

	if (R2 > R1)
	{
		z = R2;
		R2 = R1;
		R1 = z;
	}
	if ((R1 <= 0) || (R2 <= 0))
	{
		printf("Окружности не существуют");
	}
	  if (d == R1 + R2)
	{
		printf("Окружности касаются изнутри");
	}
	  if (d == R1-R2)
	{ 
		if (d==0)
		printf("Окружности совподают");
		else
	    printf("Окружности соприкасаются внутри");
	}
	  if (d > R1 + R2)
	{
		printf("Окружности не имеют общих точек");
	}
	  if ((R1 + R2 > d) && (R1 - R2 < d))
	{
		printf("Окружности пересекаются");
	}
	  if (d < R1 - R2)
	{
		printf("Окружность внутри окружности");
	}
	  _getch();
}


