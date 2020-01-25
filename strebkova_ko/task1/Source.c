#include <stdio.h>
#include <math.h>
#include <locale.h>
const double pWood = 640;
const double pDSP = 650;
const double pDVP = 850;
double okrugl(double M, int s)
{
	M = round(M * pow(10, s)) / pow(10, s);
	return M;
}
double diapason (int down, int up, int k)
{
	double parametr = 0;
	while ((parametr < down) || (parametr > up))
	{
		switch (k)
		{
		    case 1: printf("������� ������ �� 180 �� 220 ��: ");
			    break;
		    case 2: printf("������� ������ �� 80 �� 120 ��: ");
			    break;
		    case 3: printf("������� ������� �� 50 �� 90 ��: ");
			    break;
		}
		scanf_s("%lf", &parametr);
		if ((parametr < down) || (parametr > up))
			printf("����� �� ���������\n");
	}
	return parametr;
}
void main()
{
	double h, w, d, mBWalls, mWalls, mCapps, mShelfs, mDoors, M;
	int s, output;
	setlocale(LC_ALL, "Rus");
	h = diapason(180, 220, 1);
	w = diapason(80, 120, 2);
	d = diapason(50, 90, 3);
	// ����� ������ ������
	mBWalls = pDVP * h * 0.01 * w * 0.01 * 0.005;
	// ����� �������
	mWalls = 2 * h * 0.01 * d * 0.01 * 0.015 * pDSP;
	// ����� ������
	mCapps = 2 * d * 0.01 * (w - 3) * 0.01 * 0.015 * pDSP;
	// ����� ������
	mDoors = h * 0.01 * w * 0.01 * 0.01 *pWood;
	int n = (h - 3) / 41.5;
	// ����� n �����
	mShelfs = n * (w - 3)* 0.01 * d * 0.01 * 0.015 * pDSP;
	M = mBWalls + mWalls + mCapps + mDoors + mShelfs;
	printf("�������� ��������������� ����:\n");
	printf("1)����� ����� ����� ������\n");
	printf("2)����� ����� ������������ ������\n");
	printf("3)����� ����� ������������ ������ � �����������\n");
	scanf_s("%d", &output);
	switch (output)
	{
	case 1:
		printf("%d (��)\n", (int)M);
		break;
	case 2:
		printf("%lf (��)\n", M);
		break;
	case 3:
	{
		printf("������� ����� �����, �� �������� ��������� ��������� ����� : ");
		scanf_s("%d", &s);
		printf("%lf (��)\n", okrugl(M, s));
		break;
	}
	default:
		printf("������ ������\n");
	}
	system("pause");
}

