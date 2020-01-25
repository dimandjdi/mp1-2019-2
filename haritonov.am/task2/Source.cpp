#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>

	int question()
	{
		int k, t, num;
		num = rand() % 1001;
		k = 0;
		t = 0;
		while (k != num)
		{
			t = t + 1;
			printf("Введите число ");
			scanf_s("%i", &k);
			if (k > num)
				printf("Искомое число <\n");
			else if (k < num)
				printf("Искомое число >\n");
			else if (k == num)
			{
				printf("Угадали");
				break;
			}
		}
		return t;
	}

	int answer()
	{
		int k, max, min, tt;
		char n, m;
		min = 1;
		max = 1000;
		tt = 0;
		k = 0;
		n = '(';
		while (n != '=')
		{
			tt = tt + 1;
			k = (min + max) / 2;
			printf("Ваше число = %i ?\n", k);
			n = getchar();
			m = getchar();
			if (m == '>')
				min = k;
			else if (m == '<')
				max = k;
			else if (m == '=')
			{
				printf("Угадал", tt);
				break;
			}
		}
		return(tt);
	}

void main()
{
	setlocale(LC_ALL, "Russian");
	int sw, sw2, t, tt, end;
	srand(time(NULL));

	printf("Выберите режим");
	printf("\n1)ПК загадывает число");
	printf("\n2)ПК отгадывает число\n");
	scanf_s("%i", &sw);
	switch (sw)
	{
	case 1:
		t = question();
		printf("\nКоличество ваших ходов - %i", t);
		printf("\nХотите сразиться с компьютером?\n1)Да\n2)Нет\n");
 		scanf_s("%i", &sw2);
		switch (sw2)
			{
			case 1:
				tt = answer();
				printf("\nКоличество ходов компьютера - %i\n", tt);
				if (t < tt)
				{
					printf("Славная победа!\n");
					scanf_s("%i", &end);
				}
				else
				{
					printf("Потрачено\n");
					scanf_s("%i", &end);
				}
				break;
			case 2:
				break;
			}
		break;
	case 2:
		tt = answer();
		printf("\nКоличество ходов компьютера - %i", tt);
		printf("\nХотите сразиться с компьютером?\n1)Да\n2)Нет\n");
		scanf_s("%i", &sw2);
		switch (sw2)
		{
		case 1:
			t = question();
			printf("\nКоличество ваших ходов - %i\n", t);
			if (t < tt)
			{
				printf("Славная победа!\n");
				scanf_s("%i", &end);
			}
			else
			{
				printf("Потрачено\n");
				scanf_s("%i", &end);
			}
			break;
		case 2:
			break;
		}
		break;
	}
}