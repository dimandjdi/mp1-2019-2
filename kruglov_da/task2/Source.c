#include <stdio.h>        
#include <locale.h>
#include <time.h>
#include <conio.h>
int main(void) {
	char *locale = setlocale(LC_ALL, "");
	int k = 0, ch, min = 1, max = 1000, p = 0, t, d = 0; // min - нижний порог, max - верхний порог
	char c = ' ', x;
	while (p == 0) {
		printf("Если хочешь я могу попробывать отгадать, тогда введи 1 в обратном случае введи 0 \n");
		scanf_s("%d", &t);
		if (t == 0) {
			ch = srand() % 500 + 500 ;
			printf("Ну если ты так настаиваешь, то дерзай : %d \n", ch);
			while (d != ch) {
				k++;
				printf("Пробуй))");
				scanf_s("%d", &d);
				if (d == ch) {
					printf("Да ты вундеркинд!!! \n Вот твое кол-во попыток : %d \n", k);
				}
				else {
					if (d < ch) {
						printf("Неа, попробуй число побольше \n");
					}
					else {
						printf("Неа, попробуй число поменьше \n");
					}
				}
			}
		}
		else {
			printf("Ладно, ладно, я попробую \n ухх  \n ");
			while (p != 2) {
				ch = (min + max) / 2;
				if (c != '\n') {
					k++;
					printf("%d  оно больше '>' или меньше '<' \n", ch);
				}
				c = getchar();
				if (c == '>') {
					max = ch;
				}
				if (c == '<') {
					min = ch;
				}
				if (c == '=') {
					printf("Красота, да я монстр \n Вот мое кол-во попыток : %d \n ", k);
				}
			}
		}
		p = 1;
		printf("Может еще раз сыграем введи 0 \n");
		scanf_s("%d", &p);
	}
}