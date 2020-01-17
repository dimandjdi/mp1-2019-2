#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <locale.h>

long double fexp(double x, int *N,double eps)
{
	int i;
	double a = 1, y = 1;
	double zn = exp(x);
	for (i = 2; i <= N; i++)
	{
		a = (a*x) / (i - 1);
		y = y + a;
		if (fabsl(zn - y) < eps)
		{
			N = i - 1;
			return y;
		}
	}
	return y;
}

long double fsin(double x, int *N, double eps)
{
	int i, j;
	x = fmod(x, 2 * M_PI);
	long double a = x, y = x;
	long double result = sin(x);
	for (i = 2, j = 0; i <= N; i++, j++)
	{
		a = (a*x*x) / ((i + j)*(i + (j + 1)));
		if (i % 2 == 0)
			y = y - a;
		else
			y = y + a;
		if (fabsl(result - y) < eps)
		{
			N = i - 1;
			return y;
		}
	}
	return y;
}

long double fcos(double x, int *N, double eps)
{
	int i, j;
	x = fmod(x, 2 * M_PI);
	double a = 1, y = 1;
	double result = cos(x);
	for (i = 2, j = -1; i <= N; i++, j++)
	{
		a = (a*x*x) / ((i + j)*(i + (j + 1)));
		if (i % 2 == 0)
			y = y - a;
		else
			y = y + a;
		if (fabsl(result - y) < eps)
		{
			N = i - 1;
			return y;
		}
	}
	return y;
}

long double facos(double x, int *N, double eps)
{
	int i = 0;
	double a = x, y = M_PI / 2 - x;
	double result = acos(x);
	for (i = 0; i < N; i++)
	{
		a = a * ((2 * i + 1)*x*x*(2 * i + 1)) / (2 * (i + 1)*(2 * i + 3));
		y = y - a;
		if (fabsl(result - y) < eps)
		{
			N = i - 1;
			return y;
		}
	}
	return y;
}
void main()
{
	setlocale(LC_ALL, "Rus");
	int exit = 0, regim = 0, func, ys = 0;
	int N = 0, i;
	double x, eps;
	long double(*function[4])(double, int, double);
	function[0] = fexp;
	function[1] = fsin;
	function[2] = fcos;
	function[3] = facos;
	double(*Efunction[4])(double);
	Efunction[0] = exp;
	Efunction[1] = sin;
	Efunction[2] = cos;
	Efunction[3] = acos;
	long double result, myresult;
	while (exit == 0)
	{
		do {
			printf("Выберите режим работы:\n1. Однократный расчёт функции в заданной точке;\n2. Серийный эксперимент;\n");
			scanf("%d", &regim);
			if (regim < 1 || regim > 2)
				printf("Введите верный режим\n");
			} 
		while (regim < 1 || regim > 2);

		if (regim == 1)
		{
			printf("Выберите функцию:\n1 - exp(x)\n2 - sin(x);\n3 - cos(x);\n4 - arccos(x);\n");
			ys = 0;
			while (ys == 0)
			{
				scanf("%d", &func);
				ys = 1;
				if (func < 1 || func > 4)
				{
					printf("Введите верную функцию!\n");
					ys = 0;
				}
			}
			printf("Введите x, который хотите посчитать\n");
			scanf("%lf", &x);
			do {
				printf("Выберите точность вычислений (точность вычислений >=0,000001)\n");
				scanf("%lf", &eps);
				if ((eps < 0.000001) || (eps >= 1))
				{
					printf("Введите верную точность вычислений\n");
				}
				}
			while (eps < 0.000001);
			do {
				printf("Выберите число элементов ряда для выполнения расчета (число элементов ряда находится в промежутке от 1 до 10000)\n");
				scanf("%d", &N);
				if (N < 1 || N > 1000)
					printf("Введите верное количество\n");
				} 
			while (N < 1 || N > 1000);
			
			result = Efunction[func-1](x);
			myresult = function[func-1](x, N, eps);
			eps = fabsl(result - myresult);
			printf("Итог:\nЭталонное значение:                            %lf\n", result);
			printf("Оценка значения функции:                       %lf\n", myresult);
			printf("Разницу между оценкой и эталонным значением:   %lf\n", eps);
			printf("Количество слагаемых, которое было вычислено:  %d\n", N);
		}

		if (regim == 2)
		{
			N = 0;
			eps = -1;
			printf("Выберите функцию:\n1 - exp(x);\n2 - sin(x);\n3 - cos(x);\n4 - arccos(x);\n");
			ys = 0;
			while (ys == 0)
			{
				scanf("%d", &func);
				ys = 1;
				if (func < 0 || func > 4)
				{
					printf("Введите верный номер функции!\n");
					ys = 0;
				}
			}
			printf("Введите x, который хотите посчитать \n");
			if (func == 4)
				printf("Введите x с 2 знаками после запятой в диапазоне от -1 до 1!\n");
			scanf("%lf.2", &x);
			do {
				printf("Выберите число экспериментов для выполнения расчета от 1 до 25\n");
				scanf("%d", &N);
				if (N < 1 || N > 25)
					printf("Введите верное количество\n");
			} while (N < 1 || N > 25);
			result = 1.0471975512;
			printf("N      Эталон           Оценка           Разница\n");
			printf("-      ------           ------           -------\n");
			for (i = 1; i <= N; i++)
			{
				myresult = function[func-1](x, i, eps);
				printf("%.2d %16.10lf %16.10lf %16.10lf\n", i, result, myresult, fabsl(result - myresult));
			}
			exit = sin(x);
			printf("%d\n", exit);
		}
		printf("Если хотите выйти из программы - введите 1,если хотите продолжить - 0\n");
		scanf("%d", &exit);
	}
}