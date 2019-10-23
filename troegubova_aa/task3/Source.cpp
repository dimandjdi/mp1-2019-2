#include<stdio.h>
#include<locale.h>
#include<time.h>
#include<math.h>
#include "stdlib.h"
#include "ConsoleApplication5.h"

void gotoxyprint(int x, int y, int n)
{
	gotoxy(x, y);
	for (int i = 0; i < n; i++)
		printf(" ");
}

int main()
{
	setlocale(LC_CTYPE, "Russian");
	textbackground(15);
	for (int i = 0; i < 2160; i++)
	{
		printf(" ");
	}
	gotoxy(1, 1);
	gotoxy(9, 15);
	textbackground(0);
	gotoxyprint(9, 15, 8);
	gotoxyprint(7, 16, 12);
	gotoxyprint(6, 17, 14);
	gotoxyprint(6, 18, 14);
	gotoxyprint(6, 19, 14);
	gotoxyprint(6, 20, 14);
	gotoxyprint(7, 21, 12);
	gotoxyprint(8, 22, 10);
	gotoxyprint(8, 23, 10);
	gotoxyprint(9, 24, 8);
	gotoxy(2, 16);
	textbackground(8);
	gotoxyprint(2, 15, 2);
	gotoxyprint(2, 16, 2);
	gotoxyprint(2, 17, 4);
	gotoxyprint(22, 15, 2);
	gotoxyprint(22, 16, 2);
	gotoxyprint(20, 17, 4);
	gotoxy(9, 18);
	textbackground(15);
	gotoxyprint(9, 18, 3);
	gotoxyprint(9, 19, 3);
	gotoxyprint(14, 18, 3);
	gotoxyprint(14, 19, 3);
	gotoxy(9, 19);
	textbackground(2);
	gotoxyprint(9, 19, 2);
	gotoxyprint(14, 19, 2);
	gotoxy(11, 22);
	textbackground(6);
	gotoxyprint(11, 22, 4);
	gotoxyprint(11, 23, 4);
	textbackground(0);
	gotoxyprint(15, 23, 3);

	gotoxy(62, 13);
	textbackground(13);
	gotoxyprint(62, 13, 2);
	gotoxyprint(62, 14, 2);
	gotoxyprint(62, 15, 3);
	gotoxyprint(76, 13, 2);
	gotoxyprint(76, 14, 2);
	gotoxyprint(75, 15, 3);
	gotoxyprint(62, 16, 2);
	gotoxyprint(76, 16, 2);
	gotoxy(15, 66);
	textbackground(8);
	gotoxyprint(66, 15, 8);
	gotoxyprint(64, 16, 12);
	gotoxyprint(63, 17, 14);
	gotoxyprint(63, 18, 14);
	gotoxyprint(63, 19, 14);
	gotoxyprint(63, 20, 14);
	gotoxyprint(64, 21, 12);
	gotoxyprint(65, 22, 10);
	gotoxyprint(65, 23, 10);
	gotoxyprint(67, 24, 6);
	gotoxy(66, 18);
	textbackground(15);
	gotoxyprint(66, 18, 3);
	gotoxyprint(66, 19, 3);
	gotoxyprint(71, 18, 3);
	gotoxyprint(71, 19, 3);
	gotoxy(67, 18);
	textbackground(3);
	gotoxyprint(67, 18, 2);
	gotoxyprint(72, 18, 2);
	gotoxy(68, 22);
	textbackground(13);
	gotoxyprint(68, 22, 4);
	gotoxyprint(69, 23, 2);
	textbackground(8);
	gotoxyprint(71, 23, 4);



	textattr(RED | WHITE * 16);
	int n, k, t, x, f, w, bull, cow;
	bull = cow = n = x = t = f = k = w = 0;
	int a[5], b[5];
	gotoxy(20, 2);
	printf("Если ты захочешь сдаться, то введи: -1 \n");
	textcolor(1);
	gotoxy(10,4);
	while ((n < 2) || (n > 5))
	{
		printf("Выбери количество цифр в загаданом числе (от 2 до 5 цифр): ");
		scanf_s("%d", &n);
	}
	srand(time(NULL));
	a[0] = rand() % 9 + 1;
	for (int i = 1; i < n; i++)
	{
		f = 1;
		while (f != 0)
		{
			f = 0;
			a[i] = rand() % 10;
			for (int j = 0; j < i; j++)
				if (a[i] == a[j])
				{
					f = 1;
					break;
				}
		}
	}
	while (bull != n)
	{
		do
		{
			do
			{
				gotoxy(32,6);
				textattr(BLUE | WHITE * 16);
				printf("Введи число:      ");
				gotoxy(45,6);
				scanf_s("%d", &t);
				k = 0;
				x = t;
				if (t == -1)
				{
					clrscr();
					gotoxy(15, 5);
					printf("Игра проиграна, в следующий раз тебе повезёт больше. \n");
					break;
				}
				while (x != 0)
				{
					k++;
					x /= 10;
				}
			} while (k != n);
			if (t == -1)
			{
				break;
			}
			for (int i = n - 1; i >= 0; i--)
			{
				b[i] = t % 10;
				t /= 10;
			}
			w = 0;
			for (int i = 0; i < n - 1; i++)
			{
				for (int j = i + 1; j < n; j++)
				{
					if (b[i] == b[j])
					{
						w = 1;
						break;
					}
				}
			}
		} while (w != 0);
		if (t == -1)
		{
			break;
		}
		bull = cow = 0;
		for (int i = 0; i < n; i++)
		{
			if (a[i] == b[i])
			{
				bull++;
			}
			else
			{
				for (int j = 0; j < n; j++)
				{
					if ((a[i] == b[j]) && (i != j))
					{
						cow++;
					}
				}
			}
		}
		gotoxy(11, 7);
		textattr(BLUE | WHITE * 16);
		printf("Быков: ");
		gotoxy(10, 9);
		for (int i = 0; i < 425; i++)
		{
			printf(" ");
		}

		switch (bull)
		{
		case 0:
			gotoxy(11, 9);
			textbackground(1);
			gotoxyprint(11, 9, 4);
			gotoxyprint(10, 10, 1);
			gotoxyprint(10, 11, 1);
			gotoxyprint(10, 12, 1);
			gotoxyprint(11, 13, 4);
			gotoxyprint(15, 10, 1);
			gotoxyprint(15, 11, 1);
			gotoxyprint(15, 12, 1);
			break;
		case 1:
			gotoxy(13, 9);
			textbackground(1);
			gotoxyprint(13, 9, 1);
			gotoxyprint(12, 10, 2);
			gotoxyprint(11, 11, 1);
			gotoxyprint(13, 11, 1);
			gotoxyprint(13, 12, 1);
			gotoxyprint(11, 13, 5);
			break;
		case 2:
			gotoxy(11, 9);
			textbackground(1);
			gotoxyprint(11, 9, 4);
			gotoxyprint(11, 10, 1);
			gotoxyprint(14, 10, 1);
			gotoxyprint(13, 11, 1);
			gotoxyprint(12, 12, 1);
			gotoxyprint(11, 13, 5);
			break;
		case 3:
			gotoxy(11, 10);
			textbackground(1);
			gotoxyprint(12, 9, 3);
			gotoxyprint(11, 10, 1);
			gotoxyprint(15, 10, 1);
			gotoxyprint(13, 11, 2);
			gotoxyprint(15, 12, 1);
			gotoxyprint(11, 12, 1);
			gotoxyprint(12, 13, 3);
			break;
		case 4:
			gotoxy(11, 9);
			textbackground(1);
			gotoxyprint(11, 9, 1);
			gotoxyprint(15, 9, 1);
			gotoxyprint(11, 10, 1);
			gotoxyprint(15, 10, 1);
			gotoxyprint(11, 11, 5);
			gotoxyprint(15, 12, 1);
			gotoxyprint(15, 13, 1);
			break;
		default:
			gotoxy(12, 9);
			textbackground(1);
			gotoxyprint(12, 9, 4);
			gotoxyprint(12, 10, 1);
			gotoxyprint(12, 11, 3);
			gotoxyprint(15, 12, 1);
			gotoxyprint(12, 13, 3);
			break;
		}
		gotoxy(67, 7);
		textattr(BLUE | WHITE * 16);
		printf("Коров: ");
		switch (cow)
		{
		case 0:
			gotoxy(67, 9);
			textbackground(1);
			gotoxyprint(67, 9, 4);
			gotoxyprint(66, 10, 1);
			gotoxyprint(66, 11, 1);
			gotoxyprint(66, 12, 1);
			gotoxyprint(67, 13, 4);
			gotoxyprint(71, 10, 1);
			gotoxyprint(71, 11, 1);
			gotoxyprint(71, 12, 1);
			break;
		case 1:
			gotoxy(69, 9);
			textbackground(1);
			gotoxyprint(69, 9, 1);
			gotoxyprint(68, 10, 2);
			gotoxyprint(67, 11, 1);
			gotoxyprint(69, 11, 1);
			gotoxyprint(69, 12, 1);
			gotoxyprint(67, 13, 5);
			break;
		case 2:
			gotoxy(67, 9);
			textbackground(1);
			gotoxyprint(67, 9, 4);
			gotoxyprint(67, 10, 1);
			gotoxyprint(70, 10, 1);
			gotoxyprint(69, 11, 1);
			gotoxyprint(68, 12, 1);
			gotoxyprint(67, 13, 5);
			break;
		case 3:
			gotoxy(67, 10);
			textbackground(1);
			gotoxyprint(68, 9, 3);
			gotoxyprint(67, 10, 1);
			gotoxyprint(71, 10, 1);
			gotoxyprint(69, 11, 2);
			gotoxyprint(71, 12, 1);
			gotoxyprint(67, 12, 1);
			gotoxyprint(68, 13, 3);
			break;
		case 4:
			gotoxy(67, 9);
			textbackground(1);
			gotoxyprint(67, 9, 1);
			gotoxyprint(71, 9, 1);
			gotoxyprint(67, 10, 1);
			gotoxyprint(71, 10, 1);
			gotoxyprint(67, 11, 5);
			gotoxyprint(71, 12, 1);
			gotoxyprint(71, 13, 1);
			break;
		default:
			gotoxy(68, 9);
			textbackground(1);
			gotoxyprint(68, 9, 4);
			gotoxyprint(68, 10, 1);
			gotoxyprint(68, 11, 3);
			gotoxyprint(71, 12, 1);
			gotoxyprint(68, 13, 3);
			break;
		}
		if (bull == n)
		{
			break;
		}
	}
	if (bull == n)
	{
		clrscr();
		gotoxy(30, 5);
		textattr(RED | WHITE * 16);
		printf("Ты выйграл игру, ура!!! \n");
	}
	textcolor(15); 
	textbackground(15);
	system("pause");
}
