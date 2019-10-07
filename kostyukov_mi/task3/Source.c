#include <stdio.h>

int main(void)
{
	int a = 5;
	int b = 6;
	// a ^= b ^= a ^= b;
	a -= b = (a += b) - b;
	printf("%d %d", a, b);
	scanf_s("%d", &a);
}