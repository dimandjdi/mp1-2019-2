#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>  
#include <conio.h>
#include <stdlib.h>  
#include <io.h>  
#include <time.h>  
#include <string.h>
#include <locale.h>

#define MAX_FILES 4550

void print_size(int count, long size[MAX_FILES], char* names[MAX_FILES]);
void bubbleSort(int count, long size[MAX_FILES], char* names[MAX_FILES]);
void selectSort(int count, long size[MAX_FILES], char* names[MAX_FILES]);
void insertSort(int count, long size[MAX_FILES], char* names[MAX_FILES]);
void mergeSort(long size[MAX_FILES], char* names[MAX_FILES], int lb, int ub);
void quickSortR(int count, long size[MAX_FILES], char* names[MAX_FILES]);
void shellSort(int count, long size[MAX_FILES], char* names[MAX_FILES]);
void countingSort(int count, long size[MAX_FILES], char* names[MAX_FILES]);

int main(void)
{
	setlocale(2, "Rus");

	struct _finddata_t c_file;
	intptr_t hFile;
	char path[200];
	int count = 0;
	long size[MAX_FILES];
	char* names[MAX_FILES];
	printf("Введите путь до директории: ");
	gets_s(path);
    strcat(path, "*");

	if ((hFile = _findfirst(path, &c_file)) == -1L)
		printf("No files in current directory!\n");
	else
	{
		do
		{
			if (c_file.name[0] == '.') // Убираем файлы '.', '..'
				continue;

			size[count] = c_file.size;
			names[count] = (char*)malloc(strlen(c_file.name) + 1); // Выделили место под название файла
			strcpy(names[count], c_file.name); // Скопировали название файла

			count++;

			if (count == MAX_FILES)
				break;
		} while (_findnext(hFile, &c_file) == 0);
		_findclose(hFile);

		int q;
		printf("Сортировки:\n1 bubbleSort\n2 selectSort\n3 incertSort\n4 mergeSort\n5 quickSortR\n6 shellSort\n7 countingSort\n");
		printf("Выберите метод сортировки: ");
		scanf_s("%d", &q);

		print_size(count, size, names); // Порядок до сортировки
		clock_t begin = clock();

		switch (q)
		{
		case 1:
			bubbleSort(count, size, names);
			break;
		case 2:
			selectSort(count, size, names);
			break;
		case 3:
			insertSort(count, size, names);
			break;
		case 4:
			mergeSort(size, names, 0, count - 1);
			break;
		case 5:
			quickSortR(count, size, names);
			break;
		case 6:
			shellSort(count, size, names);
			break;
		case 7:
			countingSort(count, size, names);
			break;
		default:
			printf("Неверный номер алгоритма\n");
			system("pause");
			return 0;
		}

		clock_t end = clock();
		double timeSpent = (double)(end - begin) / CLOCKS_PER_SEC;

		printf("\nВремя работы сортировки: %.3lf sec\n", timeSpent);

		print_size(count, size, names); // Порядок после сортировки
	}
	system("pause");
}

void print_size(int count, long size[MAX_FILES], char* names[MAX_FILES])
{
	printf("\ncount of files: %d\n", count);
	printf("FILE                 SIZE\n");
	printf("----                 ----\n");
	for (int i = 0; i < count; i++)
	{
		printf("%-12.12s    %10ld\n", names[i], size[i]);
	}
}

void bubbleSort(int count, long size[MAX_FILES], char* names[MAX_FILES])
{
	long i, j;
	long x1;
	char* x2;

	for (i = 0; i < count; i++) 
	{            
		for (j = count - 1; j > i; j--)     
		{
			if (size[j - 1] > size[j])    
			{
				x1 = size[j - 1];
				size[j - 1] = size[j];
				size[j] = x1;

				x2 = names[j - 1];
				names[j - 1] = names[j];
				names[j] = x2;
			}
		}
	}
}

void selectSort(int count, long size[MAX_FILES], char* names[MAX_FILES])
{
	long i, j, k;
	long x1;
	char* x2;

	for (i = 0; i < count; i++) 
	{
		k = i;
		x1 = size[i];
		x2 = names[i];

		for (j = i + 1; j < count; j++)
			if (size[j] < x1)
			{
				k = j;  
				x1 = size[j];
				x2 = names[j];
			}

		size[k] = size[i];
		size[i] = x1;   	

		names[k] = names[i];
		names[i] = x2;
	}
}

