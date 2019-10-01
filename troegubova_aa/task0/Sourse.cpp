#include <math.h> 
#include <stdio.h> 
#include <locale.h> 
int main() 
{
	setlocale(LC_CTYPE, "Russian"); 
	double x1, y1, r1, x2, y2, r2; 
    double a, h; 
    printf("Введите x1, y1, r1 и x2, y2, r2: "); 
    scanf_s("%lf %lf %lf %lf %lf %lf", &x1, &y1, &r1, &x2, &y2, &r2); 
    a = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)); 
    if ((a == 0) && (r1 == r2)) 
        printf("Окружности совпадают"); 
    else if (a < fabs(r1 - r2)) 
        printf("Одна окружность расположена внутри другой окружности"); 
    else if ((a > fabs(r1 - r2)) && (a < r1 + r2)) 
        printf("Окружности пересекаются"); 
    else if (a == r1 + r2) 
        printf("Окружности касаются внешним образом"); 
    else if (a == fabs(r1 - r2))			
        printf("Окружности касаются внутренним образом"); 
    else if (a > r1 + r2) 
        printf("Одна окружность находится вне другой окружности");
	printf("\n");
	system("pause");
}

работа с гитом:
git init
git add *
git commit -m 'first commit'
git remote add origin https://github.com/user/project.git !! поменять https на свой линк на репозиторий
git pull --rebase origin master
git push origin master




Лабораорка №2
#include <stdio.h> 
#include <locale.h>
void main()
{
	setlocale(LC_CTYPE, "Russian");
	int h, w, d;
	double bwall, swall, cap, door, n, sf, m;
	printf("Введите высоту шкафа (выбираемый диапозон от 180 до 120 см):");
	scanf_s("%d", &h);
	printf("Введите ширину шкафа (выбираемый диапозон от 80 до 120 см):");
	scanf_s("%d", &w);
	printf("Введите глубину шкафа (выбираемый диапазон от 50 до 90 см):");
	scanf_s("%d", &d);
	bwall = (h * w * 0.5) / 1000000; //объём задней стенки в м^3
	swall = (h * d * 3) / 1000000; //объём 2х боковых стенок
	cap = (w * d * 3) / 1000000; //суммарный объём верхней и нижней крышки
	door = (h * w * 1) / 1000000; //объём 2х дверей
	n = (int)(h / 41.5); //кол-во полочек в шкафу
	sf = (n * (w - 3) * d * 1.5) / 1000000; //объём всех полочек
	m = bwall * 850 + (swall + cap + sf) * 800 + door * 690;//плотность ДВП = 850 кг/м^3; пл-ть ДСП = 800 кг/м^3; пл-ть дерева (дуба) 690 кг/м^3
	printf("Масса шкафа в кг: %lf\n", m);
	system("pause");
}

