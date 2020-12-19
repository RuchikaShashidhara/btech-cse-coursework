#include <stdio.h> 
#include <stdlib.h> 

//Queue delete front and insert rear
  
// Node type 
typedef struct Node 
{ 
    int data; 
    struct Node *link;
}Node; 
  
void display(Node *front, Node *rear){
    if(front == NULL){
        printf("EMPTY\n");
    }
    else{
        while(front != rear){
            printf("%d->", front->data);
            front = front->link;
        }
        printf("%d\n", front->data);
    }
}

void enq(int element, Node** pfront, Node** prear){
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->data = element;
    temp->link = NULL;
    if(*pfront == NULL){
        *pfront = *prear = temp;
    }
    else{
        (*prear)->link = temp;
        *prear = temp;
    }
}

void deq(Node** pfront, Node** prear){
    Node *temp = *pfront;
    if(*pfront == NULL){
        printf("EMPTY\n");
    }
    else{
        if(*pfront == *prear){
            *pfront = *prear = NULL;
        }
        else{
            *pfront = temp->link;
        }
        free(temp);
    }
}

int main(){
    int ele, ch, k;
    Node *front, *rear;
    front = rear = NULL;
    do{
        printf("1.Inset from rear\n2.Delete from front\n3.Exit\n");
        scanf("%d", &ch);
        switch(ch){
            case 1:
                printf("Enter the element\n");
                scanf("%d", &ele);
                enq(ele, &front, &rear);
                display(front, rear);
                break;
            case 2:
                deq(&front, &rear);
                display(front, rear);
                break;
            case 3:
                break;
            default:
                printf("Invalid entry\n");
        }
    } while(ch!=3);
    return 0;
}

