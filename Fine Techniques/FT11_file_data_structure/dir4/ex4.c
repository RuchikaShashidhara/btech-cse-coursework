#include <stdio.h>
#include <stdlib.h>
#include "person4.h"
#include "file4.h"

int main()
{
	int opt; int pos;
	person_t x;
	FILE *fp = open_file("four.dat");
	printf("0: exit; 1: insert/overwrite; 2: disp : 3:disp all ");
	scanf("%d", &opt);
	while(opt)
	{
		switch(opt)
		{
			case 1 : printf("enter name age and pos : ");
					 scanf("%s %d %d", x.name, &x.age, &pos); 
					 write_file(fp, &x, pos);
					 break;
			case 2 : printf("enter pos : ");
					 scanf("%d", &pos);
					 read_file(fp, &x, pos);
		 			 printf("name: %s age: %d  pos: %d\n",
		 			 	 x.name, x.age, pos);
					 break;
			case 3 : disp_all(fp); break;
			
					
		}
		printf("0: exit; 1: insert/overwrite; 2: disp : "
			" 3:disp all ");
		scanf("%d", &opt);
	}
	close_file(fp);
}
