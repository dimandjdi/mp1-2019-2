#define _CRT_SECURE_NO_WARNINGS
#define NFILES 6000
#define length 40
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <io.h>
#include <string.h>
#include <locale.h>
struct file
{
	struct _finddata_t file;
	char buffer[30];
};
void SelectSort(struct file* files, int q, int mode)
{
	long long int max = -2;
	int k;
	for (int i = 0; i < q; i++)
	{
		max = -2;
		for (int j = i; j < q; j++)
		{
			if (files[j].file.size > max)
			{
				max = files[j].file.size;
				k = j;
			}
		}
		files = swap(files, i, k);
	}
	if (mode == 0)
		files = swipe(files, q);
	return files;

}
	
void InsertSort(struct file* files, int q, int mode)
{
	int j;
	for (int i = 0; i < q; i++)
	{
		struct file x = files[i];
		for (j = i - 1; (j >= 0) && (files[j].file.size > x.file.size); j--)
			files[j + 1] = files[j];
		files[j + 1] = x;
	}
	if (mode == 1)
		files = swipe(files, q);
	return files;
}
void BubbleSort(struct file* files, int q, int mode)
{
	for (int i = 0; i < q; i++)
	{
		for (int j = q - 1; j > i; j--)
		{
			if (files[j].file.size < files[j - 1].file.size)
			{
				files = swap(files, j, j - 1);
			}
		}
	}
	if (mode == 1)
		files = swipe(files, q);
	return files;
}
void QuickSort(struct file* files, long q)
{
	long i = 0, j = q - 1;
	struct file temp;
	_fsize_t p = files[q >> 1].file.size;
	do {
		while (files[i].file.size < p) i++;
		while (files[j].file.size > p) j--;
		if (i <= j) {
			temp = files[i]; files[i] = files[j]; files[j] = temp;
			i++; j--;
		}
	} while (i <= j);
	if (j > 0) quickSort(files, j);
	if (j > 0) quickSort(files, j + 1);
	if (q > i) quickSort(files + i, q - i);
}
void MergerSort(struct file* files, int q, int mode)
{
	ms(files, 0, q - 1);
	if (mode == 1)
		files = swipe(files, q);
	return files;
}
void MerSort(struct file* files, int first, int last)
{
	if (first < last)
	{
		int split = (first + last) / 2;
		MerSort(files, first, split);
		MerSort(files, split + 1, last);
		MSort(files, first, split, last);
	}
	return files;
}
void MSort(struct file* files, int first, int split, int last)
{
struct file* sorted;
	sorted = (struct file*)calloc(last - first + 1, sizeof(struct file));
	int i = first, j = split + 1;
	for (int k = 0; k <= last - first; k++)
		if ((j > last) || ((i <= split) && (files[i].file.size < files[j].file.size)))
			sorted[k] = files[i++];
		else
			sorted[k] = files[j++];
	for (int k = first; k <= last; k++)
		files[k] = sorted[k - first];
	return files;
}
void ShellSort(struct file* files, int q, int mode)
{
	long inc, i, j, seq[40];
	int s;
	s = increment(seq, q);
	while (s >= 0)
	{
		inc = seq[s--];
		for (i = inc; i < q; i++)
		{
			struct file temp = files[i];
			for (j = i - inc; (j >= 0) && (files[j].file.size > temp.file.size); j -= inc)
				files[j + inc] = files[j];
			files[j + inc] = temp;
		}
	}
	if (mode == 1)
		files = swipe(files, q);
	return files;
}
void CountingSort(struct file* files, int q, int mode)
{
	struct file* sorted;
	sorted = (struct file*)calloc(q, sizeof(struct file));
	int max = 0, * counts;
	for (int i = 0; i < q; i++)
	{
		if (files[i].file.size > max)
			max = files[i].file.size;
	}
	if (max > 1000 || q < max)
	{
				printf("Этот вид сортировки не работает в данном каталоге");
		return 0;
	}
	counts = (int*)calloc(max + 2, sizeof(int));
	for (int i = 0; i < max + 2; i++)
		counts[i] = 0;
	for (int i = 0; i < q; i++)
		++counts[files[i].file.size + 1];
	if (counts[0] != 0)
		counts[0] = counts[0] * (-1);
	for (int i = 1; i < max + 2; i++)
		counts[i] += counts[i - 1];
	for (int i = q - 1; i >= 0; i--)
	{
		counts[files[i].file.size + 1] -= 1;
		sorted[counts[files[i].file.size + 1]] = files[i];
	}
	if (mode == 1)
		sorted = swipe(sorted, q);
	return sorted;
}


