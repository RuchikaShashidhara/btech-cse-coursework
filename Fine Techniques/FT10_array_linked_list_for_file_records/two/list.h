#ifndef LIST_H
#define LIST_H
#define MAX 10
struct node
{
	int key;
	int link;
};
typedef struct node node_t;
struct list
{
	node_t a[MAX];
	int head_free;
	int head_filled;
};
typedef struct list list_t;
void init_list(list_t *ptr_list);
void disp_list(const list_t *ptr_list);
void insert(list_t *ptr_list, int key);
void delete(list_t *ptr_list, int key);
#endif

