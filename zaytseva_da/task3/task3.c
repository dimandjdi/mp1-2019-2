#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>
int main()
{
	setlocale(LC_ALL, "Rus");
	int z, n, i, j, end, a, c;
	int t = 0, k = 0, b = 0;
	int m[5] = { 0 };
	int p[5] = { 0 };
	srand(time(NULL));
	printf("����� ������ ����, �� ������ ������ ����� ����� ����� �� ������ ��������� \n ������� ���������� �������� ����� (�� 2 �� 5, ������������): \n");
	scanf_s("%i", &z);
	while ((z < 2) || (z > 5))
	{
		printf("��������� ������������, � ����������� �������� ���, ��� �� �������� ��� ������ ����� ����� \n ����������, ���������� ��� ���: \n");
		scanf_s("%i", &z);
	}
	for (i = 0; i < z; i++)
	{
		m[i] = (rand() % 9 + 1);
		for (j = 0; j < i; j++)
		{
			while (m[i] == m[j])
			{
				m[i] = (rand() % 9 + 1);
			}
		}
	}
	printf("������� ���� ������� �������� ����� � ���������������� ������� \n");
	scanf_s("%i", &n);
	while (b != z)
	{
		while ((n >= pow(10, (z + 1))) || (n < pow(10, (z - 1))))
		{
			printf("��������� ������������, � ����������� �������� ���, ��� ���� ����� �� ������ � ��������� ��������!\n");
			scanf_s("%i", &n);
		}
		t++;
		c = n;
		for (i = z - 1; i >= 0; i--)
		{
			a = pow(10, i);
			p[i] = c / a;
			c %= a;
		}
		b = 0;
		k = 0;
		for (i = 0; i < z; i++)
		{
			if (p[i] == m[i])
				b++;
			else
				for (j = 0; j < z; j++)
				{
					if ((i != j) && (p[i] == m[j]))
						k++;
				}
		}
		if (b == z)
			break;
		printf("���������� �����: %i \n ���������� �����: %i \n", b, k);
		scanf_s("%i", &n);
	}
	printf("�����������! �� �������! ��� ����� %i. ���������� ������� ���������: %i\n", n, t);
	scanf_s("%i", &end);
	return 0;
}