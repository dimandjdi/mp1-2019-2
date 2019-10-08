#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
int main(void)
{
	int  a, x, y, n;
	char simbol;
	setlocale(LC_ALL, "Russian");
	printf("Выберите режим программы: \n 1 (Вы отгадываете число от 0 до 1000, которое загадала программа) или 2 (программа отгадывает число от 0 до 1000, которое загадали Вы)\n ");//Вы, Ваше и тп пишется с большой буквы, потому что если программа не работает, то она хотя бы будет максимально вежливой. Клиентоориентированность - наше все:)
	scanf_s("%i", &a);
	switch (a)
	{
	case 1:
		x = n = 0;
		y = rand() % 1000 + 1;
		srand(time(NULL));
		while (x != y)
		{
			printf("Введите свою отгадку от 0 до 1000 \n");
			scanf_s("%i", &x);
			if (x < y)
				printf("Ваше число меньше загаданного \n");
			else if (x > y)
				printf("Ваше число больше загаданного \n");
			else
				printf("Поздравляю, Вы угадали! \n");
			n++;
		}
		printf("Количество попыток: %i \n", n);
		break;
	case 2:
		a = 0;
		x = 1000;
		simbol = n = 0;
		printf("Загадайте число от 1 до 1000.\n");
		while (simbol != '=')
		{
			y = (a + x) / 2;
			printf("Ваше число %i? Если да, введите '=', если нет, введите '<' или '>'\n", y);
			scanf_s("%c", &simbol);
			scanf_s("%c", &simbol);
			n++;
			switch (simbol)
			{
			case '<':
				x = y;
				break;
			case '>':
				a = y;
				break;

			case '=':

				printf("Программа угадала Ваше число за %i попыток.\n", n);
				break;
			default:

				printf("Введите '=', '<' или '>'\n");
				break;
			}
		}
		break;
	default:
		printf("Вы допустили ошибку при выборе режима программы, пожалуйста, попробуйте еще раз \n");
		break;
	}
	system("pause");
}