#include <stdio.h>
#include <math.h>
#include <locale.h>
int main()
{
	setlocale(LC_ALL, "Rus");
	 double m,m1, m2, m3, m4, m5, dsp, dvp, der;
	 int n, h, w, d;
	 der = 0.0006; // кг/см3
	 dsp = 0.00085;
	 dvp = 0.0007;

	printf("Введите высоту шкафа (от 180 до 220 см)\n");
	scanf_s("%d", &h);
	
	n = ((h - 3)/ 41.5); //Количество полок
	printf ("Количество полок = %d \n", n);

	printf("Введите ширину шкафа (от 80 до 120 см)\n");
	scanf_s("%d", &w);

	printf("Введите глубину шкафа (от 50 до 90 см)\n");
	scanf_s("%d", &d);

	m1 = dvp * h * w * 0.5;
	m = ((dvp * h * w * 0.5) + 2*(dsp * h * d * 1.5) + 2*(dsp * w * d * 1.5) + 2*(der * h * (w / 2)) + n*(dsp * d * (w - 3) * 1.5));
	printf ("Масса шкафа = %f \n", m);
}