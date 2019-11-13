#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  
#include <stdlib.h>  
#include <io.h>  
#include <time.h>

void swap(int* x, int* y)
{
	*x ^= *y ^= *x ^= *y;
}

int main()
{
	int x = 5;
	int y = 6;
	printf("%d %d\n", x, y);
	printf("%d %d\n", &x, &y);
	swap(&x, &y);
	printf("%d %d\n", x, y);
	getchar();
}