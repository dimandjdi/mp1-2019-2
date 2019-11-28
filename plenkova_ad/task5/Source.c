#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  
#include <locale.h>
#include <stdlib.h>  
#include <io.h>  
#include <time.h> 
#include <string.h>
#include <conio.h>
void Puziryok(struct _finddata_t massiv[], int size)
{
	struct _finddata_t temp;
	int i, j, names;
	for (i = 0; i < size; i++)
	{
		for (j = size - 1; j > i; j--)
		{
			if (massiv[j - 1].size > massiv[j].size)
			{
				temp = massiv[j - 1];
				massiv[j - 1] = massiv[j];
				massiv[j] = temp;
			}
		}
	}
}
void Vibor(struct _finddata_t massiv[], int size)
{
	int i, j, k;
	struct _finddata_t x;
	for (i = 0; i < size; i++)
	{
		k = i;
		x = massiv[i];
		for (j = i + 1; j < size; j++)
			if (massiv[j].size < x.size)
			{
				k = j;
				x = massiv[j];
			}
		massiv[k] = massiv[i];
		massiv[i] = x;
	}
}
void Vstavka(struct _finddata_t massiv[], int size)
{
	int i, j;
	struct _finddata_t x;
	for (i = 1; i < size; i++)
	{
		x = massiv[i];
		for (j = i - 1; j >= 0 && massiv[j].size > x.size; j--)
			massiv[j + 1] = massiv[j];
		massiv[j + 1] = x;
	}
}
void Sliyanie(struct _finddata_t massiv[], long size)
{
	int rght, rend;
	int i, j, m;
	int* b = (int*)malloc(size * sizeof(int));
	for (int k = 1; k < size; k *= 2)
	{
		for (int left = 0; left + k < size; left += k * 2)
		{
			rght = left + k;
			rend = rght + k;
			if (rend > size) rend = size;
			m = left; i = left; j = rght;
			while (i < rght && j < rend)
			{
				if (massiv[i].size <= massiv[j].size)
				{
					b[m] = massiv[i].size; i++;
				}
				else
				{
					b[m] = massiv[j].size; j++;
				}
				m++;
			}
			while (i < rght)
			{
				b[m] = massiv[i].size;
				i++; m++;
			}
			while (j < rend)
			{
				b[m] = massiv[j].size;
				j++; m++;
			}
			for (m = left; m < rend; m++)
			{
				massiv[m].size = b[m];
			}
		}
	}
	for (int i = 0; i < size; i++)
		massiv[i].size = b[i];
	free(b);

}
void QuickSort(struct _finddata_t* massiv, int size)
{
	int i = 0, j = size - 1;
	struct _finddata_t temp;
	long p;
	p = massiv[size >> 1].size;
	do {
		while (massiv[i].size < p)
			i++;
		while (massiv[j].size > p)
			j--;
		if (i <= j)
		{
			temp = massiv[i];
			massiv[i] = massiv[j];
			massiv[j] = temp;
			i++;
			j--;
		}
	} while (i <= j);
	if (j > 0) QuickSort(massiv, j + 1);
	if (size > i) QuickSort(massiv + i, size - i);
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
void ShellSort(struct _finddata_t* massiv, int size)
{
	long inc, i, j, seq[40];
	int s;
	struct _finddata_t temp;
	s = increment(seq, size);
	while (s >= 0)
	{
		inc = seq[s--];
		for (i = inc; i < size; i++)
		{
			temp = massiv[i];
			for (j = i - inc; (j >= 0) && (massiv[j].size > temp.size); j -= inc)
				massiv[j + inc] = massiv[j];
			massiv[j + inc] = temp;
		}
	}
}
void Podschyot(struct _finddata_t massiv[], int size, int sortedMass[])
{
	for (int i = 0; i < size; i++)
	{
		int k = 0;
		for (int j = 0; j < size; j++)
		{
			if (massiv[i].size > massiv[j].size)
				k++;
		}
		sortedMass[i] = massiv[k].size;
	}


}

int main(void)
{
	setlocale(LC_ALL, "rus");
	struct _finddata_t file;
	struct _finddata_t massiv[1000];
	intptr_t hFile;
	char path[200];
	int size = 0;
	int sortedMass[1000] = { 0 };
	int tip, mode, i = 0, sort = 1;
	float tt;
	clock_t t1, t2;
	printf("Введите путь до папки, в которой надо отсортировать файлы\n");
	gets_s(path, 200);
	strcat(path, "\\*.*");
	if ((hFile = _findfirst(path, &file)) == -1L)
		printf("Нет таких файлов в выбранной папке\n");
	else
	{
		printf("Список файлов\n\n");
		printf("FILE               SIZE\n");
		printf("----               ----\n");
		do {
			printf("%-12.12s  %10ld\n", file.name, file.size);
			massiv[size] = file;
			size++;
		} while (_findnext(hFile, &file) == 0);
		_findclose(hFile);

		while (sort != 0)
		{
			printf("\nОтсортировать по возрастанию - 1, по убыванию - 2\n");
			scanf_s("%d", &mode);
			printf("\nВыберите тип сортировки:\nСортировка Пузырьком 1\nСортировка Выбором 2\nСортировка Вставками 3\nСортировка Слиянием 4\nСортировка Хоара(Быстрая сортировка) 5\nСортировка Шелла 6\nСортировка подсчётом 7\n");
			scanf_s("%d", &tip);
			switch (tip)
			{
			case(1):
				t1 = clock();
				Puziryok(massiv, size);
				t2 = clock();
				sort = 0;
				break;
			case(2):
				t1 = clock();
				Vibor(massiv, size);
				t2 = clock();
				sort = 0;
				break;

			case(3):
				t1 = clock();
				Vstavka(massiv, size);
				t2 = clock();
				sort = 0;
				break;
			case(4):
				t1 = clock();
				Sliyanie(massiv, size);
				t2 = clock();
				sort = 0;
				break;
			case(5):
				t1 = clock();
				QuickSort(massiv, size);
				t2 = clock();
				sort = 0;
				break;
			case(6):
				t1 = clock();
				ShellSort(massiv, size);
				t2 = clock();
				sort = 0;
				break;
			case(7):
				t1 = clock();
				Podschyot(massiv, size, sortedMass);
				t2 = clock();
				sort = 0;
				break;
			}

			printf("\nКоличество файлов: %d\n", size);
			printf("FILE                SIZE\n");
			printf("----                ----\n");

			if (mode == 1)
				for (int i = 0; i < size; i++)
					printf("%-12.12s  %10ld\n", massiv[i].name, massiv[i].size);
			if (mode == 2)
				for (int i = size - 1; i >= 0; i--)
					printf("%-12.12s  %10ld\n", massiv[i].name, massiv[i].size);

			tt = (float)(t2 - t1) / CLOCKS_PER_SEC;
			printf("Время сортировки = %f\n", tt);
			printf("Хотите отсортировать ещё раз? да - 1, нет - 0\n");
			scanf_s("%d", &sort);
		}
	}
}