//#include "pch.h"
//#include<iostream>
#include <locale>
#include <stdio.h>
#include <math.h>
int main()
{
	setlocale(LC_CTYPE, "Russian");
	double x1, x2, y1, y2, r1, r2, z;
	printf_s("������� ���������� ������ ���������� x1 � y1:");
	scanf_s("%lf %lf", &x1, &y1);
	printf("������� ���������� ������ ���������� x2 � y2:");
	scanf_s("%lf %lf", &x2, &y2);
	printf("������� ������� r1 � r2:");
	scanf_s("%lf %lf", &r1, &r2);
	z = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	if (z == r1 + r2)
		printf_s("���������� �������� ������");
	else
	{
		if ((z == 0) && (r1 == r2))
			printf("���������� ��������� ");
		else
		{
			if ((z > fabs(r1 - r2)) && (z < r1 + r2))
				printf("���������� ������������ ");
			else
			{
				if (z == fabs(r2 - r1))
					printf("���������� �������� ������");
				else
				{
					if (z < fabs(r1 - r2))
						printf("���� ���������� ����������� ������ ������ ����������");
					else
						printf("���������� �� ������������");
				}
			}
		}
	}
	return 0;
}

