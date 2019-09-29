##include <locale.h>
#include <math.h>
include <stdio.h>
const double pWood = 640;
const double pDSP = 650;
const double pDVP = 850;
double okrugl(double M, int s)
{
	M = round(M * pow(10, s)) / pow(10, s);
	return M;
}
double diapason (int down, int up, int k)
{
	double parametr = 0;
	while ((parametr < down) || (parametr > up))
	{
		switch (k)
		{
		    case 1: printf("Введите высоту от 180 до 220 см: ");
			    break;
		    case 2: printf("Введите ширину от 80 до 120 см: ");
			    break;
		    case 3: printf("Введите глубину от 50 до 90 см: ");
			    break;
		}
		scanf_s("%lf", &parametr);
		if ((parametr < down) || (parametr > up))
			printf("Выход из диапазона\n");
	}
	return parametr;
}
void main()
{
double h, w, d, mBWalls, mWalls, mCapps, mShelfs, mDoors, M;
int s, output;
setlocale (LC_ALL, "Rus");
h = diapason(180, 220, 1);
w = diapason(80, 120, 2);
d = diapason(50, 90, 3);
// Масса задней стенки
mBWalls = pDVP * h * 0.01 * w * 0.01 * 0.005;
// Масса боковин
mWalls = 2 * h * 0.01 * d * 0.01 * 0.015 * pDSP;
// Масса крышек
mCapps = 2 * d * 0.01 * (w - 3) * 0.01 * 0.015 * pDSP;
// Масса дверей
mDoors = h * 0.01 * w * 0.01 * 0.01 *pWood;
int n = (h - 3) / 41.5;
// Масса n полок
mShelfs = n * (w - 3)* 0.01 * d * 0.01 * 0.015 * pDSP;
M = mBWalls + mWalls + mCapps + mDoors + mShelfs;
printf("Выберете соответствующую циру:\n");
printf("1)Вывод массы целым числом\n");
printf("2)Вывод массы вещественным числом\n");
printf("3)Вывод массы вещественным числом с округлением\n");
scanf_s("%d", &output);
switch (output)
{
    case 1:
	    printf("%d (кг)\n", (int)M);
	    break;
    case 2:
	    printf("%lf (кг)\n", M);
	    break;
    case 3:
    {
	    printf("Введите номер знака, до которого требуется округлить массу : ");
	    scanf_s("%d", &s);
	    printf("%lf (кг)\n", okrugl(M, s));
	    break;
    }
    default:
	printf("Ошибка выбора\n");
}
system ("pause");
}

