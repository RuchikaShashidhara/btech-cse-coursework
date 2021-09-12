#include <stdio.h>
#include "assignment_4.h"

//traversal helper functions
static void inorder(FILE* fp, int off);
static void preorder(FILE* fp, int off);

//create a file with the filename and initialize the header with tree_t structure
//if the file already exists, just return the file ptr
FILE* init_tree(const char* filename)
{
	FILE* fp = fopen(filename, "r+");
	if(fp == NULL)	//empty file
	{
		fp = fopen(filename, "w");
		tree_t head_tree;	//initialzing free_head and root of tree_t
		head_tree.free_head = -1;
		head_tree.root = -1;
		fwrite(&head_tree, sizeof(tree_t), 1, fp);	//updating free_head;
		fclose(fp);
		fp = fopen(filename, "r+");
	}
	return fp;
}

//close the file pointed by fp
void close_tree(FILE *fp)
{
	fclose(fp);
}

//wrapper function to display inorder traversal
//space separated keys. Last key followed by '\n'
void display_inorder(FILE *fp)
{
	fseek(fp, 0, SEEK_SET);
	tree_t bst;
	fread(&bst, sizeof(tree_t), 1, fp);
	inorder(fp, bst.root);
	printf("\n");
}

//recursive function to display inorder traversal - left, root, right
static void inorder(FILE *fp, int off)
{
	if(off != -1)
	{
		fseek(fp, off, SEEK_SET);
		node_t temp;
		fread(&temp, sizeof(node_t), 1, fp);
		inorder(fp, temp.left_offset);
		printf("%d ", temp.key);
		inorder(fp, temp.right_offset);	
	}
}

//wrapper function to display preorder traversal
//space separated keys. Last key followed by '\n'
void display_preorder(FILE *fp)
{
	fseek(fp, 0, SEEK_SET);
	tree_t bst;
	fread(&bst, sizeof(tree_t), 1, fp);
	preorder(fp, bst.root);
	printf("\n");
}

//recursive function to display preorder traversal - root, left, right
static void preorder(FILE *fp, int off)
{
	if(off != -1)
	{
		fseek(fp, off, SEEK_SET);
		node_t temp;
		fread(&temp, sizeof(node_t), 1, fp);
		printf("%d ", temp.key);
		preorder(fp, temp.left_offset);		
		preorder(fp, temp.right_offset);	
	}
}

//fp, offset	//node_t	//usage
//temp_off	//curr_node	//node for traversal
//temp_off	//temp_node	//node to be inserted
//prev_off	//prev_node	//parent node of temp_node
//free_head(0)	//next_free	//node to be filled when gaps exist in the file
//insert the key into the tree in the file
//if the key already exists just return
void insert_key(int key, FILE *fp)
{
	node_t temp_node, curr_node, prev_node, next_free;	
	int prev_off, temp_off, flag, flag2;
	flag = flag2 = 0;
	
	temp_node.key = key;	//creating node_t: temp_node with key
	temp_node.left_offset = -1;
	temp_node.right_offset = -1;
	
	tree_t bst, new_bst;
	fseek(fp, 0, SEEK_SET);		//retrieving free_head and root offsets
	fread(&bst, sizeof(tree_t), 1, fp);	
	
	//retrieving offset: temp_off to insert temp_node with key
	if(bst.free_head == -1)		//no empty node_t gaps in file
	{
		fseek(fp, 0, SEEK_END);
		temp_off = ftell(fp);
	}
	else	//empty node_t gaps exist
	{
		temp_off = bst.free_head;				
		fseek(fp, temp_off, SEEK_SET);
		fread(&next_free, sizeof(node_t), 1, fp);
		flag2 = 1;		
	}	
	
	if(bst.root == -1)	//if there are no nodes in the tree
	{
		fseek(fp, 0, SEEK_SET);		//retrieving free_head and root offsets
		fread(&new_bst, sizeof(tree_t), 1, fp);
		new_bst.root = temp_off;	//updating new root offset to the offset containg the root node data		
		fseek(fp, new_bst.free_head, SEEK_SET);
		fread(&next_free, sizeof(node_t), 1, fp);
		
		if(bst.free_head == -1)		//updating bst.free_head when no empty node_t gaps in file
		{
			new_bst.free_head = -1;
		}
		else	//updating bst.free_head with it's next empty node_t gap in file
		{
			new_bst.free_head = next_free.right_offset;
		}
		
		fseek(fp, 0, SEEK_SET);		//updating new free_head and root offset after inserting root
		fwrite(&new_bst, sizeof(tree_t), 1, fp);		
		fseek(fp, temp_off, SEEK_SET);		//updating temp_off node_t containing key as root 
		fwrite(&temp_node, sizeof(node_t), 1, fp);
		return;
		
	}
	else	//if nodes are present in the tree
	{
		fseek(fp, bst.root, SEEK_SET);		//retrieving root node's data in curr_node
		fread(&curr_node, sizeof(node_t), 1, fp);
		prev_off = bst.root;
		
		while(!flag)	//travering until optimal place to insert the temp_node containing k hasn't been found
		{
			prev_node = curr_node;
			if(temp_node.key == curr_node.key)	//key already exists
			{
				return;
			}
			else if(temp_node.key < curr_node.key)		//traversing towards the left
			{
				if(curr_node.left_offset == -1)
				{					
					prev_node.left_offset = temp_off;
					fseek(fp, prev_off, SEEK_SET);		//updating parent node: prev_node of temp_node
					fwrite(&prev_node, sizeof(node_t), 1, fp);
					
					fseek(fp, temp_off, SEEK_SET);		//updating temp_node containg key
					fwrite(&temp_node, sizeof(node_t), 1, fp);
					flag = 1;
				}
				else
				{
					prev_off = curr_node.left_offset;
					fseek(fp, curr_node.left_offset, SEEK_SET);	//travesing towards the left
					fread(&curr_node, sizeof(node_t), 1, fp);
				}
			}
			else //traversing towards the right
			{
				if(curr_node.right_offset == -1)
				{					
					prev_node.right_offset = temp_off;
					fseek(fp, prev_off, SEEK_SET);		//updating parent node: prev_node of temp_node
					fwrite(&prev_node, sizeof(node_t), 1, fp);
					
					fseek(fp, temp_off, SEEK_SET);		//updating temp_node containg key
					fwrite(&temp_node, sizeof(node_t), 1, fp);
					flag = 1;
				}
				else
				{
					prev_off = curr_node.right_offset;
					fseek(fp, curr_node.right_offset, SEEK_SET);	//travesing towards the right
					fread(&curr_node, sizeof(node_t), 1, fp);
				}
			}
		}		
	}
	if(flag2 == 1)
	{
		bst.free_head = next_free.right_offset;		//updating free_head with it's next empty node_t gap in file
		fseek(fp, 0, SEEK_SET);		//updating the free_head and root offsets
		fwrite(&bst, sizeof(tree_t), 1, fp);
	}
}

