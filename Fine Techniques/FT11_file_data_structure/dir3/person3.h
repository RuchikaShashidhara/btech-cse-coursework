#ifndef PERSON_H
#define PERSON_H
struct person
{
	char name[20];
	int age;
};
typedef struct person person_t;
extern size_t size;
#endif

