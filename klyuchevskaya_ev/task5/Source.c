#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>  
#include <stdlib.h>  
#include <io.h>  
#include <time.h>
#include <locale.h>
#include <string.h>

void BubbleSort(struct _finddata_t *file, int count)
{
	int i, j;
	struct _finddata_t x;
	for (i = 0; i < count; i++)
	{
		for (j = count - 1; j > i; j--)
		{
			if (file[j - 1].size > file[j].size)
			{
				x = file[j];
				file[j] = file[j - 1];
				file[j - 1] = x;
			}
		}
	}
}

void SelectSort(struct _finddata_t *file, int count)
{
	int i, j, n;
	struct _finddata_t m;
	for (i = 0; i < count; i++)
	{
		n = i;
		m = file[i];
		for (j = i + 1; j < count; j++)
			if (file[j].size < m.size)
			{
				n = j;
				m = file[j];
			}
		file[n] = file[i];
		file[i] = m;
	}
}

void InsertSort(struct _finddata_t *file, int count)
{
	int i, j;
	struct _finddata_t m;
	for (i = 1; i < count; i++)
	{
		m = file[i];
		for (j = i - 1; j >= 0 && file[j].size > m.size; j--)
			file[j + 1] = file[j];
		file[j + 1] = m;
	}
}

void merge(struct _finddata_t *file, long lb, long split, long ub)
{
	long pos1 = lb, pos2 = split + 1, pos3 = 0;
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

void MergeSort(struct _finddata_t *file, long lb, long ub)
{
	long split;
	if (lb < ub)
	{
		split = (lb + ub) / 2;
		MergeSort(file, lb, split);
		MergeSort(file, split + 1, ub);
		merge(file, lb, split, ub);
	}
}

void QuickSort(struct _finddata_t *file, int count)
{
	int i = 0, j = count - 1;
	struct _finddata_t temp;
	long p;
	p = file[count >> 1].size;
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
	if (count > i) QuickSort(file + i, count - i);
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

void ShellSort(struct _finddata_t *file, int count)
{
	long inc, i, j, seq[40];
	int s;
	struct _finddata_t temp;
	s = increment(seq, count);
	while (s >= 0)
	{
		inc = seq[s--];
		for (i = inc; i < count; i++)
		{
			temp = file[i];
			for (j = i - inc; (j >= 0) && (file[j].size > temp.size); j -= inc)
				file[j + inc] = file[j];
			file[j + inc] = temp;
		}
	}
}

void CountingSort(struct _finddata_t *file, long count)
{
	long max;
	int i, j, m = 0;
	struct _finddata_t t;
	max = file[0].size;
	for (int i = 0; i < count; i++)
	{
		if (file[i].size > max)
			max = file[i].size;
	}
	max++;
	int *d = (int*)malloc(max * sizeof(int));
	memset(d, 0, max * sizeof(int));
	for (i = 0; i < count; i++)
		d[file[i].size]++;
	for (i = 0; i < max; i++)
	{
		if (d[i] != 0)
		{
			for (j = m; j < count; j++)
				if (file[j].size == i)
				{
					t = file[j];
					file[j] = file[m];
					file[m] = t;
					m++;
				}
		}
	}
	free(d);
}

void main()
{
	setlocale(LC_ALL, "Rus");
	char path[200];
	int i, n, count = 0;
	intptr_t hFile;
	struct _finddata_t *file;
	struct _finddata_t c_file;
	printf("Введите путь до  директория (например : C:\\\\temp\\\\*.*) : \n");
	gets_s(path, 200);
	strcat(path, "*");
	if ((hFile = _findfirst(path, &c_file)) == -1L)
		printf("Вы ввели неверный директорий или в нем не оказалось файлов\n");
	else {
		printf("Неотсортированный список файлов:\n");
		printf("FILE                SIZE\n", ' ');
		printf("----                ----\n", ' ');
		do 
		{
			if (count <= 200)
				printf("%-12.12s  %10ld\n", c_file.name, c_file.size);
			count++;
		} 
		while (_findnext(hFile, &c_file) == 0);
		_findclose(hFile);
		printf("\nКоличество файлов: %d\n", count);
		file = (struct _finddata_t*)malloc(count * sizeof(struct _finddata_t));
		hFile = _findfirst(path, &file[0]);
		for (i = 1; i < count; i++)
			_findnext(hFile, &file[i]);
		do
		{
			printf("Введите номер желаемой сортировки:\n 1)Пузырьком\n 2)Выбором\n 3)Вставками\n 4)Слиянием\n 5)Хоара\n 6)Шелла\n 7)Подсчетом\n");
			scanf_s("%d", &n);
			clock_t start = clock();

			switch (n)
			{
			case 1:
				BubbleSort(file, count);
				break;
			case 2:
				SelectSort(file, count);
				break;
			case 3:
				InsertSort(file, count);
				break;
			case 4:
				MergeSort(file, 0, count-1);
				break;
			case 5:
				QuickSort(file, count);
				break;
			case 6:
				ShellSort(file, count);
				break;
			case 7:
				CountingSort(file, count);
				break;
			}

			clock_t end = clock();

			printf("FILE                SIZE\n", ' ');
			printf("----                ----\n", ' ');
			for (i = 0; i < count; i++) {
				printf("%-12.12s %10u\n", file[i].name, file[i].size);
			}

			double timeSpent = (double)(end - start) / CLOCKS_PER_SEC;
			printf("\nВремя работы сортировки: %.10lf sec\n", timeSpent);
			printf("Введите 1 для новой сортировки, 0 - для завершения работы\n");
			scanf_s("%d", &n);
		} while (n == 1);
		free(file);
	}	system("pause");
}