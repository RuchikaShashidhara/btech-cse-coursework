#include <stdio.h>
#include <stdlib.h>

#include "assignment_1.h"


//Global variables
char *p;	//char pointer pointing to the main char array
int size;	//interger that holds the size of the char array


//List - Data structure(List) that holds the blocks of allocated and free blocks
//Each block holds the size of the block, address of the next block,
//a flag called free that holds either 0 or 1, 1 - free block, 0 - allocated block

struct block
{
	int size;	    //size of bytes in allocated/free block
	int free;	    //flag free, 1 - free block, 0 - allocated block
	struct block *next; //address of the next block
};
typedef struct block Block;

//Global data structure that holds the bookkeeping block data structure
//mymalloc function allocates memory from this List
static Block *List;		


//Helper Functions

//1) Returns the smallest free block if present, else returns NULL
static Block *bestBlock(int requestedSize);	
//2) Makes a new block allocated by splitting a free block and stores it in List		
static void splitBlocks(Block *fittingSlot, int blockSize);
//3) Merges the consecutive free blocks by removing the 
//   conceptual book block in between them and stores it in List
static void mergeBlocks();

//Allocates memory of n bytes for p array and memory for 
//bookkeeping is initialized within the same n bytes of memory
void allocate(int n)
{
	//Initializes the size variable to size of n bytes
	size = n;
	//Initializes p char array of size size bytes
	p = (char *)malloc(size * sizeof(char));
	//Initializes the first block of memory - free, with size of the block = size - size of book
	List = (void *)p;
	List->next = NULL;
	List->free = 1;	
	List->size = size - sizeof(Block);	
}

//Returns the pointer that refers to the free memory location of 
//requestedSize bytes on the policy of best fit,
//returns NULL if no free memory block is found
void *mymalloc(int requestedSize){
	 //Initializing resultBlock pointer that will return the starting address of the allotted memory that is requested
	 void *resultBlock;
	 //Initalizing prev block pointer
	 Block *prev;
	 //Initalizing current - curr block pointer pointing to List
	 Block *curr = List;
	 //Traversing to the smallest free block that is available to allocate memory
	 while((((curr->size) <= requestedSize) || (!(curr->free))) && (curr->next!=NULL))
	 {
		  prev = curr;
		  curr = curr->next;
	 }
	 //If the requestedSize <= current block size <= requestedSize + size of book
	 if(((curr->size) >= requestedSize) && (curr->size <= requestedSize + sizeof(Block)) && (curr == bestBlock(requestedSize)))
	 {
 		  //Making the free block into allocated block by setting free flag to 0
 		  curr->free = 0;
 		  //return the address of the allocted memory block
		  resultBlock = (void*)(++curr);
		  return resultBlock;
	 }
	 //if current block size > requestedSize
	 else if(((curr->size) > (requestedSize + sizeof(Block))) && (curr == bestBlock(requestedSize)))
	 {
		  //Split the current free block into one block of alloacted block with requestedSize and a free block with remaining memory
		  splitBlocks(curr, requestedSize);
		  //return the address of the allocted memory block
		  resultBlock = (void*)(++curr);
		  return resultBlock;
	 }
	 else
	 {
	 	  //return NULL when no free block of memory is present in List
		  resultBlock = NULL;
		  return resultBlock;
	 }
}

//Frees the block pointed by the parameter including merging two free blocks if present,
//doesn't do anything when the pointer points to NULL
void myfree(void* b)
{
	 //Checking whether the address of the given pointer lies within the address range of char memory array
	 if(((void *)p <= b) && (b <= (void *)(p + size)))
	 {
		  //Initializing the current block pointer to b
		  Block* curr = b;
		  --curr;
		  //Making the allocated block to free block by setting the free flag to 0
		  curr->free = 1;
		  mergeBlocks();
		  
		  //merging two consecutive free blocks by removing a conceptual book block between them
		  Block *prev = NULL;
	 	  curr = List;
		  while((curr != NULL) && (curr->next != NULL))
		  {
			  if((curr->free) && (curr->next->free))
			  {
			  	curr->size += (curr->next->size) + sizeof(Block);
			   	curr->next = curr->next->next;
			  }
			  prev = curr;
			  curr = curr->next;
		  }			  
	 }
	 //Doesn't do anything if the pointer to be freed is NULL or out of range
	 else
	 {
	 	return;
	 }
}

