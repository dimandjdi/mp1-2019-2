#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


int main()
{   
	setlocale(LC_ALL, "Russian");
	char *tovar[6] = { "Товар №1", "Товар №2", "Товар №3", "Товар №4", "Товар №5", "Товар №6" };
	int firstprice[6] = { 100, 500 , 1400, 1600, 2000, 9000 };
	int shcode[6] = {1001, 1002, 1003, 1004, 1005, 1006};
	int lastprice[6] = { 0, 0, 0, 0, 0, 0 };
	int s = 5;
	int shk;
	int chekqq[6] = { 0, 0, 0, 0, 0, 0 };
	printf("Введите штрихкод: \n");
	
	
	int k;
	int g = 0;
	int z = 0;

	do 
	{	scanf_s("%d", &shk);
		for (k = 0; k < 6; k++)
		{
			if (shk == shcode[k])
			{
				lastprice[k] = firstprice[k] - (firstprice[k] / 100 * s);
				z = z + lastprice[k];
				g = g + firstprice[k] - lastprice[k];
				
				if (s < 50) 
				{
					s = s + 5;
				}
				printf("%s, цена без скидки: %d, цена со скидкой %d \n", tovar[k], firstprice[k], lastprice[k]);
				chekqq[k]++;


			}
		}
		
	} while (shk != 0);
	
	printf("\n         Чек \n ______________________________________\n \n");
	for (k=0; k<6; k++)
	{
		if (chekqq[k] != 0) 
		{	
			printf(" %s, цена без скидки: %d, количество: %d \n  ", tovar[k], firstprice[k], chekqq[k]);
			
		}
	}
	printf("Общая скидка: %d \n, Итого: %d \n", g, z);



	system("pause");
}