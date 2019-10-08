#include <stdio.h>        
#include <locale.h>
int main(void) {
	const int N = 10000;
	char *locale = setlocale(LC_ALL, "");
	char str[1000];

	int k = 0, p = 0, chisla = 0, words = 0;
	char c = '1', rstr;
	while (p == 0) {
		rstr = gets(str);
		printf("%c \n", str[0]);
		for (int i = 0; i < 1000; i++) {
			if (str[i] != '\n') {
				if ((str >= '0') && (str <= '9')) {
					chisla++;
					printf("число");
					while (str != ' ') {
						if (str == ' ') {
							break;
						}
						i++;
					}
				}
				else {
					words++;
					printf("слово");
					while (str != ' ') {
						i++;
						if (str == ' ') {
							break;
						}
					}
				}
			}
			else {
				break;
			}
		}

	}
	printf("Вот колличество слов сударь - %d \n Ах, да чуть не забыл колличество чисел - %d \n Если хочешь можем больше не играть нажми 1 ", words, chisla);
	scanf_s("%d", &p);
	system("pause");
}