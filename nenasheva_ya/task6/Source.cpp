#include <stdio.h>  
#include <stdlib.h> 
#include <string.h>
#include <math.h>

double fsin(double x, int *n, double e)
{
	double a = x;
	double y = a;
	if (*n > 0)
	{
		for (int i = 1; i < *n; i++)  //do kolichestva
		{
			a = -a * x * x / ((2 * i)*(2 * i + 1));
			y += a;
		}
	}
	else
	{
		for (int i = 1; ; i++)  //do tochnosti
		{
			a = -a * x * x / ((2 * i)*(2 * i + 1));
			if (fabs(a) < e)
				break;
			y += a;
			*n = i;
		}
	}	
	return y;
}

double fcos(double x, int *n, double e)
{
	double a = 1;
	double y = a;
	if (*n > 0)
	{
		for (int i = 1; i < *n; i++)  //do kolichestva
		{
			a = -a * x * x / ((2 * i)*(2 * i - 1));
			y += a;
		}
	}
	else
	{
		for (int i = 1; ; i++)  //do tochnosti
		{
			a = -a * x * x / ((2 * i)*(2 * i - 1));
			if (fabs(a) < e)
				break;
			y += a;
			*n = i;
		}
	}
	return y;
}

double fexp(double x, int *n, double e)
{
	double a = 1;
	double y = a;
	if (*n > 0)
	{
		for (int i = 1; i < *n; i++)  //do kolichestva
		{
			a = a * x / i;
			y += a;
		}
	}
	else
	{
		for (int i = 1; ; i++)  //do tochnosti
		{
			a = a * x / i;
			if (fabs(a) < e)
				break;
			y += a;
			*n = i;
		}
	}
	return y;
}

double fsinh(double x, int *n, double e)
{
	double a = x;
	double y = a;
	if (*n > 0)
	{
		for (int i = 1; i < *n; i++)  //do kolichestva
		{
			a = a * x * x / ((2 * i)*(2 * i + 1));
			y += a;
		}
	}
	else
	{
		for (int i = 1; ; i++)  //do tochnosti
		{
			a = a * x * x / ((2 * i)*(2 * i + 1));
			if (fabs(a) < e)
				break;
			y += a;
			*n = i;
		}
	}
	return y;
}

void Rezhim1()
{
	printf("Esli n = 0, to p > 0 (po tochnosti)\n");
	printf("Esli n > 0, to p = 0 (po kolichestvu)\n");
	int n;
	printf("Vvedite n: ");
	scanf_s("%d", &n);
	double e;
	printf("Vvedite e (tochnost'): ");
	scanf_s("%lf", &e);
	double x;
	printf("x=");
	scanf_s("%lf", &x);

	double y1, y2, d(exp(1));

	int k;
	printf("Functions:\n1.sin\n2.cos\n3.exp\n4.sinh\nViberite funkciyu: ");
	scanf_s("%d", &k);
	switch (k)
	{
	case 1:
		y1 = sin(x);
		y2 = fsin(x, &n, e);
		break;
	case 2:
		y1 = cos(x);
		y2 = fcos(x, &n, e);
		break;
	case 3:
		y1 = exp(x);
		y2 = fexp(x, &n, e);
		break;
	case 4:
		y1 = sinh(x);
		y2 = fsinh(x, &n, e);
		break;
	}
	printf("etalon = %14.12lf\n", y1);
	printf("ocenka = %14.12lf\n", y2);


	double r = y1 - y2;
	printf("r = %14.12lf\n", r);
	printf("n = %d\n", n);    //kolichestvo slagaemih
}

void Rezhim2()
{
	int q;
	printf("Functions:\n1.sin\n2.cos\n3.exp\n4.sinh\nViberite funkciyu: ");
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
			y2 = fsin(x, &i, 0);
			break;
		case 2:
			y1 = cos(x);
			y2 = fcos(x, &i, 0);
			break;
		case 3:
			y1 = exp(x);
			y2 = fexp(x, &i, 0);
			break;
		case 4:
			y1 = sinh(x);
			y2 = fsinh(x, &i, 0);
			break;
		}
		printf("%2d\t %14.12lf\t  %14.12lf\n", i, y2, y1 - y2);
	}
}

int main(void)
{
	int t;
	printf("Viberite rezhim: ");
	scanf_s("%d", &t);
	switch (t)
	{
	case 1:
		Rezhim1();
		break;
	case 2:
		Rezhim2();
		break;
	}
	system("pause");
}