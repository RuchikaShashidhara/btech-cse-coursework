#include <stdio.h>
#include <stdlib.h>
#include "1_list.h"

int main()
{

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
#if 0
	list_t l;
	FILE *fp;
	fp = fopen("list1.dat", "r");
	init_list(&l);
	read_file(&l, fp);
	fclose(fp);
	disp(&l);
#endif	

// find the ith record in the file directly
// 1. read the file repeatedly n - 1 times - ignore those read
//	read the nth record
// 2. position at the nth rec and read
//	  do not have read the intermediate records
//		seeking:
//		fseek
//			file pointer
//			offset : how far in bytes
//			whence : direction of measurement of offset
//			beginning of file : 0 or SEEK_SET
//			current position : 1 or SEEK_CUR
//			end of file : 2 or SEEK_END

#if 1
// list content: 20 10 40 50 30
	FILE *fp;
	fp = fopen("list1.dat", "r");
	int recno;
	scanf("%d", &recno);
	fseek(fp, recno * sizeof(int), SEEK_SET);// efficient
	// not costly; does no i/o operation
	int key;
	fread(&key, sizeof(int), 1, fp);  
	printf("key : %d\n", key);
	fclose(fp);
#endif	
}
// what if the node has a complicated record structure?
//		details of students - SRN is the key
//		event:  date and detail
// How do we write to the file?
//	1. convert each field to a text and write
//  2. dump whatever the record contains to the harddisk

// In the first case, I can cat the file.
// In the second case, I cannot.


// create a data structure by dumping:
// a) make the node to have
//		name : age : gender(one char)
//		create a list; write to a file; read back and display
//		try - formatted way and non-formatted way
// b) making a binary tree on a harddisk
//		dump a traversal
//		read the traversal and re-create the tree? NO
//		dump two traversals : pre and in and then re-create
//			while reading? YES


