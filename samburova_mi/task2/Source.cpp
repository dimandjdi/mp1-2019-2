#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main()
{
	int n, k, i, b, p;
	char ss[1];
	printf("How do you want to play?\n");
	printf("1.I want to guess by myself\n");
	printf("2.Let the program works itself\n");
	printf("Your choiñe:\n");
	int input;
	scanf_s("%d", &input);
	switch (input) {
	case 1:
		srand(time(NULL));
		n = rand() % 1001 + 1;
		printf("Enter the number");
		i = 0;
		do 
		{   
			scanf_s("%d", &k);
			if (k = n) then
				printf("You are right");
			else if (k < n)
				printf("Number is upper");
			else
				printf("Number is lower");
			i++;
		} while (n != k);
		printf("Òumber of attempts:%d", &i);
		break;
	case 2:
		 
		do {
			b = rand() % 1001 + 1;
			printf("Is your number %d? If yes, enter '=', if your number is upper, enter '>', if number is lower, enter '<'\n", &b);
			fgets(ss, 2, stdin);
			fflush(stdin);
			puts(ss);
			if (ss = '=')
			{
				printf("Congratulations!");
				break;
			}
			p++;
		} while (ss = '=');
		printf("Number of attempts:%d", &p);
		break;
	default:
		printf("Wrong choice");
}
		



	}


