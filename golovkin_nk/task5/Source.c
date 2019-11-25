#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>  
#include <stdlib.h>  
#include <io.h>  
#include <time.h>  
#include <conio.h>
#include <string.h>
#include <malloc.h>
#include <locale.h>
int vibori()
{
	int sort;
	printf("Выберите сортировку\n");
	printf("1 - Пузырьком\n");
	printf("2 - Выбором\n");
	printf("3 - Вставками\n");
	printf("4 - Слиянием\n");
	printf("5 - Хоара\n");
	printf("6 - Шелла\n");
	printf("7 - Подсчётом\n");
	scanf_s("%i", &sort);
	return sort;
}
struct sortirovochka
{
	int razmer;
	char name[200];
};
struct sortirovochka sortirovka[20];
int increment(long inc[], long size) 
{
	int p1, p2, p3, s;
	p1 = p2 = p3 = 1;
	s = -1;
	do {
		if (++s % 2) {
			inc[s] = 8 * p1 - 6 * p2 + 1;
		}
		else {
			inc[s] = 9 * p1 - 9 * p3 + 1;
			p2 *= 2;
			p3 *= 2;
		}
		p1 *= 2;
	}
	while (3 * inc[s] < size);
	return s > 0 ? --s : 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Bubble(struct sortirovochka sortirovka[], int k)
{
	int i, j;
	struct sortirovochka x;
	for (i = 0; i < k; i++)
	{
		for (j = k ; j > i; j--)
		{
			if (sortirovka[j - 1].razmer > sortirovka[j].razmer)
			{
				x = sortirovka[j - 1];
				sortirovka[j - 1] = sortirovka[j];
				sortirovka[j] = x;
			}
		}
	}
} 
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void selectSort(struct sortirovochka sortirovka[], int k) {
	int i, j, a;
	struct sortirovochka x;

	for (i = 0; i < k ; i++) {   	
		a = i; x = sortirovka[i];

		for (j = i + 1 ; j < k + 1; j++)	
			if (sortirovka[j].razmer < x.razmer) {
				a = j; x = sortirovka[j];	       
			}

		sortirovka[a] = sortirovka[i]; sortirovka[i] = x;   	
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void insertSort(struct sortirovochka sortirovka[], int k) 
{
	struct sortirovochka x;
	int i, j;

	for (i = 0; i < k + 1; i++) 
	{ 
		x = sortirovka[i];
		for (j = i - 1; j >= 0 && sortirovka[j].razmer > x.razmer; j--)
			sortirovka[j + 1] = sortirovka[j];
		sortirovka[j + 1] = x;
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void quickSort(struct sortirovochka sortirovka[], int k)
{
	long i = 0, j = k;
	struct sortirovochka x;
	long p;
	p = sortirovka[k >> 1].razmer;
	do 
	{
		while (sortirovka[i].razmer < p) i++;
		while (sortirovka[j].razmer > p) j--;
		if (i <= j)
		{
			x = sortirovka[i];
			sortirovka[i] = sortirovka[j];
			sortirovka[j] = x;
			i++; j--;
		}
	} 
	while (i <= j);
	if (j > 0) quickSort(sortirovka, j);
	if (k > i) quickSort(sortirovka + i, k - i);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void shellSort(struct sortirovochka sortirovka[], int k)
{
	int inc, i, j, seq[40],s;
	struct sortirovochka x;
	s = increment(seq,k);
	while (s >= 0) 
	{
		inc = seq[s--];
		for (i = inc; i < k+1; i++)
		{
			x = sortirovka[i];
			for (j = i - inc; (j >= 0) && (sortirovka[j].razmer > x.razmer); j -= inc)
				sortirovka[j + inc].razmer = sortirovka[j].razmer;
			sortirovka[j + inc] = x;
		}
	}

}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void merge(struct sortirovochka sortirovka[], int lb, int split, int ub)
{
	struct sortirovochka *x;
	int pos1 = lb;
	int pos2 = split + 1;
	int pos3 = 0;
	x = (struct sortirovochka *)malloc((ub - lb + 1) * sizeof(struct sortirovochka));
	while (pos1 <= split && pos2 <= ub) {
		if (sortirovka[pos1].razmer < sortirovka[pos2].razmer)
			x[pos3++] = sortirovka[pos1++];
		else
			x[pos3++] = sortirovka[pos2++];
	} 
	while (pos2 <= ub) 
		x[pos3++] = sortirovka[pos2++];
	while (pos1 <= split)  
		x[pos3++] = sortirovka[pos1++];
	for (pos3 = 0; pos3 < ub - lb + 1; pos3++)
		sortirovka[lb + pos3] = x[pos3];
	free(x);
}void mergeSort(struct sortirovochka sortirovka[], int lb, int ub) 
{
	int split;    
	time_t start, end;
	if (lb < ub) 
	{ 
		split = (lb + ub) / 2;
		mergeSort(sortirovka, lb, split);       
		mergeSort(sortirovka, split + 1, ub);
		merge(sortirovka, lb, split, ub); 
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
void CountingSort(struct sortirovochka *sortirovka, int k)
{
	unsigned long max, min;
	int i, j, m = 0, *p;
	struct sortirovochka x;
	max = min = sortirovka[0].razmer;
	for (i = 0; i < k; i++)
	{
		if (sortirovka[i].razmer > max)
			max = sortirovka[i].razmer;
		if (sortirovka[i].razmer < min)
			min = sortirovka[i].razmer;
	}
	max++;
	p = (int*)malloc(max * sizeof(int));
	memset(p, 0, max * sizeof(int));
	for (i = 0; i < k+1; i++)
		p[sortirovka[i].razmer]++;
	for (i = min; i < max; i++)
	{
		if (p[i] != 0)
		{
			for (j = m; j < k+1; j++)
				if (sortirovka[j].razmer == i)
				{
					x = sortirovka[j];
					sortirovka[j] = sortirovka[m];
					sortirovka[m] = x;
					m++;
				}
		}
	}
	free(p);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
int main(void)
{
	setlocale(LC_ALL, "ru");
	struct _finddata_t c_file;
	intptr_t hFile;
	char path[200];
	int count = 0, sort, i, k;
	printf("Введите путь\n");
	gets(path);
	strcat(path, "*");
	i = 0;
	if ((hFile = _findfirst(path, &c_file)) == -1L)
		printf("No *.c files in current directory!\n");
	else
	{
		printf("Listing of .c files\n\n");
		printf("FILE              SIZE\n", ' ');
		printf("----              ----\n", ' ');
		do {
			if (count <= 20)
			{
				strcpy(sortirovka[i].name, c_file.name);
				sortirovka[i].razmer = c_file.size;
				printf("%-12.12s  %10ld\n", c_file.name, c_file.size);
				count++;
				i++;
			}
		} while (_findnext(hFile, &c_file) == 0);
		_findclose(hFile);
		printf("\ncount of files: %d\n", count);
		k = i - 1 ;
	}
		sort = vibori();
		clock_t nachalo = clock();
		switch (sort)
		{
		case 1:
			Bubble(sortirovka, k);
			break;
		case 2:
			selectSort(sortirovka, k);
			break;
		case 3:
			insertSort(sortirovka, k);
			break;
		case 4:
			mergeSort(sortirovka, 0, k);
			break;
		case 5:
			quickSort(sortirovka, k);
			break;
		case 6:
			shellSort(sortirovka, k);
			break;
		case 7:
			CountingSort(sortirovka, k);
			break;
		}
		clock_t konec = clock();
		printf("Время сортировки: %.30lf с\n", (double)(konec - nachalo) / CLOCKS_PER_SEC);
	for (i = 0; i <= k; i++)
	{
		printf("%-12.12s     %i\n", sortirovka[i].name, sortirovka[i].razmer);
	}
	int choice;
	do
	{
		printf("Выберете соответствующую цифру:\n");
		printf("1)Новая сортировка\n");
		printf("2)Конец \n");
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1:
			getchar();
			main();
			break;
		case 2:
			return 0;
			break;
		default:
			printf("Ошибка выбора\n");
			break;
		}
	} while ((choice != 1) || (choice != 2));
	system("pause");
}