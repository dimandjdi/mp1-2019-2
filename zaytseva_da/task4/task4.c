#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>
#define l 5
int main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	int code[l] = { 1111, 2222, 3333, 4444, 5555 };
	int cena[l] = { 54, 60, 42, 20, 35 };
	int itog[l] = { 0 };
	int skidka[l] = { 0 };
	char fruct[5][20] = { {"Ïåðñèêè"}, {"Àáðèêîñû"}, {"Áàíàíû"}, {"ßáëîêè"}, {"Ãðóøè"} };
	int i, n, cash, number, end, skidos;
	int itogg = 0;
	int summ = 0;
	int summa[l] = { 0 };

	printf("Ïðèâåòñòâóåì Âàñ â ôðóêòîâîé ëàâêå!\nÂâåäèòå øòðèõêîä èç ïðåäñòàâëåííûõ íèæå:\n1111\n2222\n3333\n4444\n5555\nÅñëè Âû çàêîí÷èëè ñ ïîêóïêîé, ââåäèòå 0 âìåñòî øòðèõêîäà.\n");
	scanf_s("%i", &n);
	for (i = 0; i < l; i++)
	{
		skidka[i] = (rand() % 49 + 1);
	}
	while (n != 0)
	{
		while ((n != 0) && (n != code[1]) && (n != code[2]) && (n != code[3]) && (n != code[4]) && (n != code[0]))
		{
			printf("Ôðóêòîâ ñ òàêèì øòðèõêîäîì íåò â íàëè÷èè! Âèäèìî íå ñåçîí äëÿ íèõ. Ïîïðîáóéòå çàéòè ÷åðåç ïàðó íåäåëü èëè âûáðàòü äðóãîé ôðóêò :)\n");
			scanf_s("%i", &n);
		}
		for (i = 0; i < l; i++)
		{
			if (n == 0)
				break;
			else
				if (n == code[i])
				{
					printf("Ôðóêò: ");
					puts(fruct[i]);
					itog[i] = cena[i] * (100 - skidka[i]) / 100;
					printf("Öåíà çà 100ã ôðóêòà %i ðóá.\nÑêèäêà %i ïðîö.\nÖåíà ñ ó÷åòîì ñêèäêè %i ðóá.\n", cena[i], skidka[i], itog[i]);
					printf("Ââåäèòå â öåëûõ ñîòíÿõ ãðàììîâ âåñ ïîêóïàåìîãî ôðóêòà: ");
					scanf_s("%i", &number);
					summa[i] += number;
					printf("Ââåäèòå øòðèõêîä ñëåäóþùåãî ôðóêòà èëè 0.\n");
					scanf_s("%i", &n);
					break;
				}
		}
	}
	for (i = 0; i < l; i++)
	{
		itog[i] = summa[i] * (cena[i] * (100 - skidka[i]) / 100);
		summ += itog[i];
		itogg += summa[i] * cena[i];
	}
	skidos = itogg - summ;
	printf("*ÊÀÑÑÎÂÛÉ ×ÅÊ*\n");
	for (i = 0; i < l; i++)
	{
		if (summa[i] > 0)
		{
			puts(fruct[i]);
			printf("ÂÅÑ (Â ÑÎÒÍßÕ ÃÐÀÌÌÎÂ) %i,  ÑÓÌÌÀ %i ÐÓÁ.\n", summa[i], itog[i]);
		}
	}
	printf("ÑÒÎÈÌÎÑÒÜ ÒÎÂÀÐÎÂ Â ÏÎÊÓÏÊÅ %i ÐÓÁ.\nÑÓÌÌÀÐÍÀß ÑÊÈÄÊÀ %i ÐÓÁ.\nÈÒÎÃ %i ÐÓÁ.\n Ñïàñèáî çà ïîñåùåíèå íàøåé ôðóêòîâîé ëàâêè!\n Äà, ìû çíàåì, ÷òî êîôå-ýòî ôðóêò, íî òóò îí íå ïðîäàåòñÿ, à Âû ìîæåòå åãî ïîëó÷èòü áåñïëàòíî ïðè ñëåäóþùåé ïîêóïêå! \n(òîëüêî ïðè óñëîâèè ñîõðàíåíèÿ äàííîãî ÷åêà) ", itogg, skidos, summ);
	scanf_s("%i", &end);
}