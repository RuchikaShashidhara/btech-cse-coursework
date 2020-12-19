#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *prevlink;
    struct Node *nextlink;
}Node;

typedef struct List{
    Node *head;
    int num_of_nodes;
}List;

//positions of the list start from 0 to (num_of_nodes - 1)

//To create a node in an DLL
Node* create_node(int data);

//To initialize a DLL
List* dll_initialize();

//To insert at the begining of the DLL
void dll_insert_begining(List* list, int data);

//To insert at the end of the DLL
void dll_insert_end(List* list, int data);

//To insert at position in DLL
//if position = num_of_nodes, it inserts at the end; if position = 0, it inserts at the begining
void dll_insert_at_position(List *list, int data, int position);

//To insert into an ordered DLL
void dll_insert_ordered(List *list, int data);

//To delete at the begining of the DLL
void dll_delete_begining(List* list);

//To delete at the end of the DLL
void dll_delete_end(List* list);

//To delete at position in DLL
void dll_delete_at_position(List *list, int position);

//Search for a particular node - returns position of the key if present, else returns -1
int find_key(List *list, int data);

//Displays all elements of the DLL 
void dll_display(List* list);

//Displays alternate elements of the DLL
void dll_display_alternate(List* list);

//Deallocates resources held by the list 
void list_destroy(List *list);


int main()
{
    int choice, choice2, element, index;
    List* list = dll_initialize();
    do{
        printf("1.Insert Node\n2.Delete Node\n3.Find Node\n4.Display List\n5.Display alternate nodes\n0.Exit\n");
        printf("Enter choices from 0-4\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("1.Insert at the begining of the list\n2.Insert at the end of the list\n3.Insert at a position of the list\n4.Ordered Insertion\n");
                printf("Enter choices from 1-3\n");
                scanf("%d", &choice2);
                switch(choice2){
                    case 1:
                        printf("Enter element\n");
                        scanf("%d", &element);
                        dll_insert_begining(list, element);
                        dll_display(list);
                        break;
                    case 2:
                        printf("Enter element\n");  
                        scanf("%d", &element);
                        dll_insert_end(list, element);
                        dll_display(list);
                        break;
                    case 3:
                        printf("Enter element and position\n");
                        scanf("%d %d", &element, &index);
                        dll_insert_at_position(list, element, index);
                        dll_display(list);
                        break;
                    case 4:
                        printf("Enter element\n");
                        scanf("%d", &element);
                        dll_insert_ordered(list, element);
                        dll_display(list);
                        break;
                    default:
                        printf("Invalid Choice\n");
                        break;
                }
                break;
            case 2:
                printf("1.Delete at the begining of the list\n2.Delete at the end of the list\n3.Delete at a position of the list\n");
                printf("Enter choices from 1-3\n");
                scanf("%d", &choice2);
                switch(choice2){
                    case 1:
                        dll_delete_begining(list);
                        dll_display(list);
                        break;
                    case 2:
                        dll_delete_end(list);
                        dll_display(list);
                        break;
                    case 3:
                        printf("Enter position\n");
                        scanf("%d",&index);
                        dll_delete_at_position(list, index);
                        dll_display(list);
                        break;  
                    default:
                        printf("Invalid Choice\n");
                        break;
                }
                break;
            case 3:
                printf("Enter element to find\n");
                scanf("%d",&element);
                index = find_key(list, element);
                printf("%d is found at position no.%d\n", element, index);
                break;
            case 4:
                dll_display(list);
                break;
            case 5:
                dll_display_alternate(list);
                break;
            case 0:
                break;
            default:
                printf("Invalid Choice\n");
                break;
        }
    } while(choice!=0);
    list_destroy(list);
    return 0;
}

//To create a node in an DLL
Node* create_node(int data){
	Node *node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->prevlink = NULL;
	node->nextlink = NULL;
	return node;
}	

//To initialize a DLL
List* dll_initialize(){
    List *list = (List*)malloc(sizeof(List));
    list->head = NULL;
    list->num_of_nodes = 0;
    return list;
}

//To insert at the begining of the DLL
void dll_insert_begining(List* list, int data){
    Node* new_node = create_node(data);
    if(list->head == NULL){ //no nodes
        list->head = new_node;
        list->num_of_nodes ++;
        return;
    }
    Node* temp = list->head;
	new_node->nextlink = temp;
    temp->prevlink = new_node;
    list->head = new_node;
    list->num_of_nodes ++;
}

//To insert at the end of the DLL
void dll_insert_end(List* list, int data){
	Node* new_node = create_node(data);
    Node* temp = list->head;
    if(list->head == NULL){
        list->head = new_node;
        list->num_of_nodes ++;
        return;
    }
    else{
        while(temp->nextlink != NULL){
            temp = temp->nextlink;
        }
        temp->nextlink = new_node;
        new_node->prevlink = temp;
    }
    list->num_of_nodes ++;
}

