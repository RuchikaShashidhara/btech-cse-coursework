#include <stdio.h>
#include <stdlib.h>
#include "person4.h"
size_t size = sizeof(person_t);

void disp_person(const person_t* ptr_person)
{
	printf("name: %s age: %d\n",
		 			 	 ptr_person->name, ptr_person->age);  
}

