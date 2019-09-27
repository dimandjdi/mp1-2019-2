#include <stdio.h> 
#include <math.h>
#include <locale.h>
int main(void) {
	setlocale(LC_ALL, "Rus");
	double h, w, d, pDVP, pDSP, pD, q, mZ, mB, mP, mD, M, k, x, y;
	printf("Введите высоту(от 180 до 220 см), ширину(от 80 до 120 см), глубину(от 50 до 90 см) в сантиметрах ");
	scanf_s("%lf %lf %lf", &h, &w, &d);
	k = 0.5;
	x = 1.5;
	y = 1;
	pDVP = 0.00085; //кг на кубический сантиметр
	pDSP = 0.00065;
	pD = 0.00045;
	q = (int)(h - (1.5 * 2)) / 41.5;
	mZ = k * h * w * pDVP; //масса задней стенки
	mB = x * h * d * 2 * pDSP; //масса боковых стенок
	mP = x * w * d * (2 + q) * pDSP; //масса полок и крышек
	mD = y * w * h * 2 * pD; // масса дверей
	M = mZ + mB + mP + mD;
	printf("Масса шкафа равна %lf кг.    ", M);
	system("pause");
}
