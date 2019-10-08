#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void user_quesses()
{
	srand(time(0));
	int d, z, n, u;
	n = 1 + rand() % 1000;
	z = 0;
	d = 0;
	while (z <= 1000)
	{
		z++;
		printf("%d-ya pop'itka: ", z);
		scanf_s("%d", &u);
		if (u < n) printf("Zagadannoe chislo bol'she\n");
		else
			if (u > n) printf("Zagadannoe chislo men'she\n");
			else 
			{
				printf("Ugadali)))))\n");
				break;
			}
	}
	printf("Kolichestvo pop'itok: %d\n", z);
}

void programm_quesses()
{
	int r = 1;
	char c = ' ';
	printf("\nZagada'ite chislo\nIgra'ite chestno;)\n");
	int a = 500; // Vmesto randoma vvodim opredelyennoe chislo, ymen'shaya diapazon v 2 raza  
	int step = a / 2;
	while (true)
	{
		printf("%d-ya pop'itka: %d \n", r++, a);
		c = getchar();
		c = getchar();

		if (c == '<')
			a -= step;
		else if (c == '>')
			a += step;
		else if (c == '=')
		{
			printf("Ura, ya ugadal!\n");
			r--;
			printf("Kolichestvo pop'itok: %d\n", r);
			break;
		}
		if (step != 1) step /= 2;
	}
}

int main()
{
	int q;
	srand(time(0));
	printf("1 Ya zagadivayu\n");
	printf("2 T'i zagad'ivaesh\n");
	printf("V'iberite rezhim: ");
	scanf_s("%d", &q);
	switch (q)
	{
	case 1:
		user_quesses();
		break;
	case 2:
		programm_quesses();
		break;
	}
	system("pause");
}
