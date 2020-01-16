#define _USE_MATH_DEFINES 
#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>

double exp_etalon(double x)
{
	double etalon = exp(x);
	return etalon;
}
double sinus_etalon(double x)
{
	x *= M_PI / 180;
	double etalon = sin(x);
	return etalon;
}
double cosinus_etalon(double x)
{
	x *= M_PI / 180;
	double etalon = cos(x);
	return etalon;
}
double shinus_etalon(double x)
{
	x *= M_PI / 180;
	double etalon = sinh(x);
	return etalon;
}
double coshinus_etalon(double x)
{
	x *= M_PI / 180;
	double etalon = cosh(x);
	return etalon;
}

double exponenta(double x, int N, double tochnost)
{
	int i;
	double znachenie = 1, znach1 = x;
	for (i = 1; i <= N; i++)
	{
		znachenie += znach1;
		znach1 *= x / (i + 1);
		if (fabs(znachenie - exp(x)) < tochnost)
			break;
	}
	N = i - 1;
	return znachenie;
}
double sinus(double x, int N, double tochnost)
{
	int i;
	x *= M_PI / 180;
	double znachenie = 0, znach1 = 1;
	znach1 = x;
	for (i = 1; i <= N; i++)
	{
		znachenie += znach1;
		znach1 *= ((-1) * x * x) / ((2 * i) * (2 * i + 1));
		if (fabs(znachenie - sin(x)) < tochnost)
			break;
	}
	N = i - 1;
	double raznitsa = fabsl(znachenie - sin(x));
	return znachenie;

}
double cosinus(double x, int N, double tochnost)
{
	x *= M_PI / 180;
	int i;
	double znachenie = 0, znach1 = 1;

	for (i = 1; i <= N; i++)
	{
		znachenie += znach1;
		znach1 *= ((-1) * x * x) / ((2 * i) * (2 * i - 1));
		if (fabs(znachenie - cos(x)) < tochnost)
			break;
	}
	N = i - 1;
	double raznitsa = fabsl(znachenie - cos(x));
	return znachenie;
}
double coshinus(double x, int N, double tochnost)
{
	x *= M_PI / 180;
	int i;
	double znach1 = 1;
	double znachenie = 1;
	for (i = 2; i <= N; i++)
	{
		znach1 *= (x / (i - 1));

		if (i % 2 == 1)
		{
			znachenie += znach1;
		}

		if (fabs(znachenie - cosh(x)) < tochnost)
			break;
	}
	N = i - 1;
	double raznitsa = fabsl(znachenie - cosh(x));
	return znachenie;
}
double shinus(double x, int N, double tochnost)
{
	x *= M_PI / 180;
	int i;
	double znach1 = x;
	double znachenie = x;

	for (i = 2; i <= N; i++)
	{
		znach1 *= ((x * x) / ((2 * i - 2) * (2 * i - 1)));
		znachenie += znach1;
	}
	N = i - 1;
	double raznitsa = fabsl(znachenie - sinh(x));
	return znachenie;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	int vibor_fuctii, Chislo_slagaemih, NMax = 0, mode;
	double tochnost, tochka_x, raznitsa, znachenie;

	double (*function1[5]) (double, int, double);
	function1[0] = sinus;
	function1[1] = cosinus;
	function1[2] = exponenta;
	function1[3] = coshinus;
	function1[4] = shinus;

	double(*Etalonnye_znacheniya[5])(double);
	Etalonnye_znacheniya[0] = sinus_etalon;
	Etalonnye_znacheniya[1] = cosinus_etalon;
	Etalonnye_znacheniya[2] = exp_etalon;
	Etalonnye_znacheniya[3] = shinus_etalon;
	Etalonnye_znacheniya[4] = coshinus_etalon;

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

		printf("Эталонное значение - %lf\n", Etalonnye_znacheniya[vibor_fuctii - 1](tochka_x));
		printf("Полученное значение - %lf\n", function1[vibor_fuctii - 1](tochka_x, Chislo_slagaemih, tochnost));
		printf("Разница в значениях - %lf\n", fabsl(Etalonnye_znacheniya[vibor_fuctii - 1](tochka_x) - function1[vibor_fuctii - 1](tochka_x, Chislo_slagaemih, tochnost)));
		printf("Число слагаемых - %d\n", Chislo_slagaemih);
		break;
	case 2:
		while ((NMax < 1) || (NMax > 25))
		{
			printf("Сколько провести экспериментов? (от 1 до 25)\n");
			scanf_s("%d", &NMax);
		}
		int j = 1;
		printf(" №         ЧТО ДОЛЖНО БЫТЬ          ЧТО ПОЛУЧИЛОСЬ           РАЗНИЦА\n");
		printf(" ~              ~~~~~~                   ~~~~~~~              ~~~~~~\n");
		for (int i = 0; i < NMax; i++)
		{
			printf("%2d %20lf %24lf %20lf\n", j++, Etalonnye_znacheniya[vibor_fuctii - 1](tochka_x), function1[vibor_fuctii - 1](tochka_x, i + 1, tochnost), fabsl(Etalonnye_znacheniya[vibor_fuctii - 1](tochka_x) - function1[vibor_fuctii - 1](tochka_x, i + 1, tochnost)));

		}
		break;
	}
	system("pause");
	return 0;
}