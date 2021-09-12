// find lowerboud, upperbound and # of elements
// array in non decreasing order with repeating elements

#include <stdio.h>
int lower_bound(int a[], int n, int e)
{
	int l = -1; int r = n;
	int m = -1; 
	while(l + 1 != r)
	{
		m = (l + r) / 2;
		if(a[m] >= e)
		{
			r = m;
		}
		else
		{
			l = m;
		}
		
	}
	return (a[r] == e) ? r : -1;
}


int upper_bound(int a[], int n, int e)
{
	int l = -1; int r = n;
	int m = -1; 
	while(l + 1 != r)
	{
		m = (l + r) / 2;
		if(a[m] <= e)
		{
			l = m;
		}
		else
		{
			r = m;
		}
		
	}
	return (a[l] == e) ? l : -1;
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
