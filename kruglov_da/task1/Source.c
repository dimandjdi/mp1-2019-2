#include <stdio.h>        
#include <locale.h>
int main(void)
{
	char *locale = setlocale(LC_ALL, "");
	float h, w, d, t = 1.5, t1 = 0.5, P_ldsp, Pdvp, Pmdf, m;  // h - высота w - ширина d- глубина t- толщина лдсп t1- толщина двп , P_ldsp - плотность лдсп , Pdvp - плотность двп, Pmdf- плотногсть Мдф дверей, масса m
	int k; // кол-во полок
	printf("Введите высоту , глубину и ширину шкафа и кол-во полок \n");
	scanf_s("%f %f %f", &h, &d, &w);
	printf("Введите плотность ЛДСП P_ldsp = , плотность ДВП Pdvp = , плотность МДФ Pmdf = \n");
	scanf_s("%f %f %f", &P_ldsp, &Pdvp, &Pmdf);
	k = (h - 3) / 41.5; // рассчет кол-ва полок
	m = (k + 2)* d * (w - 3) * t * P_ldsp + 2 * d * h * t * P_ldsp + w * h * t1 * Pdvp + w  * h * Pmdf * t; // рассчет массы
	printf("Получилась масса m = %f", m / 1000);

	//scanf_s("%f", &h); // по-другому вылетает
	system("pause");
}