#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define p 4 //количество товаров
#define M 2// целочисленные показатели чека + то, что не выводим
#define N 4 //все целочисленные показатели продукта

int main()
{
	int barcode = 0, count = 0, u, g, all = 0, all_sale = 0, all_cost = 0;
	int products[p][N] = { 0 }, check[p][M] = { 0 };// все целочисленные параметры
	char products_char[p][20] = { {"Pen"},{"Notebook"},{"Diary"},{"Pencil"} };
	srand(time(0));
	for (int i = 0; i < p; i++)
	{
		for (int j = 0; j < N; j++)
		{
			switch (j)
			{
			case 0:
				products[i][j] = rand() % 1000 + 1000;
				printf("%d ", products[i][j]);//штрихкод
				puts(products_char[i]);
				break;
			case 1:
				products[i][j] = rand() % 500 + 1;//цена
				break;
			case 2:
				g = rand() % 10 + 1;
				products[i][j] = g * 5;//скидка с шагом в 5
				break;
			case 3:
				products[i][j] = (float)(products[i][1] * (100 - products[i][2])) / 100;//цена со скидкой
				break;
			} // итого, заполнили двумерный массив
		}
	}
	printf("Dobro pozhalovat' v magazin office supplies\n");
	printf("Vvedite number of products: ");
	scanf_s("%d", &u); //пусть конечное количество товаров неизвестно
	printf("Vvedite shtrichkod: \n");
	while (u != 0)
	{
		scanf_s("%d", &barcode);
		for (int i = 0; i < p; i++)
		{
			if ((check[i][0] != barcode) && (check[i][0] > 0)) continue;
			else if (check[i][0] == barcode) {
				check[i][1]++;
				break;
			}
			else if (check[i][0] == 0) {
				check[i][0] = barcode;
				check[i][1]++;
				break;
			}
		}
		u--;
	}
	for (int i = 0; i < p - 1; i++)
	{
		for (int j = 0; j < p; j++)
		{
			if (products[j][0] == check[i][0])
			{
				all_sale += (products[j][1] - products[j][3])*check[i][1];
				all_cost += products[j][1] * check[i][1];
				all += products[j][3] * check[i][1];
				printf("%s\t", products_char[j]);//вывели название
				printf("%d\t", products[j][1]);//вывели цену
				printf("%d\t", check[i][1]);//вывели количество
				printf("%d\n", products[j][3] * check[i][1]);//вывели общую стоимость товара
			}
		}
		if (check[i + 1][0] == 0)
			break;
	}
	printf("All summ shop is %d\n", all_cost);
	printf("All sale is %d\n", all_sale);
	printf("All is cost %d\n", all);
	system("pause");
}