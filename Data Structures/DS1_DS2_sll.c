#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *link;
}Node;

typedef struct List{
    Node *head;
    int num_of_nodes;
}List;

//positions of the list start from 0 to (num_of_nodes - 1)

//To create a node in an SLL
Node* create_node(int data);

//To initialize a SLL
List* sll_initialize();

//To insert at the begining of the SLL
void sll_insert_begining(List* list, int data);

//To insert at the end of the SLL
void sll_insert_end(List* list, int data);

//To insert at position in SLL
//if position = num_of_nodes, it inserts at the end; if position = 0, it inserts at the begining
void sll_insert_at_position(List *list, int data, int position);

//To insert into an ordered SLL
void sll_insert_ordered(List *list, int data);

//To delete at the begining of the SLL
void sll_delete_begining(List* list);

//To delete at the end of the SLL
void sll_delete_end(List* list);

//To delete at position in SLL
void sll_delete_at_position(List *list, int position);

//Search for a particular node - returns position of the key if present, else returns -1
int find_key(List *list, int data);

//Displays all elements of the SLL 
void sll_display(List* list);

//Displays alternate elements of the SLL
void sll_display_alternate(List* list);

//Deallocates resources held by the list 
void list_destroy(List *list);


int main()
{
    int choice, choice2, element, index;
    List* list = sll_initialize();
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
                        sll_insert_begining(list, element);
                        sll_display(list);
                        break;
                    case 2:
                        printf("Enter element\n");  
                        scanf("%d", &element);
                        sll_insert_end(list, element);
                        sll_display(list);
                        break;
                    case 3:
                        printf("Enter element and position\n");
                        scanf("%d %d", &element, &index);
                        sll_insert_at_position(list, element, index);
                        sll_display(list);
                        break;
                    case 4:
                        printf("Enter element\n");
                        scanf("%d", &element);
                        sll_insert_ordered(list, element);
                        sll_display(list);
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
                        sll_delete_begining(list);
                        sll_display(list);
                        break;
                    case 2:
                        sll_delete_end(list);
                        sll_display(list);
                        break;
                    case 3:
                        printf("Enter position\n");
                        scanf("%d",&index);
                        sll_delete_at_position(list, index);
                        sll_display(list);
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
                sll_display(list);
                break;
            case 5:
                sll_display_alternate(list);
                break;
            default:
                printf("Invalid Choice\n");
                break;
        }
    } while(choice!=0);
    list_destroy(list);
    return 0;
}

//To create a node in an SLL
Node* create_node(int data){
	Node *node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->link = NULL;
	return node;
}	

//To initialize a SLL
List* sll_initialize(){
    List *list = (List*)malloc(sizeof(List));
    list->head = NULL;
    list->num_of_nodes = 0;
    return list;
}

//To insert at the begining of the SLL
void sll_insert_begining(List* list, int data){
    /*Node *n = (Node*)malloc(sizeof(Node));
    n->data = data;
    n->link = list->head;*/
    Node* new_node = create_node(data);
	new_node->link = list->head; 
    list->head = new_node;
    list->num_of_nodes ++;
}

//To insert at the end of the SLL
void sll_insert_end(List* list, int data){
    /*Node *n = (Node*)malloc(sizeof(Node));
    n->data = data;
    n->link = NULL;*/
	Node* new_node = create_node(data);
    Node* temp = list->head;
    if(list->head == NULL){ //if list is empty, point to list->head and add the node
        list->head = new_node;
    }
    else{
        while(temp->link != NULL){ //traverse till the last node(temp), add the last node to temp->link
            temp = temp->link;
        }
        temp->link = new_node;
    }
    list->num_of_nodes ++;
}

//To insert at position in SLL
void sll_insert_at_position(List *list, int data, int position){
    if(position < 0 || position > list->num_of_nodes){
        return;
    }
    Node *temp = list->head;
    Node *prev = NULL;
    /*Node *n = (Node*)malloc(sizeof(Node));
    n->data = data;
    n->link = NULL;*/
	Node* new_node = create_node(data);
    int i=0;
    while(temp!=NULL && i!=position){
        prev = temp;
        temp = temp->link;
        i++;
    }
    if(prev==NULL){
        new_node->link = list->head;
        list->head = new_node;
    }
    else{
        new_node->link = temp;
        prev->link = new_node;
    }
    list->num_of_nodes ++;
}

//To insert into an ordered SLL
void sll_insert_ordered(List *list, int data){
    /*Node *n = (Node*)malloc(sizeof(Node));
    n->data = data;
    n->link = NULL;*/
	Node* new_node = create_node(data);
    Node* temp = list->head;
    if(temp==NULL || new_node->data < temp->data){ //only one node is present
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
    list->num_of_nodes ++;
}

//To delete at the begining of the SLL
void sll_delete_begining(List* list){
    if(list->head == NULL){
        return;
    }
    Node* temp = list->head;
    list->head = list->head->link;
    free(temp);
    list->num_of_nodes --;
}

//To delete at the end of the SLL
void sll_delete_end(List* list){
    if(list->head == NULL){ //no nodes
        return;
    }
    Node *temp = list->head;
    Node *prev;
    if(temp->link == NULL){ //only one node
        list->head = NULL;
    }
    else{
        while(temp->link != NULL){
            prev = temp;
            temp = temp->link;
        }
        prev->link = NULL;
    }
    free(temp);
    list->num_of_nodes --;
}

//To delete at position in SLL
void sll_delete_at_position(List *list, int position){
    if(position < 0 || position > list->num_of_nodes){
        return; //invalid
    }
    Node *temp = list->head;
    Node *prev = NULL;
    Node *next = NULL;
    int i=0;
    while(temp!=NULL && i!=position){
        prev = temp;
        temp = temp->link;
        i++;
    }
    
    if(temp==NULL){ //invalid
        return;
    }
    else if(prev==NULL){ //one node present
        list->head = list->head->link;
    }
    else{ 
        prev->link = temp->link;
    }
    free(temp);
    list->num_of_nodes --;
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
        temp = temp->link;
    }
    return -1;
}

//Displays all elements of the SLL 
void sll_display(List* list){
    if(list->head == NULL){
        printf("EMPTY\n");
        return;
    }
    else{
        Node *temp = list->head;
        while(temp != NULL){
            printf("%d->", temp->data);
            temp = temp->link;
        }
        printf("NULL\n");
    }
    printf("Total number of nodes are %d\n", list->num_of_nodes);
}

//Displays alternate elements of the SLL
void sll_display_alternate(List* list){
    if(list->head == NULL){ //no nodes
        printf("EMPTY\n");
        return;
    }
    else{
        int count;
        Node *temp = list->head;
        while(temp!=NULL){
            printf("%d, ", temp->data);
            count ++;
            if(temp->link==NULL){
                break;
            }
            else{
                temp = temp->link->link; //skips a node
            }
        }
        printf("Total number of alternante nodes are %d\n", count);
    }
    printf("Total number of nodes are %d\n", list->num_of_nodes);
}


//Deallocates resources held by the list 
void list_destroy(List *list){
    Node *temp = list->head;
    Node *prev;
    while(temp != NULL){
        prev = temp;
        temp = temp->link;
        free(prev);
    }
}
