
#ifndef LIST_H
#define LIST_H
// header node concept
struct node
{
	int key;
	struct node *next;
};
typedef struct node node_t;
struct list
{
	node_t *head;
};
typedef struct list list_t;
void init_list(list_t *ptr_list);
void insert_list(list_t *ptr_list, int elem);
void delete_list(list_t *ptr_list, int elem);
void disp_list(const list_t *ptr_list);
//void list_destroy(list_t *ptr_list);
#endif
