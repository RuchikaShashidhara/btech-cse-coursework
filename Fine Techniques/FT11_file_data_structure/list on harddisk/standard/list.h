#ifndef LIST_H
#define LIST_H
#define MAX 5
struct node
{
	int key;
	int link;
};
typedef struct node node_t;
struct list
{
	int free_head;
	int filled_head;
	node_t a[MAX];
};
typedef struct list list_t;
void init_list(list_t *);
void disp_list(const list_t *);
void insert_key(list_t *, int);
void delete_key(list_t *, int);
#endif
