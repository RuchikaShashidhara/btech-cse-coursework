#include <stdio.h>
#include "prison1.h"
// 0 : closed; 1 : open
void init_prison(prison_t* p, int n)
{
	int base;
	p->n = n;
	for(int i = 0; i <= p->n; i += sizeof(int))
	{
		base = i / sizeof(int);
		p->cell[base] = 0;
	}	
}
void disp_open(const prison_t* p )
{
	for(int i = 1; i <= p->n; ++i)
	{
		int base = i / sizeof(int);
		int offset = i % sizeof(int);
		if(p->cell[base] & (1 << offset))
		{
			printf("%d ", i);
		}
	}
	printf("\n");
	
}

void open_close(prison_t* p )
{
	int base;
	int offset;
	for(int factor = 1; factor <= p->n; ++factor)
	{
		for(int multiple = factor; multiple <= p->n; multiple += factor)
		{
			base = multiple / sizeof(int);
			offset = multiple % sizeof(int);
			if(p->cell[base] & (1 << offset))
			{
				p->cell[base] &= ~(1 << offset);
			}
			else
			{
				p->cell[base] |= (1 << offset);
			}
		}
	}
}


