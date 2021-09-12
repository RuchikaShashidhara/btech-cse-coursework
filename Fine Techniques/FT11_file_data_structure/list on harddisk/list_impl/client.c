#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main()
{
	FILE *fp;
	list_t l;
	//fp = init_list(&l, "mylist.dat");
	fp = init_list(&l, "mylist.txt");
	int key;
	int opt;
	scanf("%d", &opt);
	while(opt)
	{
		switch(opt)
		{
			case 1 : printf("enter key to insert : ");
					 scanf("%d", &key);
					 insert_key(&l, key, fp);
					 break;
			case 2 : scanf("%d", &key);
					 delete_key(&l, key, fp);
					 break;
			case 3 : printf("list begin\n");
					 disp_list(&l, fp);
					 printf("list end\n");
					 break;
		}
		printf("enter option : ");
		scanf("%d", &opt);
	}
	close_list(&l, fp);
}
