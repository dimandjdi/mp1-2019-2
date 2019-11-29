#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <io.h>

int countt(char path[])
{
	struct _finddata_t c_file;
	intptr_t hFile;
	long int count = 0;
	if ((hFile = _findfirst(path, &c_file)) == -1L)
		printf("В данной директории нет файлов\n");
	else
		do {
			count++;
		} while (_findnext(hFile, &c_file) == 0);
		_findclose(hFile);
		return count;
}
void Bubllesort(struct _finddata_t* files, long int kol)
{
	long int i, j;
	struct _finddata_t c;
	for (i = 0; i < kol; i++)
		for (j = kol - 1; j > i; j--)
			if (files[j - 1].size > files[j].size)
			{
				c = files[j - 1];
				files[j - 1] = files[j];
				files[j] = c;
			}
}
void selectSort(struct _finddata_t* files, long int kol)
{
	long i, j, m;
	struct _finddata_t x;
	for (i = 0; i < kol; i++)
	{
		m = i;
		x = files[i];
		for (j = i + 1; j < kol; j++)
		{
			if (files[j].size < x.size)
			{
				m = j;
				x = files[j];
			}
			files[m] = files[i];
			files[i] = x;
		}
	}
}
void insert_sort(struct _finddata_t* files, long int kol)
{
	long i, j;
	struct _finddata_t c;
	for (i = 0; i < kol; i++)
	{
		c = files[i];
		for (j = i - 1; (j >= 0) && (files[j].size > c.size); j--)
		{
			files[j + 1] = files[j];

		}
		files[j + 1] = c;
	}
}
void merge(struct _finddata_t* files, long start, long middle, long end)
{
	long p1 = start, p2 = middle + 1, p3 = 0;
	struct _finddata_t*  c = (struct _finddata_t*)malloc((end - start + 1) * sizeof(struct _finddata_t));
	while ((p1 <= middle) && (p2 <= end))
	{
		if (files[p1].size < files[p2].size)
			c[p3++] = files[p1++];
		else
			c[p3++] = files[p2++];
	}
	while (p2 <= end)
		c[p3++] = files[p2++];
	while (p1 <= middle)
		c[p3++] = files[p1++];

	for (p3 = 0; p3 < end - start + 1; p3++)
	{
		files[start + p3] = c[p3];
	}
	free(c);
}
void merge_sort(struct _finddata_t* files, long begin, long end)
{
	long middle;
	if (begin < end)
	{
		middle = (begin + end) / 2;
		merge_sort(files, begin, middle);
		merge_sort(files, middle + 1, end);
		merge(files, begin, middle, end);
	}
}
void quickSort(struct _finddata_t* files, long int kol)// сортировка Хоара
{
	int i = 0;
	int j = kol - 1;
	struct _finddata_t p = files[kol >> 1];
	do
	{
		while (files[i].size < p.size) i++;
		while (files[j].size > p.size) j--;
		if (i <= j)
		{
			struct _finddata_t buf = files[i];
			files[i] = files[j];
			files[j] = buf;
			i++;
			j--;
		}
	} while (i <= j);
	if (j > 0)
		quickSort(files, j + 1);
	if (kol > i)
		quickSort(files + i, kol - i);
}
int increment(long inc[], long int kol)
{
	int p1, p2, p3, s;
	p1 = p2 = p3 = 1;
	s = -1;
	do {
		if (++s % 2)
		{
			inc[s] = 8 * p1 - 6 * p2 + 1;
		}
		else {
			inc[s] = 9 * p1 - 9 * p3 + 1;
			p2 *= 2;
			p3 *= 2;
		}
		p1 *= 2;
	} while (3 * inc[s] < kol);
	return s > 0 ? --s : 0;
}
void shell_sort(struct _finddata_t* files, long int kol)
{
	long inc, i, j, seq[40];
	int s;
	s = increment(seq, kol);
	while (s >= 0) {
		inc = seq[s--];
		for (i = inc; i < kol; i++)
		{
			struct _finddata_t buf = files[i];
			for (j = i - inc; (j >= 0) && (files[j].size > buf.size); j -= inc)
				files[j + inc] = files[j];
			files[j + inc] = buf;
		}
	}
}
void CountingSort(struct _finddata_t* file, int kol)
{
	long max = 0;
	long min = 0;
	long i = 0;
	struct _finddata_t* files = (struct _finddata_t*)malloc(kol * sizeof(struct _finddata_t));
	memcpy(files, file, kol * sizeof(struct _finddata_t));
	for (int i = 0; i < kol; i++)
	{
		if (file[i].size > max)
			max = file[i].size;
		if (file[i].size < min)
			min = file[i].size;
	}
	max++;
	int* C = (int*)malloc(max * sizeof(int));
	memset(C, 0, max * sizeof(int));
	for (i = 0; i < kol; i++)
	{
		C[file[i].size]++;
	}
	int c = 0;
	for (i = 0; i < max; i++)
	{
		int t = C[i];
		C[i] = c;
		c += t;
	}
	for (i = 0; i < kol; i++)
	{
		files[C[file[i].size]] = file[i];
		C[file[i].size]++;
	}
	memmove(file, files, kol * sizeof(struct _finddata_t));
	free(C);
	free(files);
}

