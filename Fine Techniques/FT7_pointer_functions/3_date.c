#include <stdio.h>
#include "3_date.h"

void disp(const date_t* ptr_date)
{
	printf("%d-%d-%d", ptr_date->dd, ptr_date->mm, ptr_date->yy);
}

void disp_all(const date_t* ptr_date, int n)
{
	for(int i = 0; i < n; ++i)
	{
		disp(ptr_date + i);
		printf("\n");
	}
}
int compare_date(const date_t* lhs, const date_t* rhs)
{
	if(rhs->yy < lhs->yy)
		return 1;
	if(rhs->yy == lhs->yy && rhs->mm < lhs->mm)
		return 1;
	if(rhs->yy == lhs->yy && rhs->mm == lhs->mm && rhs->dd < lhs->dd)
		return 1;
	if(rhs->yy == lhs->yy && rhs->mm == lhs->mm && rhs->dd == lhs->dd)
		return 0;
	return -1;
	
		
}
int compare_month(const date_t* lhs, const date_t* rhs)
{
	return rhs->mm - lhs->mm;
}



