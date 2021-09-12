#include <stdio.h>
#include <stdlib.h>


int main()
{
	//int na[100];
	int i,j,n;
	scanf("%d", &n);
	n += 1;
	//int n=100;
	int *na = (int*)malloc((n) * sizeof(int));
	for(i=0; i<n; i++)
		na[i] = 0;
	for(i=1; i<=n; i++){
		for(j=1; j<=n; j++){
			if((i-1)%j == 0){
				if(na[i-1] == 0)
					na[i-1] = 1;
				else
					na[i-1] = 0;
			}
		}
	}
	for(i=1; i<n; i++)
	{
		if(na[i] == 1)
		printf("%d ", i);
	}
	printf("\n");
}


//sedgwig - noice videos for adts
//lru
//PIMPL
//simonsom - toc
//heaps sort is not efficient as i, 2i mem loctaion are fetched, they are unlikely in cached mem
//templates in c++
//stepenhoff - programming 
//scott meyers - most important designing guideline
//how do you find if a given number is a power of 2
//bucket sort

