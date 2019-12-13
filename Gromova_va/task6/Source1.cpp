#define _USE_MATH_DEFINES 
#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>

void exponenta(double x, int& N, double tochnost)
{
	int i;
	double result = 1., res = x;
	double reference = exp(x);
	for (i = 1; i < N; i++)
	{
		result += res;
		res *= x / double(i + 1);
		if (fabs(result - reference) < tochnost)
			break;
	}
	N = i - 1;
	double delta = fabsl(result - reference);
	printf("Эталонное значение в точке x: %lf\n", reference);
	printf("Вычисленная оценка значения функции в точке x: %lf\n", result);
	printf("Разница между оценкой и эталонным значением в точке x: %lf\n", delta);
	printf("Количество слагаемых, которое было вычислено: %li\n", N);
	_getch();
}
void Exponenta(double x, int& N)
{
	int i;
	double result = 1., res = x;
	double reference = exp(x);
	for (i = 1; i < N; i++)
	{
		result += res;
		res *= x / double(i + 1);
		printf("%3i %17lf %15lf %15lf\n", i, reference, result, fabs(reference - result));
	}
	_getch();
}
void sinys(double x, int& N, double tochnost)
{
	int i;
	x *= M_PI / 180;
	double result = 0, res = 1;
	double reference = sin(x);
	res = x;
	for (i = 1; i < N; i++)
	{
		result += res;
		res *= ((-1) * x * x) / ((2 * i) * (2 * i + 1));
		if (fabs(result - reference) < tochnost)
			break;
	}
	N = i - 1;
	double delta = fabsl(result - reference);
	printf("Эталонное значение в точке x: %lf\n", reference);
	printf("Вычисленная оценка значения функции в точке x: %lf\n", result);
	printf("Разница между оценкой и эталонным значением в точке x: %lf\n", delta);
	printf("Количество слагаемых, которое было вычислено: %li\n", N);
	_getch();
}
void Sinys(double x, int& N)
{
	int i;
	x *= M_PI / 180;
	double result = 0, res = 1;
	double reference = sin(x);
	res = x;
	for (i = 1; i < N; i++)
	{
		result += res;
		res *= ((-1) * x * x) / ((2 * i) * (2 * i + 1));
		printf("%3i %17lf %15lf %15lf\n", i, reference, result, fabs(reference - result));
	}
	_getch();
}
void cosinys(double x, int& N, double tochnost)
{
	x *= M_PI / 180;
	int i;
	double result = 0., res = 1.;
	double reference = cos(x);
	for (i = 1; i < N; i++)
	{
		result += res;
		res *= ((-1.) * x * x) / ((2 * i) * (2 * i - 1));
		if (fabs(result - reference) < tochnost)
			break;
	}
	N = i - 1;
	double delta = fabsl(result - reference);
	printf("Эталонное значение в точке x: %lf\n", reference);
	printf("Вычисленная оценка значения функции в точке x: %lf\n", result);
	printf("Разница между оценкой и эталонным значением в точке x: %lf\n", delta);
	printf("Количество слагаемых, которое было вычислено: %li\n", N);
	_getch();
}
void Cosinys(double x, int& N)
{
	x *= M_PI / 180;
	int i;
	double result = 0., res = 1.;
	double reference = cos(x);
	for (i = 1; i < N; i++)
	{
		result += res;
		res *= ((-1.) * x * x) / ((2 * i) * (2 * i - 1));
		printf("%3i %17lf %15lf %15lf\n", i, reference, result, fabs(reference - result));
	}
	_getch();
}
double bink(int n, int k)
{
	double result = 1;
	for (unsigned i = 1; i <= n - k; i++)
		result *= double(k + i) / double(i);
	return result;
}
double bernulli(int n)
{
	if (n > 255)
		n = 255;
	double ber[256] = { 0 };
	ber[0] = 1.;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
			ber[i] += bink(i + 1, j + 1) * ber[i - j];
		ber[i] *= (-1.) / double(i + 1);
	}
	return ber[n];
}
void tangens(double x, int& N, double tochnost)
{
	x = x * M_PI / 180;
	int i;
	double result = 0., res1 = 1., res2 = -1.;
	res1 /= x;
	res2 /= x;
	double reference = tan(x);
	for (i = 1; i < N; i++)
	{
		double berni = bernulli(2 * i) / bernulli(2 * i - 2);
		res1 *= ((-4.) * x * x * berni) / ((2 * i) * (2 * i - 1));
		res2 *= ((-16.) * x * x * berni) / ((2 * i) * (2 * i - 1));
		result += res1 + res2;
		if (fabs(result - reference) < tochnost)
			break;
	}
	N = i - 1;
	double delta = fabsl(result - reference);
	printf("Эталонное значение в точке x: %lf\n", reference);
	printf("Вычисленная оценка значения функции в точке x: %lf\n", result);
	printf("Разница между оценкой и эталонным значением в точке x: %lf\n", delta);
	printf("Количество слагаемых, которое было вычислено: %li\n", N);
	_getch();
}
void Tangens(double x, int& N)
{
	x = x * M_PI / 180;
	int i;
	double result = 0., res1 = 1., res2 = -1.;
	res1 /= x;
	res2 /= x;
	double reference = tan(x);
	for (i = 1; i < N; i++)
	{
		double ber = bernulli(2 * i) / bernulli(2 * i - 2);
		res1 *= ((-4.) * x*x * ber) / ((2 * i) * (2 * i - 1));
		res2 *= ((-16.) * x*x * ber) / ((2 * i) * (2 * i - 1));
		result += res1 + res2;
		printf("%3i %17lf %15lf %15lf\n", i, reference, result, fabs(reference - result));
	}
	_getch();
}
int main()
{
	setlocale(2, "Rus");
	double res_pr;//результат от компьютера;
	int i, num = 0, N = 0, NMax = 0;
	double tochnost = -1;//для погрешности;
	double  x ;//переменная для расчётов;
	double delta = 0, myresult = 0;
	int mode =0;
	void(*myfunc[4])(double, int& , double);//для однократных расчётов;
	myfunc[0] = sinys;
	myfunc[1] = cosinys;
	myfunc[2] = exponenta;
	myfunc[3] = tangens;
	void(*myfunc1[4])(double, int&);//для серийного эксперимента;
	myfunc1[0] = Sinys;
	myfunc1[1] = Cosinys;
	myfunc1[2] = Exponenta;
	myfunc1[3] = Tangens;
	do
	{
		printf("Введите режим:\n1 - Однократный расчёт функции в заданной точке,\n2 - Серийный эксперимент;\n");
		scanf_s("%d", &mode);
	} while ((mode < 1) || (mode > 2));
	while ((num < 1) || (num > 4))
	{
		printf("Выберите функцию из предложенных:\n1) sin(x)\n2) cos(x)\n3) exp(x)\n4) tg(x)\n");
		scanf_s("%i", &num);
	}
	printf("Введите точку x, в которой необходимо вычислить значение.\n");
	scanf_s("%lf", &x);
	switch (mode)
	{
	case 1://если выбрали однократный расчёт;
		while (tochnost < 0.000001)
		{
			printf("Выберите точность вычислений.(Точность вычислений >=0,000001)\n");
			scanf_s("%lf", &tochnost);
		}	
		while ((N < 1) || (N > 1000))
		{
			printf("Задайте число элементов ряда для выполнения расчета (от 1 до 1000):\n");
			scanf_s("%i", &N);
		}
		  myfunc[num - 1](x, N, tochnost);
		  break;
	case 2://если выбрали серийный эксперимент;
		while ((NMax < 1) || (NMax > 25))
		{
			printf("Задайте число экспериментов NMax (от 1 до 25).\n");
			scanf_s("%d", &NMax);
		}
		printf("  N           ЭТАЛОН          ОЦЕНКА          РАЗНИЦА\n");
		printf("  -           ------           ------         -------\n");
		myfunc1[num - 1](x, NMax);
	}
	system("pause");
}