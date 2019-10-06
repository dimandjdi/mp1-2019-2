#include <stdio.h>
#include <locale.h>
void main()
{
	setlocale(LC_ALL, "Ru");
	int ndigit, nword,rez;
	ndigit = 0; nword = 0;
	char c,pred;
	pred = ' ';
	printf("Введите строку: ");
	do
	{
		c = getchar();
		switch (c)
		{
		case'0':case'1':case'2':case'3':case'4':case'5':case'6':case'7':case'8':case'9':
		{

				if ((pred == '\t') || (pred == ' '))

					ndigit++;

				pred = c;
		}
		break;
		default:
		{
			if (((pred == '\t') || (pred == ' ')) && ((c < (int)(0)) || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) && (c != '\n'))
				nword++;
			pred = c;
		}
		break;
		}
		
	} 
	while (c!='\n');
	printf("Слов:%i  Чисел:%i \n", nword, ndigit);
	system("pause");

}