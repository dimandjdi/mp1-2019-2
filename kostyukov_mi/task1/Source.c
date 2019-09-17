#include <stdio.h>

void main()
{
	const float DSV_P = 0.0008; // плотность ƒ—¬
	const float DSP_P = 0.00085; // плотность ƒ—ѕ
	const float WOOD_P = 0.0008; // плотность дерева дл€ дверей

	float w, h, d;

	printf("w h d \n");
	scanf_s("%f%f%f", &w, &h, &d);

	float DVP_V = w * h * (0.5); //задн€€ стенка
	
	float DSP_V = 2 * h * d * (1.5); // две боковины

	float WOOD_V = h * w; // двери

	DSP_V += 2 * w * d * (1.5); // верхн€€ и нижн€€ крышки

	int S = (h - 3) / (41.5); // кол-во полок

	DSP_V += S * d * w * (1.5); // полки

	float m = DSP_V * DSP_P + DVP_V * DSV_P + WOOD_V * WOOD_P; // масса шкафа

	printf("\n%f", m);

}