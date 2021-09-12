#ifndef PERSON_H
#define PERSON_H
#define MAX 10
struct header
{
	int pos[MAX + 1];
};
typedef struct header header_t;

struct person
{
	char name[20];
	int age;
};
typedef struct person person_t;
extern size_t size;
void disp_person(const person_t*);
#endif

