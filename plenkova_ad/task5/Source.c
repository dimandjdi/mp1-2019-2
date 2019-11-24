#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  
#include <locale.h>
#include <stdlib.h>  
#include <io.h>  
#include <time.h> 
#include <string.h>
void Puziryok(int massiv[], int size)
{
	int i, j, temp;
	for (i = 0; i < size; i++)
	{
		for (j = size - 1; j > i; j--)
		{
			if (massiv[j - 1] > massiv[j])
			{
				temp = massiv[j - 1];
				massiv[j - 1] = massiv[j];
				massiv[j] = temp;
			}
		}
	}
}
void Vibor(int massiv[], int size)
{
	int i, j, k, x;
	for (i = 0; i < size; i++)
	{   	// i - номер текущего шага
		k = i;
		x = massiv[i];

		for (j = i + 1; j < size; j++)	// цикл выбора наименьшего элемента
			if (massiv[j] < x)
			{
				k = j; x = massiv[j];	        // k - индекс наименьшего элемента
			}

		massiv[k] = massiv[i];
		massiv[i] = x;   	// меняем местами наименьший с a[i]
	}
}
void Vstavka(int massiv[], int size) // сортировка вставками
{
	int x, j; // временная переменная для хранения значения элемента сортируемого массива
		 // индекс предыдущего элемента
	for (int i = 1; i < size; i++)
	{
		x = massiv[i]; // инициализируем временную переменную текущим значением элемента массива
		j = i - 1; // запоминаем индекс предыдущего элемента массива
		while (j >= 0 && massiv[j] > x) // пока индекс не равен 0 и предыдущий элемент массива больше текущего
		{
			massiv[j + 1] = massiv[j]; // перестановка элементов массива
			massiv[j] = x;
			j--;
		}
	}
}
void Sliyanie(int massiv[], long size)
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
				if (massiv[i] <= massiv[j])
				{
					b[m] = massiv[i]; i++;
				}
				else
				{
					b[m] = massiv[j]; j++;
				}
				m++;
			}
			while (i < rght)
			{
				b[m] = massiv[i];
				i++; m++;
			}
			while (j < rend)
			{
				b[m] = massiv[j];
				j++; m++;
			}
			for (m = left; m < rend; m++)
			{
				massiv[m] = b[m];
			}
		}
	}
	for (int i = 0; i < size; i++)
		massiv[i] = b[i];

}
void QuickSort(int* massiv, int left, int right)
{
	int pivot; // разрешающий элемент
	int l_hold = left; //левая граница
	int r_hold = right; // правая граница
	pivot = massiv[left];
	while (left < right) // пока границы не сомкнутся
	{
		while ((massiv[right] >= pivot) && (left < right))
			right--; // сдвигаем правую границу пока элемент [right] больше [pivot]
		if (left != right) // если границы не сомкнулись
		{
			massiv[left] = massiv[right]; // перемещаем элемент [right] на место разрешающего
			left++; // сдвигаем левую границу вправо
		}
		while ((massiv[left] <= pivot) && (left < right))
			left++; // сдвигаем левую границу пока элемент [left] меньше [pivot]
		if (left != right) // если границы не сомкнулись
		{
			massiv[right] = massiv[left]; // перемещаем элемент [left] на место [right]
			right--; // сдвигаем правую границу вправо
		}
	}
	massiv[left] = pivot; // ставим разрешающий элемент на место
	pivot = left;
	left = l_hold;
	right = r_hold;
	if (left < pivot) // Рекурсивно вызываем сортировку для левой и правой части массива
		QuickSort(massiv, left, pivot - 1);
	if (right > pivot)
		QuickSort(massiv, pivot + 1, right);
}
int increment(int inc[], int size) {
	// inc[] массив, в который заносятся инкременты
	// size размерность этого массива
	int p1, p2, p3, s;

	p1 = p2 = p3 = 1;
	s = -1;
	do {// заполняем массив элементов по формуле Роберта Седжвика
		if (++s % 2) {
			inc[s] = 8 * p1 - 6 * p2 + 1;
		}
		else {
			inc[s] = 9 * p1 - 9 * p3 + 1;
			p2 *= 2;
			p3 *= 2;
		}
		p1 *= 2;
		// заполняем массив, пока текущая инкремента хотя бы в 3 раза меньше количества элементов в массиве
	} while (3 * inc[s] < size);

	return s > 0 ? --s : 0;// возвращаем количество элементов в массиве
}
template<class T>
void shellSort(T massiv[], long size) {
	// inc инкремент, расстояние между элементами сравнения
	// i и j стандартные переменные цикла
	// seq[40] массив, в котором хранятся инкременты
	int inc, i, j, seq[40];
	int s;//количество элементов в массиве seq[40]

	// вычисление последовательности приращений
	s = increment(seq, size);
	while (s >= 0) {
		//извлекаем из массива очередную инкременту
		inc = seq[s--];
		// сортировка вставками с инкрементами inc
		for (i = inc; i < size; i++) {
			T temp = massiv[i];
			// сдвигаем элементы до тех пор, пока не дойдем до конца или не упорядочим в нужном порядке
			for (j = i - inc; (j >= 0) && (massiv[j] > temp); j -= inc)
				massiv[j + inc] = massiv[j];
			// после всех сдвигов ставим на место j+inc элемент, который находился на i месте
			massiv[j + inc] = temp;
		}
	}
}
void Podschyot(int massiv[], int size, int sortedMass[])
{
	for (int i = 0; i < size; i++)
	{
		int k = 0;
		for (int j = 0; j < size; j++)
		{
			if (massiv[i] > massiv[j])
				k++;
		}
		sortedMass[i] = massiv[k];
	}
	
		
}

int main(void)
{
	setlocale(LC_ALL, "rus");
	struct _finddata_t c_file;
	intptr_t hFile;
	char path[200];
	int size = 0;
	int sortedMass[100] = { 0 };
	int massiv[100];
	char name[100][100];
	int tip, mode, i = 0, sort = 1;
	double tt;
	clock_t t1, t2;
	// Find first .c file in directory c:\temp
	printf("Введите путь до папки, в которой надо отсортировать файлы\n");
	gets_s(path);
	strcat(path, "\\*.*");
	if ((hFile = _findfirst(path, &c_file)) == -1L)
		printf("No files in current directory!\n");
	else
	{
		printf("Listing of files\n\n");
		printf("FILE               SIZE\n");
		printf("----               ----\n");
		do {
			printf("%-12.12s  %10ld\n", c_file.name, c_file.size);
			strcpy(name[size], c_file.name);
			massiv[size] = c_file.size;
			size++;
		} while (_findnext(hFile, &c_file) == 0);
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
				QuickSort(massiv, 0, size - 1);
				t2 = clock();
				sort = 0;
				break;
			case(6):
				t1 = clock();
				shellSort(massiv, size);
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

			printf("\ncount of files: %d\n", size);
			printf("FILE               SIZE\n");
			printf("----               ----\n");

			if (mode == 1)
				for (int i = 0; i < size; i++)
					printf("%-12.12s  %10ld\n", name[i], massiv[i]);
			if (mode == 2)
				for (int i = size - 1; i >= 0; i--)
					printf("%-12.12s  %10ld\n", name[i], massiv[i]);

			tt = (t2 - t1) / CLOCKS_PER_SEC;
			printf("Время сортировки = %lf\n", tt);
			printf("Хотите отсортировать ещё раз? да - 1, нет - 0\n");
			scanf_s("%d", &sort);
		}
	}
}