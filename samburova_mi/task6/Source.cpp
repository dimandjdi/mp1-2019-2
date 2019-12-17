#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <locale.h>
#include "Source2.h"

void(*funcs[5])(long double* results, long long x, long double accruracy, long long n) =
{
	mysin,
	mycos,
	myexp,
	myth,
};
void(*funcs_s[5])(long double* results, long double* deltas, long long x, long long NMax) =
{
	mysin_s,
	mycos_s,
	myexp_s,
	myth_s,
};


int main()
{
	setlocale(LC_ALL, "Rus");
	while (true)
	{
		printf("Выберите функцию\n");
		printf("1) Sin\n");
		printf("2) Cos\n");
		printf("3) Exp\n");
		printf("4) Th \n");
		int k, m, x, n, delta;
		scanf("%d", &k);
		printf("Выберите режим\n");
		scanf("%d", &m);
		switch (m)
		{
		case 1:
			printf("Введите точку, точность вычисления, кол-во элементов ряда\n");
			scanf("%ld %lf %ld", &x, &delta, &n);
			long double results[4];
			funcs[k - 1](results, x, delta, n);
			printf("Эталонное значение: %lf\n", results[1]);
			printf("Вычисленное значение: %lf\n", results[0]);
			printf("Разница между эталонным и вычисленным значением: %lf\n", results[2]);
			printf("Кол-во вычисленных слагаемых: %ld\n", results[3]);
			break;
		case 2:
			printf("Введите точку, число экспериментов\n");
			scanf("%d %d", &x, &n);
			long double results[26];
			long double deltas[26];
			funcs_s[k - 1](results, deltas, x, n);
			printf("Кол-во слагаемых  Вычисленное значение Разница с эталонным значением\n"); 
			for (int i = 1; i < n; i++)
			{
				printf("%ld %lf %lf\n", i, results[i], deltas[i]);
			}
			break;
		default:
			continue;
		}
	}
}