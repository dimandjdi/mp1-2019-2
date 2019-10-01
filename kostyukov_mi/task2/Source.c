#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <time.h>

int r1(void)
{
	srand(time(NULL));
	int r = (rand() % 1000) + 1;
	int n = 0;
	int i = 0;
	printf("Угадывай число\n");
	do 
	{
		i++;
		scanf("%d", &n);
		if (n > r)
			printf("Загаданное число меньше\n");
		if (n < r)
			printf("Загаданное число больше\n");
	} while (n != r);
	printf("Ты угадал загаданное число за %d попыток\n", i);
	return 0;
}
int r2(void)
{
	char c=0, o=0;
	int n1 = 1;
	int n2 = 1000;
	int n = 0;
	int i = 0;
	printf("Хочу угадать\n");
	do
	{
		n = (n1 + n2) / 2;
		printf("%d\n", n);
		c = getchar();
		o = getchar();
		o = getchar();
		i++;
		if ( (c == '>') || (o == '>') )
		{
			n1 = n;
		}
		if ((c == '<') || (o == '<'))
		{
			n2 = n;
		}
	} while ( (c != '=') && (o != '=' ));
	printf("Я угадал за %d попыток\n", i);
}


int main(void)
{
	setlocale(LC_ALL, "Rus");

	int r;

	int(*func[3])() = { exit, r1,r2 };
	do
	{
		printf("Выберите режим\n1)Ты угадываешь\n2)Я угадываю\n0)Выйти\n");
		scanf("%d", &r);
		if ((r >= 0) && (r <= 2))
		{
			func[r]();
		}
	} while (2 * 2 == 4);

	/* 

	Какой вариант более предпочтителен: использованный в программе или приведенный ниже?

	do
	{
		printf("Выберите режим\n1)Ты угадываешь\n2)Я угадываю\n0)Выйти\n");
		scanf("%d", &r);
		switch (r)
		{
		case 0:
			exit();
			break;
		case 1:
			r1();
			break;
		case 2:
			r2();
		default:
			break;
		}
	} while (2 * 2 == 4);
	*/
}