//fp, offset	//node_t	//usage
//temp_off	//curr_node	//node to be deleted
//prev_off	//prev_node	//parent node of curr_node
//t_off		//temp_node	//inorder successor node of temp_node
//pt_off	//ptemp_node	//parent node of temp_node
//head_off	//free_head	//free node offset before curr_node containing key is deleted
// delete the key from the tree in the file
// the key may or may not exist
void delete_key(int key, FILE *fp)
{
	node_t temp_node, curr_node, prev_node, ptemp_node;	
	int flag, flag2, flag3, temp_off, prev_off, head_off, pt_off, t_off;
	flag = flag2 = flag3 = 0;
	
	tree_t bst;
	fseek(fp, 0, SEEK_SET);
	fread(&bst, sizeof(tree_t), 1, fp);
	
	if(bst.root == -1)	//empty tree
	{
		return;
	}
	else	//nodes are present in the tree
	{
		temp_off = bst.root;
		fseek(fp, bst.root, SEEK_SET);		//retrieving free_head and root offsets
		fread(&curr_node, sizeof(node_t), 1, fp);
		prev_off = bst.root;
		
		while(!flag)	//traversing till the node_t containing key has been found
		{

			if(key == curr_node.key)	//node_t: curr_node containing key is found
			{
				flag = 1;	
			}
			else if(key < curr_node.key)	//traversing towards the left
			{
				if(curr_node.left_offset != -1)
				{
					prev_off = ftell(fp);
					prev_node = curr_node;
					temp_off = curr_node.left_offset;
					fseek(fp, curr_node.left_offset, SEEK_SET);	//traversing towards the left
					fread(&curr_node, sizeof(node_t), 1, fp);
				}
				else	//traversed till the end of the tree, node_t containing key has not been found
				{
					flag = 2;	
				}
			}
			else	//traversing towards the right
			{
				if(curr_node.right_offset != -1)
				{
					prev_off = ftell(fp);
					prev_node = curr_node;
					temp_off = curr_node.right_offset;
					fseek(fp, curr_node.right_offset, SEEK_SET);	//traversing towards the left
					fread(&curr_node, sizeof(node_t), 1, fp);
				}
				else	//traversed till the end of the tree, node_t containing key has not been found
				{
					flag = 2;	
				}
			}
		}
		
		node_t t1;		//retrieving free_head and root_offsets
		fseek(fp, bst.root, SEEK_SET);
		fread(&t1, sizeof(t1), 1, fp);
		
		if(flag == 2)		//traversed till the end of the tree, node_t containing key has not been found
		{
			return;
		}
		if(flag == 1)		//node_t: curr_node with key is found, it's parennt node_t is prev_node
		{
			prev_off -= (int)sizeof(node_t);		
			if(t1.key == key)	//key to be deleted is present in root node
			{

				prev_off = bst.root;
				//retrieving the offset to which new root is to be connected
				if(curr_node.left_offset == -1 && curr_node.right_offset == -1)	//only root node_t is present in the tree
				{			
					bst.root = -1;
				}
				else if(curr_node.right_offset == -1)	//only left subtree of root node_t exists
				{
					bst.root = curr_node.left_offset;
				}
				else if(curr_node.left_offset == -1)	//only right subtree of root node_t exists
				{
					bst.root = curr_node.right_offset;
				}
				else	//root node_t has both left and right subtrees
				{
					flag3 = 1;
				}
				
				if(flag3 == 0)		//either root_node contains left subtree or(inclusive) right subtree
				{
					head_off = bst.free_head;	//inserting deleted node_t: curr_node to free_head list
					bst.free_head = prev_off;				
					curr_node.left_offset = head_off;
					curr_node.right_offset = head_off;
					fseek(fp, 0, SEEK_SET);		//updating new free_head and root offsets
					fwrite(&bst, sizeof(tree_t), 1, fp);
					fseek(fp, prev_off, SEEK_SET);	//updating the free_head list to the deleted node_t: curr_node
					fwrite(&curr_node, sizeof(node_t), 1, fp);
				}
				else	//root node_t has both left and right subtrees, replacing root node_t with its inorder successor
				{
					temp_off = bst.root;
					t_off = curr_node.right_offset;	//retrieving the right child of the root node_t into temp_node
					fseek(fp, curr_node.right_offset, SEEK_SET);
					fread(&temp_node, sizeof(node_t), 1, fp);
					
					if(temp_node.left_offset == -1)		//if temp_node only has a right subtree
					{
						curr_node.key = temp_node.key;		
						curr_node.right_offset = temp_node.right_offset;
						fseek(fp, temp_off, SEEK_SET);//updating the root node_t: curr_node with its right child
						fwrite(&curr_node, sizeof(node_t), 1, fp);
						
					}
					else//temp_node has a left subtree
					//finding the min(right subtree of root node_t) to find inorder successor
					{
						while(temp_node.left_offset != -1)	//traversing till the inorder successor
						{
							//retrieving the parent node_t: ptemp_node of inorder succesor - temp_node
							ptemp_node = temp_node;		
							pt_off = ftell(fp) - (int)sizeof(node_t);
							t_off = temp_node.left_offset;
							//retrieving the node_t: temp_node - inorder succesor
							fseek(fp, temp_node.left_offset, SEEK_SET);
							fread(&temp_node, sizeof(node_t), 1, fp);
						}
						//replacing key of root node_t: curr_node with its inorder successor
						curr_node.key = temp_node.key;
						fseek(fp, temp_off, SEEK_SET);		//updating the root node_t with its new key
						fwrite(&curr_node, sizeof(node_t), 1, fp);
						
						if(temp_node.right_offset == -1)  //inorder successor: temp_node has no right subtree
						{
							ptemp_node.left_offset = -1;	
						}
						else		//inorder successor: temp_node has a right subtree
						{
							ptemp_node.left_offset = temp_node.right_offset;
						}
						fseek(fp, pt_off, SEEK_SET);		//updating parent of inorder successor	
						fwrite(&ptemp_node, sizeof(node_t), 1, fp);
						
					}
					head_off = bst.free_head;	//inserting deleted node_t: temp_node to free_head list
					bst.free_head = t_off;
					temp_node.left_offset = head_off;
					temp_node.right_offset = head_off;
					fseek(fp, t_off, SEEK_SET);	//updating the free_head list to the deleted node_t: temp_node
					fwrite(&temp_node, sizeof(node_t), 1, fp);
					fseek(fp, 0, SEEK_SET);		//updating new free_head and root offsets
					fwrite(&bst, sizeof(tree_t), 1, fp);	
				}
				return;
			}
			else	//key to be deleted is not the root node, key is present in curr_node
			{
				if(curr_node.left_offset == -1 && curr_node.right_offset == -1)	//curr_node to be deleted has 0 children
				{
					if(prev_node.left_offset == temp_off)
					{
						prev_node.left_offset = -1;
						
					}
					else
					{
						prev_node.right_offset = -1;
					}
					
				}
				else if(curr_node.left_offset == -1)	//curr_node to be deleted only has right subtree
				{
					if(prev_node.left_offset == temp_off)
					{
						prev_node.left_offset = curr_node.right_offset;
					}
					else
					{
						prev_node.right_offset = curr_node.right_offset;
					}
					
				}
				else if(curr_node.right_offset == -1)	//curr_node to be deleted only has left subtree
				{
					if(prev_node.left_offset == temp_off)
					{
						prev_node.left_offset = curr_node.left_offset;
					}
					else
					{
						prev_node.right_offset = curr_node.left_offset;
					}
					
				}
				else	//curr_node has both left and right subtrees, replacing curr_node with its inorder successor
				{
					flag2 = 1;
					t_off = curr_node.right_offset;	  //retrieving the right child of the curr_node into temp_node
					fseek(fp, curr_node.right_offset, SEEK_SET);	
					fread(&temp_node, sizeof(node_t), 1, fp);	
					
					if(temp_node.left_offset == -1)		//if root temp_node only has a right subtree
					{
						temp_node.left_offset = curr_node.left_offset;
						fseek(fp, t_off, SEEK_SET);	//updating temp_node - inorder successor
						fwrite(&temp_node, sizeof(node_t), 1, fp);
						
						if(prev_node.left_offset == temp_off)
						{
							prev_node.left_offset = t_off;
						}
						else
						{
							prev_node.right_offset = t_off;
						}						
						fseek(fp, prev_off, SEEK_SET);	//updating prev_node: parent of node_t to be deleted
						fwrite(&prev_node, sizeof(node_t), 1, fp);
						
						head_off = bst.free_head;	//inserting deleted node_t: curr_node to free_head list
						bst.free_head = temp_off;
						curr_node.left_offset = head_off;
						curr_node.right_offset = head_off;
						fseek(fp, temp_off, SEEK_SET); //updating the free_head list with deleted curr_node
						fwrite(&curr_node, sizeof(node_t), 1, fp); 
						fseek(fp, 0, SEEK_SET);		//updating new free_head and root offsets
						fwrite(&bst, sizeof(tree_t), 1, fp);
					}
					else //temp_node has a left subtree
					//finding the min(right subtree of temp_node) to find inorder successor
					{
						while(temp_node.left_offset != -1)	//traversing till the inorder successor
						{
							//retrieving the parent node_t: ptemp_node of inorder succesor - temp_node
							ptemp_node = temp_node;
							pt_off = ftell(fp) - (int)sizeof(node_t);
							t_off = temp_node.left_offset;
							//retrieving the node_t: temp_node - inorder succesor
							fseek(fp, temp_node.left_offset, SEEK_SET);
							fread(&temp_node, sizeof(node_t), 1, fp);		
						}
						//replacing key of root node_t: curr_node with its inorder successor
						curr_node.key = temp_node.key;
						fseek(fp, temp_off, SEEK_SET);
						fwrite(&curr_node, sizeof(node_t), 1, fp);
						
						if(temp_node.right_offset == -1) //inorder successor: temp_node has no right subtree
						{			
							ptemp_node.left_offset = -1;
						}
						else	//inorder successor: temp_node has a right subtree
						{							
							ptemp_node.left_offset = temp_node.right_offset;
						}						
						fseek(fp, pt_off, SEEK_SET);	//updating parent of inorder successor	
						fwrite(&ptemp_node, sizeof(node_t), 1, fp);
						
						head_off = bst.free_head;	//inserting deleted node_t: temp_node to free_head list
						bst.free_head = t_off;
						temp_node.left_offset = head_off;
						temp_node.right_offset = head_off;
						fseek(fp, t_off, SEEK_SET); //updating the free_head list to the deleted node_t: temp_node
						fwrite(&temp_node, sizeof(node_t), 1, fp);
						fseek(fp, 0, SEEK_SET);		//updating new free_head and root offsets
						fwrite(&bst, sizeof(tree_t), 1, fp);
					}
					return;					
				}
			}
		}
	}
	if(flag2 == 0)
	{
		fseek(fp, prev_off, SEEK_SET);	//updating parent: prev_node of deleted node_t: curr_node containing key
		fwrite(&prev_node, sizeof(node_t), 1, fp);
		
		head_off = bst.free_head;	//inserting deleted node_t: curr_node to free_head list
		bst.free_head = temp_off;
		curr_node.left_offset = head_off;
		curr_node.right_offset = head_off;
		fseek(fp, temp_off, SEEK_SET);	//updating the free_head list to the deleted node_t: curr_node
		fwrite(&curr_node, sizeof(node_t), 1, fp);
		fseek(fp, 0, SEEK_SET);		//updating new free_head and root offsets
		fwrite(&bst, sizeof(tree_t), 1, fp);
	}
}

