#include <stdio.h>
// avoid the problem of multiple inclusion at compile time
#include "list.h"
#include "list.h"

int main()
{
	/*list_t l;
	init_list(&l);
	int a[] = {25, 15, 35, 5, 45};
	int n = 5;
	for(int i = 0; i < n; ++i)
	{
		insert_list(&l, a[i]);
	}
	disp_list(&l);*/

	int choice, ele;
	list_t l;
	init_list(&l);
	
    do{
		printf("Enter your choice\n1. Insert Node\n2. Delete Node\n3. Display List\n0. Exit\n");
		scanf("%d", &choice);
		switch(choice)
		{
		case 1:
			printf("Enter element ");
			scanf("%d", &ele);
			insert_list(&l, ele);
			//disp_list(&l);
			break;
		case 2:
			printf("Enter element ");
			scanf("%d", &ele);
			delete_list(&l, ele);
			//disp_list(&l);
			break;
		case 3:
			disp_list(&l);
			break;
		case 0:
			break;
	        }
      } while(choice != 0);
	return 0;
}
