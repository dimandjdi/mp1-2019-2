#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>
struct list
{
	int bar;
	char name[15];
	int sum;
	int percent;
} L;

void main()
{
	L.bar;
	int bar, sum, percent;
	char name[15];
	FILE * spisok = fopen("list.txt", "r");
	while (!feof(spisok))
	{
		fscanf(spisok)
	}
}