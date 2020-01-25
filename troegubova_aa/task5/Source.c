<<<<<<< HEAD
#define _CRT_SECURE_NO_WARNINGS 
=======
﻿#define _CRT_SECURE_NO_WARNINGS 
>>>>>>> a915b65b57a3b10d80b52d292c7779881049bd25

#include <stdio.h> 
#include <stdlib.h> 
#include <io.h> 
#include <string.h> 
#include <time.h> 
<<<<<<< HEAD
#include <locale.h> 
=======
#include <locale.h>
>>>>>>> a915b65b57a3b10d80b52d292c7779881049bd25

void BubbleSort(struct _finddata_t *file, long size)
{
	long i, j;
<<<<<<< HEAD
	struct _finddata_t x;
=======
	struct _finddata_t  x;
>>>>>>> a915b65b57a3b10d80b52d292c7779881049bd25

	for (i = 0; i < size; i++)
	{
		for (j = size - 1; j > i; j--)
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

void SelectSort(struct _finddata_t *file, long size)
{
	long i, j, k;
	long x;
	struct _finddata_t t;
	for (i = 0; i < size; i++)
	{
<<<<<<< HEAD
		k = i; x = file[i].size;
=======
		k = i; x = file[i].size; 
>>>>>>> a915b65b57a3b10d80b52d292c7779881049bd25

		for (j = i + 1; j < size; j++)
			if (file[j].size < x)
			{
				k = j;
				x = file[j].size;
			}
		t = file[i];
		file[i] = file[k];
		file[k] = t;
	}
}

inline void InsertSortGuarded(struct _finddata_t *file, long size)
{
	long x;
	long i, j;
	struct _finddata_t t;
	for (i = 0; i < size; i++)
	{
		x = file[i].size; t = file[i];
		for (j = i - 1; j >= 0 && file[j].size > x; j--)
			file[j + 1] = file[j];
		file[j + 1] = t;
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

void QuickSort(struct _finddata_t *file, long size)
{
	long i = 0, j = size - 1;
	struct _finddata_t temp;
	long p;
	p = file[size >> 1].size;

	do {
		while (file[i].size < p)
			i++;
		while (file[j].size > p)
			j--;

		if (i <= j)
		{
			temp = file[i]; file[i] = file[j]; file[j] = temp;
			i++; j--;
		}
	} while (i <= j);

	if (j > 0)
		QuickSort(file, j);
	if (size > i)
		QuickSort(file + i, size - i);
}

int increment(long inc[], long size) {
	int p1, p2, p3, s;

	p1 = p2 = p3 = 1;
	s = -1;
	do {
		if (++s % 2)
		{
			inc[s] = 8 * p1 - 6 * p2 + 1;
		}
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
	s = increment(seq, n);
	while (s >= 0)
	{
		inc = seq[s--];
		for (i = inc; i < n; i++)
		{
			struct _finddata_t temp = file[i];
			for (j = i - inc; (j >= 0) && (file[j].size > temp.size); j -= inc)
				file[j + inc].size = file[j].size;
			file[j + inc] = temp;
		}
	}
}

void upend(struct _finddata_t *file, int size)
{
	for (int i = 0; i < size / 2; i++)
	{
		struct _finddata_t x = file[i];
		file[i] = file[size - 1 - i];
		file[size - 1 - i] = x;
	}
}

int main(void)
{
	setlocale(LC_ALL, "Rus");
	struct _finddata_t cfile;
	intptr_t hFile;
	char path[200];
	long count = 0;
	int x, y;
	double time;
<<<<<<< HEAD
	printf("������� ���� �� ����������, � ������� ���������� ������������� �����:\n ");
=======
	printf("Введите путь до директории, в которой необходимо отсортировать файлы:\n ");
>>>>>>> a915b65b57a3b10d80b52d292c7779881049bd25
	gets(path);
	strcat(path, "*.*");

	if ((hFile = _findfirst(path, &cfile)) == -1L)
<<<<<<< HEAD
		printf("� ���������, ��� ������ � ������� ����������!\n");
=======
		printf("К сожалению, нет файлов текущей директории!\n");
>>>>>>> a915b65b57a3b10d80b52d292c7779881049bd25
	else
	{
		do
		{
			count++;
		} while (_findnext(hFile, &cfile) == 0);
		_findclose(hFile);
	}
	struct _finddata_t *file;
	file = (struct _finddata_t *)malloc(count * sizeof(struct _finddata_t));
	count = 0;
<<<<<<< HEAD

	if ((hFile = _findfirst(path, &cfile)) == -1L)
		printf("� ���������, ��� ������ � ������� ����������!\n");
=======
	 
	if ((hFile = _findfirst(path, &cfile)) == -1L)
		printf("К сожалению, нет файлов текущей директории!\n");
>>>>>>> a915b65b57a3b10d80b52d292c7779881049bd25
	else
	{
		do
		{
			char buffer[30];
			ctime_s(buffer, _countof(buffer), &cfile.time_write);
<<<<<<< HEAD
			if
				(cfile.attrib & _A_SUBDIR) continue;
=======
			if (cfile.attrib & _A_SUBDIR) continue;  
>>>>>>> a915b65b57a3b10d80b52d292c7779881049bd25
			file[count++] = cfile;
		} while (_findnext(hFile, &cfile) == 0);
		_findclose(hFile);
	}
	int a = 1;
	do
	{
<<<<<<< HEAD
		printf("������ ����� ���������� �� ������������:\n1)���������\n2)�������\n3)���������\n4)��������\n5)�����\n6)�����\n");
		scanf_s("%d", &x);
		printf("������ ����� ����������:\n1)�� �����������\n2)�� ��������\n");
=======
		printf("Выбери метод сортировки из предложенных:\n1)пузырьком\n2)выбором\n3)вставками\n4)слиянием\n5)Хоара\n6)Шелла\n");
		scanf_s("%d", &x);
		printf("Выбери режим сортировки:\n1)По возрастанию\n2)По убыванию\n");
>>>>>>> a915b65b57a3b10d80b52d292c7779881049bd25
		scanf_s("%d", &y);

		clock_t time1 = clock();
		switch (x)
		{
		case 1:
			BubbleSort(file, count);
			break;
		case 2:
			SelectSort(file, count);
		case 3:
			InsertSortGuarded(file, count);
		case 4:
			MergeSort(file, 0, count - 1);
		case 5:
			QuickSort(file, count);
		case 6:
			ShellSort(file, count);
		default:
			break;
		}
<<<<<<< HEAD

=======
>>>>>>> a915b65b57a3b10d80b52d292c7779881049bd25
		if (y == 2)
			upend(file, count);
		clock_t time2 = clock();
		time = (double)(time2 - time1) / CLOCKS_PER_SEC;
<<<<<<< HEAD
		printf("���� %20c %10c ������\n", ' ', ' ');
		printf("--� %20c %10c �--\n", ' ', ' ');
=======
		printf("ФАЙЛ %20c %10c РАЗМЕР\n", ' ', ' ');
		printf("---- %20c %10c ----\n", ' ', ' ');
>>>>>>> a915b65b57a3b10d80b52d292c7779881049bd25
		for (int i = 0; i < count; i++)
		{
			printf("%-32.32s %10lu\n", file[i].name, file[i].size);
		}
<<<<<<< HEAD
		printf("\n����� ����������: %.10lf sec\n", time);
		printf("������ ��������:\n1)������� ������ ����� ����������\n2)��������� ������ ���������\n");
		scanf_s("%d", &a);
	} while (a == 1);
	system("pause");
}
=======
		printf("\nВремя сортировки: %.6lf sec\n", time);
		printf("Выбери действие:\n1)выбрать другой метод сортировки\n2)закончить работу программы\n");
		scanf_s("%d", &a);
	} while (a == 1);
	system("pause");
}		
>>>>>>> a915b65b57a3b10d80b52d292c7779881049bd25
