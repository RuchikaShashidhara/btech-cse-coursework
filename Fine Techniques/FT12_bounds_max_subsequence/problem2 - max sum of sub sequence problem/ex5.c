//find the max sum of a contiguous subsequence
// linear algorithm
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
	int max_l = -1;
	int max_r = -1;
	int max_end = 0;
	for(int i = 0; i < n; ++i)
	{
		if(max_end + a[i] > 0)
		{
			max_end += a[i];
			max_r = i;
		}
		else
		{
			max_end = 0;
			max_l = i + 1;
		}
		if(max_end > current_max)
		{
			current_max = max_end;
			current_i = max_l;
			current_j = max_r;
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
