#include "stdio.h"

#include "math.h"

int main()



{

	const int  dvp = 800, dsp = 735, der = 690, x = 5, y = 15, z = 15, k = 10, m = 400;

	double h, w, d;

	printf("������� �������� ������ h, ������ w, ������� d: ");

	scanf_s("%lf %lf %lf", &h, &w, &d);

	if (((1800 <= h) && (h <= 2200)) && ((800 <= w) && (w <= 1200)) && ((500 <= d) && (d <= 900))) {

		double massa = (h * x * w * dvp + 2 * h * y * d * dsp + 2 * w * z * d * dsp + h * w * k * der + (h / (m + y)) * w * d * dsp) / 1000000000;

		printf("����� ����� ����� � = %f\n", massa);

	}

	else printf("������� �������� ��������\n");

	return 0;

}