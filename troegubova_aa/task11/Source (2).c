#include <stdio.h>
#include <locale.h>
void main()
{
	setlocale(LC_CTYPE, "Russian");
	int x1, y1, x2, y2;
	char a;
	printf("������� ���������� ������ ������ �1:");
	scanf_s("%d %d", &x1, &y2);
	printf("������� ���������� ������ ������ �2:");
	scanf_s("%d %d", &x2, &y2);
	printf("�������� ������:");
	scanf_s("%c", &a);
	