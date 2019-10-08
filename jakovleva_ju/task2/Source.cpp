#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
int main(void)
{
	int rezim;
	printf("Viberete rezim\n rezim 1:vi ugadivaete chislo\n rezim 2:vi zagadivaete chislo\n");
	scanf_s("%d", &rezim);
	switch (rezim)
	{
	case 1:
		srand(time(0));
		int n, x, i;
		n = rand() % 1000 + 1;
		x = 0;
		i = 1;
		printf("Vas privetstvuet igra ugaday chislo\n");
		printf("Vvedite chislo ot 1 do 1000\n");
		do
		{
			printf("%d-ya pop'itka: ", i++);
			scanf_s("%d", &x);
			if (x < n)
				printf("zagadannoe chislo boi'she\n");
			if (x > n)
				printf("zagadannoe chislo men'she\n");
		} while ((x != n) && (i <= 15));
		{
			printf("chislo ugadano za %d popitok\n", i);
			break;
		}
	case 2:
		int r = 0, e = 500, s = e / 2, z;
		char o = ' ';
		printf("Pridumaite chislo ot 1 do 1000\n");
		scanf_s("%d", &z);
		do
		{
			r++;
			printf("%d-ya pop'itka: %d \n", r, e);
			o = getchar();
			o = getchar();

			if (o == '<')
				e = e - s;
			else if (o == '>')
				e = e + s;
			if (s != 1) s = s / 2;

		} while (o != '=');
		{
			printf("Kolichestvo pop'itok: %d\n", r);
		}
		break;
	}
	system("pause");
}