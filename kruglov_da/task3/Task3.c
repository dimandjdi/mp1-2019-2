#include <stdio.h>        
#include <locale.h>
#include <time.h>
#include <conio.h>
int main(void) {
	char *locale = setlocale(LC_ALL, "");
	int chislo[5], computer[5]; // chislo - это массив элементов которые вводит пользователь,computer - массив случайно генерируемого числа
	int b, k, p, ch, n, l = 0 , x = 1;// b - Быки , k - коровы ,ch - случайно генерируемое число , l - флаг, x - флаг 
	while (x == 1) {
		printf("Введи n");
		scanf_s("%d", &n);
		srand(time(NULL));
		for (int i = 0; i < n; i++) {
			ch = rand() % 10;
			while (l == 0) {			// генерируем случайное число					
				for (int j = 0; j < n; j++) {
					while (computer[j] == ch) {
						ch = rand() % 10;
						j = 0;		
					}
					if (j == n - 2) {
						l = 1;
					}
				}
			}
			if (l == 1) {
				computer[i] = ch;
				ch = 0;
				//printf("%d", computer[i]);
				l = 0;
			}
		}
		  /*_______//________Привет!______________
			______(o)(o)___________________________
			______(°_°)____Я ползу сейчас____________
			_______(_)____________через этот_______
			_______(_)_______________________код_
			_________(_)_________(_)(_)_____________
			___________(_)____(_)(_)__(_)(_)__________
			_____________(_)(_)__________(_)(_)(_)(_)__
			______________________________________
			и мне очень тяжело, Помогиии спаси */
		k = 0;
		b = 0;
		p = 0;
		while (p == 0) {
			printf("Пробуй угадать\n");
			scanf_s("%d", &ch);
			b = 0;
			k = 0;
			for (int i = n - 1; i >= 0; i--) {		// ну это, там ,короче считаем этих, ну как его, пяточков 
				chislo[i] = ch % 10;
				ch = ch / 10;
				//printf("i = %d chislo[i] = %d \n", i, chislo[i]);
				if (chislo[i] == computer[i]) {
					b++;
				}
				else {
					for (int j = 0; j < n; j++) {
						if ((chislo[i] == computer[j]) && (j != i)) {
							k++;
						}
					}
				}
			}
			if (b == n) {
				printf("Ты угадал\n");
				p = 1;
			}
			else {
				printf("Вот кол-во быков %d и коров %d\n", b, k);

			}
		}
		x = 0;
		printf("Если хочешь сыграть еще раз, то введи 1");
		scanf_s("%d", &x);
	}
}