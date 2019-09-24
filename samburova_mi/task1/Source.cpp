#include <stdio.h>
#include "math.h"
#include "locale.h"

#define DWP 820;
#define DSP 650;
#define BLACKWOOD 1300;  /*Используется чёрное дерево*/

double h, w, d, back, top_and_bot, sidewalls, shelfs, doors, m;
int s;

void main()
{
	setlocale(LC_ALL, "Russian");
	printf("Введите ширину, высоту и глубину шкафа");
	scanf_s("%lf, %lf, %lf" & h, &w, &d);
	s = 0;
	if ((h >= 0, 18) && (h <= 0, 22) && (w >= 0, 08) && (w <= 0, 12) && (d >= 0, 05) && (d <= 0, 09))
	{
		while (h >= 0, 08)
		{
			h = h - 0, 0415;
			s = s + 1;
		}
		back = h * w * 0, 005 * DWP;
		top_and_bot = d * w * 0, 015 * DSP * 2;
		sidewalls = h * d * 0, 015 * DSP * 2;
		shelfs = w * d * 0, 015 * s * DSP;
		doors = h * w * 0, 01 * BLACKWOOD;
		m = back + top_and_bot + sidewalls + shelfs + doors;
		printf("%lf, Масса шкафа-", m);

	}
	else printf("Данные параметры не удовлетворяют стандартам нашей компании!");

