#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<conio.h>
int main(void)
{
	setlocale(LC_ALL, "Russian");
	srand(time(0));
	int x , r , z , l , n = 0 , A = 1 , B = 1000 , k = 0 , usl = 0;
	char zn = ' ';
	printf("���� �� ������ ������� �����-������� 1, ���� �� ������ �������� �����-������� 2 : ");
	scanf_s("%d", &r);
	if ((r != 1) && (r != 2))
	{
		printf("�� ������� �������������� �����\n");
	}
	else
	{
		switch (r) {
		case 1:
			printf("����,�� ������� 1 �����,��� ���������� ������� ����� �� 1 �� 1000\n");
			x = A + rand() % (B - A + 1);
			do
			{
				n = n + 1;
				printf("������� �������������� ����� : ");
				scanf_s("%d", &z);
				if (z < x) {
					printf("���������� ����� ������\n");
				}
				else {
					if (z > x) {
						printf("���������� ����� ������\n");
					}
					else {
						printf("���! �� ������� ����� c %d �������!\n", n);
					}
				}

			} while (x != z);
			break;
		case 2:
			printf("����,�� ������� 2 �����, ��������� ����� �� 1 �� 1000 : ");
			scanf_s("%d", &l);
			srand(time(0));
			while (usl != 1) {

				if (zn != '\n') {
					x = A + rand() % (B-A+1) ;
					k=k+1;
					printf("%d > (������) , < (������) ��� = (�����) ����������� �����?\n", x);
				}
				zn = getchar();

				if (zn == '<') {
					A = x+1;
				}
				if (zn == '>') {
					B =x-1;
				}
				
				if (zn == '=') {
					printf("���! ��������� ������� ����� � %d �������! \n", k);
					usl = 1;
				}
			}
			break;
		}
		
	}
		system("pause");
}