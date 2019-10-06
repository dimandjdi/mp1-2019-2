#include <stdio.h>
#include <math.h>
#include <locale.h>
int main()
{
	setlocale(LC_ALL, "Rus");
	int a = 0, b = 0; //a -количество слов, b - количество чисел
	char j;
	printf("Введите строку символов\n");
	do
	{
		j = getchar();
		if ((j >= '0') && (j <= '9'))
		{
			b = b + 1;
		}
		else
		{
			a = a + 1;
		}
		while ((j != ' ') && (j != '\t') && (j != '\n'))
		{
			j = getchar();
		}
	} while (j != '\n');

	printf("Количетсво слов = %d\nКоличество чисел = %d", a, b);
}
