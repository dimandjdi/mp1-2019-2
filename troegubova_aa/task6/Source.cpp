#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <conio.h>

//-----------------------------------------------------------------------------------------------------------------------------------
int control_1(int left, int right, int x)
{
	while ((left > x) || (right < x))
	{
		printf("Задано некорректное значение, введите другое число: \n");
		scanf_s("%d", &x);
	}
	return x;
} 

double control_2(double left, double right, double x)
{
	while ((left >= x) || (right <= x))
	{
		printf("Задано некорректное значение, введите другое число: \n");
		scanf_s("%lf", &x);
	}
	return x;
}
//------------------------------------------------------------------------------------------------------------------------------------
 double expon(double x, int& n, double accur)
{
	double factorial = x;
	int count;
	double value = 1;
	for (count = 2; count < n + 2; count++) 
	{
		value += factorial;
		factorial *= x / count;
		if (fabs(exp(x) - value) < accur)
			break;
	}
	n = (n < count ? n : count);
	return value;
}

 double sin_f(double x, int& n, double accur)
{
	double factorial = x;
	double value = x;
	int r = 1; int  i;
	int sing[4] = { 1, 0, -1, 0 };
	for ( i = 1; i < n + 1; i++)
	{
		factorial *= x / (r + 1);
		r++;
		value += factorial * sing[i % 4];
		if (fabs(sin(x) - value) < accur)
			break;
	}
	if ((n + 1) > i)
		n = (i / 2) + 1;
	return value;
}

double cos_f(double x, int& n, double accur)
{
	double value = 1; int r = 1; int i;
	double factorial = x;
	int sing[4] = {0, -1, 0, 1};
	for ( i = 1; i < n; i++)
	{
		factorial *= x / (r + 1);
		r++;
		value += factorial * sing[i % 4];
		if (fabs(cos(x) - value) < accur)
			break;
	}
	if (n > i)
		n = (i / 2) + 3;
	return value;
}

double arsh_f(double x, int& n, double accur)
{
	x = control_2(-1, 1, x);
	double value = x;
	double factorial = x; int i, j;
	double k = 1; double r = 1; double v = 0;
	int sing[4] = { 1, 0, -1, 0 };
	for ( i = 1, j = 0; i < n; i++, j++)
	{
		factorial *= (x * r) / (r + 1);
		r++;
		v = factorial * sing[i % 4];
		if (v)
		{
			k *=(double) j / i;
			value += factorial * sing[i % 4] * k;
		}
		if (fabs(asinh(x) - value) < accur)
			break;
	}
	if (n > i)
		n = (i / 2) + 2;
	return value;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------
void regime_1()
{
	double(*function[5])(double x) = { exp, sin, cos, asinh };
	double(*mass[5])(double x, int& n, double accur) = { expon, sin_f, cos_f, arsh_f };
	int func; int n;
	printf("Выберите функцию из предложенного списка: \n1)exp(x)\n2)sin(x)\n3)cos(x)\n4)arsh(x)\n");
	scanf_s("%d", &func);
	func = control_1(1, 4, func);
	double x = 0;
	if (func == 4)
	{
		printf("Введите точку x, удовлетворяющую условию |x| < 1, в которой необходимо вычислить значение:\n");
		scanf_s("%lf", &x);
		x = control_2(-1, 1, x);
	}
	else
	{
		printf("Введите точку x, в которой необходимо вычислить значение:\n");
		scanf_s("%lf", &x);
	}
	double accur;
	printf("Введите число элементов ряда для выполнения расчета (N - от 1 до 1000):\n");
	scanf_s("%d", &n);
	n = control_1(1, 1000, n);
	printf("Введите точность вычисления (>= 0,000001):\n");
	scanf_s("%lf", &accur);
	accur = control_2(0.0000001, 1, accur);
	double value;
	value = mass[func - 1](x, n, accur);
	printf("Эталонное значение: %lf\n", function[func - 1](x));
	printf("Вычисленное значение функции: %lf\n", value);
	printf("Разница между оценкой и эталонным значением: %lf\n", fabs(function[func - 1](x) - value));
	printf("Количество слагаемых, которое было вычислено: %d\n", n);
}

void regime_2()
{
	double(*function[4])(double x) = { exp, sin, cos, asinh };
	double(*mass[4])(double x, int& n, double accur) = { expon, sin_f, cos_f, arsh_f };
	int func; double value; double accur = 0;
	printf("Выберите функцию из предложенного списка: \n1)exp(x)\n2)sin(x)\n3)cos(x)\n4)arsh(x)\n");
	scanf_s("%d", &func);
	func = control_1(1, 4, func); 
	double x;
	if (func == 4)
	{
		printf("Введите точку x, удовлетворяющую условию |x| < 1, в которой необходимо вычислить значение:\n");
		scanf_s("%lf", &x);
		x = control_2(-1, 1, x);
	}
	else
	{
		printf("Введите точку x, в которой необходимо вычислить значение:\n");
		scanf_s("%lf", &x);
	}
	int N;
	printf("Введите число экспериментов (NMax - от 1 до 25)\n");
	scanf_s("%d", &N);
	N = control_1(1, 25, N);
	int j = 1;
	printf("Эталонное значение: %lf\n", function[func - 1](x));
	printf("КОЛ-ВО СЛАГАЕМЫХ  %10c ВЫЧЕСЛЕННОЕ ЗНАЧЕНИЕ %10c РАЗНИЦА МЕЖДУ ОЦЕНКОЙ И ЭТАЛОННЫМ ЗНАЧЕНИЕМ\n" , ' ', ' ');
	printf("----------------- %10c -------------------- %10c -------------------------------------------\n", ' ', ' ');
	switch (func)
	{
	case 1:
		for (int i = 0; i < N; i++)
		{
			value = mass[func - 1](x, i, accur);
			printf("%9d %33lf %45lf\n", i + 1, value, fabs(function[func - 1](x) - value));
		}
		break;
	default:
		N *= 2;
		for (int i = 0; i < N; i += 2)
		{
			value = mass[func - 1](x, i, accur);
			printf("%9d %33lf %45lf\n", j++, value, fabs(function[func - 1](x) - value));
		}
		break;
	}
}
//--------------------------------------------------------------------------------------------------------------------------------------
int main()
{
	setlocale(LC_ALL, "Rus");
	int p = 1;
	while (p == 1)
	{
		void(*regime[2])() = { regime_1 , regime_2 };
		int r;
		printf("Выбери один из двух режимов работы программы:\n1)oднократный расчет функции в заданной точке\n2)серийный эксперимент\n");
		scanf_s("%d", &r);
		r = control_1(1, 2, r);
		regime[r - 1]();
		printf("Выбери действие:\n1)продолжить работу программы\n2)завершить работу программы\n");
		scanf_s("%d", &p);
		p = control_1(1, 2, p);
	}
	return 0; 
}