//To insert at position in DLL
void dll_insert_at_position(List *list, int data, int position){
    if(position < 0 || position > list->num_of_nodes){ //invalid
        return;
    }
    if(position==0){ //position = 0(head)
        dll_insert_begining(list, data);
        return;
    }
    Node* temp = list->head;
    Node* prev_temp = NULL;
	Node* new_node = create_node(data);
    int i=0;
    while(temp!=NULL && i!=position){
        if(i == (list->num_of_nodes - 1)){
            prev_temp = temp;
        }
        temp = temp->nextlink;
        i++;
    }
    if(temp == NULL){ //position = n-1 (last)
        prev_temp->nextlink = new_node;
        new_node->prevlink = prev_temp;
    }
    else{ // position is in between the list
        new_node->nextlink = temp;
        temp->prevlink->nextlink = new_node;
        new_node->prevlink = temp->prevlink;
        temp->prevlink = new_node;
    }        
    
    list->num_of_nodes ++;
}

//To insert into an ordered DLL
void dll_insert_ordered(List *list, int data){
	/*Node* new_node = create_node(data);
    Node* temp = list->head;
    if(temp==NULL || new_node->data < temp->data){
        new_node->link = list->head;
        list->head = new_node;
    }
    else{
        Node *prev = NULL;
        while(temp!=NULL && new_node->data >= temp->data){
            prev = temp;
            temp = temp->link;
        }
        new_node->link = temp;
        prev->link = new_node;
    }
    list->num_of_nodes ++;*/
    return;
}

//To delete at the begining of the DLL
void dll_delete_begining(List* list){
    if(list->head == NULL){ //no nodes
        return;
    }
    Node* temp = list->head;
    list->head = list->head->nextlink;
    free(temp);
    list->num_of_nodes --;
}

//To delete at the end of the DLL
void dll_delete_end(List* list){
    if(list->head == NULL){
        return;
    }
    Node *temp = list->head;
    if(temp->nextlink == NULL){
        list->head = NULL;
    }
    else{
        while(temp->nextlink != NULL){
            temp = temp->nextlink;
        }
        temp->prevlink->nextlink = NULL;
    }
    free(temp);
    list->num_of_nodes --;
}

//To delete at position in DLL
void dll_delete_at_position(List *list, int position){
    /*if(position < 0 || position >= list->num_of_nodes){
        return;
    }
    if(position == 0){
        dll_delete_begining(list);
        return;
    }
    Node* temp = list->head;
    Node* prev_temp = NULL;
    int i=0;
    while(temp!=NULL && i!=position){
        if(i==(list->num_of_nodes - 1)){
            prev_temp = temp;
            printf("%d", i);
        }
        temp = temp->nextlink;
        printf("%d", i);
        i++;
    }
    if(temp==NULL){
        prev_temp->nextlink = NULL;
    }
    else{
        temp->prevlink->nextlink = temp->nextlink;
        temp->nextlink->prevlink = temp->prevlink;
    }
    free(temp);
    list->num_of_nodes --;*/
    int n=(list->num_of_nodes-1),i;
    if(position<0||position>n) //no nodes
        return;
    Node* temp = list->head;
    if(position==0){ //position = 0(head)
        if(temp==NULL){ //no nodes
            return;
        }
        else{ 
            list->head = temp->nextlink;
        }
    }
    else if(position<n)
    {
        for(i=0;i<position;i++)
            temp = temp->nextlink;
        temp->prevlink->nextlink = temp->nextlink;
        temp->nextlink->prevlink = temp->prevlink;
       
    }
    else // position = n-1(last )
    {
        for(i=0;i<n;i++)
            temp = temp->nextlink;
        temp->prevlink->nextlink = NULL;
    }
    free(temp);
    list->num_of_nodes--;
}

//Search for a particular node - returns position of the key if present, else returns -1
int find_key(List *list, int data){
    Node *temp = list->head;
    int i=0;
    while(temp != NULL){
        if(data == temp->data){
            return i;
        }
        i++;
        temp = temp->nextlink;
    }
    return -1;
}

//Displays all elements of the DLL 
void dll_display(List* list){
    if(list->head == NULL){
        printf("EMPTY\n");
        return;
    }
    else{
        Node *temp = list->head;
        while(temp != NULL){
            printf("%d->", temp->data);
            temp = temp->nextlink;
        }
        printf("NULL\n");
    }
    printf("Total number of nodes are %d\n", list->num_of_nodes);
}

//Displays alternate elements of the DLL
void dll_display_alternate(List* list){
    if(list->head == NULL){
        printf("EMPTY\n");
        return;
    }
    else{
        int count;
        Node *temp = list->head;
        while(temp!=NULL){
            printf("%d, ", temp->data);
            count ++;
            if(temp->nextlink==NULL){
                break;
            }
            else{
                temp = temp->nextlink->nextlink;
            }
        }
        printf("Total number of alternante nodes are %d\n", count);
    }
    printf("Total number of nodes are %d\n", list->num_of_nodes);
}


//Deallocates resources held by the list 
void list_destroy(List *list){
    Node *temp = list->head;
    Node *prev_temp;
    while(temp != NULL){
        prev_temp = temp;
        temp = temp->nextlink;
        free(prev_temp);
    }
}

