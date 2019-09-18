#include <stdio.h>

void main()
{
	const double DSP_P = 0.00085; // плотность ДСП
	const double DVP_P = 0.0008; // плотность ДВП
	const double WOOD_P = 0.0008; // плотность дерева для дверей

	double h, w, d;

	printf("h w d \n");
	scanf_s("%lf%lf%lf", &h, &w, &d);

	// Однострочное вычисление массы
	// double m = 1.5 * DSP_P * d * (2 * (h + w) + (w - 3) * ((int)((h - 3) / 41.5))) + WOOD_P * h * w + DVP_P * 0.5 * h * w;
	//	printf("%lf", m);

	// Поэтапное вычисление массы
	double DVP_V = h * w * 0.5; // объем задней стенки

	double DSP_V = 2 * h * d * 1.5; // объем боковин

	double WOOD_V = h * w; // объем дверей

	DSP_V += 2 * w * d * 1.5; // объем верхней и нижней крышек

	int S = (h - 3) / 41.5; // кол-во полок

	DSP_V += S * (w - 3) * d * (1.5); // объем полок

	double m = DSP_V * DSP_P + DVP_V * DVP_P + WOOD_V * WOOD_P; // масса шкафа

	printf("\n%lf", m);
}