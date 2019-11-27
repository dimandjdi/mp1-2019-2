#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
void user()
{
	int secret, attempt, k = 0;
	srand(time(0));
	secret = rand() % 1000 + 1;
	printf("Компьютер загадал число от 1 до 1000.\nПопробуйте отгадать его:\n");
	scanf_s("%d", &attempt);
	do
	{
		if (secret > attempt)
			printf("Загаданное число больше.\nПопробуйте снова:\n");
		else if (secret < attempt)
			printf("Загаданное число меньше.\nПопробуйте снова:\n");
		k++;
		scanf_s("%d", &attempt);
	} while (attempt != secret);
	printf("Ура! Вы угадали :)\n");
	printf("Количество попыток: %d\n", k + 1);
}
void compukter()
{
	int attempt, min = 1, max = 1000, k = 0;
	char znak;
	printf("Загадайте любое число от 1 до 1000.\n");
	do
	{
		attempt = (min + max) / 2;
		printf("Введите соответствующий знак ( >, =, < ) вместо знака ?:\n(загаданное число) ? %d\n", attempt);
		getchar(); 
		scanf_s("%c", &znak);
		if (znak == '>')
			min = attempt;
		else if (znak == '<')
			max = attempt;
		k++;
	} while (znak != '=');
	printf("Ваше число: %d\n", attempt);
	printf("Количество попыток: %d\n", k);
}
void main()
{
	setlocale (LC_ALL, "Rus");
	int regime;
	printf("Выберете режим игры:\n");
	printf("1)Вы экстрасенс и угадываете число загаданное компьютером\n");
	printf("2)Компьютер экстрасенс и угадывает число загаданное вами\n");
	scanf_s("%d", &regime);
	switch (regime)
	{
	    case 1:
		    user();
		    break;
	    case 2:
		    compukter();
		    break;
	    default:
		    printf("Ошибка выбора\n");
		    break;
	}
	int choice;
	do
	{
		printf("Выберете соответствующую цифру:\n");
		printf("1)Новая игра\n");
		printf("2)Конец игры\n");
		scanf_s("%d", &choice);
		switch (choice)
		{
		    case 1:
			    main();
			    break;
		    case 2:
			    return 0;
			    break;
		    default:
			    printf("Ошибка выбора\n");
			    break;
		}
	} while ((choice != 1) || (choice != 2));
	system("pause");
}