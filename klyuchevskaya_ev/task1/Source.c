#include <stdio.h>
#include <locale.h>
#include <math.h>
int main(void) 
{
	setlocale(LC_ALL, "Russian");
	const double pder = 0.67;          // ��-�� ������ � �/��^3
	const double pdvp = 0.85;         //  ��-�� ��� � �/��^3
	const double pdsp = 0.80;        //   ��-�� ��� � �/��^3
	double zst , bok , krvn , door , shelfs , N , M;
	float h , w , d;
	printf ("������� ������ ����� (�� 180 �� 220 ��): ");
	scanf_s ("%f" , & h);
	printf ("������� ������ ����� (�� 80 �� 120 ��) : ");
	scanf_s ("%f" , & w);
	printf ("������� ������� ����� (�� 50 �� 90 ��) : ");
	scanf_s ("%f" , & d);
	if ((( h >= 180 ) && ( h <= 220 )) && (( w >= 80 ) && ( w <= 120 )) && (( d >= 50 ) && ( d <= 90 )))
	{
		N = floor((h-2*1.5) / 41.5);                                    //���������� ����� � �����
		zst = h * w * 0.5 * pdvp;                                      //����� ������ ������ � �
		bok = 2 * h * d * 1.5 * pdsp;                                 //����� ���� ������� ������ � �
		krvn = 2 * w * d * 1.5 * pdsp;                               //����� ������� � ������ ������ � �
		door = h * w * 1 * pder;                                    //����� ������ � �
		shelfs = N * (w - 3) * d * 1.5 * pdsp;                       //����� ����� � �
		M = (zst + bok + krvn + door + shelfs)/1000;              //����� ����� � ��
		printf("����� ����� = %.2f " , M);
		printf("�� \n");
	}
	else {
		printf("�� ����� �������� ������, ��������� ������� ����� \n");
	}
	system("pause");
	return 0;

}