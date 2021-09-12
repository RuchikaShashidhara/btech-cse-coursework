#include <stdio.h>
#include "list.h"

int main()
{
	list_t l;
	init_list(&l);
	int key;
	int opt;
	scanf("%d", &opt);
	while(opt)
	{
		switch(opt)
		{
			case 1 : scanf("%d", &key);
					 insert_key(&l, key);
					 break;
			case 2 : scanf("%d", &key);
					 delete_key(&l, key);
					 break;
			case 3 : disp_list(&l);
					 break;
		}
		scanf("%d", &opt);
	}
}