//Prints the size used by bookkeeping structre i.e. Block
void print_book()
{
	printf("%ld", sizeof(Block));
} 

//Prints start address, size of blocks in bytes and status(book, allocated or free) 
//for each block in the conceptual bookkeeping structure
void display_mem_map()
{
	//Initializing a block pointer to traverse List
	Block *curr = List;
	int addr = 0;
	//Traversing the list till the last block
	while(curr != NULL)
	{
		//Printing conceptual book block information
		printf("%d\t%ld\tbook\n", addr ,sizeof(Block));
		addr += sizeof(Block);
		//Printing allocated or free block information
		printf("%d\t%d\t", addr, curr->size);
		if(curr->free)
		{
			printf("free\n");
		}
		else
		{
			printf("allocated\n");
		}
		addr += curr->size;
		//Traversing to the next block
		curr = curr->next;
	}
}

static Block *bestBlock(int requestedSize)
{
	//Initializing a block of minimum size - minSizeBlock wrt free block present in List
	Block *minSizeBlock = NULL;
	//Initializing a block pointer to traverse List
	Block *curr = List;
	//Trversing List till the last block of List
	while(curr != NULL)
	{
		//Checking whether the block is free and size of free block >= requestedSize in mymalloc function
		//and size of the current free block > size of previous minSizeBlock
		if((curr->free) && (curr->size >= requestedSize) && (!minSizeBlock || curr->size < minSizeBlock->size))
		{
			//Assigning the current block to minSizeBlock
			minSizeBlock = curr;
		}
		//Traversing to the next block
		curr = curr->next;
	}
	//Returning the minSizeBlock
	return minSizeBlock;
}

//Makes a new block allocated by splitting a free block and stores it in List		
static void splitBlocks(Block *fittingSlot, int blockSize)
{
	 //Initializing new block - newBlock pointing to the block of memory whose size is more than required - fittingSlot
	 Block *newBlock = (void *)((void *)fittingSlot + blockSize + sizeof(Block));
	 //Setting the size of newBlock to the amount of free pace after the block is split
	 newBlock->size = (fittingSlot->size) - blockSize - sizeof(Block);
	 //Setting the free flag to 1, as newBlock becomes a free block
	 newBlock->free = 1;
	 //Pointing newBlock to the address of List where fittingSlot was pointing to before
	 newBlock->next = fittingSlot->next;
	 //Pointing fittingSlot to the address of newBlock
	 fittingSlot->next = newBlock;
	 //Setting the free flag to 0, as fittingBlock becomes an allocated block
	 fittingSlot->free = 0;
	 //Setting the size of fittingBlock to the size of bytes that was requested i.e. blockSize
	 fittingSlot->size = blockSize;
}

//Merges the consecutive free blocks by removing the 
//conceptual book block in between them and stores it in List
static void mergeBlocks()
{
	 //Initializing prev Block pointer
	 Block *prev= NULL;
	 //Initialzing current curr Block pointer pointing to List
	 Block *curr = List;
	 //Traversing till the last two blocks of List
	 while((curr != NULL) && ((curr->next) != NULL))
	 {
	 	  //Checking if the current block and the block after the current block are free blocks
		  if((curr->free) && (curr->next->free))
		  {
			   //Setting the size of the current block to the size of current free block
			   // and size of the free block after the current free block
			   curr->size += (curr->next->size) + sizeof(Block);
			   //Pointing the current free block to List where the block after current free block was pointing to
			   curr->next = curr->next->next;
		  }
		  //Assigning the current block to prev block
		  prev = curr;
		  //Traversing to the next block
		  curr = curr->next;
	 }
}



