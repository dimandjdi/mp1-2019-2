#include <stdio.h>
#include <math.h>
#include <locale.h>

void main()
{
	setlocale(LC_ALL, "Russian");
	char s;
	int num, word, end;

	word = num = 0;
	printf("Введите строку\n");
	while ((s=getchar()) != '\n')
	{
		if ((s >= '0') && (s <= '9'))
		{
			num = num + 1;
			while (((s = getchar()) != ' ') && (s != '\n')) {}
		}
		else
		{
			word = word + 1;
			while (((s = getchar()) != ' ') && (s != '\n')) {}
		}
		if (s == '\n')
			break;
	}
	printf("Количество цифр = %i, Количество букв = %i\n", num, word);
	scanf_s("%i", &end);
}