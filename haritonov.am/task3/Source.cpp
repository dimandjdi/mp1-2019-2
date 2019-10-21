#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>
															//Создание числа из n неповторяющихся цифр через массив
int number(int n)
{
	int i = 1, k, j = 0, flag, num[5], x = 0;
	num[4] = rand() % (9);
	for (i; i != n; i++)
	{
		flag = 0;
		while (!0)
		{
			k = rand() % (9);
															//Проверка на повторяющиеся цифры через флаг
			for (j; j != i; j++)
				if (k == num[4-j])
					flag = 1;
			j = 0;
			if ((flag == 0) && (i != n-1))
			{
				num[4 - i] = k;
				break;
			}
															//Проверка на "0" 1-й цифрой
			else if ((flag ==0) && (i == n-1) && (k != 0))
			{
				num[4 - i] = k;
				break;
			}
			flag = 0;
		}
	}
	i = 0;
															//Превращение массива в число для вывода из функции
	for (i; i != n; i++)
		x = x + num[4-i] * pow(10, i);
	return(x);
}


void main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	int i, j, num, ask, ans[5], que[5], n, log, byk = 0, kor = 0, ch;


	printf("Введите число от 2 до 5\n");
	scanf_s("%i", &n);
	if ((n > 1) && (n < 6))
	{
		num = number(n);
		printf("%i\n", num);
																//Превращение числа обратно в массив
		for (i = 0; i != n; i++)
		{
			ans[4 - i] = num % 10;
			num = num / 10;
		}
	}
	else exit(0);
	printf("Угадывайте, \"00000\" - сдаться\n");
	log = 1;
	ch = 0;														//Сравнение чила пользователя и загаданного числа
	while ((log != 0) && (log != 2))
	{
		scanf_s("%i", &ask);
		if (ask == 00000)
		{
			log = 2;
			break;
		}
		for (i = 0; i != n; i++)
		{
			que[4 - i] = ask % 10;
			ask = ask / 10;
		}
		for (i = 0; i != (n); i++)
			for (j = 0; j != (n); j++)
			{
				if ((que[4 - i] == ans[4 - j]) && (i == j))
					byk++;
				else if ((que[4 - i] == ans[4 - j]) && (i != j))
					kor++;
			}
		if (byk == n)
			log = 0;

		else printf("Быки - %i Коровы - %i\n", byk, kor);
		byk = 0;
		kor = 0;
		ch++;
	}
	if (log == 0)
		printf("Победа за %i попыток, молодец!\n", ch);
	else if (log == 2)
		printf("Либераху порвало");
	scanf_s("%i", i);

}
