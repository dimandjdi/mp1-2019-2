#include <math.h>
#include "Source2.h"
#include <string.h>

void mysin(long double* results, long double x, long double accruracy, long long n)
{
	long double refres = sin(x);
	long double res = x;
	long double delta = 0;
	long double buffer = x;
	for (long long i = 2; i <= n; i++)
	{

		buffer *= (-1) * (x * x) / ((2 * i - 2) * (2 * i - 1));

		res += buffer;

		delta = fabs(refres - res);

		if (delta < accruracy)
		{
			n = i;
			break;
		}
	}
	results[0] = res;
	results[1] = refres;
	results[2] = delta;
	results[3] = n;
}

void mysin_s(long double* results, long double* deltas, long double x, long long NMax)
{
	long double refres = sin(x);
	long double res = x;
	results[1] = x;
	long double delta;
	deltas[1] = fabs(x - refres);
	long double buff = x;
	for (long long i = 2; i <= NMax; i++)
	{
		buff *= (-1) * (x * x) / ((2 * i - 2) * (2 * i - 1));

		res += buff;

		results[i] = res;
		delta = fabs(refres - res);
		deltas[i] = delta;
	}
}
void mycos(long double* results, long double x, long double accruracy, long long n)
{
	long double refres = cos(x);
	long double res = 1;
	long double delta = 0;
	long double buffer = 1;
	for (long long i = 2; i <= n; i++)
	{
		buffer *= (-1) * (x * x) / ((2 * i - 3) * (2 * i - 2));

		res += buffer;

		delta = fabs(refres - res);

		if (delta < accruracy)
		{
			n = i;
			break;
		}
	}
	results[0] = res;
	results[1] = refres;
	results[2] = delta;
	results[3] = n;
}

void mycos_s(long double* results, long double* deltas, long double x, long long NMax)
{
	long double refres = cos(x);
	long double res = 1;
	results[1] = 1;
	long double delta;
	deltas[1] = 1 - refres;
	long double buffer = 1;
	for (long long i = 2; i <= NMax; i++)
	{
		buffer *= (-1) * (x * x) / ((2 * i - 3) * (2 * i - 2));

		res += buffer;

		results[i] = res;
		delta = fabs(refres - res);
		deltas[i] = delta;
	}
}

void myexp(long double* results, long double x, long double accruracy, long long n)
{
	double refres = exp(x);
	long double buffer = 1;
	long double res = 1;
	long double delta = 0;
	for (long long i = 1; i < n; i++)
	{
		buffer *= x / i;

		res += buffer;

		delta = fabs(refres- res);

		if (delta < accruracy)
		{
			n = i+1;
			break;
		}

	}

	results[0] = res;
	results[1] = refres;
	results[2] = delta;
	results[3] = n;
}

void myexp_s(long double* results, long double* deltas, long double x, long long NMax)
{
	long double refres = exp(x);
	long double buffer = 1;
	long double res = 1;
	long double delta;
	results[1] = 1;
	deltas[1] = fabs(refres - 1);
	long long factorial = 1;
	for (long long i = 1; i < NMax; i++)
	{
		buffer *= x / i;

		res += buffer;

		results[i + 1] = res;
		delta = fabs(refres - res);
		deltas[i + 1] = delta;
	}
}

void myth(long double* results, long double x, long double accruracy, long long n)
{
	long double refres = tanh(x);
	long double sinh_buff = x;
	long double cosh_buff = 1;
	long double _sinh = x;
	long double _cosh = 1;
	long double res = x;
	long double delta = fabs(refres - x);

	for (long long i = 2; i <= n; i++)
	{
		sinh_buff *= pow(x, 2) / ((2 * i - 2) * (2 * i - 1));
		cosh_buff *= pow(x, 2) / ((2 * i - 3) * (2 * i - 2));

		_sinh += sinh_buff;
		_cosh += cosh_buff;

		res = _sinh / _cosh;

		delta = fabs(refres - res);

		if (delta < accruracy)
		{
			n = i;
			break;
		}
	}

	results[0] = res;
	results[1] = refres;
	results[2] = delta;
	results[3] = n;
}

void myth_s(long double* results, long double* deltas, long double x, long long NMax)
{
	long double refres = tanh(x);
	long double sinh_buff = x;
	long double cosh_buff = 1;
	long double _sinh = x;
	long double _cosh = 1;
	long double res = results[1] = x;
	deltas[1] = fabs(refres - x);
	for (long long i = 2; i <= NMax; i++)
	{
		sinh_buff *= pow(x, 2) / ((2 * i - 2) * (2 * i - 1));
		cosh_buff *= pow(x, 2) / ((2 * i - 3) * (2 * i - 2));
		
		_sinh += sinh_buff;
		_cosh += cosh_buff;

		res = _sinh / _cosh;
		results[i] = res;
		deltas[i] = fabs(refres - res);
	}
}