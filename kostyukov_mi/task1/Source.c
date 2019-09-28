#include <stdio.h>
#include <locale.h>

double checked_input(char V[7],int minL, int maxL)
{
	double value;
	printf("%s в см\n", V);
	scanf_s("%lf", &value);
	if ( (value <= maxL) && (value >= minL))
	{
		return value;
	}
	else
	{
		printf("Некорректные данные");
		exit(0);
	}
	return 0.1;
}

void main()
{
	setlocale(LC_ALL, "Rus");
	const double DSP_P = 0.00085; // плотность ДСП
	const double DVP_P = 0.0008; // плотность ДВП
	const double WOOD_P = 0.0008; // плотность дерева для дверей

	double h, w, d;
	
	h = checked_input("Высота", 180, 220);
	w = checked_input("Ширина", 80, 120);
	d = checked_input("Глубина", 50, 90);


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

	printf("\n Масса шкафа: %.3lf кг", m);
}