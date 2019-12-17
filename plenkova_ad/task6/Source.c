#define _USE_MATH_DEFINES 
#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>


void exponenta(double x, int N, double tochnost)
{
	int i;
	double znachenie = 1, znach1 = x;
	double etalon = exp(x);
	for (i = 1; i < N; i++)
	{
		znachenie += znach1;
		znach1 *= x / (i + 1);
		if (fabs(znachenie - etalon) < tochnost)
			break;
	}
	N = i - 1;
	double raznitsa = fabsl(znachenie - etalon);
	printf("Эталонное значение - %lf\n", etalon);
	printf("Полученное значение - %lf\n", znachenie);
	printf("Разница - %lf\n", raznitsa);
	printf("Количество слагаемых - %d\n", N);

}
void sinus(double x, int N, double tochnost)
{
	int i;
	x *= M_PI / 180;
	double znachenie = 0, znach1 = 1;
	double etalon = sin(x);
	znach1 = x;
	for (i = 1; i < N; i++)
	{
		znachenie += znach1;
		znach1 *= ((-1) * x * x) / ((2 * i) * (2 * i + 1));
		if (fabs(znachenie - etalon) < tochnost)
			break;
	}
	N = i - 1;
	double raznitsa = fabsl(znachenie - etalon);
	printf("Эталонное значение - %lf\n", etalon);
	printf("Полученное значение - %lf\n", znachenie);
	printf("Разница - %lf\n", raznitsa);
	printf("Количество слагаемых - %d\n", N);

}
void cosinus(double x, int N, double tochnost)
{
	x *= M_PI / 180;
	int i;
	double znachenie = 0, znach1 = 1;
	double etalon = cos(x);
	for (i = 1; i < N; i++)
	{
		znachenie += znach1;
		znach1 *= ((-1) * x * x) / ((2 * i) * (2 * i - 1));
		if (fabs(znachenie - etalon) < tochnost)
			break;
	}
	N = i - 1;
	double raznitsa = fabsl(znachenie - etalon);
	printf("Эталонное значение - %lf\n", etalon);
	printf("Полученное значение - %lf\n", znachenie);
	printf("Разница - %lf\n", raznitsa);
	printf("Количество слагаемых - %d\n", N);

}
void koshinus(double x, int N, double tochnost)
{
	x *= M_PI / 180;
	int i;
	double znach1 = 1;
	double znachenie = 1;
	double etalon = cosh(x);

	for (i = 2; i <= N; i++)
	{
		znach1 *= (x / (i - 1));

		if (i % 2 == 1)
		{
			znachenie += znach1;
		}

		if (fabs(znachenie - etalon) < tochnost)
			break;
	}
	N = i - 1;
	double raznitsa = fabsl(znachenie - etalon);
	printf("Эталонное значение - %lf\n", etalon);
	printf("Полученное значение - %lf\n", znachenie);
	printf("Разница - %lf\n", raznitsa);
	printf("Количество слагаемых - %d\n", N);
}
void shinus(double x, int N, double tochnost)
{
	x *= M_PI / 180;
	int i;
	double znach1 = x;
	double znachenie = x;
	double etalon = sinh(x);
	for (i = 2; i <= N; i++)
	{
		znach1 *= ((x * x) / ((2 * i - 2) * (2 * i - 1)));
		znachenie += znach1;
	}
	N = i - 1;
	double raznitsa = fabsl(znachenie - etalon);
	printf("Эталонное значение - %lf\n", etalon);
	printf("Полученное значение - %lf\n", znachenie);
	printf("Разница - %lf\n", raznitsa);
	printf("Количество слагаемых - %d\n", N);
}


