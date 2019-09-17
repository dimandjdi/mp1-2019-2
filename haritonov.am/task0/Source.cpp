#include <stdio.h>
#include <math.h>
#include <locale.h>


void main()
{
	setlocale(LC_ALL, "Russian");
	double x1, y1, a, x2, y2, b, l, k, q;
	printf("Введите a, (x1,y1) и b, (x2,y2)");
	scanf_s("%lf %lf %lf %lf %lf %lf", &a, &x1, &y1, &b, &x2, &y2);
	l = sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
	if (b>a)  
	{
		k = b;
		b = a;
		a = k;
	}
	if (l > (a + b))
		printf("1) Окружности не пересекаются");
	else if (l == a + b)
			printf("2) Окружности соприкасаются с внешней стороны");
		 else if (l < a + b)
				  if (l > a - b)
					  printf("3) Окружности пересекаются");
					  if ((l == a - b) && (l != 0))
						  printf("4) Окружности пересекаются изнутри");
						  else if (l < a - b)
						           printf("5) Одна окружность внутри другой");
						           else if ((l == 0) && (a - b == 0))
						                    printf("6) Окружности равны");
scanf_s("%lf", &q); 
}