int main(void)
{
	struct _finddata_t file;
	intptr_t hFile;
	char path[200];
	long count = 0;
	int a = 0;
	int b = 0;
	long i = 0;
	int sort = 0, mode = 0;
	clock_t t1, t2;
	double tt = 0;
	unsigned long sizes[NFILES];
	char names[NFILES][length];
	setlocale(LC_ALL, "Rus");

	while (a == 0)
	{

		printf("Введите путь до каталога файлов\n");
		gets_s(path, 200);
		if ((hFile = _findfirst("c:\\temp\\*.*", &file)) == -1L)
			printf("Вы ошиблись при вводе или по указанному Вами адресу файлов нет, пожалуйста, попробуйте еще раз:\n");
		else
		{
			printf("Список файлов\n");
			printf("ФАЙЛ         ДАТА %24c   РАЗМЕР\n", ' ');
			printf("----         ---- %24c    ----\n", ' ');
			do {
				char buffer[30];
				ctime_s(buffer, _countof(buffer), &file.time_write);
				if (count < NFILES)
				{
					strncpy(names[count], file.name, length);
					sizes[count] = file.size;
					printf("%-12.12s %.24s  %10ld\n", file.name, buffer, file.size);
					count++;
				}
			} while (_findnext(hFile, &file) == 0);
			_findclose(hFile);
			do
			{
				if ((mode != 1) && (mode != 2))
				{
					printf("Выберите способ сортировки:\n1)По возрастанию\n2)По убыванию \n");
					scanf_s("%i", &mode);
				}
				if ((sort != 1) && (sort != 2) && (sort != 3) && (sort != 4) && (sort != 5) && (sort != 6) && (sort != 7))
				{
					printf("Выберите метод сортировки:\n1)Пузырьком\n2)Выбором\n3)Вставками\n4)Слиянием\n5)Хоара\n6)Шелла\n7)Подсчетом\n");
					scanf_s("%i", &sort);
				}
				switch (sort)
				{
				case 1:
					t1 = clock();
					BubbleSort(sizes, names, count);
					t2 = clock();
					break;
				case 2:
					t1 = clock();
					SelectSort(sizes, names, count);
					t2 = clock();
				case 3:
					t1 = clock();
					InsertSort(sizes, names, count);
					t2 = clock();
				case 4:
					t1 = clock();
					QuickSort(sizes, names, count);
					t2 = clock();
				case 5:
					t1 = clock();
					MergerSort(sizes, names, count);
					t2 = clock();
				case 6:
					t1 = clock();
					ShellSort(sizes, names, count);
					t2 = clock();
				case 7:
					t1 = clock();
					CountingSort(sizes, names, count);
					t2 = clock();
				}
				printf("Отсортированный список файлов:\n");
				printf("ФАЙЛ         ДАТА %24c   РАЗМЕР\n", ' ');
				printf("----         ---- %24c    ----\n", ' ');
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
				tt = (t2 - t1) / CLOCKS_PER_SEC;
				printf("Время сортировки: %f\n", tt);
				printf("Хотите изменить метод сортировки?\n0 - да, 1 - нет.\n");
				scanf_s("%i", &b);
				while ((b!= 0) && (b!= 1))
				{
					printf("Введите 0 или 1\n");
					scanf_s("%i", &b);
				}
			} while (b == 0);
			a = 1;
		}
	}
}