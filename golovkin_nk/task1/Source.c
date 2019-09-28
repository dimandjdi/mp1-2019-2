#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <conio.h>

const double DSP = 0.00075;
const double DVP = 0.00085;
const double WOOD = 0.00051;

double vvod(int min, int max, int count)
{
	double value;

	do
	{
		switch (count)
		{
		    case 1:
		    {
			    printf("Введите высоту от %d до %d см: ", min, max);
			    break;
		    }
		    case 2:
		    {
			    printf("Введите ширину от %d до %d см: ", min, max);
			    break;
		    }
		    case 3:
		    {
			    printf("Введите глубину от %d до %d см: ", min, max);
			    break;
		    }
		}
		scanf_s("%lf", &value);

		if ((value < min) || (value > max))
		{
			printf("Не удовлетворяет диапазону \n");
		}

	} while ((value < min) || (value > max));

	return value;
}
void main()
{
	setlocale(LC_ALL, "rus");



	double h, w, d, m, x;

	h = vvod(180, 220, 1);
	w = vvod(80, 120, 2);
	d = vvod(50, 90, 3);

	x = (h - 3) / 41.5;
	m = h * w * 0.5 * DVP + 2 * h * d * 1.5 * DSP + w * d * 1.5 * 2 * DSP + h * w * 1 * WOOD + x * (w - 3) * 1.5 * d * DSP;

	printf("Масса шкафа: %.2lf (кг)\n", m);
	system("pause");
}