void main(void)
{
	setlocale(2, "Rus");
	struct _finddata_t c_file;
	intptr_t hFile;
	char path[200];
	long int count = 0;
	clock_t t1, t2;
	double tt = 0;
	int  a = 0, view = 0, m = 0, n;
	int flag = 0;
	struct _finddata_t* files;
	printf("Введите путь до директории: \n");
	gets_s(path, 200);
	strcat(path, "*");
	if ((count = countt(path)) != 0)
	{
		files = (struct _finddata_t*)malloc(count * sizeof(struct _finddata_t));
		hFile = _findfirst(path, &files[0]);
		for (int a = 1; a < count; a++)
			_findnext(hFile, &files[a]);

		if ((hFile = _findfirst(path, &c_file)) == -1L)
			printf("Нет таких файлов в выбранной папке!\n");
		else
		{
			printf("FILE                SIZE\n", ' ');
			printf("----                ----\n", ' ');
			do
			{

				printf("%-12.12s %10lu\n", c_file.name, c_file.size);

			} while (_findnext(hFile, &c_file) == 0);
			_findclose(hFile);
		}
		printf("Количество файлов: %d\n", count);
		do
		{
			printf("Выберете сортировку:\n");
			printf("    1 - Пузырек\n");
			printf("    2 - Выбором\n");
			printf("    3 - Вставками\n");
			printf("    4 - Слиянием\n");
			printf("    5 - Хоара, более известная как быстрая сортировка\n");
			printf("    6 - Шелла\n");
			printf("    7 - Подсчётом\n");
			flag = 0;
			do
			{
				if (flag == 1)
					printf("Вы неправильно ввели номер, повторите попытку\n");
				else
					flag = 1;
				scanf_s("%d", &a);
			} while (a < 1 || a > 7);
			printf("Как хотите отсортировать?\n1 -по возрастанию , 2 -по убыванию\n");
			flag = 0;
			do
			{
				if (flag == 1)
					printf("Вы неправильно ввели номер, повторите попытку\n");
				else
					flag = 1;
				scanf_s("%d", &view);
			} while (view < 1 || view > 2);
			switch (a)
			{
			case 1:
				t1 = clock();
				Bubllesort(files, count);
				t2 = clock();
				break;
			case 2:
				t1 = clock();
				selectSort(files, count);
				t2 = clock();
				break;
			case 3:
				t1 = clock();
				insert_sort(files, count);
				t2 = clock();
				break;
			case 4:
				t1 = clock();
				merge_sort(files, 0, count - 1);
				t2 = clock();
				break;
			case 5:
				t1 = clock();
				quickSort(files, count);
				t2 = clock();
				break;
			case 6:
				t1 = clock();
				shell_sort(files, count);
				t2 = clock();
				break;
			case 7:
				t1 = clock();
				CountingSort(files, count);
				t2 = clock();
				break;
			}
			printf("FILE               SIZE\n", ' ');
			printf("----               ----\n", ' ');
			if (view == 1)
			{
				for (int i = 0; i < count; i++)
					printf("%-12.12s  %10ld\n", files[i].name, files[i].size);
			}
			if (view == 2)
			{
				for (int i = count - 1; i >= 0; i--)
					printf("%-12.12s  %10ld\n", files[i].name, files[i].size);
			}
			tt = (double)(t2 - t1) / CLOCKS_PER_SEC;
			printf("Время на сортировку составило:\n %f \n", tt);
			printf("Хотите изменить способ сортировки?\n0 - да, 1 - нет.\n");
			scanf_s("%i", &n);
			while ((n != 0) && (n != 1))
			{
				printf("Введите  0 или 1.\n");
				scanf_s("%i", &n);
			}
		} while (n == 0);
	}
	system("pause");
}