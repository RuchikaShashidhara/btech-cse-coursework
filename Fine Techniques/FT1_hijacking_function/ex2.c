#include <stdio.h>
#if 0
#define ABC 100
#define PQR ABC
int main()
{
	printf("ondu : %d\n", ABC);
	printf("eradu : %d\n", PQR);
	
}
#endif

#if 0
#define ABC 300
void foo();
int main()
{
	printf("ABC : %d\n", ABC);
	foo();
	#define ABC 100
	{
		printf("sonne : %d\n", ABC);	
		foo();
		#define ABC 200
		printf("ondu : %d\n", ABC);
		foo();
	}
	printf("eradu : %d\n", ABC);
	foo();

}
void foo()
{
	printf("mooru : %d, in foo\n\n", ABC);
}
#endif

// give a value for pre-processor symbol
//	-D<preprocessor-symbol>=<value>
//gcc -E -DABC=1729
#if 0
int main()
{
	printf("ondu : %d\n", ABC);
	return 0;
}
#endif






