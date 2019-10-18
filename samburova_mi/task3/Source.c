#include <stdio.h>
#include <math.h>
#include <time.h>
#include <locale.h>

int unique(int n, int mass_machine[])
{
	int sovpad = 0;
	for (int f = 0; f < n; f++)
		for (int d = 0; d < n; d++)
		{
			if (mass_machine[f] == mass_machine[d])
				sovpad++;
		}
	if (sovpad == n)
		return 1;
	else return 0;
}



void main()
{
	setlocale(LC_ALL, "Rus");
	int n = 0, user_number = 0, mass_machine[5], mass_human[5], f = 0, k = 0, r = 0, bull = 0, cow = 0;

	printf("Выберите длину загадываемого числа; от 2 до 5\n");
	scanf_s("%d", &n);
	srand(time(NULL));

	do
	{
		for (f = 0; f < n; f++)
			mass_machine[f] = rand() % 10;


	} while (unique(n, mass_machine) == 0);
	
	do {
		bull = 0;
		cow = 0;
		printf("Введите ваше число\n");
		scanf_s("%d", &user_number);
		for (k = 0; k < n; k++)
		{
			mass_human[k] = user_number % 10;
			user_number = user_number / 10;
		}

		for (f = 0; f < n; f++)
		{
			if (mass_machine[f] == mass_human[f])
				bull++;
		}
		for (f = 0; f < n; f++)
				for (k = 0; k < n; k++)

					if (mass_machine[f] == mass_human[k])
						if (f!=k) 
							cow++;


			if (bull == n)
				printf("Поздравляем с победой!");
			else printf("Быков - %d, коров - %d. Почти получилось!\n", bull, cow);
		} while (bull != n);

		system("pause>nul");
	}

