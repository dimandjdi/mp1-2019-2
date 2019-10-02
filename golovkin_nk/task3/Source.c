#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h>

float mode(int count)
{
	int k, n, chislo, min, max, a, chelovek, comp, rez;//добавить значения
	char g;
	n = 0; min = 0; max = 1000; rez = 0;
	switch (count)
	{
	case 1:
	{
		chislo = rand() % 1000 + 1;
		printf("Компьютер загадал число ");
		do
		{
			scanf_s("%i", &k);// К-предлагаемое число пользователем
			n = n + 1;
			if (k < chislo)
				printf("Загаданное число больше \n");
			else if (k > chislo)
				printf("Загаданное число меньше \n");
		} while (k != chislo);
		printf("Вы угадали \n");
		printf("Колличество попыток: %i \n", n);
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
		printf("Колличество попыток: %i \n", n);
		system("pause");
	}
	break;
	case 3:// ИГРА КОМПЬЮТЕРА ПРОТИВ ЧЕЛОВЕКА
	{
		printf("Начинается игра \n");
		chislo = rand() % 1000 + 1;
		printf("Компьютер загадал число,введи своё: \n");
		scanf_s("%i", &chelovek); //ЧИСЛО ЗАГАДАННОЕ ЧЕЛОВЕКОМ
		do
		{
			comp = min + rand() % (max - min);//человек проверяет число компьютера через свичи с 3-мя кейсами (1:>,2:<,3:=)
			printf("Число компьютера: %i", comp);
			getchar(); scanf_s("%c", &g);
			if (g == '>')
				min = comp;
			else if (g == '<')
				max = comp;
			else if (g == '=')
			{
				printf("Компьютер угадал число");
				rez = 1;
			}
			printf("Ваша попытка угадывать \n");
			scanf_s("%i", &k);
			if (k < chislo)
				printf("Загаданное число больше \n");
			else if (k > chislo)
				printf("Загаданное число меньше \n");
			else if (k = chislo)
			{
				printf("Вы угадали число");
				rez = 2;
			}
			if ((k = chislo) && (g == '='))
				rez = 3;
			//компьютер проверяет число человека и так по кругу
		} while (rez == 0);
		switch (rez)
		{
		case 1:
		{
			printf("Победил компьютер");
		}
		break;
		case 2:
		{
			printf("Вы победили");
		}
		break;
		case 3:
		{
			printf("Боевая ничья");
		}
		break;
		}
		break;
	}
	default:
		printf("Неправильный ввод \n");
		break;
	}
}
void main()
{
	setlocale(LC_ALL, "rus");
	int count, x;
	printf("Выберите режим игры: 1 - программа загадывает, 2 - пользователь загадывает, 3 - игра против компьютера ");
	scanf_s("%i", &count);
	x = mode(count);
	system("pause");
}