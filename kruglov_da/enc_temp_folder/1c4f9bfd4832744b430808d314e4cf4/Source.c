#include <stdio.h>        
#include <locale.h>
//#include <iostream>
FILE *products;
//FILE *productsinchek;
int main(void) {
	setlocale(LC_ALL, "Russian");
	int f = 0;
	char product;
	//while (f = 0) {
		int sum, cost, sumproduct, barcode, S1, y;
		errno_t err;
		err = fopen_s(&products, "C:\\Users\\HP\\Desktop\\S1", "r");
		fscanf_s(&products, "%d ", &barcode);
		printf("%d ", barcode);
		fclose(products);
	//}
}