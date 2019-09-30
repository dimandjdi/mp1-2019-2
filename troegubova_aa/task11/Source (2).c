#include <stdio.h>
#include <locale.h>
void main()
{
	setlocale(LC_CTYPE, "Russian");
	int x1, y1, x2, y2;
	char a;
	printf("Введите координаты первой клетки к1:");
	scanf_s("%d %d", &x1, &y2);
	printf("Введите координаты второй клетки к2:");
	scanf_s("%d %d", &x2, &y2);
	printf("Выбирете фигуру:");
	scanf_s("%c", &a);
	