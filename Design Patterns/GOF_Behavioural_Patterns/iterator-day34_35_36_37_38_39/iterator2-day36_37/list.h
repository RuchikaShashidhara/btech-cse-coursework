#ifndef LIST_H
#define LIST_H
typedef struct node
{
	int key;
	struct node* link;
} node_t;

typedef struct list
{
	node_t* head;
} list_t;
void init(list_t *ptr_list);
void insert(list_t *ptr_list, int key);
void disp(const list_t *ptr_list);

struct iterator
{
	node_t* current;
};
typedef struct iterator iterator_t;
void init_iterator(list_t *ptr_list, iterator_t *ptr_iterator);
int has_next(const iterator_t *ptr_iterator);
int next(iterator_t *ptr_iterator);
// set, get
// find
// modify the list implementation to an arraylist
//	
#endif
