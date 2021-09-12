#include <stdio.h>
#define SIZE (10001/sizeof(int) + 1)
#define BITSIZE (sizeof(int)*8)
void fill(int sieve[], int size, int n)
{
	int base;
	int offset;
	for(int i = 2; i <= n; ++i)
	{
		base = i / BITSIZE;
		offset = i % BITSIZE;
		sieve[base] |= (1 << offset);
	}
}
void disp(int sieve[], int size, int n)
{
	int base;
	int offset;
	for(int i = 2; i <= n; ++i)
	{
		base = i / BITSIZE;
		offset = i % BITSIZE;
		if(sieve[base] & (1 << offset))
		{
			printf("%d ", i);
		}
	}
	printf("\n");
}
void filter(int sieve[], int size, int n)
{
	int base;
	int offset;
	for(int factor = 2; factor <= n; ++factor)
	{
		base = factor / BITSIZE;
		offset = factor % BITSIZE; 
		if(sieve[base] & (1 << offset))
		{
			for(int multiple = factor + factor; multiple <= n; multiple += factor)
			{
				base = multiple/ BITSIZE;
				offset = multiple % BITSIZE;
				sieve[base] &= ~(1 << offset);
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
