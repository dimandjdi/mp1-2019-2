#include <stdio.h>
#include <locale.h>
#include <math.h>
int main(void) {

	setlocale(LC_ALL, "Russian");
	float x1, x2, y1, y2, r1, r2, l;
	printf("������� ���������� ������ ������ ���������� � �� ������ : ");
	scanf_s("%f %f %f", &x1, &y1, &r1);
	printf("������� ���������� ������ ������ ���������� � �� ������ : ");
	scanf_s("%f %f %f", &x2, &y2, &r2);
	l = sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
	if ((x1 == x2) && (y1 == y2) && (r1 == r2))
		printf("���������� ���������");
	else
		if (l > (r1 + r2))
			printf("���������� �������� ���� �� �����\n");
		else
			if (l == (r1 + r2))
				printf("���������� �������� ������\n");
			else
				if ((l > fabs(r1 - r2)) && (l < (r1 + r2)))
					printf("���������� ������������\n");
				else
					if (l == fabs(r1 - r2))
						printf("���������� �������� ���������\n");
					else
						printf("���� ���������� ������ ������\n");
	system("pause");
	return 0;
}