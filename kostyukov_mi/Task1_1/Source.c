#include <stdio.h>
#include <math.h>
#include <locale.h>

int queen(int X1, int Y1, int X2, int Y2)
{
	if ((abs(X2 - X1) == abs(Y2 - Y1)) || (X1 == X2) || (Y1 == Y2))
		return 1;
	else
		return 0;
}

int rook(int X1, int Y1, int X2, int Y2)
{
	if ((X1 == X2) || (Y1 == Y2))
		return 1;
	else
		return 0;
}

int king(int X1, int Y1, int X2, int Y2)
{
	if (((abs(X2 - X1) == 1) && (abs(Y2 - Y1) <= 1)) || ((abs(X2 - X1) <= 1) && (abs(Y2 - Y1) == 1)))
		return 1;
	else
		return 0;
}
int elephant(int X1, int Y1, int X2, int Y2)
{
	if (abs(X2 - X1) == abs(Y2 - Y1))
		return 1;
	else
		return 0;
}
int horse(int X1, int Y1, int X2, int Y2)
{

	if (((abs(X2-X1) == 1) && (abs(Y2-Y1) == 2)) || ((abs(X2-X1) == 2) && (abs(Y2-Y1) == 1)))

		return 1;

	else

		return 0;

}


void main()
{
	setlocale(LC_ALL, "Rus");
	char K1[3];
	char K2[3];
	char p[10][10] = {"","Ферзь", "Ладья", "Король", "Cлон", "Конь"};
	int piece;
	int can_make_move[6];
	int (*func[6])(int X1, int Y1, int X2, int Y2);
	func[1] = queen;
	func[2] = rook;
	func[3] = king;
	func[4] = elephant;
	func[5] = horse;


	int c,d, m ,n, x1,x2,y1,y2;
	printf("Первая клетка: ");
	scanf("%s", &K1);
	printf("Вторая клетка: ");
	scanf("%s", &K2);
	x1 = (int)K1[0] - 65;
	y1 = (int)K1[1] - 49;
	x2 = (int)K2[0] - 65;
	y2 = (int)K2[1] - 49;
	if ((x1 > 7) || (y1 > 7) || (x2 > 7) || (y2 > 7) || (x1 < 0) || (y1 < 0) || (x2 < 0) || (y2 < 0))
	{
		printf("Некорректные данные");
		exit(0);
	}

	printf("Выберите фигуру:\n");
	printf("1. Ферзь\n");
	printf("2. Ладья\n");
	printf("3. Король\n");
	printf("4. Слон\n");
	printf("5. Конь\n");
	scanf("%i", &piece);

	for (int i = 1; i <= 5; i++)
	{
		can_make_move[i] = func[i](x1, y1, x2, y2);
	}
	if (can_make_move[piece] == 1)
		printf("1)%s может за один ход перейти из %s в %s\n", p[piece], K1, K2);
	else
		printf("1)%s не может за один ход перейти из %s в %s\n", p[piece], K1, K2);
	printf("2)\n");
	for (int i = 1; i <= 5; i++)
	{
		if ((i != piece) && (can_make_move[i] == 1))
			printf("%s может за один ход перейти из %s в %s\n", p[i], K1, K2);
	}
}