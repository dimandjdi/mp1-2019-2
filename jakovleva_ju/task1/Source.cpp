#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
	double p1 = 800;
	double p2 = 800;
	double p3 = 850;

	double h, w, d, M;
	printf("vvedite h,w,d v metrah\n");
	scanf_s("%lf%lf%lf", &h, &w, &d);
	if ((h >= 1.8) && (h <= 2.2) && (w >= 0.8) && (w <= 1.2) && (d >= 0.5) && (d <= 0.9))
	{
		M = p1 * (h * w * 0.005) + 2 * p2 * (h * d * 0.015) + 2 * p2 * (d * w * 0.015) + p3 * (h * w * 0.01) + (h / 0.415 - 1) * p2 * (d * (w-0.03) * 0.015);
		printf("%.3lf ", M );
		printf("kilogramm\n");
	}
	else
		printf("vvedennye znacheniya ne verny");
	system("pause");
}
