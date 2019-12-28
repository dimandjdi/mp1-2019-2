#include <stdio.h>  
#include <stdlib.h> 
#include <string.h>
#include <math.h>

void Rezim1();
void Rezim2();

int main(void)
{
	int k;
	printf("Vi otkrili programmu rasschota funkcii po formule Teilora\n");
	printf("Viberete rezim programmi: \n 1.Odnokratni rasschit\n 2.Seriyniy experiment\n");
	scanf_s("%d", &k);
	switch (k)
	{
	case 1:
		Rezim1();
		break;
	case 2:
		Rezim2();
		break;
	}
	system("pause");
}

double Rsin(double x, int* n, double e)
{
	double a = x;
	double y = a;
	if (*n > 0)
	{
		for (int i = 1; i < *n; i++)
		{
			a = -a * x * x / ((2 * i) * (2 * i + 1));
			y = y + a;
		}
	}
	else
	{
		for (int i = 1; ; i++)  
		{
			a = -a * x * x / ((2 * i) * (2 * i + 1));
			if (fabs(a) < e)
				break;
			y = y + a;
			*n = i;
		}
	}
	return y;
}

double Rcos(double x, int* n, double e)
{
	double a = 1;
	double y = a;
	if (*n > 0)
	{
		for (int i = 1; i < *n; i++)
		{
			a = -a * x * x / ((2 * i - 1) * (2 * i));
			y = y + a;
		}
	}
	else
	{
		for (int i = 1; ; i++)
		{
			a = -a * x * x / ((2 * i - 1) * (2 * i));
			if (fabs(a) < e)
				break;
			y = y + a;
			*n = i;
		}
	}
	return y;
}

double Rexp(double x, int* n, double e)
{
	double a = 1;
	double y = a;
	if (*n > 0)
	{
		for (int i = 1; i < *n; i++)
		{
			a = a * x / i ;
			y = y + a;
		}
	}
	else
	{
		for (int i = 1; ; i++)
		{
			a = a * x / i ;
			if (fabs(a) < e)
				break;
			y = y + a;
			*n = i ;
		}
	}
	return y;
}

double Rch(double x, int* n, double e)
{
	double a = 1;
	double y = a;
	if (*n > 0)
	{
		for (int i = 1; i < *n; i++)
		{
			a = a * x * x / ((2 * i - 1) * (2 * i));
			y = y + a;
		}
	}
	else
	{
		for (int i = 1; ; i++)
		{
			a = a * x * x / ((2 * i - 1) * (2 * i));
			if (fabs(a) < e)
				break;
			y = y + a;
			*n = i;
		}
	}
	return y;
}

double Rarth(double x, int* n, double e)
{
	double a = 1 / x;
	double y = 0;
	if (*n > 0)
	{
		int i = 1;
		a = -(a * 1 * x * x / (2 * i - 1)) * (2 * i - 3);
		y = a;
		for (int i = 2; i < *n; i++)
		{
				a = (a * 1 * x * x / (2 * i - 1)) * (2 * i - 3);
			y = y + a;
		}
	}
	else
	{

		for (int i = 1; ; i++)
		{
			if (i==1)
			a = -(a * 1 * x * x / (2 * i - 1))*(2*i - 3);
			if (i !=1)
				a = (a * 1 * x * x / (2 * i - 1)) * (2 * i - 3);
			if (fabs(a) < e)
				break;
			y = y + a;
			*n = i + 1;
		}
	}
	return y;
}

void Rezim1()
{
	printf("Esli n = 0, to p > 0 (po tochnosti)\n");
	printf("Esli n > 0, to p = 0 (po kolichestvu)\n");
	int n;
	double e, x;
	printf("Vvedite chislo chlenov n= \nVedite trebuemuyu tochnost e = \nVvedite tochku razlozeniya x = \n");
	scanf_s("%d%lf%lf", &n, &e, &x);

	double y1, y2, d(exp(1));

	int z;
	printf("Viberite funkciyu:\n1.sin\n2.cos\n3.exp\n4.ch\n5.arth (-1 < x < 1)\n");
	scanf_s("%d", &z);
	switch (z)
	{
	case 1:
		y1 = sin(x);
		y2 = Rsin(x, &n, e);
		break;
	case 2:
		y1 = cos(x);
		y2 = Rcos(x, &n, e);
		break;
	case 3:
		y1 = exp(x);
		y2 = Rexp(x, &n, e);
		break;
	case 4:
		y1 = cosh(x);
		y2 = Rch(x, &n, e);
		break;
	case 5:
		y1 = atanh(x);
		y2 = Rarth(x, &n, e);
	}
	printf("etalon = %14.12lf\n", y1);
	printf("ocenka = %14.12lf\n", y2);


	double raz = y1 - y2;
	printf("raznitsa = %13.12lf\n", raz);
	printf("n = %d\n", n);
}

void Rezim2()
{
	int q;
	printf("Viberite funkciyu:\nFunctions:\n1.sin\n2.cos\n3.exp\n4.sinh\n5.arth (-1 < x < 1)\n ");
	scanf_s("%d", &q);
	double y1, y2, d(exp(1));
	double x;
	printf("x=");
	scanf_s("%lf", &x);

	int NMax;
	printf("Vvedite NMax: ");
	scanf_s("%d", &NMax);

	for (int i = 1; i <= NMax; i++)
	{
		switch (q)
		{
		case 1:
			y1 = sin(x);
			y2 = Rsin(x, &i, 0);
			break;
		case 2:
			y1 = cos(x);
			y2 = Rcos(x, &i, 0);
			break;
		case 3:
			y1 = exp(x);
			y2 = Rexp(x, &i, 0);
			break;
		case 4:
			y1 = cosh(x);
			y2 = Rch(x, &i, 0);
			break;
		case 5:
			y1 = atanh(x);
			y2 = Rarth(x, &i, 0);
		}
		printf("Nomer experimenta: %2d\t Etalon: %13.12lf\t Ocenka: %13.12lf\t Raznica: %13.12lf\n", i, y1, y2, y1 - y2);
	}
}
