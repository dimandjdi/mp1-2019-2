#include"stdio.h"
#include"math.h"
#include"time.h"
#include"locale.h"
void main()
{
	setlocale(LC_CTYPE, "Russian");
	int a, b, c, d;//��� ������� ������ ����������
	int n, m, v;//��� ������� ������ ����������
	char sign;
	sign = '1';
	n = 0;
	d = 0; //���������� ������� ����
	b = 0;
	v = 0;
	a = 0;
	printf("�������� ����� ������ ����,� ������� ������ �������:");
	printf("����� 1-��������� ���������� ��������� �����,����� 2-�� ����������� ��������� �����");
	scanf_s("%d", &a);
	switch (a)
	{
	default:
		printf("�� ����� ����� ,�� ��������������� ������");
		break;
	case 1:
		srand(time(NULL));
		c = (rand() % 1000) + 1;
		printf("� - ������� ����������� ���� ������� �����, � ���, ������� ����, �������� ������� ���.\n");
		while (c != b)
		{
			printf("������� �����:");
			scanf_s("%d", &b);
			if (c > b)
				printf("�� ����� ������ \n");
			else if (c < b)
				printf("�� ����� ������ \n");
			else
				printf("�� �������� ����.��� �� ����� ������� � �������.\n");
			d++;
		}
		printf("���������� ������� ��������� : %i", d);
		break;
	case 2:
		printf("��������� ����� (�� 1 �� 1000), � � ����� ������ ������� ���.");
		scanf_s("%d", &m);
		if ((m < 1) || (m > 1000))
		{
			printf("�� ����� �����, ������� �� ������ � ���������� (�� 1 �� 1000) \n");
		}
		else
			n = 500;
		v = n / 2;
		while (m != n)
		{
			printf("���� ����� %d? \n", n);
			scanf_s(" %c", &sign);
			if (sign == '>')
			{
				n = n + v;
			}
			else
			{
				n = n - v;
			}
			v = (v + 1) / 2;
			d++;
		}
		d++;
		printf("���� ����� %d? \n", n);
		scanf_s(" %c", &sign);
		printf("���� ����� ������� \n");
		printf("���������� ������� ���������: %d \n", d);
		break;
	}system("pause");
}