#include <stdio.h>
#include <math.h>
#include <locale.h>
int main()
{
	setlocale(LC_ALL, "Rus");
	float m, m1, m2, m3, m4, m5, dsp, dvp, der, h, w, d;
	int n;

	printf("������� ������ ����� (�� 180 �� 220 ��)\n");
	scanf_s("%f", &h);
	if (h < 180 || h > 220)
	{
		printf("�������� ��������!");
		return 0;
	}

	n = int((h - 3) / 41.5); //���������� �����
	printf("���������� ����� = %d \n", n);

	printf("������� ������ ����� (�� 80 �� 120 ��)\n");
	scanf_s("%f", &w);
	if (w < 80 || w > 120)
	{
		printf("�������� ��������!");
		return 0;
	}

	printf("������� ������� ����� (�� 50 �� 90 ��)\n");
	scanf_s("%f", &d);
	if (d < 50 || d > 90)
	{
		printf("�������� ��������!");
		return 0;
	}

	der = 800;
	dsp = 850;
	dvp = 800;

	printf("��������� ������ = %.1f �� �� �3 \n", der);

	printf("��������� ��� = %.1f �� �� �3 \n", dsp);

	printf("��������� ��� = %.1f �� �� �3 \n", dvp);

	m1 = dvp * h * w * 0.5; //������ ������
	m2 = 2 * dsp * h * d * 1.5; //������� ������
	m3 = 2 * dsp * w * d * 1.5; //���� � ���
	m4 = 2 * der * h * (w / 2) * 1; //�����
	m5 = n * dsp * d * (w - 3) * 1.5; //�����

	m = (m1 + m2 + m3 + m4 + m5) / 1000000;
	printf("����� ����� = %.1f ��", m);
}