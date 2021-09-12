// certain data structures like B-tree are created in harddisk
// they are too big to fit into memory
// get a feel of how to create data structure in harddisk

// step 1:
//	create a list and dump it into harddisk and read and recreate
//		the data structure
// step 2:
//	create a data structure on harddisk itself directly and
//		manipulate (add and/or remove nodes)


#include <stdio.h>
#include <stdlib.h>
#include "1_list.h"

int main()
{
#if 0
	list_t l;
	init_list(&l);
	int a[] = {20, 10, 40, 50, 30};
	int n = sizeof(a) / sizeof(*a);
	for(int i = 0; i < n; ++i)
	{
		add(&l, a[i]);
	}
	disp(&l);
#endif
#if 0
	list_t l;
	FILE *fp;
	fp = fopen("list1.dat", "w");
	// not checking for fopen failures
	init_list(&l);
	int a[] = {20, 10, 40, 50, 30};
	int n = sizeof(a) / sizeof(*a);
	for(int i = 0; i < n; ++i)
	{
		add(&l, a[i]);
	}
	write_file(&l, fp);
	fclose(fp);
#endif
// problem: list created is the reverse of the list we had
//	assignment : how do you correct this?

	list_t l;
	FILE *fp;
	fp = fopen("list1.dat", "r");
	init_list(&l);
	read_file(&l, fp);
	fclose(fp);
	disp(&l);
}
// what if the node has a complicated record structure?
//		details of students - SRN is the key
//		event:  date and detail
// How do we write to the file?
//	1. convert each field to a text and write
//  2. dump whatever the record contains to the harddisk

// In the first case, I can cat the file.
// In the second case, I cannot.

