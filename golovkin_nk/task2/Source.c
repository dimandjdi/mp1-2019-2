#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

float mode(int count)
{
	int k, n, chislo, min, max, a, chelovek, comp, rez;//�������� ��������
	char g;
	n = 0; min = 0; max = 1000; rez = 0;
	switch (count)
	{
	case 1:
	{
		chislo = rand() % 1000 + 1;
		printf("��������� ������� ����� ");
		do
		{
			scanf_s("%i", &k);// �-������������ ����� �������������
			n = n + 1;
			if (k < chislo)
				printf("���������� ����� ������ \n");
			else if (k > chislo)
				printf("���������� ����� ������ \n");
		} while (k != chislo);
		printf("�� ������� \n");
		printf("����������� �������: %i \n", n);
		system("pause");
	}
	break;
	case 2:
	{
		do
		{
			chislo = (min + max) / 2;
			n++;
			printf("%i", chislo);
			getchar(); scanf_s("%c", &g);
			if (g == '>')
				min = chislo;
			else if (g == '<')
				max = chislo;
		} while (g != '=');
		printf("����������� �������: %i \n", n);
		system("pause");
	}
	break;
	case 3:// ���� ���������� ������ ��������
	{
		printf("���������� ���� \n");
		chislo = rand() % 1000 + 1;
		printf("��������� ������� �����,����� ���: \n");
		scanf_s("%i", &chelovek); //����� ���������� ���������
		do
		{
			comp = min + rand() % (max - min);
			printf("��������� �������,���: %i ", comp);
			getchar(); scanf_s("%c", &g);
			if (g == '>')
				min = comp;
			else if (g == '<')
				max = comp;
			else if (g == '=')
			{
				printf("��������� ������ ����� \n");
				rez = 1;
			}
			printf("���� ������� ��������� \n");
			scanf_s("%i", &k);
			if (k < chislo)
				printf("���������� ����� ������ \n");
			else if (k > chislo)
				printf("���������� ����� ������ \n");
			else if (k == chislo)
			{
				printf("�� ������� ����� \n");
				rez = 2;
			}
			if ((k == chislo) && (g == '='))
			{
				rez = 3;
			}
			
		} while (rez == 0);
		switch (rez)
		{
		case 1:
		
			printf("������� ��������� \n");
		
		break;
		case 2:
		
			printf("�� �������� \n");
		
		break;
		case 3:
		
			printf("������ ����� \n");
		
		break;
		}
		break;
	}
	default:
		printf("������������ ���� \n");
		break;
	}
}
void main()
{
	setlocale(LC_ALL, "rus");
	int count, x;
	srand(time(0));
	printf("�������� ����� ����: 1 - ��������� ����������, 2 - ������������ ����������, 3 - ���� ������ ���������� ");
	scanf_s("%i", &count);
	x = mode(count);
	system("pause");
}