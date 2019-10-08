#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int i = 0, x, n = 0;
	srand(time(0));
	i = rand() % 9;
	while ((n <= 5) && (n>=2))
	{
		printf("Vvedite chislo iz n znakov");
		scanf_s("%d", &x);

	}
	system("pause");
}
