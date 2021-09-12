//find the max sum of a contiguous subsequence
// brute force : cubic algorithm
#include <stdio.h>
struct seqsum
{
	int l;
	int r;
	double sum;
};
typedef struct seqsum seqsum_t;
seqsum_t find_sum(double a[], int n)
{
	seqsum_t s;
	double current_max = 0;
	int current_i = -1;
	int current_j = -1;
	for(int i = 0; i < n; ++i)
	{
		for(int j = i; j < n; ++j)
		{
			double sum = 0;
			for(int k = i; k <= j; ++k)
			{
				sum += a[k];
			}
			if(sum > current_max)
			{
				current_max = sum;
				current_i = i;
				current_j = j;
			}
		}
	}
	s.l = current_i; s.r = current_j; s.sum = current_max;
	return s;
}
int main()
{
	double a[] = { 31, -41, 59, 26, -53, 58, 97, -93, -23, 84 };
	int n = 10;
	seqsum_t s;
	s = find_sum(a, n);
	printf("l : %d r : %d sum : %lf\n", s.l, s.r, s.sum);
}
