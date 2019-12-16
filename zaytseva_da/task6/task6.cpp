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
			printf("Выберите режим работы:\n1) Однократный расчёт функции в заданной точке;\n2) Серийный эксперимент;\n");
			scanf("%d", &r);
			if (r < 1 || r>2)
				printf("К сожалению, Вы ошиблись при вводе режима. Пожалуйста, попробуйте еще раз\n");
		} while (r < 1 || r>2);
		switch (r)
		{
		case 1:
			printf("Выберите функцию:\n0) e^(x);\n1) sin(x);\n2) cos(x);\n3) arccos(x);\n4) atanh(x);\n");
			flag0 = 0;
			while (flag0 == 0)
			{
				scanf("%d", &f);
				flag0 = 1;
				if (f < 0 || f>4)
				{
					printf("Пожалуйстa введите номер функции, согласно предложенным ранее\n");
					flag0 = 0;
				}
			}
			printf("Введите x, который хотите посчитать...\n");
			scanf("%lf", &x);
			do {
				printf("Выберите точность вычислений >=0,000001\n");
				scanf("%lf", &t);
				if (t < 0.000001)
				{
					printf("К сожалению, Вы ввели точность вычислений неверно, пожалуйста, попробуйте ещё раз\n");
				}
			} while (t < 0.000001);
			do {
				printf("Выберите число элементов ряда для выполнения расчета (от 1 до 10000)\n");
				scanf("%d", &N);
				if (N < 1 || N>1000)
					printf("К сожалению, Вы ошиблись при вводе числа элементов, пожалуйста, попробуйте ещё раз\n");
			} while (N < 1 || N>1000);
			result = ITfunc[f](x);
			myresult = myfunc[f](x, N, t);
			t = fabsl(result - myresult);
			printf("Итог:\nЭталонное значение:                    %lf\n", result);
			printf("Оценка значения функции:                      %lf\n", myresult);
			printf("Разницу между оценкой и эталонным значением:  %lf\n", t);
			printf("Количество слагаемых, которое было вычислено: %d\n", N);
			break;
		case 2:
			N = 0;
			t = -1;
			printf("Выберите функцию:\n0) e^(x);\n1) sin(x);\n2) cos(x);\n3) arccos(x);\n4) atanh(x);\n");
			flag0 = 0;
			while (flag0 == 0)
			{
				scanf("%d", &f);

				flag0 = 1;
				if (f < 0 || f>4)
				{
					printf("Пожалуйстa введите номер функции, согласно предложенным ранее\n");
					flag0 = 0;
				}
			}
			printf("Введите x, который хотите посчитать:\n");
			if ((f == 3)||(f==4))
				printf("Для подсчета функций arccos(x) и atanh(x), пожалуйста, введите x в диапазоне от -1 до 1 и с двумя знаками после запятой \n");
			scanf("%lf.2", &x);
			do {
				printf("Выберите число экспериментов для выполнения расчета\n (минимальное количество 1, максимальное - 25)\n");
				scanf("%d", &N);
				if (N < 1 || N>25)
					printf("К сожалению, вы ошиблись при вводе количества экспериментов. Пожалуйста, попробуйте ещё раз\n");
			} while (N < 1 || N>25);
			result = ITfunc[f](x);
			printf("N      Эталон         Оценка         Разница\n");
			printf("-      ------         ------         -------\n");
			for (i = 1; i <= N; i++)
			{
				myresult = myfunc[f](x, i, t);
				printf("%.2d %16.10lf %16.10lf %16.10lf\n", i, result, myresult, fabsl(result - myresult));
			}
			break;
		}
		printf("Хотите завершить работу с программой?\n 0) нет, 1) да\n");
		scanf("%d", &a);
	}
}