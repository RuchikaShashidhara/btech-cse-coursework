#include <stdio.h>
#if 0
#define A 10
int main()
{
	printf("one\n");
	printf("A : %d\n", A);
	printf("two\n");
}
#endif

#if 1
#define A 10
int main()
{
	printf("one\n");
	printf("A : %d\n", A);
	printf("two\n");
	#define B 20
	printf("B: %d\n", B);
	printf("three\n");
	#define A 30
	printf("A : %d\n", A);
	printf("four\n");
	{
		#define A 40
		printf("A : %d\n", A);
		printf("five\n");
	
	}
	printf("A : %d\n", A); // 40
	printf("six\n");
	//printf("C : %d\n", C);
	//#define C 100 
}
#endif
// preprocessor variable
//		table created at pre-processing stage
//		A 10 30
//		B 20
// does not understand scope


// Try:
// a) two recursive defines
// b) cascaded defines

