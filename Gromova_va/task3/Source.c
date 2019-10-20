#include <stdio.h> 
#include <locale.h> 
#include <time.h> 
#include <stdlib.h> 
int main()
{
 setlocale(2, "Russian");
 int n, t = 1,j = 0, i = 0, m;
 int mass[5], mas[5];
 int cow = 0 , bulls = 0 ;
 srand(time(NULL));
 printf("Приветствую вас ,дорогой игрок! Выберете диапазон размера числа и введите его (от 2 до 5 символов):\n");
 scanf_s(" %d", &n);
 while ((n > 5) || (n < 2))
 {
	 printf("Введите число, соответствующее заданому диапазоную \n");
	 scanf_s("%d", &n);
 }
  mass[0] = rand() % 9 + 1;
  for (i = 1; i < n; i++)
  {
	mass[i] = rand() % 10;
	for (j = 0; j < i; j++)
	{
	  while (mass[i] == mass[j])
	  {
		mass[i] = rand () % 10;
		j = 0;
	  }
	}
  }
  do
  {
	 cow = 0;
	 bulls = 0;
	 printf("Введите такое число ,в котором количество элементов равно выбранному вашему диапазону:");
	 scanf_s(" %d", &m);
	 for (i = n - 1; i >= 0; i = i - 1)
	 {
			 mas[i] = m % 10;
			 m /= 10;
	 }
	 for ( i = 0; i < n; i++)
	 {
		 if (mass[i] == mas[i])
		 {
			 bulls++;
		 }
		 else
		 {
			 for (j = 0; j < n; j++)
			 {
				 if ((mass[i] == mas[j]) && (i != j))
				 {
					 cow++;
				 }

			 }
		 }
		 printf("Количество коров :%d \n", cow);
		 printf("Количество быков: % d \n", bulls);
	 }
  } while (bulls != n);
  if (bulls = n)
  {
		printf("Ты угадал число.)");
  }
  system("pause");
}