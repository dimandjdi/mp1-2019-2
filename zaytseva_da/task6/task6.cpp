#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <locale.h>

long double myexp(long double x, int& N, long double eps)
{
	int i;
	long double a = 1, y = 1;
	long double m = exp(x);
	for (i = 2; i <= N; i++)
	{
		a = (a * x) / (i - 1);
		y = y + a;
		if (fabsl(m - y) < eps)
		{
			N = i - 1;
			return y;
		}
	}
	return y;
}

long double mysin(long double x, int& N, long double eps)
{
	int i, j;
	x = fmod(x, 2 * M_PI);
	long double a = x, y = x;
	long double m = sin(x);
	for (i = 2, j = 0; i <= N; i++, j++)
	{
		a = (a * x * x) / ((i + j) * (i + (j + 1)));
		if (i % 2 == 0)
			y = y - a;
		else
			y = y + a;
		if (fabsl(m - y) < eps)
		{
			N = i - 1;
			return y;
		}
	}
	return y;
}

long double mycos(long double x, int& N, long double eps)
{
	int i, j;
	x = fmod(x, 2 * M_PI);
	long double a = 1, y = 1;
	long double m = cos(x);
	for (i = 2, j = -1; i <= N; i++, j++)
	{
		a = (a * x * x) / ((i + j) * (i + (j + 1)));
		if (i % 2 == 0)
			y = y - a;
		else
			y = y + a;
		if (fabsl(m - y) < eps)
		{
			N = i - 1;
			return y;
		}
	}
	return y;
}

long double myacos(long double x, int& N, long double eps)
{
	int i = 0;
	long double a = x, y = M_PI / 2 - x;
	long double m = acos(x);
	for (i = 0; i < N; i++)
	{
		a = a * ((2 * i + 1) * x * x * (2 * i + 1)) / (2 * (i + 1) * (2 * i + 3));
		y = y - a;
		if (fabsl(m - y) < eps)
		{
			N = i - 1;
			return y;
		}
	}
	return y;
}



long double myatanh(long double x, int& N, long double eps)
{
	int i, z = 0, j = 3;
	double y = x, buffer = x;
	if ((x >= 1) || (x <= -1))
	{
		if (x == 1)
			return INFINITY;
		if (x == -1)
			return -INFINITY;
		return -NAN;
	}
	for (i = 2; i <= N; i++)
	{
		y += (y * x * x) / j;
		j = j + 2;
		if (fabs(atanh(x) - y) < eps)
			break;
		z++;
	}
	N = z + 1;
	eps = fabs(atanh(x) - y);
	return y;
}


void main()
{
	setlocale(LC_ALL, "Rus");
	int a = 0, r = 0, f, flag0 = 0;
	int N = 0, i;
	long double x, t;
	long double(*myfunc[5])(long double, int&, long double);
	myfunc[0] = myexp;
	myfunc[1] = mysin;
	myfunc[2] = mycos;
	myfunc[3] = myacos;
	myfunc[4] = myatanh;
	double(*ITfunc[5])(double);
	ITfunc[0] = exp;
	ITfunc[1] = sin;
	ITfunc[2] = cos;
	ITfunc[3] = acos;
	ITfunc[4] = atanh;
	long double result, myresult;
	setlocale(LC_ALL, "Rus");
	while (a == 0)
	{
		do
		{
			printf("�������� ����� ������:\n1) ����������� ������ ������� � �������� �����;\n2) �������� �����������;\n");
			scanf_s("%d", &r);
			if (r < 1 || r>2)
				printf("� ���������, �� �������� ��� ����� ������. ����������, ���������� ��� ���\n");
		} while (r < 1 || r>2);
		switch (r)
		{
		case 1:
			printf("�������� �������:\n0) e^(x);\n1) sin(x);\n2) cos(x);\n3) arccos(x);\n4) atanh(x);\n");
			flag0 = 0;
			while (flag0 == 0)
			{
				scanf_s("%d", &f);
				flag0 = 1;
				if (f < 0 || f>4)
				{
					printf("���������a ������� ����� �������, �������� ������������ �����\n");
					flag0 = 0;
				}
			}
			if ((f == 3) || (f == 4))
			{
				printf("��� �������� ������� arccos(x) � atanh(x), ����������, ������� x � ��������� �� -1 �� 1 � � ����� ������� ����� ������� \n");
			}
			else
			{
				printf("������� x, ������� ������ ���������...\n");
			}
			scanf_s("%lf", &x);
			do {
				printf("�������� �������� ���������� >=0,000001\n");
				scanf_s("%lf", &t);
				if (t < 0.000001)
				{
					printf("� ���������, �� ����� �������� ���������� �������, ����������, ���������� ��� ���\n");
				}
			} while (t < 0.000001);
			do {
				printf("�������� ����� ��������� ���� ��� ���������� ������� (�� 1 �� 10000)\n");
				scanf_s("%d", &N);
				if (N < 1 || N>1000)
					printf("� ���������, �� �������� ��� ����� ����� ���������, ����������, ���������� ��� ���\n");
			} while (N < 1 || N>1000);
			result = ITfunc[f](x);
			myresult = myfunc[f](x, N, t);
			t = fabsl(result - myresult);
			printf("����:\n��������� ��������:                    %lf\n", result);
			printf("������ �������� �������:                      %lf\n", myresult);
			printf("������� ����� ������� � ��������� ���������:  %lf\n", t);
			printf("���������� ���������, ������� ���� ���������: %d\n", N);
			break;
		case 2:
			N = 0;
			t = -1;
			printf("�������� �������:\n0) e^(x);\n1) sin(x);\n2) cos(x);\n3) arccos(x);\n4) atanh(x);\n");
			flag0 = 0;
			while (flag0 == 0)
			{
				scanf_s("%d", &f);

				flag0 = 1;
				if (f < 0 || f>4)
				{
					printf("���������a ������� ����� �������, �������� ������������ �����\n");
					flag0 = 0;
				}
			}
			if ((f == 3) || (f == 4))
			{
				printf("��� �������� ������� arccos(x) � atanh(x), ����������, ������� x � ��������� �� -1 �� 1 � � ����� ������� ����� ������� \n");
			}
			else
			{
				printf("������� x, ������� ������ ���������...\n");
			}
			scanf_s("%lf.2", &x);
			do 
			{
				printf("�������� ����� ������������� ��� ���������� �������\n (����������� ���������� 1, ������������ - 25)\n");
				scanf_s("%d", &N);
				if (N < 1 || N>25)
					printf("� ���������, �� �������� ��� ����� ���������� �������������. ����������, ���������� ��� ���\n");
			} while (N < 1 || N>25);
			result = ITfunc[f](x);
			printf("N      ������         ������         �������\n");
			printf("-      ------         ------         -------\n");
			for (i = 1; i <= N; i++)
			{
				myresult = myfunc[f](x, i, t);
				printf("%.2d %16.10lf %16.10lf %16.10lf\n", i, result, myresult, fabsl(result - myresult));
			}
			break;
		}
		printf("������ ��������� ������ � ����������?\n 0) ���, 1) ��\n");
		scanf_s("%d", &a);
	}
}