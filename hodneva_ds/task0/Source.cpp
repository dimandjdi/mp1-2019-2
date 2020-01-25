#include "stdio.h"

#include "math.h"

#include<locale.h>

int main()

{
	setlocale(LC_ALL, "Russian");
	double a, R;
	printf("Введите a и R: ");
	scanf_s("%lf %lf", &a, &R);
	if (2 * R == a)

		printf("Сторона квадрата касается окружности");

	if (2 * R > a * sqrt(2))

		printf("Окружность и стороны квадрата не пересекаются, квадрат лежит внутри окружности");

	if ((2 * R < a) && (2 * R < a * sqrt(2)))

		printf("Окружность и стороны квадрата не пересекаются и окружность лежит внутри квадрата");

	if (2 * R == a * sqrt(2))

		printf("Окружность описана вокруг квадрата");

	if ((2 * R > a) && (2 * R < a * sqrt(2)))

		printf("Окружность и стороны квадрата пересекаются");

}
