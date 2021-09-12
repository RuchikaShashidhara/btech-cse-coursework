//find the max sum of a contiguous subsequence
// n logn - divide and conquer
#include <stdio.h>
struct seqsum
{
	int l;
	int r;
	double sum;
};
typedef struct seqsum seqsum_t;


seqsum_t max3(seqsum_t a, seqsum_t b, seqsum_t c)
{
	if(a.sum > b.sum && a.sum > c.sum)
	{
		return a;
	}
	else if(b.sum > c.sum)
	{
		return b;
	}
	else
	{
		return c;
	}
}
seqsum_t find_sum_r(double a[], int l, int r)
{
	if(l > r)
	{
		seqsum_t s = {-1, -1, 0.0};
		return s;
	}
	if(l == r)
	{
		seqsum_t s = {l, r, (a[l] > 0) ? a[l] : 0};
		return s;
	}
	int m = (l + r) / 2;
	int current_i = l;
	int current_j = m + 1;
	double lmax; double rmax; double sum; lmax = sum = 0.0;
	for(int i = m; i >= l;--i)
	{
		sum += a[i];
		if(sum > lmax)
		{
			lmax = sum;
			current_i = i;
		}
	}
	rmax = sum = 0.0;
	for(int i = m + 1; i <= r; ++i)
	{
		sum += a[i];
		if(sum > rmax)
		{
			rmax = sum;
			current_j = i;
		}
		
	}
	seqsum_t s_l_r = {current_i, current_j, lmax + rmax};
	seqsum_t s_l = find_sum_r(a, l, m);
	seqsum_t s_r = find_sum_r(a, m + 1, r);
	return max3(s_l_r, s_l, s_r);
	
}

seqsum_t find_sum(double a[], int n)
{
	return find_sum_r(a, 0, n - 1);
}

int main()
{
	double a[] = { 31, -41, 59, 26, -53, 58, 97, -93, -23, 84 };
	int n = 10;
	seqsum_t s;
	s = find_sum(a, n);
	printf("l : %d r : %d sum : %lf\n", s.l, s.r, s.sum);
}
