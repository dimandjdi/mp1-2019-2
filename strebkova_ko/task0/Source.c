#include <stdio.h>�
#include <math.h>�
#include <locale.h>
#include <conio.h>
void main ()
{
	setlocale(LC_ALL, "Rus");
	double x1, y1, x2, y2, R1, R2, s;
	printf("������� ���������� ������ � ������ ��� ������ ����������");
	scanf_s("%lf %lf %lf", &x1, &y1,&R1);
	printf("������� ���������� ������ � ������ ��� ������ ����������");
	scanf_s("%lf %lf %lf", &x2, &y2, &R2);
	s = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
	if (s == fabs(R1 - R2))
	{
		if (s == 0)
			printf("���������� ���������");
		else
			printf("���������� ������� �����������");
	}
	else if (s < fabs(R1 - R2))
		printf("���� ���������� ������ ������");
	else if (s == R1 + R2)
		printf("������� ������� �����������");
	else if (s > R1 + R2)
		printf("���������� �� ����� ����� �����");
	else if ((s > fabs(R1 - R2)) && (s < R1 + R2))
		printf("���������� ������������");
	_getch();
}