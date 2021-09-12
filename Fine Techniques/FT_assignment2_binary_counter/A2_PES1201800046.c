#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "assignment_2.h"

//Each element of the (Data Structure)Linked lists - L1 and L2
struct node
{
	int key;		//Integer data value of each node
	struct node *next;	//Pointer that holds the address of the next node
};
typedef struct node Node_t;

//Returns a set of winner sets of maximum elements which have lost to the first node of the list
static Node_t *maxWinnerSet(int *numbers, int left, int right);
//Display function to view the nodes in the maxWinnerSet 
static void displayList(Node_t* L);

//Returns the second highest value of the array *numbers
void find_second_greatest(int *numbers, int length)
{
	//MaxSet will contain a linked list of intergers which contains 
	//the highest value of *numbers followed by elements which have lost to the first element
	Node_t* MaxSet = maxWinnerSet(numbers, 0, length - 1);  
	int SecMax = MaxSet->next->key;		//Setting the second element of the linked list to be the second highest value
	Node_t* temp = MaxSet->next->next;	//Initializing temp to the third element of the linked list	
	while(temp != NULL)			//Traversing till the last element of the Linked List
	{
		if(temp->key > SecMax)		//Checking if the current value of the node is larger than SecMax
		{				//If the condition is satisfied
			SecMax = temp->key;	//Assigning the node value to SecMax
		}
		temp = temp->next;		//Traversing to the next node	
	}
	printf("\n%d\n", SecMax);		//Printing the value of the second highest integer
}

//Returns a set of winner sets of maximum elements which have lost to the first node of the Linked List
static Node_t *maxWinnerSet(int *numbers, int left, int right)
{
	//Base condition when the smallest division of the array gives a single element
	if(left == right)		
	{
		//Creating a node that points to NULL and conatins the single element
		Node_t* temp = (Node_t*)malloc(sizeof(Node_t));		
		temp->key = numbers[left];				
		temp->next = NULL;
		//Returning the Linked List conating the single element
		return temp;	
	}
	//Base condition when 2 elements are left after division of the array
	else if(right - left == 1)	
	{
		//Displaying the two elements before playing the tournament
		printf("%d x %d = ", numbers[left], numbers[right]);
		//Creating two nodes that will conatain the larger number followed by the smaller number in the Linked List
		Node_t* temp1 = (Node_t*)malloc(sizeof(Node_t));
		Node_t* temp2 = (Node_t*)malloc(sizeof(Node_t));
		temp1->next = temp2;
		temp2->next = NULL;	
		//Checking if the fist element is larger than the second element	
		if(numbers[left] > numbers[right])	
		{
			temp1->key = numbers[left];
			temp1->next = temp2;
			temp2->key = numbers[right];
			temp2->next = NULL;
		}
		//Checking if the second element is larger than the first element
		else					
		{
			temp1->key = numbers[right];
			temp1->next = temp2;
			temp2->key = numbers[left];
			temp2->next = NULL;
		}
		//Displaying the Linked List after a tournament played between the 2 elements
		displayList(temp1);
		printf("\n");
		//Returning the Linked List after the tournament played between the two elements
		return temp1;
	}
	else	//Condition when the length of the array is greater than 2 elements
	{
		//splitIndex will conatain the index to split the array
		int splitIndex = pow(2, (int)ceil(log(right - left + 1)/log(2)) - 1);
		//L1 will conatin the losing set of the first division of the array after multiple recursions
		Node_t* L1 = maxWinnerSet(numbers, left, left + splitIndex - 1);
		//L2 will conatin the losing set of the second division of the array after multiple recursions
		Node_t* L2 = maxWinnerSet(numbers, left + splitIndex, right);
		//Displaying the two Linked Lists L1 and L2 before playing the tournament
		displayList(L1);
		printf("x ");
		displayList(L2);
		printf("= ");
		if(L1->key > L2->key)			//Checking if L1 conatins a higher first element than L2
		{
			Node_t* deltemp = L2->next;	//deltemp conatins the second element of the L2 
			Node_t* temp = NULL;		//temp is used to traverse L2 for freeing the elements
			//Linking the first element of L2 to the second element of L1 
			L2->next = L1->next;	
			//Linking the first element of L1 to the first element of L2 i.e. the loser of the tournament		
			L1->next = L2;
			//Freeing the elements after deltemp 
			while(deltemp != NULL)		
			{
				temp = deltemp;
				deltemp = deltemp->next;
				free(temp);
			}
			//Displaying the merged Linked List L1 after the tournament is played between L1 and L2
			displayList(L1);
			printf("\n");
			//Returning the megered Linked List L1 that conatins the highest value and the losing set
			return L1;
		}
		else					//Checking if L2 conatins a higher first element than L1
		{
			Node_t* deltemp = L1->next;	//deltemp conatins the second element of the L2 
			Node_t* temp = NULL;		//temp is used to traverse L1 for freeing the elements
			//Linking the first element of L1 to the second element of L2
			L1->next = L2->next;
			//Linking the first element of L2 to the first element of L1 i.e. the loser of the tournament		
			L2->next = L1;
			//Freeing the elements after deltemp 
			while(deltemp != NULL)
			{
				temp = deltemp;
				deltemp = deltemp->next;
				free(temp);
			}
			//Displaying the merged Linked List L2 after the tournament is played between L1 and L2
			displayList(L2);
			printf("\n");
			//Returning the megered Linked List L1 that conatins the highest value and the losing set
			return L2;
		}
		
	}
}

//Display function to view the nodes in the maxWinnerSet 
static void displayList(Node_t* L)
{
	Node_t* temp = L;			//Temporary node is initialized to address of starting of the linked list L
	while(temp != NULL)			//Traversing till the end of the linked list(temp == NULL)
	{
		printf("%d ", temp->key);	//Printing the value of the key of the node(Node_t)
		temp = temp->next;		//Traversing to the next node
	}
}




