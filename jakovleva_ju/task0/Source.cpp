#include <stdio.h>
#include <math.h>
#include <stdlib.h>
double rasst(double x1, double x2, double y1, double y2)
{
	float rasst = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	return rasst;
}
int main(void)
{
	float a, b, x1, x2, y1, y2, r;
	printf("vvedite x1,y1, a\n");
	scanf_s("%f %f %f", &x1, &x2, &a);
	printf("vvedite x2,y2,b\n");
	scanf_s("%f %f %f", &y1, &y2, &b);
	r = rasst(x1, x2, y1, y2);
	if (r == (b - a))
		printf("okruznosti kasauca vnutrennim obrazom\n");
	if (r < (b - a))
		printf("odna okruznost vnytri drugoy\n");
	if ((r > (b - a)) && (r < (b + a)))
		printf("okruznosti peresekauca\n");
	if (r == (a + b))
		printf("okruznosti kasauca vnechnim obrazom\n");
	if (r > (a + b))
		printf("okruznosti ne imeut tochek kasaniya i ni odna ne nahodica vnutri drugoy\n");
	if ((r == 0) && (a == b))
		printf("okruznosti sovpadaut\n");
	system("pause");
}