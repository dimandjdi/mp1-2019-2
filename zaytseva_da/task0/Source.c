#include <stdio.h>
#include <math.h>
int main(void) {
	double  x1, x2, y1, y2, a, b, d, c, v, r1, r2;
	printf("������� ���������� ������ � ������ ������ ���������� x1 y1 r1:");
	scanf_s("%lf %lf %lf", &x1, &y1, &r1);
	printf("������� ���������� ������ � ������ ������ ���������� x2 y2 r2:");
	scanf_s("%lf %lf %lf", &x2, &y2, &r2);
	a = pow((x1 - x2), 2);
	b = pow((y1 - y2), 2);
	d = sqrt(a + b);
	c = fabs(r1 - r2);
	v = r1 + r2;
	if ((d > c) && (d < v))
	{
		printf("���������� ������������");
		return;
	}
	if (d < c)
		{
		printf("���� ���������� ����� ������ ������");
		return;
		}
	if (d>v)
		{ 
		printf("���� ���������� ��������� ��� ������");
		return;
		}
	if (d == v)
		{
		printf("���������� �������� ������� �������");
		return;
		}
	if (d == c)
		{
		printf("���������� �������� ���������� �������");
		return;
		}
	if ((d==0)&&(r1==r2))
		{
		printf("���������� ���������");
		return;
		}
	return;
}