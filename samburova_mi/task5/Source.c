#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>  
#include <stdlib.h>  
#include <io.h>  
#include <time.h>  
#include <locale.h>
struct _finddata_t files[10000];
int size;


void bubble_sort(struct _finddata_t* files, long size)
{
	long i, j;
	struct _finddata_t temp;

	for (i = 0; i < size; i++)
		for (j = size - 1; j > i; j--)
			if (files[j - 1].size > files[j].size)
			{
				temp = files[j - 1];
				files[j - 1] = files[j];
				files[j] = temp;
			}
}
void select_sort(struct _finddata_t* files, long size)
{
	long i, j, k;
	struct _finddata_t temp;

	for (i = 0; i < size; i++)
	{
		k = i;
		temp = files[i];

		for (j = i + 1; j < size; j++)
			if (files[j].size < temp.size)
			{
				k = j;
				temp = files[j];
			}
		files[k] = files[i];
		files[i] = temp;
	}

}

void insert_sort(struct _finddata_t* files, long n)
{
	long i, j;
	struct _finddata_t temp;

	for (i = 0; i < n; i++)
	{
		temp = files[i];
		for (j = i - 1; j >= 0 && files[j].size > temp.size; j--)
			files[j + 1] = files[j];
		files[j + 1] = temp;
	}
}
void quick_sort(struct _finddata_t* files, long N)
{

	long i = 0, j = N - 1;
	unsigned long p;
	struct _finddata_t temp;

	p = files[N >> 1].size;
	do
	{
		while (files[i].size < p) i++;
		while (files[j].size > p) j--;

		if (i <= j)
		{
			temp = files[i];
			files[i] = files[j];
			files[j] = temp;
			i++; j--;
		}
	} while (i <= j);
	if (j > 0) quick_sort(files, j);
	if (N > i) quick_sort(files + i, N - i);
}
int increment(long inc[], long size)
{
	int p1, p2, p3, s;
	p1 = p2 = p3 = 1;
	s = -1;
	do
	{
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

void shell_sort(struct _finddata_t* files, long size)
{
		long inc, i, j, seq[40];
		int s;
		s = increment(seq, size);
		while (s >= 0)
		{
			inc = seq[s--];
			for (i = inc; i < size; i++)
			{
				struct _finddata_t temp = files[i];
				for (j = i - inc; (j >= 0) && (files[j].size > temp.size); j -= inc)
					files[j + inc] = files[j];
				files[j + inc] = temp;
			}
		}
}

void counting_sort(struct _finddata_t* files, long size)
{
	long max = 0;
	long i = 0;
	struct _finddata_t* sortedfiles = (struct _finddata_t*)malloc(size * sizeof(struct _finddata_t));
	memcpy(sortedfiles, files, size * sizeof(struct _finddata_t));
	for (int i = 0; i < size; i++)
	{
		if (files[i].size > max)
			max = files[i].size;
	}
	max++;
	int* C = (int*)malloc(max * sizeof(int));
	memset(C, 0, max * sizeof(int));
	for (i = 0; i < size; i++)
	{
		C[files[i].size]++;
	}
	int c = 0;
	for (i = 0; i < max; i++)
	{
		int t = C[i];
		C[i] = c;
		c += t;
	}
	for (i = 0; i < size; i++)
	{
		sortedfiles[C[files[i].size]] = files[i];
		C[files[i].size]++;
	}
	memmove(files, sortedfiles, size * sizeof(struct _finddata_t));
	free(C);
	free(sortedfiles);
}
long count_(char* path, struct _finddata_t* files)
{
	struct _finddata_t file;
	intptr_t hFile;
	long count = 0;
	if ((hFile = _findfirst(path, &file)) != -1L)
	{
	
		do
		{
			if (file.size>0)
			{
				files[count] = file;
				count++;
			}
			if (count > 1000)
				break;
		} while (_findnext(hFile, &file) == 0);
		return count;
	}
	else
		return 0;

}
void output(struct _finddata_t* files, long size)
{
	int metod;
	printf("Сортировать по возрастанию или по убыванию? По возрастанию - нажмите 1, По убыванию - нажмите 2");
	printf("Listing of .c files\n\n");
	printf("FILE         DATE %24c   SIZE\n", ' ');
	printf("----         ---- %24c   ----\n", ' ');

	for (int i = 0; i < size; i++)
	{
		char buffer[30];
		ctime_s(buffer, _countof(buffer), &files[i].time_write);
		if (files[i].size > 0)
			printf("%-12.12s %.24s  %10ld\n", files[i].name, buffer, files[i].size);
		else
			printf("%-12.12s %.24s\n", files[i].name, buffer);
	}
}

void reverse(struct _finddata_t* files, long size)
{
	struct _finddata_t file;
	for (int i = 0; i < size >> 1; i++)
	{
		file = files[i];
		files[i] = files[size - 1 - i];
		files[size - 1 - i] = file;
	}
}


	int main()
	{

		setlocale(LC_ALL, "Russian");
		struct _finddata_t c_file;
		intptr_t hFile;
		char path[200];
		clock_t start, finish;

		int sort;
		printf("Введите путь для сортировки файлов\n");
		scanf("%s", path);
		size = count_(path, files);
		output(files, size);
		printf("Выберите метод сортировки:\n");
		printf("Пузырьком - нажмите 1\n Выбором - 2\n Вставками - 3\n Хоара - 4\n Шелла - 5\n Подсчетом - 6\n");
		scanf_s("%d", &sort);
		start = clock();
		switch (sort) {
		case 1:
		{
			bubble_sort(files, size);
			output(files, size);
			break;
		}
		case 2:
		{
			select_sort(files, size);
			output(files, size);
			break;
		}
		case 3:
		{
			insert_sort(files, size);
			output(files, size);
			break;
		}
		case 4:
		{
			quick_sort(files, size);
			output(files, size);
			break;
		}
		case 5:
		{
			shell_sort(files, size);
			output(files, size);
			break;
		}
		case 6:
		{
			counting_sort(files, size);
			output(files, size);
			break;
		}
		}
		
		finish = clock();
		printf("Время сортировки - %f", (double)(finish - start) / CLOCKS_PER_SEC);

		system("pause>nul");
	}