#include <stdio.h>
#include <math.h>
#include <stdlib.h>
float distance(float x1, float y1, float x2, float y2)
{
	float dis = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	return dis;
}
int main(void)
{
	float d, r1, r2, x1, x2, y1, y2;
	printf("Vvedite r1, x1, y1\n");
	scanf_s("%f %f %f", &r1, &x1, &y1);
	printf("Vvedite r2, x2, y2\n");
	scanf_s("%f %f %f", &r2, &x2, &y2);
	d = distance(x1, y1, x2, y2);
	if ((r2 - r1 < d) && (d < r2 + r1))
		printf("peresekautsa\n");
	else if ((d < r2 - r1) || (d > r2 + r1))
		printf("net obscih tochek\n");
	else if ((d == r2 + r1) || ((d == r2 - r1) && (r2 - r1 != 0)))
		printf("kasautsa\n");
	else if (r1 + r2 == 2 * r1)
		printf("sovpadaut\n");
	system("pause");
}
