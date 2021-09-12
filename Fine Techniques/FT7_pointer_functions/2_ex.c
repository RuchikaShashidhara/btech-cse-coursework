#include <stdio.h>


int acc1(int x[], int n)
{
	int init = 0;
	for(int i = 0; i < n; ++i)
	{
		init += x[i];
	}
	return init;
}
int acc2(int x[], int n, int init)
{
	for(int i = 0; i < n; ++i)
	{
		init += x[i];
	}
	return init;
}
int add(int x, int y) { return x + y; }
int mul(int x, int y) { return x * y; }
int big(int x, int y) { return (x > y) ? x : y; }

int acc3(int x[], int n, int init, int (*op)(int, int))
{
	for(int i = 0; i < n; ++i)
	{
		init = op(init, x[i]);
	}
	return init;
}

int main()
{
	int a[] = {2, 1, 5, 4, 3};
	int n = 5;
	int res = acc1(a, n); 
	printf("res : %d\n", res);
	
	res = acc2(a, n, 0);
	printf("res : %d\n", res);
	res = acc2(a, n, 50);
	printf("res : %d\n", res);

	res = acc3(a, n, 0, add);
	printf("res : %d\n", res);
	res = acc3(a, n, 1, mul);
	printf("res : %d\n", res);
	
//	res = acc3(a, n, a[0], big);
	res = acc3(a + 1, n - 1, a[0], big);
	printf("res : %d\n", res);
	
	

}
// int x1;
// typedef int y;
//	y x2;

// int (*f1)(int x, int y);
// typedef int fn_t(int x, int y);
// fn_t f2;




