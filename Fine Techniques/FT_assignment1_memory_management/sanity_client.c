#include <stdio.h>
#include "assignment_1.h"
void main()
{
    	allocate(200);
    	char *a = (char *)mymalloc(26 * sizeof(char));
	display_mem_map();
	printf("\n");
	char *b = (char *)mymalloc(10 * sizeof(char));
	display_mem_map();
	printf("\n");
	char *d = (char *)mymalloc(9 * sizeof(char));
	display_mem_map();
	printf("\n");	
	
	char *c = (char *)mymalloc(9 * sizeof(char));
	display_mem_map();
	printf("\n");
	myfree(b);
	display_mem_map();
	printf("\n");	
	myfree(a);
	display_mem_map();
	printf("\n");
    	myfree(c);
	display_mem_map();
	printf("\n");
	myfree(d);
	display_mem_map();
	printf("\n");
}