void insertSort(int count, long size[MAX_FILES], char* names[MAX_FILES])
{
	long i, j;
	long x1;
	char* x2;

	for (i = 0; i < count; i++)   
	{
		x1 = size[i];
		x2 = names[i];

		for (j = i - 1; j >= 0 && size[j] > x1; j--)
		{
			size[j + 1] = size[j];  	
			names[j + 1] = names[j];
		}

		size[j + 1] = x1;
		names[j + 1] = x2;
	}
}

void merge(long size[MAX_FILES], char* names[MAX_FILES], int lb, int split, int ub)
{
	long pos1 = lb;
	long pos2 = split + 1;
	long pos3 = 0;

	long* temp1 = new long[ub - lb + 1];
	char** temp2 = new char*[ub - lb + 1];

	while (pos1 <= split && pos2 <= ub)
	{
		if (size[pos1] < size[pos2])
		{
			temp1[pos3] = size[pos1];
			temp2[pos3++] = names[pos1++];
		}
		else
		{
			temp1[pos3] = size[pos2];
			temp2[pos3++] = names[pos2++];
		}
	}
	while (pos2 <= ub)   
	{
		temp1[pos3] = size[pos2];
		temp2[pos3++] = names[pos2++];
	}
	while (pos1 <= split) 
	{
		temp1[pos3] = size[pos1];
		temp2[pos3++] = names[pos1++];
	}
	for (pos3 = 0; pos3 < ub - lb + 1; pos3++)
	{
		size[lb + pos3] = temp1[pos3];
		names[lb + pos3] = temp2[pos3];
	}
	delete[] temp1;
	delete[] temp2;
}

void mergeSort(long size[MAX_FILES], char* names[MAX_FILES], int lb, int ub)
{
	long split;                  

	if (lb < ub) 
	{

		split = (lb + ub) / 2;

		mergeSort(size, names, lb, split);        
		mergeSort(size, names, split + 1, ub); 
		merge(size, names, lb, split, ub);    
	}
}

void quickSortR(int count, long size[MAX_FILES], char* names[MAX_FILES])
{
	long i = 0, j = count - 1; 		
	long temp1, p;
	char* temp2;

	p = size[count >> 1];		

	do
	{
		while (size[i] < p) i++;
		while (size[j] > p) j--;

		if (i <= j)
		{
			temp1 = size[i];
			size[i] = size[j];
			size[j] = temp1;

			temp2 = names[i];
			names[i] = names[j];
			names[j] = temp2;
			i++;
			j--;
		}
	} while (i <= j);

	if (j > 0) quickSortR(j, size, names);
	if (count > i) quickSortR(count - i, size + i, names + i);
}

int increment(long inc[], long size)
{
	int p1, p2, p3, s;

	p1 = p2 = p3 = 1;
	s = -1;
	do
	{
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

void shellSort(int count, long size[MAX_FILES], char* names[MAX_FILES])
{
	long inc, i, j, seq[40];
	int s;

	s = increment(seq, count);
	while (s >= 0)
	{
		inc = seq[s--];

		for (i = inc; i < count; i++)
		{
			long temp1 = size[i];
			char* temp2 = names[i];
			for (j = i - inc; (j >= 0) && (size[j] > temp1); j -= inc)
			{
				size[j + inc] = size[j];
				names[j + inc] = names[j];
			}
			size[j + inc] = temp1;
			names[j + inc] = temp2;
		}
	}
}

void countingSort(int count, long size[MAX_FILES], char* names[MAX_FILES])
{
	const int k = 900000;  // Максимальный размер файла
	int* c = new int[k];

	for (int i = 0; i < k; i++)
	{
		c[i] = 0;
	}
	long* size1 = new long[count];
	for (int i = 0; i < count; i++)
	{
		size1[i] = size[i];
	}
	char** names1 = new char*[count];
	for (int i = 0; i < count; i++)
	{
		names1[i] = names[i];
	}

	for (int i = 0; i < count; i++)
	{
		c[size[i]]++;
	}

	int b = 0;
	for (int i = 0; i < k; i++)
	{
		int t = 0;
		for (int j = 0; j < c[i]; j++)
		{
			size[b] = i;
			for (; t < count; t++)
			{
				if (size1[t] == i)
				{
					names[b] = names1[t];
				}
			}
			b++;
		}
	}
	delete[] c;
	delete[] size1;
}