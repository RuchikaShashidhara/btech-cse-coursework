#include <stdio.h>
#include <stdlib.h>
#include "person3.h"
#include "file3.h"

int main()
{
	int opt; int pos;
	person_t x;
	FILE *fp = open_file("three.dat");
	printf("0: exit; 1: insert/overwrite; 2: disp : ");
	scanf("%d", &opt);
	while(opt)
	{
		switch(opt)
		{
			case 1 : printf("enter name age and pos : ");
					 scanf("%s %d %d", x.name, &x.age, &pos); 
					 seek_file(fp, pos);
					 write_file(fp, &x);
					 break;
			case 2 : printf("enter pos : ");
					 scanf("%d", &pos);
					 seek_file(fp, pos);
					 read_file(fp, &x);
		 			 printf("name: %s age: %d  pos: %d\n",
		 			 	 x.name, x.age, pos);
					 break;
		}
		printf("0: exit; 1: insert/overwrite; 2: disp : ");
		scanf("%d", &opt);
	}
	close_file(fp);
}
