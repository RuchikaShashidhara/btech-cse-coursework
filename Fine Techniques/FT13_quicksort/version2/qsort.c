#include <stdio.h>
#include <stdlib.h>
#include "qsort.h"
#if DEBUG
	int move_count = 0;
	int comp_count = 0;
#endif
void shuffle(int a[], int n)
{
	int pos;
	// may want to introduce a seed for random # generation
	for(int i = 1; i <= n / 2; ++i)
	{
		pos = rand() % n + 1;
		myswap(&a[i], &a[pos]); 
	}
}

void fill(int a[], int n)
{
//	printf("fill called\n");
	for(int i = 1; i <= n; ++i)
	{
		a[i] = i;
	}
	shuffle(a, n);
}

void disp(int* a, int n)
{
	for(int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
void myswap(int *p, int *q)
{
	int t = *p; *p = *q; *q = t;
}
int partition(int a[], int l, int r)
{
	int i = l; int j = r + 1;
	int p = a[l];
	do
	{
		do
		{
			++i;
		}
		while(i <= r && a[i] < p);
		do
		{
			--j;
		}
		while(j >= l && a[j] > p);
		myswap(&a[i], &a[j]);
		#if DEBUG
			move_count += 3;
		#endif

	} while(i < j);
	myswap(&a[i], &a[j]);
	myswap(&a[l], &a[j]);
	#if DEBUG
		comp_count += r - l + 1;
		move_count += 6;
	#endif
	return j;
	
}
void myqsort(int a[], int l, int r)
{
	if(l < r) // section has more than one element
	{
		int s = partition(a, l, r);
		myqsort(a, l, s - 1);
		myqsort(a, s + 1, r);
	}
}
int is_sorted(int a[], int n)
{
	for(int i = 1; i < n; ++i)
	{
		if(a[i] > a[i + 1])
			return 0;
	}
	return 1;
}

