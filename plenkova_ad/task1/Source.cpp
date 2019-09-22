#include <stdio.h>
#include <math.h>
#include <locale.h>
void main()
{
	setlocale(LC_ALL, "Rus");
	float m, m1, m2, m3, m4, m5, dsp, dvp, der, h, w, d;
	int n;

	printf("Введите высоту шкафа (от 180 до 220 см)\n");
	scanf_s("%f", &h);

	n = (((int)h - 3) / 41.5); //Количество полок
	printf("Количество полок = %d \n", n);

	printf("Введите ширину шкафа (от 80 до 120 см)\n");
	scanf_s("%f", &w);

	printf("Введите глубину шкафа (от 50 до 90 см)\n");
	scanf_s("%f", &d);

	der = 800;
	dsp = 850;
	dvp = 800;

	printf("Плотность дерева = %.1f", der);
	printf(" кг на м3 \n");

	printf("Плотность ДСП = %.1f", dsp);
	printf(" кг на м3 \n");

	printf("Плотность ДВП = %.1f", dvp);
	printf(" кг на м3 \n");

	m1 = dvp * h * w * 0.5; //Задняя стенка
	m2 = 2 * dsp * h * d * 1.5; //Боковые стенки
	m3 = 2 * dsp * w * d * 1.5; //Верх и низ
	m4 = 2 * der * h * (w / 2) * 1; //Двери
	m5 = n * dsp * d * (w - 3) * 1.5; //Полки

	m = (m1 + m2 + m3 + m4 + m5) / 1000000;
	printf("Масса шкафа = %.1f", m);
	printf(" кг");
}