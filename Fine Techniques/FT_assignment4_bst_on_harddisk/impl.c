#include <stdio.h>
#include "assignment_4.h"

int main()
{
	FILE *fp;		fp = init_tree("mylist.dat");		
	printf("Inorder : ");	display_inorder(fp);	printf("\n");
	printf("Preorder: ");	display_preorder(fp);	printf("\n");	
	int key, opt;		opt = 1;	
	do{	
		printf("1. Insert 2. Delete 3. Inorder 4. Preorder 0. Exit\nEnter option: ");	scanf("%d", &opt);
		switch(opt){
			case 1: printf("Enter key to insert: ");	scanf("%d", &key);	insert_key(key, fp);	break;
			case 2: printf("Enter key to delete: ");	scanf("%d", &key);	delete_key(key, fp);	break;
			case 3: printf("Inorder: ");			display_inorder(fp);				break;
			case 4: printf("Preorder: ");			display_preorder(fp);				break;	
		}printf("\n");
	}while(opt);	
	close_tree(fp);
}