void Exponenta(double x, int N)
{
	int i;
	double znachenie = 1, znach1 = x;
	double etalon = exp(x);
	for (i = 1; i <= N; i++)
	{
		znachenie += znach1;
		znach1 *= x / (i + 1);
		printf("%2d %20lf %25lf %20lf\n", i, etalon, znachenie, fabs(etalon - znachenie));
	}

}
void Sinus(double x, int N)
{
	int i;
	x *= M_PI / 180;
	double znachenie = 0, znach1 = 1;
	double etalon = sin(x);
	znach1 = x;
	for (i = 1; i <= N; i++)
	{
		znachenie += znach1;
		znach1 *= ((-1) * x * x) / ((2 * i) * (2 * i + 1));
		printf("%2d %20lf %25lf %20lf\n", i, etalon, znachenie, fabs(etalon - znachenie));
	}
}
void Cosinus(double x, int N)
{
	x *= M_PI / 180;
	int i;
	double znachenie = 0, znach1 = 1;
	double etalon = cos(x);
	for (i = 1; i <= N; i++)
	{
		znachenie += znach1;
		znach1 *= ((-1) * x * x) / ((2 * i) * (2 * i - 1));
		printf("%2d %20lf %25lf %20lf\n", i, etalon, znachenie, fabs(etalon - znachenie));
	}

}
void Koshinus(double x, int N)
{
	x *= M_PI / 180;
	int i;
	double znach1 = 1;
	double znachenie = 1;
	double etalon = cosh(x);

	for (i = 2; i <= N; i++)
	{
		znach1 *= (x / (i - 1));

		if (i % 2 == 1)
		{
			znachenie += znach1;
		}
		printf("%2d %20lf %25lf %20lf\n", i, etalon, znachenie, fabs(etalon - znachenie));
	}
}
void Shinus(double x, int N)
{
	x *= M_PI / 180;
	int i;
	double znachenie = x, znach1 = x;
	double etalon = sinh(x);
	for (i = 2; i <= N; i++)
	{
		znach1 *= ((x * x) / ((2 * i - 2) * (2 * i - 1)));
		znachenie += znach1;
		printf("%2d %20lf %25lf %20lf\n", i, etalon, znachenie, fabs(etalon - znachenie));
	}
}


int main()
{
	setlocale(LC_ALL, "Rus");
	int vibor_fuctii = 0, Chislo_slagaemih = 0, NMax = 0, mode = 0;
	double tochnost, tochka_x, raznitsa = 0, znachenie = 0;

	void (*function1[5]) (double, int, double);
	function1[0] = sinus;
	function1[1] = cosinus;
	function1[2] = exponenta;
	function1[3] = koshinus;
	function1[4] = shinus;

	void(*function_series[5])(double, int);
	function_series[0] = Sinus;
	function_series[1] = Cosinus;
	function_series[2] = Exponenta;
	function_series[3] = Koshinus;
	function_series[4] = Shinus;
	printf("~~~~~~~~~~~~~~~~~~\n");
	printf("Хеллоу!\nВыберите режим:\n1 - Посчитать АДЫН РАЗ,\n2 - Провести несколько рассчётов\n");
	scanf_s("%d", &mode);

	printf("~~~~~~~~~~~~~~~~~~\n");
	printf("Выберите функцию:\n1 - sin(x)\n2 - cos(x)\n3 - exp(x)\n4 - ch(x)\n5 - sh(x)\n");
	scanf_s("%d", &vibor_fuctii);

	printf("~~~~~~~~~~~~~~~~~~\n");
	printf("В окрестности какой точки считать?\n");
	scanf_s("%lf", &tochka_x);
	switch (mode)
	{
	case 1:
		do {

			printf("Выберите точность вычислений (желательно >=0,000001)\n");
			scanf_s("%lf", &tochnost);
		} while (tochnost < 0.000001);

		printf("Сколько элементов должно быть в ряду? (от 1 до 1000):\n");
		scanf_s("%d", &Chislo_slagaemih);

		function1[vibor_fuctii - 1](tochka_x, Chislo_slagaemih, tochnost);
		break;
	case 2:
		while ((NMax < 1) || (NMax > 25))
		{
			printf("Сколько провести экспериментов? (от 1 до 25)\n");
			scanf_s("%d", &NMax);
		}
		printf(" №         ЧТО ДОЛЖНО БЫТЬ          ЧТО ПОЛУЧИЛОСЬ           РАЗНИЦА\n");
		printf(" ~              ~~~~~~                   ~~~~~~~              ~~~~~~\n");
		function_series[vibor_fuctii - 1](tochka_x, NMax);
	}
	system("pause");
	return 0;
}