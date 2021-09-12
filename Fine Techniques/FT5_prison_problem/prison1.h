#ifndef  PRISON_H
#define PRISON_H
#if 0
#define MAX 1000
struct prison
{
	int cell[MAX];
	int n;
};
typedef struct prison prison_t;
void init_prison(prison_t* p, int n);
void disp_open(const prison_t* p );
void open_close(prison_t* p );
#endif

// bit implementation
#define SIZE sizeof(int)
#define MAX ((1000 / SIZE) + 1)
struct prison
{
	unsigned int cell[MAX];
	int n;
};
typedef struct prison prison_t;
void init_prison(prison_t* p, int n);
void disp_open(const prison_t* p );
void open_close(prison_t* p );


#endif 
