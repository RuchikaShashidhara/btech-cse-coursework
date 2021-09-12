// find lowerboud, upperbound and # of elements
// array in non decreasing order with repeating elements

#include <stdio.h>
int binary_search(int a[], int n, int e)
{
	int l = 0; int r = n - 1;
	int m = (l + r) / 2; // assume no overflow!!
	while(l <= r && a[m] != e)
	{
		if(a[m] > e)
		{
			r = m - 1;
		}
		else
		{
			l = m + 1;
		}
		m = (l + r) / 2;
	}
	return (l <= r) ? m : -1;
}

int lower_bound(int a[], int n, int e)
{
	int m = binary_search(a, n, e);
	if(m == -1)
	{
		return -1;
	}
	else
	{
		while(m > 0 && a[m - 1] == e)
		{
			--m;
		}
		return m;
	}
}
int upper_bound(int a[], int n, int e)
{
	int m = binary_search(a, n, e);
	if(m == -1)
	{
		return -1;
	}
	else
	{
		while(m < n - 1 && a[m + 1] == e)
		{
			++m;
		}
		return m;
	}
}
void tester(int a[], int n, int e)
{
	int lb = lower_bound(a, n, e);
	if(lb == -1)
	{
		printf("element : %d not found\n", e);
	}
	else
	{
		int ub = upper_bound(a, n, e);
		printf("element : %d ", e);
		printf("lower bound : %d upper bound : %d "
			" # of elem in range : %d\n", lb, ub, (ub - lb + 1));
	}
}
int main()
{
	int a[] = {2, 2, 2, 3, 5, 5, 5, 5, 7, 7};
	int n = 10;
	tester(a, n, 2);
	tester(a, n, 3);
	tester(a, n, 5);
	tester(a, n, 7);
	tester(a, n, 6);
	
	
}
