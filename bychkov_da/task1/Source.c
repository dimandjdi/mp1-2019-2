#include <stdio.h>
#include <math.h>
#include <locale.h>
int main(void) 
{
	char* locale = setlocale(LC_ALL, "");
	float h, w, d, pDVP, pDSP, pD, q, mZ, mB, mP, mD, M, k = 0.5, x = 1.5, y = 1;
	printf("Введите высоту боковой стенки(от 180 до 220 см), ширину задней стенки(от 80 до 120 см), глубину боковины(от 50 до 90 см) в сантиметрах ");
	scanf_s("%f %f %f", &h, &w, &d);

	if ((h < 180) || (h > 220) || (w < 80) || (w > 120) || (d < 50) || (d > 90))  
	{
		printf_s("Введены неверные данные");
	}
	else {
	pDVP = 0.00085; //кг на кубический сантиметр
	pDSP = 0.00065;
	pD = 0.00045;
	q = (int)(h - (1.5 * 2)) / 41.5;
	mZ = k * h * w * pDVP; //масса задней стенки
	mB = x * h * d * 2 * pDSP; //масса боковых стенок
	mP = x * w * d * (2 + q) * pDSP; //масса полок и крышек
	mD = y * w * h * pD; // масса дверей
	M = mZ + mB + mP + mD;
	printf("Масса шкафа равна %f кг. ", M);
	}
	system("pause");
}
