#include <stdio.h>
#include <math.h>
#include <locale.h>
int main()
{
	setlocale(LC_ALL, "Rus");

	double x1, y1, x2, y2, r1, r2, d;
	printf("\n ������� ���������� ������ ������ ���������� �1=");
	scanf_s("%lf", &x1);
	printf("\n y1=");
	scanf_s("%lf", &y1);

	printf("\n ������� ���������� ������ ������ ���������� �2=");
	scanf_s("%lf", &x2);
	printf("\n y2=");
	scanf_s("%lf", &y2);

	printf("\n ������� ������ ������ ���������� r1=");
	scanf_s("%lf", &r1);
	printf("\n ������� ������ ������ ���������� r2=");
	scanf_s("%lf", &r2);

	d = (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));

	if (d > (fabs(r1 + r2)))
		printf("\n ���������� �� ������������");

	else if (r1 == r2 && x1 == x2 && y1 == y2)
		printf("\n ���������� ������� ���������, ������� �����");

	else if (d == fabs(r1 + r2))
		printf("\n ���������� �������� �������");

	else if (((fabs(r1 - r2)) < d) && (d < (fabs(r1 + r2))))
		printf("\n ���������� ������������");

	else if (d == fabs(r1 - r2))
		printf("\n ���������� �������� ���������");

	else if (d < (fabs(r1 - r2)))
		printf("\n ���� ���������� ������ ������");
}