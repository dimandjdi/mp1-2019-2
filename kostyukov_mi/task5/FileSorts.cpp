#include <stdio.h>  
#include <stdlib.h>  
#include <io.h>  
#include <time.h>
#include <string.h>

void bubbleSort(_finddata_t* files, long size)
{
	long i, j;
	_finddata_t temp;

	for (i = 0; i < size; i++)
		for (j = size - 1; j > i; j--)
			if (files[j - 1].size > files[j].size)
			{
				temp = files[j - 1];
				files[j - 1] = files[j];
				files[j] = temp;
			}
}

void selectSort(_finddata_t* files, long size)
{
	long i, j, k;
	_finddata_t temp;

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

void quickSort(_finddata_t* files, long N)
{
	long i = 0, j = N - 1;
	unsigned long p;
	_finddata_t temp;

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
	if (j > 0) quickSort(files, j);
	if (N > i) quickSort(files + i, N - i);
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
void shellSort(_finddata_t* files, long size)
{
	long inc, i, j, seq[40];
	int s;
	s = increment(seq, size);
	while (s >= 0)
	{
		inc = seq[s--];
		for (i = inc; i < size; i++)
		{
			_finddata_t temp = files[i];
			for (j = i - inc; (j >= 0) && (files[j].size > temp.size); j -= inc)
				files[j + inc] = files[j];
			files[j + inc] = temp;
		}
	}
}

void insertSort(_finddata_t* files, long n)
{
	long i, j;
	_finddata_t temp;

	for (i = 0; i < n; i++)
	{
		temp = files[i];
		for (j = i - 1; j >= 0 && files[j].size > temp.size; j--)
			files[j + 1] = files[j];
		files[j + 1] = temp;
	}
}

void countingSort(_finddata_t* files, long n)
{
	long max = 0;
	long i = 0;
	_finddata_t* sortedfiles = (_finddata_t*)malloc(n * sizeof(_finddata_t));
	memcpy(sortedfiles, files, n * sizeof(_finddata_t));
	for (int i = 0; i < n; i++)
	{
		if (files[i].size > max)
			max = files[i].size;
	}
	max++;
	int* C = (int*)malloc(max * sizeof(int));
	memset(C, 0, max * sizeof(int));
	for (i = 0; i < n; i++)
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
	for (i = 0; i < n; i++)
	{
		sortedfiles[C[files[i].size]] = files[i];
		C[files[i].size]++;
	}
	memmove(files, sortedfiles, n * sizeof(_finddata_t));
	free(C);
	free(sortedfiles);
}

void merge(_finddata_t* files, long begin, long split, long end)
{
	long pos1 = begin, pos2 = split + 1, pos3 = 0;
	_finddata_t* temp = (_finddata_t*)malloc((end - begin + 1) * sizeof(_finddata_t));
	while ((pos1 <= split) && (pos2 <= end))
	{
		if (files[pos1].size < files[pos2].size)
			temp[pos3++] = files[pos1++];
		else
			temp[pos3++] = files[pos2++];
	}
	while (pos2 <= end)
		temp[pos3++] = files[pos2++];
	while (pos1 <= split)
		temp[pos3++] = files[pos1++];

	for (pos3 = 0; pos3 < end - begin + 1; pos3++)
	{
		files[begin + pos3] = temp[pos3];
	}
	free(temp);
}

void _mergeSort(_finddata_t* files, long begin, long end)
{
	long split;
	if (begin < end)
	{
		split = (begin + end) / 2;
		_mergeSort(files, begin, split);
		_mergeSort(files, split + 1, end);
		merge(files, begin, split, end);
	}
}

void mergeSort(_finddata_t* files, long size)
{
	_mergeSort(files, 0, size - 1);
}

void(*Sorts[7])(_finddata_t* files, long len) = {
	bubbleSort,
	selectSort,
	insertSort,
	mergeSort,
	quickSort,
	shellSort,
	countingSort,
};