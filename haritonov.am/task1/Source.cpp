#include <stdio.h>
#include <math.h>
#include <locale.h>

void main()
{
	setlocale(LC_ALL, "Russian");
	double w, h, d, pds, pdv, pdr, m1, m2, m3, m4, m5, ms, end;
	pdr = 640;
	pds = 650;
	pdv = 850;
<<<<<<< HEAD
	printf("Введите высоту h");
	scanf_s("%lf", &h);
	printf("Введите глубину d");
	scanf_s("%lf", &hd);
	printf("Введите ширину w");
	scanf_s("%lf", &w);
	h = h / 100;
	w = w / 100;
	d = d / 100;
	m1 = 0.005 * w * h * pdv;
	m2 = 0.015 * d * h * pds * 2;
	m3 = 0.015 * d * w * pds * 2;
	m4 = 0.01 * h * w * 2;
	m5 = 0.015 * d * w * (h / 0.415);
	ms = m1 + m2 + m3 + m4 + m5;
	printf("Масса шкафа: %lf", ms);
=======
	printf("Введите высоту h,см  180<h<220     h=");
	scanf_s("%lf", &h);
	printf("Введите глубину d,см  50<d<90     d=");
	scanf_s("%lf", &d);
	printf("Введите ширину w,см  80<w<120     w=");
	scanf_s("%lf", &w);
	if ((h <= 220) && (h >= 180) && (w <= 180) && (w >= 80) && (d <= 90) && (d >= 50))
	{
		h = h / 100;
		w = w / 100;
		d = d / 100;
		m1 = 0.005 * w * h * pdv;
		m2 = 0.015 * d * h * pds * 2;
		m3 = 0.015 * d * w * pds * 2;
		m4 = 0.01 * h * w * pdr;
		m5 = 0.015 * d * w * pds * (h / 0.415);
		ms = m1 + m2 + m3 + m4 + m5;
		printf("Масса шкафа: %lf", ms);
	}
	else
		printf("Данные некорректны");
>>>>>>> 0661451e5bcd3225dbb9b239cb84deab34f2f556
	scanf_s("%lf", &end);
}