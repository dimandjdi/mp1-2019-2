﻿#define _CRT_SECURE_NO_WARNINGS

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

int choice_sorting()
{
	int sorting;
	printf("Введите номер нужной сортировки:\n");
	printf("1)Пузырьком\n");
	printf("2)Выбором\n");
	printf("3)Вставками\n");
	printf("4)Слиянием\n");
	printf("5)Хоара\n");
	printf("6)Шелла\n");
	printf("7)Подсчетом\n");
	scanf_s("%d", &sorting);
	return sorting;
}

void BubbleSort(struct _finddata_t *file, int n)
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

void SelectSort(struct _finddata_t *file, int n)
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

void InsertSort(struct _finddata_t *file, int n)
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

void merge(struct _finddata_t *file, long lb, long split, long ub)
{
	long pos1 = lb;
	long pos2 = split + 1;
	long pos3 = 0;
	struct _finddata_t *temp = (struct _finddata_t *)malloc((ub - lb + 1) * sizeof(struct _finddata_t));
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

void MergeSort(struct File *files, long lb, long ub)
{
	long split;
	if (lb < ub)
	{
		split = (lb + ub) / 2;
		MergeSort(files, lb, split);
		MergeSort(files, split + 1, ub);
		merge(files, lb, split, ub);
	}
}

void QuickSort(struct _finddata_t *file, int n)
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
	if (j > 0) QuickSort(file, j + 1);
	if (n > i) QuickSort(file + i, n - i);
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

void ShellSort(struct _finddata_t *file, int n)
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

void CountingSort(struct _finddata_t *file, int n)
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

void outputfiles(struct _finddata_t *file, int n)
{
	int i, c;
	printf("Введите 1 для сортировки по возрастанию или 2 для сортировки по убыванию\n");
	scanf_s("%d", &c);
	printf("Listing of files\n\n");
	printf("FILE   %14c   SIZE\n", ' ');
	switch (c)
	{
	case 1:
		for (i = 0; i < n; i++)
			printf("%-12.12s   %.14c  %10ld\n", file[i].name, ' ', file[i].size);
		break;
	case 2:
		for (i = n; i > 0; i--)
			printf("%-12.12s %.14c  %10ld\n", file[i - 1].name, ' ', file[i - 1].size);
		break;
	}
}

void main()
{
	setlocale(LC_ALL, "Rus");
	char path[200];
	int n, i, c;
	intptr_t hFile;
	struct _finddata_t *file;
	clock_t start, end;
	printf("Введите путь до директории:\n");
	gets(path);
	strcat(path, "*");
	if ((n = countfile(path)) != 0)
	{
		file = (struct _finddata_t*)malloc(n * sizeof(struct _finddata_t));
		hFile = _findfirst(path, &file[0]);
		for (i = 1; i < n; i++)
			_findnext(hFile, &file[i]);
		do
		{
			c = choice_sorting();
			start = clock();
			switch (c)
			{
				case 1:
					BubbleSort(file, n);
					break;
				case 2:
					SelectSort(file, n);
					break;
				case 3:
					InsertSort(file, n);
					break;
				case 4:
					MergeSort(file, 0, n - 1);
					break;
				case 5:
					QuickSort(file, n);
					break;
				case 6:
					ShellSort(file, n);
					break;
				case 7:
					CountingSort(file, n);
					break;
			}
			end = clock();
			outputfiles(file, n);
			printf("Время сортировки: %.30lf с\n", (double)(end - start) / CLOCKS_PER_SEC);
			printf("Введите 1 для новой сортировки, 2 - для изменения пути до директории, 0 - для завершения сортировки\n");
			scanf_s("%d", &c);
		} while (c == 1);
		free(file);
	}
	switch (c)
	{
	case 0:
		exit(0);
		break;
	case 2:
		getchar();
		main();
		break;
	}
	system("pause");
}