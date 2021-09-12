#include <stdio.h>
#define SIZE 10001
void fill(int sieve[], int size, int n)
{
	for(int i = 2; i <= n; ++i)
	{
		sieve[i] = 1;
	}
}
void disp(int sieve[], int size, int n)
{
	for(int i = 2; i <= n; ++i)
	{
		if(sieve[i])
		{
			printf("%d ", i);
		}
	}
	printf("\n");
}
void filter(int sieve[], int size, int n)
{
	for(int factor = 2; factor <= n; ++factor)
	{
		if(sieve[factor])
		{
			for(int multiple = factor + factor; multiple <= n; multiple += factor)
			{
				sieve[multiple] = 0;
			}
		}
	}
}

int main()
{
	int n = 10000;
	int sieve[SIZE];
	fill(sieve, SIZE, n);
	filter(sieve, SIZE, n);
	disp(sieve, SIZE, n);
}
