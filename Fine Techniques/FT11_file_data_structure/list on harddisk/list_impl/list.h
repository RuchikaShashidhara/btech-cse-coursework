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
};
typedef struct list list_t;
FILE* init_list(list_t *, const char* name);
void close_list(list_t *, FILE *fp);
void disp_list(const list_t *ptr_list, FILE *fp);
void insert_key(list_t *ptr_list, int key, FILE *fp);
void delete_key(list_t *ptr_list, int key, FILE *fp);
#endif
