#define _CRT_SECURE_NO_WARNINGS
#define NFILES 5000
#define length 32
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <io.h>
#include <string.h>
#include <locale.h>
void SelectSort(unsigned long a[], char name[NFILES][length], long n)
{
	long i, j, k;
	unsigned long x;
	char p[200];
	for (i = 0; i < n; i++)
	{
		k = i; x = a[i];
		for (j = i + 1; j < n; j++)
		{
			if (a[j] < x)
			{
				k = j; x = a[j];
			}
			a[k] = a[i]; a[i] = x;
			strncpy(p, name[k], length);
			strncpy(name[k], name[i], length);
			strncpy(name[i], p, length);
		}
	}
}
void InsertSort(unsigned long a[], char name[NFILES][length], long n)
{
	unsigned long x;
	long i, j;
	char p[200];
	for (i = 0; i < n; i++)
	{
		x = a[i];
		strncpy(p, name[i], 32);
		for (j = i - 1; (j >= 0) && (a[j] > x); j--)
		{
			a[j + 1] = a[j];
			strncpy(name[j + 1], name[j], length);
		}
		a[j + 1] = x;
		strncpy(name[j + 1], p, length);
	}
}
void BubbleSort(unsigned long a[], char name[NFILES][length], long n)
{
	long i, j;
	unsigned int x;
	char p[200];

	for (i = 0; i < n; i++)
	{
		for (j = n - 1; j > i; j--)
		{
			if (a[j - 1] > a[j])
			{
				x = a[j - 1]; a[j - 1] = a[j]; a[j] = x;
				strncpy(p, name[j], length);
				strncpy(name[j], name[j - 1], length);
				strncpy(name[j - 1], p, length);
			}
		}
	}
}
int main(void)
{
	struct _finddata_t c_file;
	intptr_t hFile;
	char path[200];
	long count = 0;
	int n = 0;
	int m = 0;
	int end;
	long i = 0;
	unsigned int x;
	char p[200];
	long j;
	int sort, mode;
	clock_t t1, t2;
	double tt = 0;
	unsigned long sizes[NFILES], a;
	char names[NFILES][length];
	setlocale(LC_ALL, "Rus");
	while (n == 0)
	{
		printf("Введите имя каталога в формате C:\\\\...\\\\*\n");
		gets_s(path, 200);
		if ((hFile = _findfirst(path, &c_file)) == -1L)
			printf("Файлов не найдено!\n");
		else
		{
			printf("Список файлов:\n\n");
			printf("FILE               SIZE\n", ' ');
			printf("----               ----\n", ' ');
			do {
				if (count < NFILES)
				{
					strncpy(names[count], c_file.name, length);
					sizes[count] = c_file.size;
					printf("%-12.12s   %10lu\n", c_file.name, c_file.size);
					count++;
				}
			} while (_findnext(hFile, &c_file) == 0);
			_findclose(hFile);
			do {
				sort = 0;
				mode = 0;
				printf("\nКоличество файлов: %d\n", count);
				while ((sort < 1) || (sort > 3))
				{
					printf("Выберите метод сортировки:\n1) Пузырьком\n2) Выбором\n3) Вставками\n");
					scanf_s("%i", &sort);
				}
				while ((mode < 1) || (mode > 2))
				{
					printf("Выберите способ сортировки:\n1) По возрастанию\n2) По убыванию\n");
					scanf_s("%i", &mode);
				}
				switch (sort)
				{
				case 1:
					t1 = clock();
					for (i = 0; i < n; i++)
					{
						for (j = n - 1; j > i; j--)
						{
							if (a[j - 1] > a[j])
							{
								x = a[j - 1]; a[j - 1] = a[j]; a[j] = x;
								strncpy(p, name[j], length);
								strncpy(name[j], name[j - 1], length);
								strncpy(name[j - 1], p, length);
							}
						}
					}
					t2 = clock();
					break;
				case 2:
					t1 = clock();
					for (i = 0; i < n; i++)
					{
						k = i; x = a[i];
						for (j = i + 1; j < n; j++)
						{
							if (a[j] < x)
							{
								k = j; x = a[j];
							}
							a[k] = a[i]; a[i] = x;
							strncpy(p, name[k], length);
							strncpy(name[k], name[i], length);
							strncpy(name[i], p, length);
						}
					]
					t2 = clock();
				case 3:
					t1 = clock();
					for (i = 0; i < n; i++)
					{
						x = a[i];
						strncpy(p, name[i], 32);
						for (j = i - 1; (j >= 0) && (a[j] > x); j--)
						{
							a[j + 1] = a[j];
							strncpy(name[j + 1], name[j], length);
						}
						a[j + 1] = x;
						strncpy(name[j + 1], p, length);
					}
					t2 = clock();
				}
				printf("Отсортированный список файлов:\n\n");
				printf("FILE            SIZE\n", ' ');
				printf("----            ----\n", ' ');
				if (mode == 1)
				{
					for (i = 0; i < count; i++)
					{
						printf("%-12.12s %10lu\n", names[i], sizes[i]);
					}
				}
				else {
					for (i = count - 1; i >= 0; i--)
					{
						printf("%-12.12s %10lu\n", names[i], sizes[i]);
					}
				}
				tt = double(t2 - t1) / CLOCKS_PER_SEC;
				printf("Время сортировки: %d\n", tt);
				printf("Время сортировки: %f\n", tt);
				printf("Желаете изменить метод сортировки?\n0 - да, 1 - нет.\n");
				scanf_s("%i", &m);
				while ((m != 0) && (m != 1))
				{
					printf("Введите 0 или 1.\n");
					scanf_s("%i", &m);
				}
			} while (m == 0);
			n = 1;
		}
	}
}