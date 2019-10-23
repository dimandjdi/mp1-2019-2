#define _CRT_SECURE_NO_WARNINGS

#include "windows.h"
#include <iostream>
#include "stdio.h"
#include "locale.h"
#include "conio.h"
#include "memory.h"
#include "time.h"
#include "Console.cpp"

int width = 70;
int height = 30;
bool fullscreen = false;

void count(int n, int* x, int* y, int* bulls, int* cows)
{
	int flag[10] = { 0 };
	*bulls = *cows = 0;
	for (int i = 0; i < n; i++)
	{
		if (x[i] == y[i])
			(*bulls)++;
		else
			flag[x[i]] = 1;
	}
	for (int i = 0; i < n; i++)
	{
		if (flag[y[i]])
			(*cows)++;
	}
}

void make_up_number(int n, int* x)
{
	int cache[6], r;
	int i = 0;
	int guessed_n = 0;
	while (i < n)
	{
		r = true;
		srand(time(NULL) + i);
		int m = rand() % 9 + 1;
		for (int j = 0; j < n; j++)
		{
			if (cache[j] == m)
			{
				r = false;
				break;
			}
		}
		if (!r)
			continue;
		else
		{
			x[i] = m;
			i++;
		}
	}
}

void startgame(void)
{
	int n = 0;
	int counter = 0;
	int tries[15][3] = { {0,0,0} };
	int nn[1] = { 0 };
	do
	{
		clrscr();
		gotoxy(0, 0);
		printf("Введите длинну загадавыемого числа\n");
		number_input(1, 1, 1, nn);
		n = nn[0];
		if (n == -1)
			return;
	} while ((n < 2) || (n > 5));

	int g[6];
	make_up_number(n, g);
	clrscr();
	int check_u[10] = { 0 };

	int bulls, cows;
	int u[6] = { 0 };
	int flag[10] = { 0 };
	while (true) 
	{	
		gotoxy(0, 0);
		printf("Ваша попытка угадать:");
		do
		{
			for (int i = 0; i < 10; i++)
			{
				flag[i] = 0;
			}
			number_input(1, 1, n, u);
			if (u[0] == -1)
				return;
			for (int i = 0; i < n; i++)
			{
				if (flag[u[i]] > 0)
				{
					flag[0] = -1;
					gotoxy(0, 0);
					textbackground(RED);
					printf("Есть повторяющиеся цифры!");
					textbackground(BLACK);
					break;
				}
				flag[u[i]] = 1;
			}
		} while (flag[0] == -1);
		count(n, g, u, &bulls, &cows);
		counter++;
		if (bulls == n)
			break;
		clrscr();
		draw(bull_pic, 3, 12);
		draw(numbers[bulls], 15, 12);
		draw(cow_pic, 20, 12);
		draw(numbers[cows], 30, 12);
		gotoxy(50, 0);
		printf("Предыдущие попытки");
		for (int i = 14; i > 0; i--)
		{
			for (int j = 0;j<3;j++)
				tries[i][j] = tries[i-1][j];
		}
		tries[0][0] = 0;
		for (int i = 0; i < n; i++)
		{
			tries[0][0] *= 10;
			tries[0][0] += u[i];
		}
		tries[0][1] = bulls;
		tries[0][2] = cows;
		for (int i = 0; i < 15; i++)
		{
			gotoxy(50,i+2);
			if (tries[i][0] != 0)
				printf("%d %d %d", tries[i][0], tries[i][1], tries[i][2]);
		}
	}
	clrscr();
	printf("Вы выйграли за %d попыток!\n", counter);
	puts("Для выхода в главное меню нажмите любую клавишу");
	_getch();
}
void closegame(void)
{
	exit(0);
}

void MainMenu()
{
	MenuElement MainMenu[] = {
		{"Старт", startgame},
		{"Выход", closegame},
	};
	Switcher(MainMenu, 2);
}

int main(void)
{
	SMALL_RECT window;
	COORD buf;
	Init(window, buf, 70, 30);
	HideCursor();
	setlocale(LC_ALL, "Rus");
	MainMenu();
}