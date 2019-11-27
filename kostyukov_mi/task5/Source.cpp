#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  
#include <stdlib.h>  
#include <io.h>  
#include <time.h>
#include <conio.h>
#include "Console.cpp"
#include "FileSorts.cpp"
#include <string.h>

_finddata_t files[10000];
int size;

long readfolder(char* path, _finddata_t* files)
{
	_finddata_t file;
	intptr_t hFile;
	long count = 0;
	if ((hFile = _findfirst(path, &file)) != -1L)
	{
		do
		{	
			if (!(file.attrib & _A_SUBDIR))
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
void printFiles(_finddata_t* files, long size)
{
	printf("\nENTER - отсортировать файлы по размеру\nESC - ввести путь\n");
	printf("FILE %30c DATE %24c   SIZE\n", ' ', ' ');
	printf("---- %30c ---- %24c   ----\n", ' ', ' ');
	for (int i = 0; i < size; i++)
	{
		char buffer[30];
		ctime_s(buffer, _countof(buffer), &files[i].time_write);
		if (files[i].size > 0)
			printf("%-35.35s %.24s  %10lu \n", files[i].name, buffer, files[i].size);
		else
			printf("%-35.35s %.24s\n", files[i].name, buffer);
	}
}

int sortFiles(int menustate)
{
	Sorts[menustate](files, size);
	printFiles(files, size);
	return 1;
}

void chooseSort()
{
	MenuElement menuSort[] = {
		{"Сортировка пузырьком" , sortFiles},
		{"Сортировка выбором" , sortFiles},
		{"Сортировка вставками" , sortFiles},
		{"Сортировка слиянием " , sortFiles},
		{"Сортировка Хоара(quick sort)" , sortFiles},
		{"Сортировка Шелла" , sortFiles},
		{"Сортировка подсчетом" , sortFiles},
	};
	Switcher(menuSort, 7);
}

void main(void)
{
	setlocale(LC_ALL, "Rus");
	HideCursor();
	gotoxy(0, 0);
	char path[10000] ="c:\\temp\\*";
	char input[10000];
	while (true)
	{
		printf("Введите путь(Введите '..', чтобы выйти)\n");
		scanf("%s", path);
		if (!(strcmp(path, "..")))
			break;
		strcat(path, "*");
		clrscr();
		size = readfolder(path, files);
		if (size > 0)
		{
			printFiles(files, size);
			while (true)
			{
				char kb = 0;
				if (_kbhit())
				{
					kb = _getch();
					if (kb == 13)
					{
						clrscr();
						size = readfolder(path, files);
						chooseSort();
					}
					if (kb == 27)
					{
						clrscr();
						break;
					}
				}
			}
		}
		else
		{
			printf("Папка пуста или имеет неправильный путь\nESC - ввести путь заново");
			char kb = 0;
			while (true)
				if (_kbhit())
				{
					kb = _getch();
					if (kb == 27)
						break;
				}
		}
	}
}