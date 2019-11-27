#include <stdio.h>
#include <ctype.h>
#include <locale.h>
void main()
{
	setlocale(LC_ALL, "Rus");
	int ndigit = 0, nword = 0, choice;
	char c, p = ' ';
	printf("Введите текст:\n");
	do
	{
		c = getchar();
		switch (c)
		{
		case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
			if ((p == ' ') || (p == '\t'))
				ndigit++;
			break;
		default:
			if (((p == ' ') || (p == '\t')) && ((isalpha(c)) || (c < (int)(NULL))))
				nword++;
			break;
		}
		p = c;
	} while (c != '\n');
	printf("Количетсво слов: %d\n", nword);
	printf("Количество чисел: %d\n", ndigit);
	do
	{
		printf("Ввести новый текст?\n");
		printf("1)Да\n");
		printf("2)Нет\n");
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1:
			getchar();
			main();
		case 2:
			return 0;
		default:
			printf("Ошибка выбора\n");
		}
	} while ((choice != 1) || (choice != 2));
	system("pause");
}