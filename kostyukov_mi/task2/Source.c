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
	char c1=0, c2=0;
	int n1 = 1;
	int n2 = 1000;
	int n = 0;
	int i = 0;
	printf("Хочу угадать\n");
	do
	{
		n = (n1 + n2) / 2;
		printf("%d\n", n);
		c1 = getchar();
		c2 = getchar();
		i++;
		if ( (c1 == '>') || (c2 == '>') )
		{
			n1 = n;
		}
		if ((c1 == '<') || (c2 == '<'))
		{
			n2 = n;
		}
	} while ( (c1 != '=') && (c2 != '=' ));
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
}