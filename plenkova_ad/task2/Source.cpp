#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(0));
	int r;
	printf("������� 1, ����� ���������� �����\n������� 2, ����� ��������� ���������� �����\n");
	scanf_s("%d", &r);
	if (r == 1)
	{
		int n = rand() % 1000;
		int t, k = 1;
		printf("��������� �������� �����, �������� ���. ����� ����� = ...\n");
		scanf_s("%d", &t);
		while (t != n)
		{
			k = k + 1;
			if (t < n)
			{
				printf("� ��� � ������, ���������� ����� ������\n");
				printf("����� ����� = ...\n");
				scanf_s("%d", &t);
			}
			if (t > n)
			{
				printf("���, ���������� ����� ������\n");
				printf("����� ����� = ...\n");
				scanf_s("%d", &t);
			}
			if (t == n)
			{
				printf("�������\n");
			}

		}
		printf("����� ������� = %d", k);
	}
	if (r == 2)
	{
		int n0 = 0, n1 = 1000;
		int t = (n0 + n1) / 2, q = 0;
		char j = ' ';
		{
			printf("��������� ����� �� 0 �� 1000, � � �������� ��� �������\n���� ����� = %d?\n", t);
			printf("���� ���������� ����� ������, ������� '>'\n���� ���������� ����� ������, ������� '<'\n���� ��������� ������� �����, ������� '='\n");
		}
		do
		{
			j = getchar();
			q = q + 1;
			if (j == '>')
			{
				n0 = t;
				t = (n0 + n1) / 2;
				printf("%d\n", t);
			}
			else if (j == '<')
			{
				n1 = t;
				t = (n0 + n1) / 2;
				printf("%d\n", t);
			}
			else if (j == '=')
			{
				q = q / 2;
				printf("������, � ���� ��������\n");
				printf("�� ���������� ������� ����� %d", q);
			}
		} while (j != '=');

	}
}