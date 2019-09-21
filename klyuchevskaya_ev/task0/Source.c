#include <locale.h>
#include <math.h>
#include <stdlib.h>
int main(void) {

	setlocale(LC_ALL, "Russian");
	float x1, x2, y1, y2, r1, r2, l;
	printf("Введите координаты центра первой окружности и ее радиус : ");
	scanf_s("%f %f %f", &x1, &y1, &r1);
	printf("Введите координаты центра второй окружности и ее радиус : ");
	scanf_s("%f %f %f", &x2, &y2, &r2);
	l = sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
	if ((x1 == x2) && (y1 == y2) && (r1 == r2))
		printf("Окружности совпадают");
	else
		if (l > (r1 + r2))
			printf("Окружности отдалены друг от друга\n");
		else
			if (l == (r1 + r2))
				printf("Окружности касаются внешне\n");
			else
				if ((l > fabs(r1 - r2)) && (l < (r1 + r2)))
					printf("Окружности пересекаются\n");
				else
					if (l == fabs(r1 - r2))
						printf("Окружности касаются внутренне\n");
					else
						printf("Одна окружность внутри другой\n");
	system("pause");
	return 0;
}