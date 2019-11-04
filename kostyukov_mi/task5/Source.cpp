#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>

class vector
{
private:
		long long pos;
		long long size;
		int* arr;
public:
	vector(int s)
	{
		size = s;
		pos = 0;
		arr = (int*)malloc(size * sizeof(int));
	}
	~vector()
	{
		free(arr);
	}
	int get(int i)
	{
		if (i < pos)
			return arr[i];
		else
			return 0;
	}
	void resize()
	{
		int* buf = (int*)malloc(size * sizeof(int));
		for (int i = 0; i < pos; i++) buf[i] = arr[i];
		free(arr);
		size *= 2;
		arr = (int*)malloc(size * sizeof(int));
		for (int i = 0; i < pos; i++) arr[i] = buf[i];
		free(buf);
	}
	void push_back(int el)
	{
		if (pos >= size) resize();
		arr[pos++] = el;
	}
};

int main()
{
	int t = time(NULL);
	vector v(1000000005);
	for (int i = 1; i <= 10e9; i++)
	{
		v.push_back(1);
	}
	t = time(NULL) - t;
	printf("%d\n", t);
	getchar();
}
