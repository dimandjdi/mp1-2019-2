#include <stdio.h> 
#include <locale.h> 
#include <time.h> 
#include <stdlib.h> 

int main()
{
	setlocale(LC_CTYPE, "rus");

	int a[10], b[10], x, n, rmin, rmax, f;

	printf("Введите n: "); //Ввод данных 
	scanf_s("%d", &n);
	rmin = 0;
	rmax = 9;

	srand((unsigned int)time(0)); //Заполнение массива рандомными числами 
	a[0] = (rmax - 1) * ((double)rand()) / RAND_MAX + 1;

	for (int i = 1; i < n; i++)
	{
		f = 1;
		while (f != 0)
		{
			f = 0;
			a[i] = (rmax - rmin) * ((double)rand()) / RAND_MAX + rmin;
			for (int j = 0; j < i; j++)
				if (a[i] == a[j])
				{
					f = 1;
					break;
				}
		}
	}

	for (int i = 0; i < n; i++)
		printf("%d", a[i]);



	printf("\n");
	system("pause");
}
