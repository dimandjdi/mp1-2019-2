#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>  
#include <stdlib.h>   
#include <locale.h>
#include <math.h>

struct quadro
{
	long double res, diff, reference;
	int n;
};

struct quadro MSin(double x, int n, double accuracy)
{
	int i, count = 0;
	long double reference = sin(x), res = x, buffer = x;

	for (i = 3; fabs(res - reference) > accuracy && i < n+3; i += 2)
	{
		buffer *= (-1) * (x * x) / ((i - 1) * i);
		res += buffer;
		count++;
	}
	long double diff = fabs(res - reference);
	struct quadro tmp = { res, diff, reference, count };
	return tmp;
}

struct quadro MCos(double x, int n, double accuracy)
{
	int i, count = 0;
	long double reference = cos(x), res = 1, buffer = 1;
	for (i = 2; fabs(res - reference) > accuracy && i < n+2; i += 2)
	{
		buffer *= (-1) * (x * x) / ((i - 1) * i);
		res += buffer;
		count++;
	}
	long double diff = fabs(res - reference);
	struct quadro tmp = { res, diff, reference, count };
	return tmp;
}

struct quadro MExp(double x, int n, double accuracy)
{
	int i, count = 0;
	long double reference = exp(x), res = 1, buffer = 1;
	for (i = 1; fabs(res - reference) > accuracy && i < n+1; i++)
	{
		buffer *= x / i;
		res += buffer;
		count++;
	}
	long double diff = fabs(res - reference);
	struct quadro tmp = { res, diff, reference, count };
	return tmp;
}

struct quadro MArth(double x, int n, double accuracy)
{
	int i, count = 0;
	long double reference = atanh(x), res = x, buffer = x;

	for (i = 3; fabs(res - reference) > accuracy && i < n+3; i += 2)
	{
		buffer = pow(x, i) / i;
		res += buffer;
		count++;
	}
	long double diff = fabs(res - reference);
	struct quadro tmp = { res, diff, reference, count };
	return tmp;
}

struct quadro(*func[4])(double, int, double) = { MSin, MCos, MExp, MArth };

void Single()
{
	int f, n;
	double accuracy, x;
	printf("\n" "Выберите функцию:" "\n"
		"1)Sin(x)" "\n"
		"2)Cos(x)" "\n"
		"3)Exp(x)" "\n"
		"4)Arth(x)" "\n");
	scanf_s("%i", &f);

	printf("\n" "Задайте точку:" "\n");
	scanf_s("%lf", &x);

	printf("\n" "Задайте точность вычисления >= 0,000001 (через запятую :3)" "\n");
	scanf_s("%lf", &accuracy);

	printf("\n" "Выберите число элементов ряда от 1 до 1000" "\n");
	scanf_s("%i", &n);

	struct quadro tmp = func[f - 1](x, n, accuracy);
	printf_s("%lf - Вычисленное знач-е \n"
			 "%lf - Разница \n"
			 "%i - Кол-во слагаемых \n"	
			 "%lf - Эталон \n",
			 tmp.res, tmp.diff, tmp.n, tmp.reference);
}

void Serial()
{
	int f, n;
	double accuracy, x;
	printf("\n" "Выберите функцию:" "\n"
		"1)Sin(x)" "\n"
		"2)Cos(x)" "\n"
		"3)Exp(x)" "\n"
		"4)Arth(x)" "\n");
	scanf_s("%i", &f);

	printf("\n" "Задайте точку:" "\n");
	scanf_s("%lf", &x);

	printf("\n" "Выберите число экспериментов от 1 до 25" "\n");
	scanf_s("%i", &n);

	printf("№       Значение      Разница\n");
	printf("_____________________________\n");
	for (int i = 1; i < n+1; i++)
	{
		struct quadro tmp = func[f - 1](x, i, 0.0000000000000001);
		printf_s("%2i    %10lf      %lf\n",    i, tmp.res, tmp.diff);
	}
}

void main()
{
	setlocale(LC_ALL, "Rus");
	int sw, flag = 1;
	while (flag != 2)
	{
		printf("Выберите режим:" "\n" "1)Однократный рассчет" "\n" "2)Серийный эксперимент" "\n");
		scanf_s("%i", &sw);
		switch (sw)
		{
		case 1:
		{
			Single();
			break;
		}
		case 2:
		{
			Serial();
			break;
		}
		}
		printf("__________________________________________________________________\n");
		printf("Попробовать снова?\n"
				"1)Да\n"
				"2)Нет\n");
		scanf_s("%i", &flag);
		if (flag == 1)  printf("\n__________________________________________________________________\n\n");
	}
}