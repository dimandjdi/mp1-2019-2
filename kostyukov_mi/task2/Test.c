#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <time.h>

int n;

int riddler(int guess)
{
	if (guess == -1)
	{
		srand(time(NULL));
		n = 1 + rand() % 1000;
		return n;
	}
	else
	{
		if (guess > n)
			return -1;
		if (guess < n)
			return 1;
		if (guess == n)
			return 0;
	}
}

int main(void)
{
	riddler(-1);
	int i = 0;
	printf("%d\n", n);
	int in = 0;
	int ex = 1;
	scanf("%d", &ex);
	int res[1000];
	for (int j = 0; j < ex; j++)
	{
		do
		{
			srand(time(NULL) + i + rand());
			for (int m = 0; m<i;m++)
				srand(rand());
			in = 1 + rand() % 1000;
			i++;
			printf("%d    %d\n", in,i);
		} while (riddler(in) != 0);
		res[j] = i;
		i = 0;
	}
	for (int j = 0; j < ex; j++)
	{
		printf("%d ", res[j]);
	}
}