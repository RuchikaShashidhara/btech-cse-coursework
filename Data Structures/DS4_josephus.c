#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
int data;
struct Node *next;
}Node;

// To create a new node of circular
// linked list
Node *newNode(int data){
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->next = temp;
    temp->data = data;
}

int jose(int n,int m){
    Node *head=newNode(1);//insert first element into cll
    Node *prev=head;
    
    int i;
    for(i=2;i<=n;i++){ //insert all elements to the cll
        prev->next=newNode(i);
        prev=prev->next;
    }
    prev->next=head;
    
    Node *ptr1,*ptr2;
    ptr1=ptr2=head;
    while(ptr1->next!=ptr1){ //until 2 elements are present
        int count=1;
        while(count!=m){
            ptr2=ptr1; /
            ptr1=ptr1->next;
            count++;
        }
        ptr2->next=ptr1->next; //delete ptr1 node, ptr2 points to ptr1
        ptr1=ptr2->next; //ptr1 points to next node of ptr2
    }
    return ptr1->data;
}

void main(){
    int m,n;
    printf("Number of people and number of skipped:\n");
    scanf("%d%d",&n,&m);
    int j=jose(n,m);
    printf("Last person,%d",j);
}
