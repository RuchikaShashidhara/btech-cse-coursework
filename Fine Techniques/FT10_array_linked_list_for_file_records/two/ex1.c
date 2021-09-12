 
// create an array list
// how to create a file of records

#include <stdio.h>
#include "list.h"

int main()
{
	list_t l;
	init_list(&l);
	int opt;
	int key;
	printf("0: exit; 1: insert; 2: delete; 3: disp : ");
	scanf("%d", &opt);
	while(opt)
	{
		switch(opt)
		{
			case 1 : scanf("%d", &key); insert(&l, key);break;
			case 2 : scanf("%d", &key); delete(&l, key); break;
			case 3 : disp_list(&l);break;
		}
	
		printf("0: exit; 1: insert; 2: delete; 3: disp : ");
		scanf("%d", &opt);
	}
}
