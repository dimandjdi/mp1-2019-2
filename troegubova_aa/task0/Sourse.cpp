#include <math.h> 
#include <stdio.h> 
#include <locale.h> 
int main() 
{ 
setlocale(LC_CTYPE, "Russian"); 
double x1, y1, r1, x2, y2, r2; 
double a; 
printf("Введите x1, y1, r1 и x2, y2, r2: "); 
scanf_s("%lf %lf %lf %lf %lf %lf", &x1, &y1, &r1, &y2, &x2, &r2); 
a = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)); 
if ((a == 0) && (r1 == r2)) 
printf("Окрюжности совпадают"); 
else if (a < fabs(r1 - r2)) 
printf("Одна окружность расположена внутри другой окрюжности"); 
else if ((a > fabs(r1 - r2)) && (a < r1 + r2)) 
printf("Окружности пересекаются"); 
else if (a == r1 + r2) 
printf("Окружности касаются внешним образом"); 
else if (a == fabs(r1 - r2)) 
printf("Окружности касаются внутренним образом"); 
else if (a > r1 + r2) 
printf("Одна окружность находится вне другой окружности"); 
return 0; 
}


работа с гитом:
git init
git add --all
git commit -a -m 'first commit'
git remote add origin https://github.com/user/project.git !! поменять https на свой линк на репозиторий
git pull --rebase origin master
git push origin master