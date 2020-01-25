#include <stdio.h>
#include <math.h>
#include <locale.h>

float distance(float X1, float Y1, float X2, float Y2)
{
	float dist = sqrt((X2 - X1) * (X2 - X1) + (Y2 - Y1) * (Y2 - Y1));
	return dist;
}

int main(void)
{
	setlocale(LC_ALL, "Rus");

	float x1, y1, x2, y2, r1, r2, d;

	printf("\n x1 y1 r1\n");
	scanf("%f%f%f", &x1,&y1,&r1);
	printf("\n x2 y2 r2\n");
	scanf("%f%f%f", &x2,&y2,&r2);

	d = distance(x1, y1, x2, y2);

	if (d > (r1 + r2))
	{
		printf("Не пересекаются");
	}
	else if (d == r1 + r2)
	{
		printf("Касаются внешне");
	}
	else if (d < fabs(r1 - r2))
	{
		printf("Один внутри другого");
	}
	else if (d == fabs(r1 - r2))
	{
		printf("Касаются внутренне");
	}
	else
	{
		printf("Пересекаются");
	}
}