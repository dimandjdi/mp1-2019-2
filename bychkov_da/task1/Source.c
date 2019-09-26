#include <stdio.h> 
#include <math.h>
#include <locale.h>
int main(void) {
	setlocale(LC_ALL, "Rus");
	double h, w, d, pDVP, pDSP, pD, q, mZ, mB, mP, mD, M, k, x, y;
	printf("Ââåäèòå âûñîòó(îò 180 äî 220 ñì), øèðèíó(îò 80 äî 120 ñì), ãëóáèíó(îò 50 äî 90 ñì) â ñàíòèìåòðàõ ");
	scanf_s("%lf %lf %lf", &h, &w, &d);
	k = 0.5;
	x = 1.5;
	y = 1;
	pDVP = 0.00085; //êã íà êóáè÷åñêèé ñàíòèìåòð
	pDSP = 0.00065; 
	pD = 0.00045;
	q  = (int) (h - (1.5 * 2)) / 41.5;
	mZ = k * h * w * pDVP; //ìàññà çàäíåé ñòåíêè
	mB = x * h * d * 2 * pDSP; //ìàññà áîêîâûõ ñòåíîê
	mP = x * w * d * (2 + q) * pDSP; //ìàññà ïîëîê è êðûøåê
	mD = y * w * h * 2 * pD; // ìàññà äâåðåé
	M = mZ + mB + mP + mD;
	printf("Ìàññà øêàôà ðàâíà %lf êã.    ", M);
	system("pause");
}
