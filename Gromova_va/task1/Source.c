#include<stdio.h>
#include<math.h>
#include<locale.h>
int main()
{
	setlocale(LC_ALL, "Russian");
	double h, w, d, b, z;
	double b_wall, s_wall, updown, sh, weight, door;
	b = 1000000;
	printf("������� ������ (���������� ��  180 �� 220 ��) � ������ (���������� �� 80 �� 120 �� ) ������ ������  h �  w ");
	scanf_s("%lf %lf", &h, &w);
	printf("������� ������ (���������� �� 50 �� 90 ��) ������� ������ d : ");
	scanf_s("%lf", &d);
	if (((h >= 180) && (h <= 220)) && ((w >= 80) && (w <= 120)) && ((d >= 50) && (d <= 90)))
	{
		b_wall = (0.5 * h * w * 850) / b;
		s_wall = (3 * h * d *800) / b;
		updown = (3 * w * d * 800) / b;
		door = (h * w * 500) / b;
		z = (int)(h / 41.5);
		sh = (z * d * (w - 3) * 1.5 * 800) / b;
		weight = b_wall + s_wall + updown + door + sh;
		printf("�����  ����� ��������� : %lf �� ", weight);
	}
	else
		printf("�� ����� ������ ,�� ���������� �����������");
 system("pause");
}