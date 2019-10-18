#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main()
{
	int n, k, i, b, p, ff, max, min;
	char ss;
	printf("How do you want to play?\n");
	printf("1.I want to guess by myself\n");
	printf("2.Let the program work itself\n");
	printf("Your choice:\n");
	int input;
	scanf_s("%d", &input);
	switch (input) {
	case 1:
		i = 0;
		srand(time(NULL));
		n = rand() % 1001 + 1;
		printf("Enter the number\n");
		
		do
		{
			scanf_s("%d", &k);
			if (k == n)
			printf("You are right\n");
			else if (k < n)
					printf("Number is upper\n");

				else
					printf("Number is lower\n");
				i++;
			} while (n != k);
			printf("Number of attempts:%d\n", i);
			break;
	case 2:
		p = 0;
		max = 1000;
		min = 1;
		do
		{
			
			ff = (max + min) / 2;
			printf("Is your number %d, upper or lower?\n", ff);
			getchar();
			scanf_s("%c", &ss);
			if (ss == '>')
				min = ff;
			else if (ss == '<')
				max = ff;
			p++;
		} while (ss != '=');
		printf ("Your number is %d\n", ff );
		printf ("Amount of attempts:%d\n", p);

		break;
	default:
		printf("Wrong choice");
		}
	system("pause>nul");
	}	


