#include <stdio.h>
#include "3_date.h"
void mysort(int a[], int n)
{
	int i; int j;
	for(i = 0; i < n - 1; ++i)
	{
		for(j = i + 1; j < n; ++j)
		{
			if(a[j] < a[i])
			{
				int temp = a[i]; a[i] = a[j]; a[j] = temp;
			}
		}
	}
}
void sort_dates(date_t a[], int n, int (*compare)(const date_t*, const date_t*))
{
	int i; int j;
	for(i = 0; i < n - 1; ++i)
	{
		for(j = i + 1; j < n; ++j)
		{
			if(compare(&a[i], &a[j]) > 0)
			{
				date_t temp = a[i]; a[i] = a[j]; a[j] = temp;
			}
		}
	}
}
int main()
{
//	date_t d = {15, 8, 1947};
//	disp(&d); printf("\n");
	int a[] = {22, 11, 44, 55, 33};
	mysort(a, 5);
	for(int i = 0; i < 5; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	date_t d[] = {
		{26, 1, 2001},
		{30, 1, 1948},
		{26, 12, 2004},
		{11, 1, 1966},
		{11, 9, 2001}
	};
	int n = 5;
	disp_all(d, n);
	printf("calling sort\n");
	sort_dates(d, n, compare_date);
	disp_all(d, n);
	printf("calling sort\n");
	sort_dates(d, n, compare_month);
	disp_all(d, n);
	
}
