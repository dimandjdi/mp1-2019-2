#include <math.h>
#include "Source2.h"
#include <string.h>

void mysin(long double* results, long long x, long double accruracy, long long n)
{
	long double referenceResult = sin(x);
	long double result = 0;
	long double delta = 0;
	long long factorial = 1;
	for (long long i = 1; i <= n; i++)
	{
		if (i % 2 == 0)
			result -= pow(x, 2 * i - 1) / factorial;
		else
			result += pow(x, 2 * i - 1) / factorial;

		delta = fabs(referenceResult - result);

		if (delta > accruracy)
		{
			n = i;
			break;
		}

		factorial *= (2 * i) * (2 * i + 1);
	}
	results[0] = result;
	results[1] = referenceResult;
	results[2] = delta;
	results[3] = n;
}

void mysin_s(long double* results, long double* deltas, long long x, long long NMax)
{
	long double referenceResult = sin(x);
	long double result = 0;
	long double delta;
	long double deltas[26];
	long long factorial = 1;
	for (long long i = 1; i <= NMax; i++)
	{
		if (i % 2 == 0)
			result -= pow(x, 2 * i - 1) / factorial;
		else
			result += pow(x, 2 * i - 1) / factorial;
		results[i] = result;
		delta = fabs(referenceResult - result);
		deltas[i] = delta;
		factorial *= (2 * i) * (2 * i + 1);
	}
}
void mycos(long double* results, long long x, long double accruracy, long long n)
{
	long double referenceResult = cos(x);
	long double result = 1;
	long double delta = 0;
	long long factorial = 2;
	for (long long i = 1; i <= n; i++)
	{
		if (i % 2 == 0)
			result += pow(x, 2 * i) / factorial;
		else
			result -= pow(x, 2 * i) / factorial;

		delta = fabs(referenceResult - result);

		if (delta > accruracy)
		{
			n = i;
			break;
		}

		factorial *= (2 * i + 1) * (2 * i + 2);
	}
	results[0] = result;
	results[1] = referenceResult;
	results[2] = delta;
	results[3] = n;
}

void mycos_s(long double* results, long double* deltas, long long x, long long NMax)
{
	long double referenceResult = cos(x);
	long double result = 1;
	long double results[26];
	long double delta;
	long double deltas[26];
	long long factorial = 2;
	for (long long i = 1; i <= NMax; i++)
	{
		if (i % 2 == 0)
			result += pow(x, 2 * i - 1) / factorial;
		else
			result -= pow(x, 2 * i - 1) / factorial;
		results[i] = result;
		delta = fabs(referenceResult - result);
		deltas[i] = delta;
		factorial *= (2 * i + 1) * (2 * i + 2);
	}
}

void myexp(long double* results, long long x, long double accruracy, long long n)
{
	long double referenceResult = exp(x);
	long double result = 1;
	long double delta = 0;
	long long factorial = 1;
	for (long long i = 1; i <= n; i++)
	{
		result += pow(x, i) / factorial;

		delta = fabs(referenceResult - result);

		if (delta > accruracy)
		{
			n = i;
			break;
		}

		factorial *= i;
	}

	results[0] = result;
	results[1] = referenceResult;
	results[2] = delta;
	results[3] = n;
}

void myexp_s(long double* results, long double* deltas, long long x, long long NMax)
{
	long double referenceResult = exp(x);
	long double result = 1;
	long double results[26];
	long double delta;
	long double deltas[26];
	long long factorial = 1;
	for (long long i = 1; i <= NMax; i++)
	{
		result += pow(x, i) / factorial;
		results[i] = result;
		delta = fabs(referenceResult - result);
		deltas[i] = delta;
		factorial *= i;
	}
}

void myth(long double* results, long long x, long double accruracy, long long n)
{
	long double referenceResult = tanh(x);
	long double result = 1;
	long double delta = 0;
	long long factorial = 1;
	for (long long i = 1; i <= n; i++)
	{
		result += pow(2,2*i)*(pow(2,2*i)-1)*pow(x, 2*i-1) / factorial;

		delta = fabs(referenceResult - result);

		if (delta > accruracy)
		{
			n = i;
			break;
		}

		factorial *= (2*i+1)*(2*i+2);
	}

	results[0] = result;
	results[1] = referenceResult;
	results[2] = delta;
	results[3] = n;
}

void myth_s(long double* results, long double* deltas, long long x, long long NMax)
{
	long double referenceResult = exp(x);
	long double result = 1;
	long double results[26];
	long double delta;
	long double deltas[26];
	long long factorial = 1;
	for (long long i = 1; i <= NMax; i++)
	{
		result += pow(2, 2 * i) * (pow(2, 2 * i) - 1) * pow(x, 2 * i - 1) / factorial;
		results[i] = result;
		delta = fabs(referenceResult - result);
		deltas[i] = delta;
		factorial *= (2 * i + 1) * (2 * i + 2);
	}
}