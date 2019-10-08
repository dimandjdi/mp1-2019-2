#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<conio.h>
int main(void)
{
	setlocale(LC_ALL, "Russian");
	srand(time(0));
	int x , r , z , l , n = 0 , A = 1 , B = 1000 , k = 0 , usl = 0;
	char zn = ' ';
	printf("Если вы хотите угадать число-введите 1, если вы хотите загадать число-введите 2 : ");
	scanf_s("%d", &r);
	if ((r != 1) && (r != 2))
	{
		printf("Вы выбрали несуществующий режим\n");
	}
	else
	{
		switch (r) {
		case 1:
			printf("Итак,вы выбрали 1 режим,вам необходимо угадать число от 1 до 1000\n");
			x = A + rand() % (B - A + 1);
			do
			{
				n = n + 1;
				printf("Введите предполагаемое число : ");
				scanf_s("%d", &z);
				if (z < x) {
					printf("Загаданное число больше\n");
				}
				else {
					if (z > x) {
						printf("Загаданное число меньше\n");
					}
					else {
						printf("УРА! Вы угадали число c %d попытки!\n", n);
					}
				}

			} while (x != z);
			break;
		case 2:
			printf("Итак,вы выбрали 2 режим, загадайте число от 1 до 1000 : ");
			scanf_s("%d", &l);
			srand(time(0));
			while (usl != 1) {

				if (zn != '\n') {
					x = A + rand() % (B-A+1) ;
					k=k+1;
					printf("%d > (больше) , < (меньше) или = (равно) загаданному числу?\n", x);
				}
				zn = getchar();

				if (zn == '<') {
					A = x+1;
				}
				if (zn == '>') {
					B =x-1;
				}
				
				if (zn == '=') {
					printf("УРА! Программа угадала число с %d попытки! \n", k);
					usl = 1;
				}
			}
			break;
		}
		
	}
		system("pause");
}