#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>  
#include <stdlib.h>  
#include <io.h>  
#include <time.h>  
#include <string.h>
#include <malloc.h>

_finddata_t *list = NULL;
void merge_f(_finddata_t *list, int a, int split, int b)
{
	int pos1 = a, pos2 = split + 1, pos3 = 0;

	_finddata_t *temp = (_finddata_t*)malloc((b - a + 1) * sizeof(_finddata_t));


	while (pos1 <= split && pos2 <= b) {
		if (list[pos1].size > list[pos2].size)
			temp[pos3++] = list[pos1++];
		else
			temp[pos3++] = list[pos2++];
	}
	while (pos2 <= b)
		temp[pos3++] = list[pos2++];
	while (pos1 <= split)
		temp[pos3++] = list[pos1++];

	for (pos3 = 0; pos3 < b - a + 1; pos3++)
		list[a + pos3] = temp[pos3];
	free(temp);
}
int increment(long inc[], int count)
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
	} while (3 * inc[s] < count);

	return s > 0 ? --s : 0;
}


void bubble(_finddata_t *list, int count)
{
	int i, j;
	_finddata_t smth;
	for (i = 0; i < count; i++)
		for (j = count - 1; j > i; j--)
			if (list[j - 1].size < list[j].size)
			{
				smth = list[j - 1];
				list[j - 1] = list[j];
				list[j] = smth;
			}

};

void selection(_finddata_t *list, int count)
{
	int i, j, c;
	_finddata_t smth;
	for (i = 0; i < count; i++)
	{
		smth = list[i];
		c = i;
		for (j = i + 1; j < count; j++)
			if (list[j].size > smth.size)
			{
				smth = list[j];
				c = j;
			}
		list[c] = list[i];
		list[i] = smth;
	}
}

void incertion(_finddata_t *list, int count)
{
	int i, j;
	_finddata_t smth;
	for (i = 0; i < count; i++)
	{
		smth = list[i];;
		for (j = i - 1; j >= 0 && list[j].size < smth.size; j--)
			list[j + 1] = list[j];
		list[j + 1] = smth;
	}
}

void merge(_finddata_t *list, int a, int b)
{
	int split;
	if (a < b) 
	{                
		split = (a + b) / 2;
		merge(list, a, split);       // сортировать левую половину 
		merge(list, split + 1, b);// сортировать правую половину 
		merge_f(list, a, split, b);    // слить результаты в общий массив
	}
}

void quick(_finddata_t *list, int N) 
{
	int i = 0, j = N - 1;
	_finddata_t temp, p;

	p = list[N >> 1];	

	
	do 
	{
		while (list[i].size > p.size) i++;
		while (list[j].size < p.size) j--;

		if (i <= j) 
		{
			temp = list[i]; 
			list[i] = list[j]; 
			list[j] = temp;
			i++; j--;
		}
	} while (i <= j);
 
	if (j > 0) quick(list, j+1);
	if (N > i) quick(list + i, N - i);
}

void shellsort(_finddata_t *list, int count) 
{
	long inc, i, j, seq[40];
	int s;

	s = increment(seq, count);
	while (s >= 0) {
		inc = seq[s--];

		for (i = inc; i < count; i++) 
		{
			_finddata_t temp = list[i];
			for (j = i - inc; (j >= 0) && (list[j].size < temp.size); j -= inc)
				list[j + inc] = list[j];
			list[j + inc] = temp;
		}
	}
}

void counting(_finddata_t *list, int count)
{
	long max = 0, i = 0;
	int c = 0, t;
	_finddata_t *files = (_finddata_t*)malloc(count * sizeof(_finddata_t));
	memcpy(files, list, count * sizeof(_finddata_t));
	for (int i = 0; i < count; i++)
	{
		if (list[i].size > max)
			max = list[i].size;
	}
	max++;
	int *C = (int*)malloc(max * sizeof(int));
	memset(C, 0, max * sizeof(int));
	for (i = 0; i < count; i++)
	{
		C[list[i].size]++;
	}
	for (i = max-1; i > -1; i--)
	{
		t = C[i];
		C[i] = c;
		c += t;
	}
	for (i = 0; i < count; i++)
	{
		files[C[list[i].size]] = list[i];
		C[list[i].size]++;
	}
	memmove(list, files, count * sizeof(_finddata_t));
	free(C);
	free(files);
}


int main(void)
{
	while(true)
	{
		struct _finddata_t c_file;
		intptr_t hFile;
		char path[200];
		int count = 0, i, sw;
		char answer;
		clock_t start, finish;

		printf("Select a folder: ");
		scanf("%s", &path);
		strcat(path, "/*.*");


		if ((hFile = _findfirst(path, &c_file)) == -1L)
			printf("No *.c files in current directory!\n");
		else
		{	//Считаю кол-во файлов и определяю размер массива
			do { count++; } while (_findnext(hFile, &c_file) == 0);
			list = (_finddata64i32_t *)malloc(count * sizeof(c_file));
			count = 0;
			hFile = _findfirst(path, &c_file);

			//Вывод файлов на экран и заполнение массива
			printf("Listing of .c files\n\n");
			printf("FILE         DATE %24c   SIZE\n", ' ');
			printf("----         ---- %24c   ----\n", ' ');
			do {
				list[count] = c_file;
				char buffer[30];
				ctime_s(buffer, _countof(buffer), &c_file.time_write);
				printf("%-12.12s    %.24s     %10ld\n", c_file.name, buffer, c_file.size);
				count++;
			} while (_findnext(hFile, &c_file) == 0);
			_findclose(hFile);
			printf("\ncount of files: %d\n\n\n", count);
		}


		printf("\n\nChoose the type of sorting: \n1)Bubble sort \n2)Selection sort \n3)Insertion sort \n4)Merge sort \n5)Hoare(quick) sort \n6)Shellsort \n7)Counting sort \n");
		scanf_s("%i", &sw);
		start = clock();
		switch (sw)
		{
		case 1: //Пузырьком
			bubble(list, count);
			break;
		case 2: //Выбором
			selection(list, count);
			break;
		case 3: //Вставками
			incertion(list, count);
			break;
		case 4: //Слиянием
			merge(list, 0, count);
			break;
		case 5: //Хоара
			quick(list, count);
			break;
		case 6: //Шелла
			shellsort(list, count);
			break;
		case 7: //Подсчетом
			counting(list, count);
			break;
		};


		finish = clock();
		for (i = 0; i < count; i++)
			printf("%-12.12s      %10ld\n", list[i].name, list[i].size);
		printf(" %f ms\n", ((double)(finish - start)));
		printf("\ntry again? Y/N\n");
		getchar();
		scanf_s("%c", &answer);
		if (answer == 'N') break;
	}

}