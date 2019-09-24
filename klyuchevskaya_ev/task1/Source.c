#include <stdio.h>
#include <locale.h>
#include <math.h>
void main() 
{

	setlocale(LC_ALL, "Russian");
	const double pder = 0.67;          // пл-ть дерева в г/см^3
	const double pdvp = 0.85;         //  пл-ть двп в г/см^3
	const double pdsp = 0.80;        //   пл-ть дсп в г/см^3
	float zst, bok, krvn, door, shelfs,N, M,m;
	float h,w,d;
	printf ("Введите высоту шкафа (от 180 до 220 см): " );
	scanf_s (" %f", & h);
	printf ("Введите ширину шкафа (от 80 до 120 см) : " );
	scanf_s (" %f", & w);
	printf ("Введите глубина шкафа (от 50 до 90 см) : " );
	scanf_s (" %f", & d);
	m = 7;
	if (((h >= 180) && (h <= 220)) && ((w >= 80) && (w <= 120)) && ((d >= 50) && (d <= 90)))
	{
		N = floor((h-2*1.5) / 41.5);                                    //количество полок в шкафу
		zst = h * w * 0.5 * pdvp;                                      //масса задней стенки в г
		bok = 2 * h * d * 1.5 * pdsp;                                 //масса двух боковых стенок в г
		krvn = 2 * w * d * 1.5 * pdsp;                               //масса верхней и нижней крышки в г
		door = h * w * 1 * pder;                                    //масса дверей в г
		shelfs = N * (w - 3) * d * 1.5*pdsp;                       //масса полок в г
		M = (zst + bok + krvn + door + shelfs)/1000;              //масса шкафа в кг
		printf("Масса шкафа = %.2f ", M);
		printf("кг \n");
	}
	else {
		printf("Вы ввели неверные данные, повторите попытку снова \n");
	}
	system("pause");
	return 0;

}