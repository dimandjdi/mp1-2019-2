#include "stdio.h"

#include "math.h"

int main()

{
	double a, R;
	printf("������� a � R: ");
	scanf_s("%f %f", &a, &R);
	if (2 * R == a)

		printf("������� �������� �������� ����������");

	if ((2 * R > a) && (2 * R > a * sqrt(2)))

		printf("���������� � ������� �������� �� ������������, ������� ����� ������ ����������");

	if ((2 * R < a) && (2 * R < a * sqrt(2)))

		printf("���������� � ������� �������� �� ������������ � ���������� ����� ������ ��������");

	if ((2 * R > a) && (2 * R == a * sqrt(2)))

		printf("���������� ������� ������ �������");

	if ((2 * R > a) && (2 * R < a * sqrt(2)))

		printf("���������� � ������� �������� ������������");

}