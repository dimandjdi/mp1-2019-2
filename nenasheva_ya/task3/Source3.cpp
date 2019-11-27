#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	bool correct_number = true;
	int i = 1, j, bull = 0, cow = 0, n, m;
	int x[5], y[5];
	printf("Vvedite dlinu chisla(2-5): ");
	scanf_s("%d", &n);
	while (correct_number == true)
	{
		srand(time(0));
		x[0] = 1 + rand() % 9;
		correct_number = false;
		while (i < n)
		{
			x[i] = rand() % 10;
			i++;
		}
		for (i = 0; i < n; i++)
			for (j = i + 1; j < n; j++)
			{
				if (x[i] == x[j])
				{
					correct_number = true;
					break;
				}
			}
	}
	while (bull != n)
	{
		printf("Vvedite chislo iz %d znakov: ", n);
		scanf_s("%d", &m);
		bull = 0; cow = 0;
		for (i = n - 1; i >= 0; i--)
		{
			y[i] = m % 10;
			m /= 10;
		}
		for (i = 0; i < n; i++)
		{
			if (y[i] == x[i])
				bull++;
			else
			{
				for (j = 0; j < n; j++)
				{
					if (y[i] == x[j])
						cow++;
				}
			}
		}
		printf("bulls:%d   cows:%d\n\n", bull, cow);
	}
	if (bull == n) printf("Vi ugadali\n");
	system("pause");
}