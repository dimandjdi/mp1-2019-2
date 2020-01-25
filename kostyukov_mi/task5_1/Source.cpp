#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  
#include <stdlib.h>  
#include <io.h>  
#include <time.h>
#include "Console.cpp"
#include <string.h>

_finddata_t files[10000];

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

void mergeSort(_finddata_t* files, long begin, long end)
{
	long split;
	if (begin < end)
	{
		split = (begin + end) / 2;
		mergeSort(files, begin, split);
		mergeSort(files, split + 1, end);
		merge(files, begin, split, end);
	}
}

long readfolder(char* path, _finddata_t* files)
{
	_finddata_t file;
	intptr_t hFile;
	long count = 0;
	if ((hFile = _findfirst(path, &file)) != -1L)
	{
		do
		{	
			//if (!(file.attrib & _A_SUBDIR))
			if (true)
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

void main(void)
{
	HideCursor();
	gotoxy(0, 0);
	char path[10000] ="c:\\temp\\*";
	while (true)
	{
		int len = readfolder(path, files);
		//mergeSort(files, 0, len-1);
		//countingSort(files, len);
		//insertSort(files, len);
		//shellSort(files, len);
		//quickSort(files, len);
		//selectSort(files, len);
		bubbleSort(files, len);
		if (len > 0)
		{
			printf("Listing of files\n\n");
			printf("FILE %30c DATE %24c   SIZE\n", ' ', ' ');
			printf("---- %30c ---- %24c   ----\n", ' ', ' ');
			for (int i = 0; i < len; i++)
			{
				char buffer[30];
				ctime_s(buffer, _countof(buffer), &files[i].time_write);
				if (i == 0)
				{
					textcolor(BLACK);
					textbackground(WHITE);
				}
				if (files[i].size > 0)
					printf("%-35.35s %.24s  %10lu \n", files[i].name, buffer, files[i].size);
				else
					printf("%-35.35s %.24s\n", files[i].name, buffer);
				textcolor(WHITE);
				textbackground(BLACK);
			}
			int state = 0;
			while (true)
			{
				char kb = 0;
				int state_changed = 0;
				if (_kbhit())
				{
					kb = _getch();
					if (kb == 13)
					{
						clrscr();
						char bf[1000] = "";
						strncpy(bf, path, strlen(path)-1);
						strcat(bf, files[state].name);
						strcat(bf, "\\*");
						strcpy(path, bf);
						break;
					}
					if (kb == 27)
					{
						clrscr();
						state = -1;
						break;
					}
					else
					{
						kb = _getch();
						if ((kb == 72) && (state > 0))
						{
							state--;
							state_changed = 1;
						}
						if ((kb == 80) && (state < len - 1))
						{
							state++;
							state_changed = -1;
						}
					}
				}
				if (state_changed != 0)
				{
					gotoxy(0, state + 4);
					textcolor(BLACK);
					textbackground(WHITE);
					char buffer[30];
					ctime_s(buffer, _countof(buffer), &files[state].time_write);
					if (files[state].size > 0)
						printf("%-35.35s %.24s  %10lu ", files[state].name, buffer, files[state].size);
					else
						printf("%-35.35s %.24s", files[state].name, buffer);
					textcolor(WHITE);
					textbackground(BLACK);
					gotoxy(0, state + state_changed + 4);
					ctime_s(buffer, _countof(buffer), &files[state + state_changed].time_write);
					if (files[state + state_changed].size > 0)
						printf("%-35.35s %.24s  %10lu ", files[state + state_changed].name, buffer, files[state + state_changed].size);
					else
						printf("%-35.35s %.24s ", files[state + state_changed].name, buffer);
					state_changed = 0;
				}
			}
			if (state == -1)
				break;
		}
		else
		{
			printf("Wrong path");
			break;
		}
	}
	printf("%s", path);
	_getch();
}

/*
void not_main(void)
{
	struct _finddata_t file;
	_finddata_t files[10000];
	intptr_t hFile;
	char path[200] = "c:\\users\\maxim\\downloads\\*";
	int count = 0;

	if ((hFile = _findfirst(path , &file)) == -1L)
		printf("No files in current directory!\n");
	else
	{

		do {

			if (count <= 60)
			{
				files[count] = file;
				if (file.size > 0)
					printf("%-35.35s %.24s  %10ld KB\n", file.name, buffer, file.size / 1024);
				else
					printf("%-35.35s %.24s\n", file.name, buffer);
			}
			count++;
		} while (_findnext(hFile, &file) == 0);
		_findclose(hFile);
		printf("\ncount of files: %d", count);
	}
	getchar();
}
*/