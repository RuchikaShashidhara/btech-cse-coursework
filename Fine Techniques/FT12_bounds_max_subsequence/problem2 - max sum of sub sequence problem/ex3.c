//find the max sum of a contiguous subsequence
// second quadratic algorithm
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
	double acc[n + 1];
	acc[0] = 0;
	for(int i = 1; i <= n; ++i)
	{
		acc[i] = acc[i-1] + a[i-1];
	}
	
	
	for(int i = 1; i <= n; ++i)
	{
		double sum = 0;
		for(int j = i; j < n; ++j)
		{
			sum = acc[j] - acc[i-1];
		
			if(sum > current_max)
			{
				current_max = sum;
				current_i = i - 1;
				current_j = j - 1;
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
