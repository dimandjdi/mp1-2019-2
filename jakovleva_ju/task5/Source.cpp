#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>  
#include <stdlib.h>  
#include <io.h>  
#include <time.h>
#include <malloc.h>
#include <locale.h>
#include <conio.h>
#include <string.h>

int countfile(char path[])
{
	struct _finddata_t c_file;
	intptr_t hFile;
	int count = 0;
	if ((hFile = _findfirst(path, &c_file)) == -1L)
		printf("В данной директории нет файлов\n");
	else
		do {
			count++;
		} while (_findnext(hFile, &c_file) == 0);
		_findclose(hFile);
		return count;
}

void S_Bubble(struct _finddata_t* file, int n)
{
	int i, j;
	struct _finddata_t x;
	for (i = 0; i < n; i++)
	{
		for (j = n - 1; j > i; j--)
		{
			if (file[j - 1].size > file[j].size)
			{
				x = file[j - 1];
				file[j - 1] = file[j];
				file[j] = x;
			}
		}
	}
}

void S_Select(struct _finddata_t* file, int n)
{
	int i, j, k;
	struct _finddata_t x;
	for (i = 0; i < n; i++)
	{
		k = i;
		x = file[i];
		for (j = i + 1; j < n; j++)
			if (file[j].size < x.size)
			{
				k = j;
				x = file[j];
			}
		file[k] = file[i];
		file[i] = x;
	}
}

void S_Insert(struct _finddata_t* file, int n)
{
	int i, j;
	struct _finddata_t x;
	for (i = 1; i < n; i++)
	{
		x = file[i];
		for (j = i - 1; j >= 0 && file[j].size > x.size; j--)
			file[j + 1] = file[j];
		file[j + 1] = x;
	}
}

void merge(struct _finddata_t* file, long lb, long split, long ub)
{
	long pos1 = lb;
	long pos2 = split + 1;
	long pos3 = 0;
	struct _finddata_t* temp = (struct _finddata_t*)malloc((ub - lb + 1) * sizeof(struct _finddata_t));
	while (pos1 <= split && pos2 <= ub)
	{
		if (file[pos1].size < file[pos2].size)
			temp[pos3++] = file[pos1++];
		else
			temp[pos3++] = file[pos2++];
	}
	while (pos2 <= ub)
		temp[pos3++] = file[pos2++];
	while (pos1 <= split)
		temp[pos3++] = file[pos1++];
	for (pos3 = 0; pos3 < ub - lb + 1; pos3++)
		file[lb + pos3] = temp[pos3];
	free(temp);
}

void S_Merge(struct _finddata_t* files, long lb, long ub)
{
	long split;
	if (lb < ub)
	{
		split = (lb + ub) / 2;
		S_Merge(files, lb, split);
		S_Merge(files, split + 1, ub);
		merge(files, lb, split, ub);
	}
}

void S_Quick(struct _finddata_t* file, int n)
{
	int i = 0, j = n - 1;
	struct _finddata_t temp;
	long p;
	p = file[n >> 1].size;
	do {
		while (file[i].size < p)
			i++;
		while (file[j].size > p)
			j--;
		if (i <= j)
		{
			temp = file[i];
			file[i] = file[j];
			file[j] = temp;
			i++;
			j--;
		}
	} while (i <= j);
	if (j > 0) S_Quick(file, j + 1);
	if (n > i) S_Quick(file + i, n - i);
}

int increment(long inc[], long size)
{
	int p1, p2, p3, s;
	p1 = p2 = p3 = 1;
	s = -1;
	do {
		if (++s % 2)
			inc[s] = 8 * p1 - 6 * p2 + 1;
		else
		{
			inc[s] = 9 * p1 - 9 * p3 + 1;
			p2 *= 2;
			p3 *= 2;
		}
		p1 *= 2;
	} while (3 * inc[s] < size);
	return s > 0 ? --s : 0;
}

void S_Shell(struct _finddata_t* file, int n)
{
	long inc, i, j, seq[40];
	int s;
	struct _finddata_t temp;
	s = increment(seq, n);
	while (s >= 0)
	{
		inc = seq[s--];
		for (i = inc; i < n; i++)
		{
			temp = file[i];
			for (j = i - inc; (j >= 0) && (file[j].size > temp.size); j -= inc)
				file[j + inc] = file[j];
			file[j + inc] = temp;
		}
	}
}

void S_Counting(struct _finddata_t* file, int n)
{
	unsigned long max, min;
	int i, j, m = 0, *p;
	struct _finddata_t t;
	max = min = file[0].size;
	for (i = 0; i < n; i++)
	{
		if (file[i].size > max)
			max = file[i].size;
		if (file[i].size < min)
			min = file[i].size;
	}
	max++;
	p = (int*)malloc(max * sizeof(int));
	memset(p, 0, max * sizeof(int));
	for (i = 0; i < n; i++)
		p[file[i].size]++;
	for (i = min; i < max; i++)
	{
		if (p[i] != 0)
		{
			for (j = m; j < n; j++)
				if (file[j].size == i)
				{
					t = file[j];
					file[j] = file[m];
					file[m] = t;
					m++;
				}
		}
	}
	free(p);
}

void pupa(struct _finddata_t* file, int n)
{
	printf("\ncount of files: %d\n", n);
	printf("FILE                 SIZE\n");
	for (int i = 0; i < n; i++)
	{
		printf("%-12.12s    %10ld\n", file[i].name, file[i].size);
	}

}

void main()
{
	setlocale(LC_ALL, "Rus");
	char path[200];
	int n = 0, i, sort;
	intptr_t hFile;
	struct _finddata_t* file;
	struct _finddata_t c_file;
	clock_t start = clock();
	printf("Введите путь до директории:\n");
	gets_s(path);
	strcat(path, "*");
	printf("Сортировки:\n1 Пузырьком\n");
	printf("2 Выбором\n");
	printf("3 Вставками\n");
	printf("4 Слиянием\n");
	printf("5 Хоара\n");
	printf("6 Шелла\n");
	printf("7 Подсчетом\n");
	printf("Введите номер нужной сортировки: ");
	scanf_s("%d", &sort);
	if ((n = countfile(path)) != 0)
	{
		file = (struct _finddata_t*)malloc(n * sizeof(struct _finddata_t));
		hFile = _findfirst(path, &file[0]);
		for (i = 1; i < n; i++)
			_findnext(hFile, &file[i]);
		start = clock();
		switch (sort)
		{
		case 1:
			S_Bubble(file, n);
			break;
		case 2:
			S_Select(file, n);
			break;
		case 3:
			S_Insert(file, n);
			break;
		case 4:
			S_Merge(file, 0, n - 1);
			break;
		case 5:
			S_Quick(file, n);
			break;
		case 6:
			S_Shell(file, n);
			break;
		case 7:
			S_Counting(file, n);
			break;
		}
		clock_t end = clock();
		pupa(file, n);
		double Time = (double)(end - start) / CLOCKS_PER_SEC;
		printf("Время сортировки: %.3lf с\n", Time);
	}
	system("pause");
}