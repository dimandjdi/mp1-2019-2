#include <stdio.h>
#include <locale.h>
/* ASCII

10 - Enter
32 - Space
9 - Tab

*/

int main(void)
{
	setlocale(LC_ALL, "Rus");
	char c = 0;
	int i = 0;
	int nums = 0;
	int words = 0;
	do
	{
		do
		{
			c = getchar();
		} while ((c == 32) || (c == 9));
		if (isdigit(c))
		{
			nums += 1;
		}
		else 
		{
			words += 1;
		}
		do
		{
			c = getchar();
		} while ((c != 32) && (c != 9) && (c != 10));
	} while (c != 10);
	printf("Чисел: %d Слов: %d", nums, words);
}