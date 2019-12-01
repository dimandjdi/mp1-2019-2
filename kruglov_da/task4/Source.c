#include <stdio.h>        
#include <locale.h>
#define _CRT_SECURE_NO_WARNINGS
int const N = 25; // кол-во товаров существующих в магазине, столько же должно быть в файле для коректной работы программы или больше.
int main() {
	setlocale(LC_ALL, "Russian");
	int f = 0, p = 0; // f - флаг и p - кол-во товаров в чеке
	int i;
	char product[100];
	FILE *fout;
	fout = fopen("out.txt", "w"); // формирование чека
	fprintf(fout, "Кассовый чек ");
	int  barcode, y, barcodev, k = 0; //barcode - штрихкод из файла,  barcodev - штрихкод введенный продавцом , k - та самая переменная
	float discount, sum = 0, cost; // discount - скидка, sum - общая сумма , cost - цена товара из файла
	while (f == 0) {
		p++;
		k = 0;
		printf("Ведите штрих-код (он должен состоять из 4 цифр)\n");
		scanf("%d", &barcodev);
		FILE *products;
		FILE *infoproducts;
		products = fopen("C:\\Users\\HP\\Desktop\\S1.txt", "r"); // Файл в котор через пробел храняться в каждой строке штрихкод цена скидка
		infoproducts = fopen("C:\\Users\\HP\\Desktop\\S2.txt", "r"); // файл который соответствует предыдущему файлу в не храняться название и описание каждого товара в строках. Эти строки соответствуют товарам из предылущего файла
		while (barcodev != barcode && k != 25) {
			k++; // ограничивает максимальную проверку на штрихкоды
			fscanf(products, "%d%f%f ", &barcode, &cost, &discount);
		}
		if (k == 25) {
			printf("Неверно ввели штрих-код, попробуйте снова \n");
		}
		else {
			printf("Стоимость без скидки - %f, ваша скидка составит - %f процентов \n", cost, discount);
			discount = discount / 100;
			cost = cost * (1 - discount);
			sum += cost;
			printf("Стоимость товара со скидкой - %f, общая сумма покупки на данный момент - %f \n", cost, sum);

			for (i = 0; i < k; i++) {
				fgets(product, 100, infoproducts);
			}
			printf("Наименование и описание товара - %s \n ", product);
			fprintf(fout, "Товар №%d стоимость со скидкой - %f , Обозначение товара - %s ", p, cost, product);
			printf("Для печати чека нажмите 1, для следующего товара 0 \n");
			scanf("%d", &f);
		}
		fclose(products);
		fclose(infoproducts);
	}
	fprintf(fout, "Итоговая сумма - %f рублей , получилось %d товаров , Приходите к нам еще )) ", sum, p); // закрываем чек
	fclose(fout);
}
/* S1
4567 35 10 
3567 36 15
5567 37 20 
7567 38 20 
8567 39 10 
2567 34 50 

S2
Травяные чаи
Фруктовые чаи
Зеленый чай
Свежевыжатый сок
Морсы без добавления сахара
Натуральный лимонад

*/
