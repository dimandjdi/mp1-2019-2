#include<stdio.h>
#include<locale.h>
void main()
{
	setlocale(LC_CTYPE, "Russian");

	int word, numder;
	char c;
	char n ;
	word = numder = c = 0;
	printf("Введите строку: ");

	do
	{
		c = getchar();

		if ((c >= '0') && (c <= '9'))
		{
			while ((c != ' ') && (c != '\t') && (c != '\n'))
			{
				c = getchar();
			}
			numder++;
		}

		else
		{
			if ((c != ' ') && (c != '\n'))
			{
				do
				{
					c = getchar();
				}
				while ((c != ' ') && (c != '\t') && (c != '\n'));
				word++;
			}
		}
     } 
	while (c != '\n');

	printf("Количество чисел: %d \n", numder);
	printf("Количество слов: %d \n", word);
	system("pause");
}