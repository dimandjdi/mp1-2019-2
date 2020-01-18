#define _USE_MATH_DEFINES

#include <stdio.h>
#include <locale.h>
#include <math.h>
int choice_regime()
{
	int n;
	printf("Выберете режим\n");
	printf("1 - Одинократный расчет функции в точке\n");
	printf("2 - Серийный эксперимент\n");
	scanf_s("%d", &n);
	return n;
}

int choice_function()
{
	int n;
	printf("Выберете функцию\n");
	printf("1 - sin(x)\n");
	printf("2 - cos(x)\n");
	printf("3 - exp(x)\n");
	printf("4 - ch(x)\n");
	printf("5 - ln(1 + x)\n");
	printf("6 - sqrt(1 + x)\n");
	scanf_s("%d", &n);
	return n;
}

void my_sin(double x, float E, int k)
{
	int i;
	double sin_c = sin(x), func = x, delta = fabs(sin_c - func), term = x;
	for (i = 2; (i <= k) && (delta > E); i++)
	{
		term = (-1) * term * x * x / ((2 * i - 1) * (2 * i - 2));
		func = func + term;
		delta = fabs(sin_c - func);	
	}
	printf("%16d   %26.6lf   %32.6lf\n", i - 1, func, delta);
}

void my_cos(double x, float E, int k)
{
	int i;
	double cos_c = cos(x), func = 1, delta = fabs(cos_c - func), term = 1;
	for (i = 2; (i <= k) && (delta > E); i++)
	{
		term = (-1) * term * x * x / ((2 * i - 2) * (2 * i - 3));
		func = func + term;
		delta = fabs(cos_c - func);
	}
	printf("%16d   %26.6lf   %32.6lf\n", i - 1, func, delta);
}

void my_exp(double x, float E, int k)
{
	int i;
	double exp_c = exp(x), func = 1, delta = fabs(exp_c - func), term = 1;
	for (i = 2; (i <= k) && (delta > E); i++)
	{
		term = term * x / (i - 1);
		func = func + term;
		delta = fabs(exp_c - func);
	}
	printf("%16d   %26.6lf   %32.6lf\n", i - 1, func, delta);
}

void my_ch(double x, float E, int k)
{
	int i;
	double ch_c = cosh(x), func = 1, delta = fabs(ch_c - func), term = 1;
	for (i = 2; (i <= k) && (delta > E); i++)
	{
		term = term * x * x / ((2 * i - 2) * (2 * i - 3));
		func = func + term;
		delta = fabs(ch_c - func);
	}
	printf("%16d   %26.6lf   %32.6lf\n", i - 1, func, delta);
}

void my_ln(double x, float E, int k)
{
	int i;
	double ln_c = log(1 + x), func = x, delta = fabs(ln_c - func), term = x;
	for (i = 2; (i <= k) && (delta > E); i++)
	{
		term = (-1) * term * x / i;
		func = func + term;
		delta = fabs(ln_c - func);
	}
	printf("%16d   %26.6lf   %32.6lf\n", i - 1, func, delta);
}

void my_sqrt(double x, float E, int k)
{
	int i;
	double sqrt_c = sqrt(1 + x), func = 1, delta = fabs(sqrt_c - func), term = 1;
	for (i = 2; (i <= k) && (delta > E); i++)
	{
		term = term * x * (0.5 - i + 2) / (i - 1);
		func = func + term;
		delta = fabs(sqrt_c - func);
	}
	printf("%16d   %26.6lf   %32.6lf\n", i - 1, func, delta);
}

void output_one(void(*f)(double, float, int), double x, double func)
{
	float E;
	int k;
	printf("Введите точность вычисления (>= 0,000001)\n");
	scanf_s("%f", &E);
	printf("Введите количество слагаемых от 1 до 1000\n");
	scanf_s("%d", &k);
	printf("Эталонное значение: %lf\n", func);
	printf("Кол-во слагаемых   Вычисленная оценка функции   Разница между оценкой и эталоном\n");
	f(x, E, k);
}

void output_two(void(*f)(double, float, int), double x, double func)
{
	int experience, i;
	printf("Введите количество экспериментов от 1 до 25\n");
	scanf_s("%d", &experience);
	printf("Эталонное значение: %lf\n", func);
	printf("Кол-во слагаемых   Вычисленная оценка функции   Разница между оценкой и эталоном\n");
	for (i = 0; i < experience; i++)
	{
		f(x, -1, i + 1);
	}		
}

void main()
{
	setlocale(LC_ALL, "Rus");
	int n, regime;
	void(*f)(double, float, int) = NULL;
	double x, func;
	regime = choice_regime();
	n = choice_function();
	if (n == 5)
		printf("Введите x (-1 < x <= 1)\n");
	else if (n == 6)
		printf("Введите x (-1 <= x <= 1)\n");
	else
		printf("Введите x\n");
	scanf_s("%lf", &x);
	switch (n)
	{
		case 1:
			f = my_sin;
			x = x / 180 * M_PI;
			func = sin(x);
			break;
		case 2:
			f = my_cos;
			x = x / 180 * M_PI;
			func = cos(x);
			break;
		case 3:
			f = my_exp;
			func = exp(x);
			break;
		case 4:
			f = my_ch;
			func = cosh(x);
			break;
		case 5:
			f = my_ln;
			func = log(1 + x);
			break;
		case 6:
			f = my_sqrt;
			func = sqrt(1 + x);
			break;
	}
	if (regime == 1)
		output_one(f, x, func);
	else
		output_two(f, x, func);
	system("pause");
}