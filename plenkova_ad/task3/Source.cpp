#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<locale.h>
int main()
{
	setlocale(LC_ALL, "Rus");
	int n, g = 1, a;
	while (g == 1)
	{
		printf("�������� ����� ������������� �����(�� 2 �� 5)\n");
		scanf_s("%i", &n);
		if ((n < 2) || (n > 5))
		{
			printf("�������� ����� �����");
			return(0);
		}
		else
		{
			srand(time(0));
			int x[5];
			for (int i = 0; i < n; i = i + 1)//��������� ��������������� ����:
			{
				x[i] = rand() % 9 + 1;//���������� ��������� �����
				for (int j = 0; j < i; j = j + 1)//������� ���� ��� ���������
				{
					while (x[i] == x[j])//��������� � ������ ������������� ����
					{
						x[i] = rand() % 10;
						j = 0;
					}
				}
			}
			int c[5], p, m, k = 0, b = 0;
			while (b != n)
			{
				printf("���������� ������� �����\n");
				scanf_s("%d", &m);
				for (int p = n - 1; p >= 0; p = p - 1)
				{
					c[p] = m % 10;
					m = m / 10;
				}
				for (int r = 0; r < n; r = r + 1)
				{
					if (x[r] == c[r])
						b = b + 1;
					else
					{
						for (p = 0; p < n; p++)
						{
							if ((x[r] == c[p]) && (r != p))
								k = k + 1;
						}
					}
				}
				printf("�����(���� ������� �� ����� ��������) %d    �����(���� ������� �� �� ����� ��������) %d\n", b, k);
				a = b;
				b = 0;
				k = 0;
				if (a == n)
				{
					printf("�� ��������!!!");
					g = 0;
					n = 0;
					printf("���� ������ ������� ��� ���, ������� 1\n");
					scanf_s("%d", &g);

				}
			}
		}
	}
}